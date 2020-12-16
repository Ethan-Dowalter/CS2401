/**
 *        @file: btreelab.cc
 *      @author: Ethan Dowalter
 *        @date: August 13, 2020
 *       @brief: Learning about binary trees
 */

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

struct Bnode{
	string data;
	Bnode * left;
	Bnode * right;
};

void inorder(Bnode* root){
	if(root != NULL){
		inorder(root->left);
		cout<<root->data<<endl;
		inorder(root->right);
	}
}

void add(Bnode *& root, string item){
	if(root == NULL){
		root=new Bnode;
		root->data = item;
		root->left=root->right=NULL;
	}
	else if (item <= root->data)
		add(root->left,item);
	else
		add(root->right,item);
}

int size(Bnode * root){
	if(root == NULL) return 0;
	else
	return size(root->left) + size(root->right) + 1;
}

size_t count(Bnode * root, string target){
    // if (root == NULL)           //base case
    // {
    //     return 0;
    // }
    // else if (root->data == item)        //add one to total if item is search target
    // {
    //     return occurrences(root->left, item) + occurrences(root->right, item) + 1;
    // }
    // else        //else keep looking through the tree
    // {
    //     return occurrences(root->left, item) + occurrences(root->right, item);
    // }
    // int count(Bnode* root, string target){
if(root == NULL){
    return 0;
}
else if(target < root->data){
    return count(root->left, target);
}
else if(target > root->data){
    return count(root->right, target);
}
else{
    return 1 +count(root->left, target);
}

}

size_t greater_than(Bnode * root, string item){
    if (root == NULL)           //base case
    {
        return 0;
    }
    else if (root->data >= item)        //add in size of right sub-tree + 1 (for the root) if item is <= current node's data
    {
        return size(root->right) + greater_than(root->left, item) + 1;
    }
    else                //continue searching right
    {
        return greater_than(root->right, item);
    }
}


int main(){
    ifstream fin;               //used to read from data file
    fin.open("names.txt");
    if (fin.fail())
    {
        cout << "Error opening data file." << endl;
        return -1;
    }
    
    string tmp;                 //used to read from data file
    Bnode *root = NULL;         //root of binary tree

    while (fin >> tmp)          //read in names from file
    {
        add(root, tmp);
    }
    fin.close();

    inorder(root);              //output names to screen in order

    /// Part 1
    cout << "Enter a name you'd like to search for : ";
    string name;
    cin >> name;
    cout << "This name occurs " << count(root, name) << " times." << endl;

    /// Part 2
    cout << "Enter a name you'd like to compare the list to : ";
    cin >> name;
    cout << "There are " << greater_than(root, name) << " names greater than or equal to that name in the list." << endl;

    return 0;
}