
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


// ==================================================================================================================================================
// ==================================================================== DELETION ====================================================================

void deleteNode(node **head, int key){
	node *temp = *head;
	node *prev = NULL;
	if(*head == NULL)return;
	if(temp!=NULL && temp->data == key){
		*head = temp->next;
		delete temp;
		return;
	}
	while(temp!=NULL && temp->data != key){
		prev = temp;
		temp = temp->next;
	}
	prev->next = temp->next;
	delete temp;
}

// ====================================================================DELETION END ====================================================================
int main(){
	int n;
	cout<<"enter the number to insert: ";
	cin>>n;
	node* head = NULL;
	int data;
	for(int i=0; i<n; i++){
		cin>>data;
		append(data, &head);
	}
	cout<<"your final linked list is:\n";
	printList(head);
	char choice;
	while(true){
		cout<<"=========MENU==========\nTo Push Press 1\nTo Append Press 2 \nTo insert Press 3\nTo Delete Press 4\nTo Print Mid Press 5\nEnter\t:";
		cin>>choice;
		if(toupper(choice) == '1'){
			int data;
			cout<<"enter the data value: ";
			cin>>data;
			push(data, &head);
			printList(head);
		}
		else  if(choice == '2'){
			int data , count;
			cout<<"enter the data value: ";
			cin>>data;
			append(data, &head);
			printList(head);
		}

		else  if(choice == '3'){
			int data , count;
			cin>>data;
			cin>>count;
			insert(data, &head, count);
			printList(head);
		}

		else  if(choice == '4'){
			int key;
			cin>>key;
			deleteNode(&head, key);
			printList(head);
		}

		else  if(choice == '5'){
			cout<<"Middle: "<<middleElement(&head)<<endl;
			printList(head);
		}

		else
		{
			cout<<"GOOD BYE KEEP SMILING :)"<<endl;
			break;	
		}
	}


  return 0;
}
