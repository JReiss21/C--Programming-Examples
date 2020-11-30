/*
This is the binary search tree header file for the binary search tree program, this contains the class template
Written by Joseph Reiss U76703774
*/

#ifndef BST_H
#define BST_H

//include directives
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

//namespace
using namespace std;

//bst class
template <class T>
class BinarySearchTree
{
private:	//private data members
	struct tree_node
	{
		tree_node* left;
		tree_node* right;
		T data;
	};
	tree_node* root;

public:
	//constructor
	BinarySearchTree()
	{
		root = NULL;
	}

	//member functions
	bool isEmpty() const { return root == NULL; }	//returns true if the root of the tree is null aka tree is empty

	void insert(T);

	void display_inorder();
	void inorder(tree_node*) const;
	void display_preorder();
	void preorder(tree_node*) const;
	void display_postorder();
	void postorder(tree_node*) const;

	bool search(const T&) const;
	void remove_data(const T&);

	void delete_bst(tree_node*);
	void delete_bst_helper();

	void copy_bst(tree_node*, tree_node*&);
	void copy_bst_helper(tree_node*&);
	tree_node*& get_root() { return root; }		//returns a pointer address to the root of the tree (used for the copy bst functions)

	T get_min_value() const;
	void min_value_helper(tree_node*, tree_node*&) const;

	T get_max_value() const;
	void max_value_helper(tree_node*, tree_node*&) const;

	void get_successor_helper(tree_node* node, vector<T>& inorder_values_tree) const;
	T get_successor(const T&) const;

	void get_predecessor_helper(tree_node* node, vector<T>& inorder_values_tree) const;
	T get_predecessor(const T&) const;
};

/*
insert function from BinarySearchTree class
precondition: data to be inserted into the linked list bst
postcondition: inserts the data into the binary search tree
*/
template <class T>
void BinarySearchTree<T>::insert(T data)
{
	tree_node* new_node = new tree_node;
	tree_node* parent_node;
	new_node->data = data;
	new_node->left = NULL;
	new_node->right = NULL;
	parent_node = NULL;

	//checking to see if tree is empty, if so making data the root node
	if (isEmpty())
	{
		root = new_node;
	}
	else
	{
		tree_node* curr_node;	//current node
		curr_node = root;

		while (curr_node)	//looping through the tree checking which direction to traverse each time
		{
			parent_node = curr_node;
			if (new_node->data > curr_node->data)
			{
				curr_node = curr_node->right;
			}
			else
			{
				curr_node = curr_node->left;
			}
		}

		//assigning the new data to the empty node
		if (new_node->data < parent_node->data)
		{
			parent_node->left = new_node;
		}
		else
		{
			parent_node->right = new_node;
		}
	}
}

/*
display inorderfunction from BinarySearchTree class
precondition: none
postcondition: displays the bst "inorder" to the console
*/
template <class T>
void BinarySearchTree<T>::display_inorder()
{
	inorder(root);
}

/*
inorder function from BinarySearchTree class
precondition: treenode object pointer
postcondition: outputs and calls itself recursively to display the bst "inorder" to the console
*/
template <class T>
void BinarySearchTree<T>::inorder(tree_node* node) const
{
	if (node != NULL)
	{
		if (node->left)
			inorder(node->left);
		cout << " " << node->data << " ";
		if (node->right)
			inorder(node->right);
	}
	else
		return;
}

/*
display preorder function from BinarySearchTree class
precondition: none
postcondition: displays the bst "preorder" to the console
*/
template <class T>
void BinarySearchTree<T>::display_preorder()
{
	preorder(root);
}

/*
preorder function from BinarySearchTree class
precondition: treenode object pointer
postcondition: outputs and calls itself recursively to display the bst "preorder" to the console
*/
template <class T>
void BinarySearchTree<T>::preorder(tree_node* node) const
{
	if (node != NULL)
	{
		cout << " " << node->data << " ";
		if (node->left)
			preorder(node->left);
		if (node->right)
			preorder(node->right);
	}
	else
		return;
}

