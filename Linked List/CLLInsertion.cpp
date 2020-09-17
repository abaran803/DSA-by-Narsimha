#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
};

Node* head = NULL;

Node* CreateNewNode(int data)
{
	Node* temp = new Node();
	temp->data = data;
	temp->next = NULL;
	return temp;
}

void InsertAtEnd(int data)
{
	Node* temp = head;
	Node* temp1 = CreateNewNode(data);
	if(head == NULL)
	{
		head = temp1;
		temp1->next = head;
		return;
	}
	while(temp->next != head)
		temp = temp->next;
	temp->next = temp1;
	temp1->next = head;
}

void InsertAtBeginning(int data)
{
	Node* temp = head;
	Node* temp1 = CreateNewNode(data);
	if(head == NULL)
	{
		head = temp1;
		temp1->next = head;
		return;
	}
	temp1->next = head;
	while(temp->next != head)
		temp = temp->next;
	head = temp1;
	temp->next = head;
}

void Traversing()
{
	Node* temp = head;
	if(head == NULL)
		return;
	do
	{
		cout << temp->data << " ";
		temp = temp->next;
	}while(temp != head);
	cout << endl;
}

int Size()
{
	Node* temp = head;
	if(head == NULL)
		return 0;
	int count = 0;
	do
	{
		count++;
		temp = temp->next;
	}while(temp != head);
	return count;
}

int main()
{
	InsertAtEnd(5);
	InsertAtEnd(9);
	InsertAtEnd(11);
	InsertAtEnd(7);
	InsertAtBeginning(13);
	InsertAtEnd(17);
	InsertAtBeginning(12);
	Traversing();
	cout << Size();
	return 0;
}