//This Program was written by Joseph Reiss U76703774
//Project #1 Solution for Database Design COP 4710

//Include directives
#include <iostream>
#include <vector>
#include <sstream>
#include <limits>
#include <string>
#include <fstream>
#include <iomanip>
#include "coach.h"
#include "team.h"

//namespace
using namespace std;

//function declarations
void add_coach(stringstream& ss, vector<Coach>& coaches);
void add_team(stringstream& ss, vector<Team>& teams);
void load_coaches(stringstream& ss, vector<Coach>& coaches);
void load_teams(stringstream& ss, vector<Team>& teams);
void remove_coach(stringstream& ss, vector<Coach>& coaches);
void remove_team(stringstream& ss, vector<Team>& teams);
void print_coaches(vector<Coach>& coaches);
void print_teams(vector<Team>& teams);
void coaches_by_name(stringstream& ss, vector<Coach>& coaches);
void teams_by_city_league(stringstream& ss, vector<Team>& teams);
void best_coach(stringstream& ss, vector<Coach>& coaches);
void search_coaches(stringstream& ss, vector<Coach> coaches);
string replacePlus(string s);

//main function
int main()
{   
    //displaying beginning program message
    cout << endl << "Starting Program..." << endl << endl << "More detailed descriptions of each of the commands and their required arguments can be found in the readMe file." << endl << endl;

    //displaying the commands
    cout << "Program Commands:" << endl;
    cout << "add_coach" << endl;
    cout << "add_team" << endl;
    cout << "load_coaches" << endl;
    cout << "load_teams" << endl;
    cout << "remove_coach" << endl;
    cout << "remove_team" << endl;
    cout << "print_coaches" << endl;
    cout << "print_teams" << endl;
    cout << "coaches_by_name" << endl;
    cout << "teams_by_city_league" << endl;
    cout << "best_coach" << endl;
    cout << "search_coaches" << endl;
    cout << "end_program" << endl;

    //vectors to hold coaches and teams
    vector<Team> teams;
    vector<Coach> coaches;

    //main program loop to execute until program canceled
    while (true)
    {
        //geting user input for command
        string user_input;
        cout << endl << "Enter your command: ";
        getline(cin, user_input);

        //splitting input string to get first "word" or the actual command without paramaters
        stringstream ss(user_input);
        string command;
        ss >> command;

        //just for ease of reading while in console to seperate command and output
        cout << "----------------------------------------------------------------------------------------------------" << endl;

        //handling user command
        if (command == "add_coach")
        {
            add_coach(ss, coaches);
        }
        else if (command == "add_team")
        {
            add_team(ss, teams);
        }
        else if (command == "load_coaches")
        {
            load_coaches(ss, coaches);
        }
        else if (command == "load_teams")
        {
            load_teams(ss, teams);
        }
        else if (command == "remove_coach")
        {
            remove_coach(ss, coaches);
        }
        else if (command == "remove_team")
        {
            remove_team(ss, teams);
        }
        else if (command == "print_coaches")
        {
            print_coaches(coaches);
        }
        else if (command == "print_teams")
        {
            print_teams(teams);
        }
        else if (command == "coaches_by_name")
        {
            coaches_by_name(ss, coaches);
        }
        else if (command == "teams_by_city_league")
        {
            teams_by_city_league(ss, teams);
        }
        else if (command == "best_coach")
        {
            best_coach(ss, coaches);
        }
        else if (command == "search_coaches")
        {
            search_coaches(ss, coaches);
        }
        else if (command == "end_program")
            break;
        else
            cout << endl << "Invalid command. Try again." << endl;

    }
    //displaying end of program message
    cout << endl << "End of Program. Goodbye!" << endl;
    return 0;
}

//add coach function
//takes in stringstream reference that contains all the arguments for adding a coach
void add_coach(stringstream& ss, vector<Coach>& coaches)
{
    //variables
    string coach_ID;
    int season;
    string first_name;
    string last_name;
    int season_win;
    int season_loss;
    int playoff_win;
    int playoff_loss;
    string team;

    //getting all appropriate info from the stringstream
    ss >> coach_ID;
    ss >> season;
    ss >> first_name;
    first_name = replacePlus(first_name);
    ss >> last_name;
    last_name = replacePlus(last_name);
    ss >> season_win;
    ss >> season_loss;
    ss >> playoff_win;
    ss >> playoff_loss;
    ss >> team;

    //creating new coach with passed info
    Coach newCoach;
    newCoach.setID(coach_ID);
    newCoach.setSeason(season);
    newCoach.setFirstName(first_name);
    newCoach.setLastName(last_name);
    newCoach.setSeasonWin(season_win);
    newCoach.setSeasonLoss(season_loss);
    newCoach.setPlayoffWin(playoff_win);
    newCoach.setPlayoffLoss(playoff_loss);
    newCoach.setTeam(team);
    
    //adding to vector
    coaches.push_back(newCoach);
}