/*
display postorder function from BinarySearchTree class
precondition: none
postcondition: displays the bst "postorder" to the console
*/
template <class T>
void BinarySearchTree<T>::display_postorder()
{
	postorder(root);
}

/*
postorder function from BinarySearchTree class
precondition: treenode object pointer
postcondition: outputs and calls itself recursively to display the bst "postorder" to the console
*/
template <class T>
void BinarySearchTree<T>::postorder(tree_node* node) const
{
	if (node != NULL)
	{
		if (node->left)
			preorder(node->left);
		if (node->right)
			preorder(node->right);
		cout << " " << node->data << " ";
	}
	else
		return;
}

/*
search function from BinarySearchTree class
precondition: data variable to search for in the bst
postcondition: outputs to console if the variable was found or not and returns true/false accordingly
*/
template <class T>
bool BinarySearchTree<T>::search(const T& data) const
{
	//variables
	bool found = false;

	//checking to make sure tree is not empty
	if (isEmpty())
	{
		cout << endl << "The tree is empty!" << endl;
		return false;
	}

	//variables
	tree_node* curr_node;
	tree_node* parent_node;
	curr_node = root;
	parent_node = NULL;


	//looping through the tree and traversing it accordingly to see if data exists in the tree
	while (curr_node != NULL)
	{
		if (curr_node->data == data)	//data was found
		{
			found = true;
			break;
		}
		else	//data was not found, picking next appropriate node to check
		{
			parent_node = curr_node;
			if (data > curr_node->data)
				curr_node = curr_node->right;
			else
				curr_node = curr_node->left;
		}
	}

	//outputting appropriate message and than returning the bool variable
	if (found == false)
	{
		cout << endl << "Data not found!" << endl;
	}
	else if (found == true)
	{
		cout << endl << "Data is found!" << endl;
	}
	return found;
}

/*
remove data from the BinarySearchTree class
precondition: data variable to search for in the bst and remove if exists
postcondition: removes the variable from the bst if it exists in it and adjusts the bst accordingly
*/
template <class T>
void BinarySearchTree<T>::remove_data(const T& data)
{
	//variables
	bool found = false;

	//checking to make sure tree is not empty
	if (isEmpty())
	{
		cout << endl << "The tree is empty!" << endl;
		return;
	}

	//variables
	tree_node* curr_node;
	tree_node* parent_node;
	curr_node = root;
	parent_node = NULL;


	//looping through the tree and traversing it accordingly to see if data exists in the tree
	while (curr_node != NULL)
	{
		if (curr_node->data == data)	//data was found
		{
			found = true;
			break;
		}
		else	//data was not found, picking next appropriate node to check
		{
			parent_node = curr_node;
			if (data > curr_node->data)
				curr_node = curr_node->right;
			else
				curr_node = curr_node->left;
		}
	}

	//outputting appropriate message and than returning/ending the function if data does not exist in the bst
	if (found == false)
	{
		cout << endl << "Data not found!" << endl;
		return;
	}

	//if else if chain to determine which method of deleting the node is appropriate
	if ((curr_node->left == NULL && curr_node->right != NULL) || (curr_node->left != NULL && curr_node->right == NULL))		//nodes that have only one existing child node
	{
		if (curr_node->left == NULL && curr_node->right != NULL)		//right node exists but not left
		{
			if (parent_node->left == curr_node)		//if else chain setting the new parent node to the current node and than deleting the current node
			{
				parent_node->left = curr_node->right;
				delete curr_node;
			}
			else
			{
				parent_node->right = curr_node->right;
				delete curr_node;
			}
		}
		else if (curr_node->left != NULL && curr_node->right == NULL)	//right node does not exist but left does
		{
			if (parent_node->left == curr_node)		//if else chain setting the new parent node to the current node and than deleting the current node
			{
				parent_node->left = curr_node->left;
				delete curr_node;
			}
			else
			{
				parent_node->right = curr_node->left;
				delete curr_node;
			}
		}
		return;
	}

	if (curr_node->left == NULL && curr_node->right == NULL)		//nodes that have no existing child nodes aka both are NULL
	{
		if (parent_node == NULL)	//no parent node exists for the current node
		{
			delete curr_node;
		}
		else	//checking which node is the correct data to delete than setting it to NULL aka deleting it
		{
			if (parent_node->left == curr_node)
				parent_node->left = NULL;
			else
				parent_node->right = NULL;
		}
		return;
	}

	if (curr_node->left != NULL && curr_node->right != NULL)		//nodes that have two existing child nodes
	{
		//variables
		tree_node* temp;
		temp = curr_node->right;

		if ((temp->left == NULL) && (temp->right == NULL))		//current node has no children (when it enters here it is the smallest node in right subtree)
		{
			curr_node = temp;
			delete temp;
			curr_node->right = NULL;
		}
		else	//right child node still has smaller values
		{
			if ((curr_node->right)->left != NULL)
			{
				//variables
				tree_node* next_right;
				tree_node* next_right_left;
				next_right_left = (curr_node->right)->left;
				next_right = (curr_node->right);

				//moving the values up the tree accordingly
				while (next_right_left->left != NULL)
				{
					next_right = next_right_left;
					next_right_left = next_right_left->left;
				}

				curr_node->data = next_right_left->data;
				delete next_right_left;
				next_right->left = NULL;
			}
			else
			{
				//variables
				tree_node* tmp;
				tmp = curr_node->right;

				//moving the data up the tree accordingly
				curr_node->data = tmp->data;
				curr_node->right = tmp->right;
				delete tmp;
			}
		}
		return;
	}
}

