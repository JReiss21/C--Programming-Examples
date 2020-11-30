/*
This program is the solution to the COP3331 course project, binary search tree class template
Written by Joseph Reiss U76703774
*/

//include directives
#include "BST.h"
#include <iostream>

//namespace
using namespace std;

//main function
int main()
{
	//beginning message
	cout << "\nOOP Binary Search Tree Program\n\n";
	cout << "The BST begins empty with root equaling NULL (insert values before testing any other operations) and is assumed to be an integer tree.\nThis may be changed easily in the code by hardcoding different information.\n\n";

	//creating the original empty tree with root being NULL
	BinarySearchTree<int> tree;

	//main program loop
	while (true)
	{
		//variables
		int user_menu_choice = 0;
		int new_data = 0;
		int search_data = 0;
		int remove_data = 0;
		int successor_num = 0;
		int predecessor_num = 0;
		BinarySearchTree<int> copy_tree;

		//displaying the user menu to console
		display_user_menu();

		//getting user input for choice
		cout << "Enter an option: ";
		cin >> user_menu_choice;
		if (!cin.good())
		{
			cout << endl << "Invalid input" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}

		switch (user_menu_choice)	//switch to handle user menu choice
		{
		case 1:		//inserting a node option
			cout << endl << "Enter an integer to insert: ";
			cin >> new_data;
			if (!cin.good())
			{
				cout << endl << "Invalid input" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				break;
			}
			tree.insert(new_data);
			cout << endl << new_data << " was inserted into the binary search tree successfully." << endl;
			break;
		case 2:		//displaying values inorder option
			cout << endl << "The values \"inorder\" are: ";
			tree.display_inorder();
			cout << endl;
			break;
		case 3:		//displaying values preorder option
			cout << endl << "The values \"preorder\" are: ";
			tree.display_preorder();
			cout << endl;
			break;
		case 4:		//displaying values postorder option
			cout << endl << "The values \"postorder\" are: ";
			tree.display_postorder();
			cout << endl;
			break;
		case 5:		//search for a value option
			cout << endl << "Enter a value to search for: ";
			cin >> search_data;
			if (!cin.good())
			{
				cout << endl << "Invalid input" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				break;
			}
			tree.search(search_data);
			break;
		case 6:		//remove a value option
			cout << endl << "Enter a value to remove: ";
			cin >> remove_data;
			if (!cin.good())
			{
				cout << endl << "Invalid input" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				break;
			}
			tree.remove_data(remove_data);
			break;
		case 7:		//delete the bst or subtree option
			tree.delete_bst_helper();
			break;
		case 8:		//copy the bst option
			tree.copy_bst_helper(copy_tree.get_root());
			cout << endl << "The new copy tree's values are as follow: " << endl;
			cout << "Inorder values: ";
			copy_tree.display_inorder();
			cout << endl;
			cout << "Preorder values: ";
			copy_tree.display_preorder();
			cout << endl;
			cout << "Postorder values: ";
			copy_tree.display_postorder();
			cout << endl;
			break;
		case 9:		//display min value option
			cout << endl << "The minimum value in the binary search tree is: " << tree.get_min_value() << endl;
			break;
		case 10:	//display max value option
			cout << endl << "The maximum value in the binary search tree is: " << tree.get_max_value() << endl;
			break;
		case 11:	//get successor option
			cout << endl << "Enter a value to get the successor for: ";
			cin >> successor_num;
			if (!cin.good())
			{
				cout << endl << "Invalid input" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				break;
			}
			tree.get_successor(successor_num);
			break;
		case 12:	//get predecessor option
			cout << endl << "Enter a value to get the predecessor for: ";
			cin >> predecessor_num;
			if (!cin.good())
			{
				cout << endl << "Invalid input" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				break;
			}
			tree.get_predecessor(predecessor_num);
			break;
		case 13:	//exit program option
			cout << "\n\nEnd of program. Goodbye!\n";
			return 0;
			break;
		default:	//default option (an invalid integer was intered)
			cout << endl << "Invalid command." << endl;
			break;
		}	//end user menu choice switch
	}	//end main program loop
}	//end main