//print coaches function
//takes in vector containing all coaches
void print_coaches(vector<Coach>& coaches)
{
    if (coaches.size() == 0)
    {
        cout << "No information for any coaches stored in the database yet!" << endl;
        return;
    }
    for (int i = 0; i < coaches.size(); ++i)
    {
        cout << left << setw(12) << coaches[i].getID()
            << setw(7) << coaches[i].getSeason()
            << setw(10) << coaches[i].getFirstName()
            << setw(15) << coaches[i].getLastName()
            << setw(5) << coaches[i].getSeasonWin()
            << setw(5) << coaches[i].getSeasonLoss()
            << setw(5) << coaches[i].getPlayoffWin()
            << setw(5) << coaches[i].getPlayoffLoss()
            << setw(5) << coaches[i].getTeam() << endl;
    }
    return;
}

//load coaches function
//takes in vector containing coaches
void load_coaches(stringstream& ss, vector<Coach>& coaches)
{
    //opening input file and getting its name from stringstream
    string inputFileName;
    ss >> inputFileName;
    ifstream inputFile;
    inputFile.open(inputFileName.c_str());

    //variables to hold line and word
    string line;
    string word;

    //variables
    string coach_ID = "";
    int season = -1;
    string first_name = "";
    string last_name = "";
    int season_win = -1;
    int season_loss = -1;
    int playoff_win = -1;
    int playoff_loss = -1;
    string team = "";
    int counter;
    string throw_away;

    //getting first header line of input file (not necessary for use so we are essentially getting it to discard it)
    getline(inputFile, line);

    //reading each line of the input file and putting it into line
    while (getline(inputFile, line))
    {
        //putting line into a stringstream so we can than use delimiter ',' to get each word
        stringstream lineStream(line);
        //resetting counter
        counter = 1;
        //loop to get each word in a line seperated by delimiter ','
        while (getline(lineStream, word, ','))
        {
            //putting word into a stringstream so we can convert into data
            stringstream wordStream(word);
            //switch to decide what is the appropriate data to assign what is in word based on the counter variable
            switch (counter) {
            case 1:
                coach_ID = word;
                wordStream >> throw_away;
                break;
            case 2:
                wordStream >> season;
                break;
            case 3:
                first_name = word;
                wordStream >> throw_away;
                break;
            case 4:
                last_name = word;
                wordStream >> throw_away;
                break;
            case 5:
                wordStream >> season_win;
                break;
            case 6:
                wordStream >> season_loss;
                break;
            case 7:
                wordStream >> playoff_win;
                break;
            case 8:
                wordStream >> playoff_loss;
                break;
            case 9:
                team = word;
                wordStream >> throw_away;
                break;
            default:
                cout << endl << "something went wrong here" << endl;
                break;
            }
            counter++;
        }
        //creating new coach with passed info
        Coach newCoach;
        newCoach.setID(coach_ID);
        newCoach.setSeason(season);
        newCoach.setFirstName(first_name);
        newCoach.setLastName(last_name);
        newCoach.setSeasonWin(season_win);
        newCoach.setSeasonLoss(season_loss);
        newCoach.setPlayoffWin(playoff_win);
        newCoach.setPlayoffLoss(playoff_loss);
        newCoach.setTeam(team);

        //adding to vector
        coaches.push_back(newCoach);
    }
    return;
}

//remove coach function
//takes in vector containing coaches and stringstream containing arguments
void remove_coach(stringstream& ss, vector<Coach>& coaches)
{
    //checking to see if anything is in the vector first
    if (coaches.size() == 0)
    {
        cout << "No information for any coaches stored in the database yet!" << endl;
        return;
    }

    //getting coach ID from stringstream to remove
    string coach_ID;
    ss >> coach_ID;

    //variable to determine whether something was deleted or not
    bool deleted = false;

    //loop through entire vector
    for (int i = 0; i < coaches.size(); ++i)
    {
        //checking if coach at current index is one to delete based on coach ID
        if (coaches[i].getID() == coach_ID)
        {
            //erasing the coach
            coaches.erase(coaches.begin() + i);
            //setting deleted value to true to indicate something was deleted
            deleted = true;
            //decrementing index counter to adjust for new vector since something was removed
            //if this is not done than if two indices in a row need to get deleted the second will be skipped
            --i;
        }
    }

    //outputting message if nothing was deleted
    if (deleted == false)
    {
        cout << endl << "Could not find coach to delete. Nothing deleted." << endl;
    }

    return;
}