/*
delete bst function from the BinarySearchTree class
precondition: node pointer to the root node of the tree to delete
postcondition: deletes the bst starting at the root node passed
*/
template <class T>
void BinarySearchTree<T>::delete_bst(tree_node* node)
{
	if (node == NULL)
		return;

	//recursive calls to delete subtrees
	delete_bst(node->left);
	delete_bst(node->right);

	//deleting the node
	free(node);
}

/*
delete bst helper function from the BinarySearchTree class
precondition: none
postcondition: asks the user for the subtree root than deletes that subtree
*/
template <class T>
void BinarySearchTree<T>::delete_bst_helper()
{
	if (isEmpty())		//checking to make sure tree is not empty
	{
		cout << endl << "The tree is empty!" << endl;
		return;
	}

	//variables
	T subtree_root_value;

	cout << endl << "Enter the root value of the subtree you wish to delete: ";
	cin >> subtree_root_value;

	//variables
	tree_node* curr_node;
	tree_node* parent_node;
	curr_node = root;
	parent_node = NULL;
	bool found = false;


	//looping through the tree and traversing it accordingly to see if data exists in the tree
	while (curr_node != NULL)
	{
		if (curr_node->data == subtree_root_value)	//data was found
		{
			found = true;
			break;
		}
		else	//data was not found, picking next appropriate node to check
		{
			parent_node = curr_node;
			if (subtree_root_value > curr_node->data)
				curr_node = curr_node->right;
			else
				curr_node = curr_node->left;
		}
	}

	//outputting appropriate message and than returning/ending the function if data does not exist in the bst
	if (found == false)
	{
		cout << endl << "Data not found!" << endl;
		return;
	}

	//calling the actual function that deletes the subtree
	delete_bst(curr_node);

	//resetting the appropriate pointers for the parent node of the subtree that was deleted
	if (subtree_root_value > parent_node->data)
		parent_node->right = NULL;
	else
		parent_node->left = NULL;
}

