
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

void insert(int newData, node** head, int afterCount)
{
	if(*head == NULL){
		cout<<"Linked List is Empty";
		return;
	}
	node* newNode = new node();
	newNode->data=newData;
	node *curr = *head, *prev = curr;
	int count = 0;
	while(curr != NULL && count < afterCount){
		prev = curr;
		curr=curr->next;
		count+=1;
	}
	prev->next = newNode;
	newNode->next = curr;
}

void printList(node* head){
	while(head != NULL)
	{
		cout<<head->data<<"->";;
		head = head->next;
	}
	cout<<endl<<endl;
}