//coaches by name function
//takes in vector containing coaches and stringstream containing arguments
void coaches_by_name(stringstream& ss, vector<Coach>& coaches)
{
    //checking to see if anything is in the vector first
    if (coaches.size() == 0)
    {
        cout << "No information for any coaches stored in the database yet!" << endl;
        return;
    }

    //getting first name argument from passed stringstream
    string first_name;
    ss >> first_name;
    first_name = replacePlus(first_name);

    //bool variable to determine if any record was found in database
    bool found = false;

    //loop through entire vector
    for (int i = 0; i < coaches.size(); ++i)
    {
        if (coaches[i].getFirstName() == first_name)
        {
            cout << left << setw(12) << coaches[i].getID()
                << setw(7) << coaches[i].getSeason()
                << setw(10) << coaches[i].getFirstName()
                << setw(15) << coaches[i].getLastName()
                << setw(5) << coaches[i].getSeasonWin()
                << setw(5) << coaches[i].getSeasonLoss()
                << setw(5) << coaches[i].getPlayoffWin()
                << setw(5) << coaches[i].getPlayoffLoss()
                << setw(5) << coaches[i].getTeam() << endl;

            found = true;
        }
    }

    if (found == false)
    {
        cout << endl << "No coaches with that name found." << endl;
    }

    return;
}

//best coach function
//takes in vector containing all coaches
void best_coach(stringstream& ss, vector<Coach>& coaches)
{
    //checking to see if anything is in vector first
    if (coaches.size() == 0)
    {
        cout << "No information for any coaches stored in the database yet!" << endl;
        return;
    }

    //variables
    int best_coach_index = 0;
    int best = -100;
    int net_wins = 0;
    int season;
    ss >> season;

    //loop through entire vector containing coaches
    for (int i = 0; i < coaches.size(); ++i)
    {
        if (coaches[i].getSeason() == season)
        {
            //getting net wins for coach at current index
            net_wins = (coaches[i].getSeasonWin() - coaches[i].getSeasonLoss())
                + (coaches[i].getPlayoffWin() - coaches[i].getPlayoffLoss());

            //if coach is better than current best, replace it
            if (net_wins > best)
            {
                best = net_wins;
                best_coach_index = i;
            }
        }
    }

    //displaying info for best coach
    cout << left << setw(12) << coaches[best_coach_index].getID()
        << setw(7) << coaches[best_coach_index].getSeason()
        << setw(10) << coaches[best_coach_index].getFirstName()
        << setw(15) << coaches[best_coach_index].getLastName()
        << setw(5) << coaches[best_coach_index].getSeasonWin()
        << setw(5) << coaches[best_coach_index].getSeasonLoss()
        << setw(5) << coaches[best_coach_index].getPlayoffWin()
        << setw(5) << coaches[best_coach_index].getPlayoffLoss()
        << setw(5) << coaches[best_coach_index].getTeam() << endl;
}