/*
copy bst function from the BinarySearchTree class
precondition: passed a pointer to the root node of tree that it is copying, and a pointer address of the root node of the tree to copy to
postcondition: copys the original tree to the copy tree
*/
template <class T>
void BinarySearchTree<T>::copy_bst(tree_node* original, tree_node*& copy)
{
	if (isEmpty())		//checking to make sure tree is not empty
	{
		cout << endl << "The tree is empty!" << endl;
		return;
	}

	//variables
	tree_node* curr_node;
	tree_node* parent_node;
	curr_node = root;
	parent_node = NULL;

	//checking to make sure the node is not null and if not setting all of its data and pointers equal to the copy node
	if (original != NULL)
	{
		copy = new tree_node;
		copy->data = original->data;
		copy_bst(original->left, copy->left);		//recursive calls of the function to traverse the tree left
		copy_bst(original->right, copy->right);		//recursive calls of the function to traverse the tree right
	}
	else
		copy = NULL;
}

/*
copy bst helper function from BinarySearchTree class
precondition: passed the root node for the bst that is being copied into
postcondition: duplicates the original tree into the copy tree
*/
template <class T>
void BinarySearchTree<T>::copy_bst_helper(tree_node*& copy)
{
	copy_bst(root, copy);
}

/*
get min value function from the BinarySearchTree class
precondition: none
postcondition: returns the minimum value in the calling tree
*/
template <class T>
T BinarySearchTree<T>::get_min_value() const
{
	tree_node* min_val_node;
	min_value_helper(root, min_val_node);
	return min_val_node->data;
}

/*
min value helper function from the BinarySearchTree class
precondition: passed a node to check from the original tree and the address value of a node to store the min val node in
postcondition: calls itself recursively to end up with the min_val_node equaling the node containing the minimum value in the calling tree
*/
template <class T>
void BinarySearchTree<T>::min_value_helper(tree_node* node, tree_node*& min_val_node) const
{
	//break condition for recursive calls
	if (node == NULL)
	{
		return;
	}

	min_val_node = node;
	min_value_helper(node->left, min_val_node);		//recursive call to traverse the tree left (lower numbers)
}


/*
get max value function from the BinarySearchTree class
precondition: none
postcondition: returns the maximum value in the calling tree
*/
template <class T>
T BinarySearchTree<T>::get_max_value() const
{
	tree_node* max_val_node;
	max_value_helper(root, max_val_node);
	return max_val_node->data;
}

/*
max value helper function from the BinarySearchTree class
precondition: passed a node to check from the original tree and the address value of a node to store the max val node in
postcondition: calls itself recursively to end up with the max_val_node equaling the node containing the maximum value in the calling tree
*/
template <class T>
void BinarySearchTree<T>::max_value_helper(tree_node* node, tree_node*& max_val_node) const
{
	//break condition for recursive calls
	if (node == NULL)
	{
		return;
	}

	max_val_node = node;
	max_value_helper(node->right, max_val_node);		//recursive call to traverse the tree right (higher numbers)
}

/*
get successor helper function from the BinarySearchTree class
precondition: passed a treenode root pointer on original call and vector to make alterations to
postcondition: calls itself recursively and adds the values in the bst to the vector inorder which is returned to calling function
*/
template <class T>
void BinarySearchTree<T>::get_successor_helper(tree_node* node, vector<T>& inorder_values_tree) const
{
	if (node != NULL)
	{
		if (node->left)
			get_successor_helper(node->left, inorder_values_tree);
		inorder_values_tree.push_back(node->data);
		if (node->right)
			get_successor_helper(node->right, inorder_values_tree);
	}
	else
		return;
}

