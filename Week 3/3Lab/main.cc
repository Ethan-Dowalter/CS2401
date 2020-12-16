/**
 *   @file: main.cc
 * @author: Ethan Dowalter
 *   @date: July 18, 2020
 *  @brief: Linked lists practice - taking a big list of random numbers and removing repeats,
 * 			as well as splitting the list into two lists from a value entered by user
 */

/*********************************************************************
     Lab Assignment 3: This is a lab assignment in working with 
     linked lists. We will be using a struct node, for its simplicity,
     and working with non-member functions here. The main point is to 
     work with the logic of a linked list. Do not be afraid to make 
     drawings on scrap paper.
     The prototypes for the functions that you are to implement are
     included. You should uncomment them when you are ready to write 
     the implementation.
           John Dolan				Summer 2019
*********************************************************************/

#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

struct node{
    int data;
	node * link;
};


// These are the three I have written for you
void build_list(node* & head);  // note that we are passing by reference
void show_list(const node* head);
int size(const node* head);

//These are the two that you are to write, as described in the 
//instructions page.
void remove_repeats(node*& head);
void split_list(const node* original, node*& lesser, node*& greater,int split_value);


int main(){
    int start, stop;
    int split;
    node* head = NULL;
    node *lesser = NULL;
    node * greater = NULL;

    start = time(NULL);
    build_list(head);
    stop = time(NULL);
    cout<<"Time to build list = "<<stop - start <<"seconds.\n";
    start = time(NULL);
    show_list(head);
    stop = time(NULL);
    cout<<"Time to print list = "<<stop - start<<"seconds.\n";
    cout<<"Size of the list = "<<size(head)<<endl;

	/// Part 1
	start = time(NULL);
	remove_repeats(head);
	stop = time(NULL);
	cout<<"Time to remove repeats = "<<stop - start<<"seconds.\n";
	
	show_list(head);
	cout<<"Size of the list = "<<size(head)<<endl;

	/// Part 2
	cout << "Now enter a split value : ";
	cin >> split;
	start = time(NULL);
	split_list(head, lesser, greater, split);
	stop = time(NULL);
	cout<<"Time to split list = "<<stop - start<<"seconds.\n";

	show_list(lesser);
	cout<<"Size of the list = "<<size(lesser)<<endl;

	show_list(greater);
	cout<<"Size of the list = "<<size(greater)<<endl;

	return 0;
}

// builds a linked list of 2000 random integers, all in the 1 to 500 range
void build_list(node*& head){
    node* cursor;
    head = new node;
    head->data = rand()%500 + 1;
    cursor = head;
    for(int i = 0; i < 2000; ++i){
	cursor->link = new node;
        cursor = cursor->link;
        cursor->data = rand()%500 + 1;
	}
    cursor->link = NULL;
}

// outputs the contents of a linked list to the screen
void show_list(const node* head){
    const node * cursor = head;
    while(cursor !=  NULL){
    	cout<<cursor->data<<"  ";
    	cursor = cursor->link;
    }
    cout<<endl;
}

// returns the number of nodes in a linked list
int size(const node* head){
	const node* cursor = head;
	int count = 0;
	while(cursor != NULL){
  		count++;
	    cursor = cursor->link;
	}
	return count;
}

void remove_repeats(node*& head){
	node *cursor, *forward, *rear;			//Cursor will stay at one item while forward walks though
	cursor = head;							//list looking for matches to cursor, then rear will be
	while (cursor != NULL)					//used to delete the matching item. Once forward reaches
	{										//end of list, then cursor moves up by one item and process
		forward = cursor->link;				//is started over until cursor reaches end of list.
		rear = cursor;
		while (forward != NULL)
		{
			if (forward->data == cursor->data)
			{
				rear->link = forward->link;
				delete forward;
				forward = rear->link;
			}
			else
			{
				rear = forward;
				forward = forward->link;
			}
		}
		cursor = cursor->link;
	}
}

void split_list(const node* original, node*& lesser, node*& greater,int split_value){
	const node *cursor = original;			//cursor walks through original list
	node *tmp;								//tmp is for adding items to new list
	int num;								//transfers data to new lists
	while (cursor != NULL)
	{
		if (cursor->data < split_value)		//add to lesser list if number is less than split_value
		{
			num = cursor->data;
			if (lesser == NULL)
			{
				lesser = new node;
				lesser->data = num;
				lesser->link = NULL;
			}
			else
			{
				for (tmp = lesser; tmp->link != NULL; tmp = tmp->link);
				tmp->link = new node;
				tmp = tmp->link;
				tmp->data = num;
				tmp->link = NULL;
			}
		}
		else if (cursor->data > split_value)		//add to greater list if number is greater than split_value
		{
			num = cursor->data;
			if (greater == NULL)
			{
				greater = new node;
				greater->data = num;
				greater->link = NULL;
			}
			else
			{
				for (tmp = greater; tmp->link != NULL; tmp = tmp->link);
				tmp->link = new node;
				tmp = tmp->link;
				tmp->data = num;
				tmp->link = NULL;
			}
		}
		cursor = cursor->link;	
	}
}