//search coaches function
//takes in vector containing coaches and stringstream containing arguments
void search_coaches(stringstream& ss, vector<Coach> coaches)
{
    //checking to see if anything is in the vector first
    if (coaches.size() == 0)
    {
        cout << "No information for any coaches stored in the database yet!" << endl;
        return;
    }

    //variables to hold line and word
    string line;
    string argument;

    //variables with default values
    string coach_ID = "NULL";
    int season = -1;
    string first_name = "NULL";
    string last_name = "NULL";
    int season_win = -1;
    int season_loss = -1;
    int playoff_win = -1;
    int playoff_loss = -1;
    string team = "NULL";

    //loop to get each argument and its value
    while (ss >> line)
    {
        //splitting the argument and value by the '='
        stringstream wordstream(line);
        getline(wordstream, argument, '=');

        //if statements to enter the appropriate value to its argument
        if (argument == "coach_id")
        {
            wordstream >> coach_ID;
        }
        if (argument == "season")
        {
            wordstream >> season;
        }
        if (argument == "first_name")
        {
            wordstream >> first_name;
        }
        if (argument == "last_name")
        {
            wordstream >> last_name;
        }
        if (argument == "season_win")
        {
            wordstream >> season_win;
        }
        if (argument == "season_loss")
        {
            wordstream >> season_loss;
        }
        if (argument == "playoff_win")
        {
            wordstream >> playoff_win;
        }
        if (argument == "playoff_loss")
        {
            wordstream >> playoff_loss;
        }
        if (argument == "team")
        {
            wordstream >> team;
        }
    }

    //replacing plus in strings if they exist
    first_name = replacePlus(first_name);
    last_name = replacePlus(last_name);
    
    //temporary vectors
    vector<Coach> tempVec;
    vector<Coach> resultVec;
    tempVec = coaches;

    //if statements to put the appropriate information into a vector
    if (coach_ID != "NULL")
    {
        for (int i = 0; i < tempVec.size(); ++i)
        {
            if (tempVec[i].getID() == coach_ID)
            {
                resultVec.push_back(tempVec[i]);
            }
        }
        tempVec = resultVec;
        resultVec.clear();
    }
    if (season != -1)
    {
        for (int i = 0; i < tempVec.size(); ++i)
        {
            if (tempVec[i].getSeason() == season)
            {
                resultVec.push_back(tempVec[i]);
            }
        }
        tempVec = resultVec;
        resultVec.clear();
    }
    if (first_name != "NULL")
    {
        for (int i = 0; i < tempVec.size(); ++i)
        {
            if (tempVec[i].getFirstName() == first_name)
            {
                resultVec.push_back(tempVec[i]);
            }
        }
        tempVec = resultVec;
        resultVec.clear();
    }
    if (last_name != "NULL")
    {
        for (int i = 0; i < tempVec.size(); ++i)
        {
            if (tempVec[i].getLastName() == last_name)
            {
                resultVec.push_back(tempVec[i]);
            }
        }
        tempVec = resultVec;
        resultVec.clear();
    }
    if (season_win != -1)
    {
        for (int i = 0; i < tempVec.size(); ++i)
        {
            if (tempVec[i].getSeasonWin() == season_win)
            {
                resultVec.push_back(tempVec[i]);
            }
        }
        tempVec = resultVec;
        resultVec.clear();
    }
    if (season_loss != -1)
    {
        for (int i = 0; i < tempVec.size(); ++i)
        {
            if (tempVec[i].getSeasonLoss() == season_loss)
            {
                resultVec.push_back(tempVec[i]);
            }
        }
        tempVec = resultVec;
        resultVec.clear();
    }
    if (playoff_win != -1)
    {
        for (int i = 0; i < tempVec.size(); ++i)
        {
            if (tempVec[i].getPlayoffWin() == playoff_win)
            {
                resultVec.push_back(tempVec[i]);
            }
        }
        tempVec = resultVec;
        resultVec.clear();
    }
    if (playoff_loss != -1)
    {
        for (int i = 0; i < tempVec.size(); ++i)
        {
            if (tempVec[i].getPlayoffLoss() == playoff_loss)
            {
                resultVec.push_back(tempVec[i]);
            }
        }
        tempVec = resultVec;
        resultVec.clear();
    }
    if (team != "NULL")
    {
        for (int i = 0; i < tempVec.size(); ++i)
        {
            if (tempVec[i].getTeam() == team)
            {
                resultVec.push_back(tempVec[i]);
            }
        }
        tempVec = resultVec;
        resultVec.clear();
    }

    //checking if anything was found at all, if not outputting a message
    if (tempVec.size() == 0)
    {
        cout << "No coaches could be found with the specified information." << endl;
        return;
    }
    //outputting all the resultant coaches
    for (int i = 0; i < tempVec.size(); ++i)
    {
        cout << left << setw(12) << tempVec[i].getID()
            << setw(7) << tempVec[i].getSeason()
            << setw(10) << tempVec[i].getFirstName()
            << setw(15) << tempVec[i].getLastName()
            << setw(5) << tempVec[i].getSeasonWin()
            << setw(5) << tempVec[i].getSeasonLoss()
            << setw(5) << tempVec[i].getPlayoffWin()
            << setw(5) << tempVec[i].getPlayoffLoss()
            << setw(5) << tempVec[i].getTeam() << endl;
    }
    return;
}

//add team function
//takes in vector containing teams and stringstream containing arguments
void add_team(stringstream& ss, vector<Team>& teams)
{
    //variables
    string team_ID;
    string location;
    string name;
    char league;

    //getting arguments from stringstream
    ss >> team_ID;
    ss >> location;
    location = replacePlus(location);
    ss >> name;
    name = replacePlus(name);
    ss >> league;

    //creating new team and setting its member values
    Team newTeam;
    newTeam.setTeamID(team_ID);
    newTeam.setLocation(location);
    newTeam.setName(name);
    newTeam.setLeague(league);

    //adding it to vector
    teams.push_back(newTeam);
}