/*
get successor helper function from the BinarySearchTree class
precondition: passed a value to search for the successor of in the bst
postcondition: displays the appropriate message to the console and returns the successor if applicable
*/
template <class T>
T BinarySearchTree<T>::get_successor(const T& value) const
{
	if (isEmpty())		//checking to make sure tree is not empty
	{
		cout << endl << "The tree is empty!" << endl;
		return NULL;
	}

	//variables
	bool var_exists = false;
	vector<T> inorder_values_tree;

	//getting the vector of values inorder
	get_successor_helper(root, inorder_values_tree);

	//checking to make sure variable exists
	for (T test_val : inorder_values_tree)
	{
		if (test_val == value)
		{
			var_exists = true;
		}
	}
	if (!var_exists)
	{
		cout << endl << "The value you entered does not exist!" << endl;
		return NULL;
	}

	//outputting the appropriate message
	for (T test_val : inorder_values_tree)
	{
		if (test_val > value)	//returning the first value in the vector greater than the passed number aka the successor
		{
			cout << endl << "The successor of \"" << value << "\" in the binary search tree is \"" << test_val << "\"." << endl;
			return test_val;
		}
	}

	//if the function makes it this far it means there is no successor so outputting 
	cout << endl << "There is no successor to \"" << value << "\" in the binary search tree." << endl;
	return NULL;
}

/*
get predecessor helper function from the BinarySearchTree class
precondition: passed a treenode root pointer on original call and vector to make alterations to
postcondition: calls itself recursively and adds the values in the bst to the vector inorder which is returned to calling function
*/
template <class T>
void BinarySearchTree<T>::get_predecessor_helper(tree_node* node, vector<T>& inorder_values_tree) const
{

	if (node != NULL)
	{
		if (node->left)
			get_predecessor_helper(node->left, inorder_values_tree);
		inorder_values_tree.push_back(node->data);
		if (node->right)
			get_predecessor_helper(node->right, inorder_values_tree);
	}
	else
		return;
}

/*
get predecessor helper function from the BinarySearchTree class
precondition: passed a value to search for the predecessor of in the bst
postcondition: displays the appropriate message to the console and returns the predecessor if applicable
*/
template <class T>
T BinarySearchTree<T>::get_predecessor(const T& value) const
{
	if (isEmpty())		//checking to make sure tree is not empty
	{
		cout << endl << "The tree is empty!" << endl;
		return NULL;
	}

	//variables
	bool var_exists = false;
	vector<T> inorder_values_tree;

	//getting the vector of values inorder
	get_predecessor_helper(root, inorder_values_tree);

	//reversing the vector because when traversing it now you can find the first value that is less than the passed value more easily because it will be the first value that pops up that is less than
	reverse(inorder_values_tree.begin(), inorder_values_tree.end());

	//checking to make sure variable exists
	for (T test_val : inorder_values_tree)
	{
		if (test_val == value)
		{
			var_exists = true;
		}
	}
	if (!var_exists)
	{
		cout << endl << "The value you entered does not exist!" << endl;
		return NULL;
	}

	//outputting the appropriate message
	for (T test_val : inorder_values_tree)
	{
		if (test_val < value)	//returning the first value in the vector greater than the passed number aka the successor
		{
			cout << endl << "The predecessor of \"" << value << "\" in the binary search tree is \"" << test_val << "\"." << endl;
			return test_val;
		}
	}

	//if the function makes it this far it means there is no successor so outputting 
	cout << endl << "There is no predecessor to \"" << value << "\" in the binary search tree." << endl;
	return NULL;
}

/*
display user menu function
precondition: none
postcondition: outputs the user menu to the console
*/
void display_user_menu()
{
	cout << endl << "USER MENU" << endl;
	cout << "1 - Insert a new node" << endl;
	cout << "2 - Display the values \"inorder\"" << endl;
	cout << "3 - Display the values \"preorder\"" << endl;
	cout << "4 - Display the values \"postorder\"" << endl;
	cout << "5 - Search for a value" << endl;
	cout << "6 - Remove a value" << endl;
	cout << "7 - Delete the binary search tree or subtree" << endl;
	cout << "8 - Copy the binary search tree to a new one" << endl;
	cout << "9 - Display the minimum value in the binary search tree" << endl;
	cout << "10 - Display the maximum value in the binary search tree" << endl;
	cout << "11 - Get the successor of a value in the binary search tree" << endl;
	cout << "12 - Get the predecessor of a value in the binary search tree" << endl;
	cout << "13 - Exit" << endl << endl;
}
#endif