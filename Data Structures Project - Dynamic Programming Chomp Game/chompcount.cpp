// chompcount.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    //opening input file
    ifstream inputFile;
    inputFile.open("input.txt", ios::in);
    //checking to make sure file opened properly
    if (!inputFile)
    {
        cout << endl << "Something went wrong opening the input file! Closing Program." << endl;
        return -1;
    }

    //reading data from file
    vector<int> inputData;
    int num;
    while (inputFile >> num)
    {
        inputData.push_back(num);
    }
    //closing file after finished reading data
    inputFile.close();

    //creating and opening an output file for writing answers to
    ofstream outputFile;
    outputFile.open("output.txt", ios::out);
    if (!outputFile.is_open())
    {
        cout << endl << "Error creating and opening output file! Ending Program." << endl;
        return -1;
    }

    //displaying message to console saying that program is running and to wait.
    cout << endl << "Program running, please wait..." << endl;

    //loop to go through each set of input values AKA each game
    for (int i = 1; i < inputData[0] * 3; i += 3)
    {
        //creating variables
        int n = inputData[i];
        int r = inputData[i + 1];
        int c = inputData[i + 2];
        int sum;
        vector<vector<vector<int> > > dynamicArr(n+1, vector<vector<int> >(r+1, vector<int>(c+1)));

        //loop to iterate through 3 dimensional array and fill each position
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= r; j++)
            {
                for (int k = 0; k <= c; k++)
                {
                    if (i > j * k)                          //base case #1 
                        dynamicArr[i][j][k] = 0;
                    else if ((j==1 && i <= k) || (i==0))    //base case #2
                        dynamicArr[i][j][k] = 1;
                    else                                    //array lookups and sums for non base cases
                    {
                        sum = 0;
                        for (int x = 1; x <= k; x++)
                            if (i - x >= 0 && j != 0)
                                sum += dynamicArr[i - x][j - 1][x];
                        dynamicArr[i][j][k] = sum;
                    }
                }
            }
        }
        outputFile << dynamicArr[n][r][c] << '\n';      //writing answer to output.txt file
    }
    //closing output file
    outputFile.close();

    //output ending message
    cout << endl << "Program finished. Ending now!" << endl;
    return 0;
}