//load teams function
//takes in vector to load teams into and stringstream containing arguments
void load_teams(stringstream& ss, vector<Team>& teams)
{
    //opening input file and getting its name from stringstream
    string inputFileName;
    ss >> inputFileName;
    ifstream inputFile;
    inputFile.open(inputFileName.c_str());

    //variables to hold line and word
    string line;
    string word;

    //variables
    string team_ID;
    string location;
    string name;
    char league;
    int counter;
    string throw_away;

    //getting first header line of input file (not necessary for use so we are essentially getting it to discard it)
    getline(inputFile, line);

    //reading each line of the input file and putting it into line
    while (getline(inputFile, line))
    {
        //putting line into a stringstream so we can than use delimiter ',' to get each word
        stringstream lineStream(line);
        //resetting counter
        counter = 1;
        //loop to get each word in a line seperated by delimiter ','
        while (getline(lineStream, word, ','))
        {
            //putting word into a stringstream so we can convert into data
            stringstream wordStream(word);
            //switch to decide what is the appropriate data to assign what is in word based on the counter variable
            switch (counter) {
            case 1:
                team_ID = word;
                wordStream >> throw_away;
                break;
            case 2:
                location = word;
                wordStream >> throw_away;
                break;
            case 3:
                name = word;
                wordStream >> throw_away;
                break;
            case 4:
                wordStream >> league;
                break;
            default:
                cout << endl << "something went wrong here" << endl;
                break;
            }
            counter++;
        }
        //creating new team and setting its member values
        Team newTeam;
        newTeam.setTeamID(team_ID);
        newTeam.setLocation(location);
        newTeam.setName(name);
        newTeam.setLeague(league);

        //adding it to vector
        teams.push_back(newTeam);
    }
    return;
}

//print teams function
//takes in vector containing teams
void print_teams(vector<Team>& teams)
{
    //checking if anything is in vector first
    if (teams.size() == 0)
    {
        cout << "No information for any teams stored in the database yet!" << endl;
        return;
    }
    //looping through vector and outputting information
    for (int i = 0; i < teams.size(); ++i)
    {
        cout << left << setw(5) << teams[i].getTeamID()
            << setw(15) << teams[i].getLocation()
            << setw(17) << teams[i].getName()
            << setw(5) << teams[i].getLeague() << endl;
    }
    return;
}

//remove team function
//takes in stringstream containing arguments and vector containing teams
void remove_team(stringstream& ss, vector<Team>& teams)
{
    //checking if anything is in vector first
    if (teams.size() == 0)
    {
        cout << "No information for any teams stored in the database yet!" << endl;
        return;
    }

    //getting team ID from stringstream to remove
    string team_ID;
    ss >> team_ID;

    //variable to determine whether something was deleted or not
    bool deleted = false;

    //loop through entire vector
    for (int i = 0; i < teams.size(); ++i)
    {
        //checking if team at current index is one to delete based on team ID
        if (teams[i].getTeamID() == team_ID)
        {
            //erasing the coach
            teams.erase(teams.begin() + i);
            //setting deleted value to true to indicate something was deleted
            deleted = true;
            //decrementing index counter to adjust for new vector since something was removed
            //if this is not done than if two indices in a row need to get deleted the second will be skipped
            --i;
        }
    }

    //outputting message if nothing was deleted
    if (deleted == false)
    {
        cout << endl << "Could not find team to delete. Nothing deleted." << endl;
    }

    return;
}

//teams by city league function
//takes in a stringstream containing arguments and vector containing teams
void teams_by_city_league(stringstream& ss, vector<Team>& teams)
{
    //checking if anything is in vector first
    if (teams.size() == 0)
    {
        cout << "No information for any teams stored in the database yet!" << endl;
        return;
    }

    //variables to hold line and word
    string line;
    string argument;

    //variables with default values
    string location;
    char league;
    ss >> location;
    location = replacePlus(location);
    ss >> league;

    //looping through vector
    for (int i = 0; i < teams.size(); ++i)
    {
        //if team at current index in vector matches arguments than output
        if (teams[i].getLocation() == location && teams[i].getLeague() == league)
        {
            cout << left << setw(5) << teams[i].getTeamID()
                << setw(15) << teams[i].getLocation()
                << setw(17) << teams[i].getName()
                << setw(5) << teams[i].getLeague() << endl;
        }
    }
}

//replace plus function
//takes in a string to replace the plus ( '+' ) in for a space ( ' ' )
string replacePlus(string s)
{
    char c1 = '+';
    char c2 = ' ';
    int l = s.length();

    for (int i = 0; i < l; i++)
    {
        if (s[i] == c1)
            s[i] = c2;
    }
    return s;
}