
#include<bits/stdc++.h>
using namespace std;

class node{
	public:
		int data;
		node* next;
};
// insertion at different location==========================================================================================================================
void push(int newData, node** head){
	node* newNode = new node();
	newNode->data = newData;

	newNode->next = *head;
	*head = newNode;
}

void append(int newData, node** head)
{
	node* newNode = new node();
	node *last = *head;
	newNode->data =newData;
	newNode->next = NULL;
	if(*head == NULL)
		*head = newNode;

	else{
		while(last->next != NULL){
			last = last->next;
		}
		last->next = newNode;
	}
}
