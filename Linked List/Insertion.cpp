#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
};

Node* head = NULL;

void InsertAtLast(int data)
{
	Node* temp = new Node();
	temp->data = data;
	temp->next = NULL;
	Node* temp1 = head;
	if(temp1 == NULL)
	{
		head = temp;
		return;
	}
	while(temp1->next != NULL)
		temp1 = temp1->next;
	temp1->next = temp;
}

void InsertAtBeginning(int data)
{
	Node* temp = head;
	Node* temp1 = new Node();
	temp1->data = data;
	temp1->next = NULL;
	if(temp == NULL)
	{
		head = temp1;
		return;
	}
	temp1->next = head;
	head = temp1;
}

int Size();

void InsertAtN(int data,int n)
{
	if(n == 0)
	{
		InsertAtBeginning(data);
		return;
	}
	if(n > Size())
	{
		cout << "Can't Insert" << endl;
		return;
	}
	Node* temp = head;
	for(int i=0;i<n-1;i++)
		temp = temp->next;
	Node* temp1 = new Node();
	temp1->data = data;
	temp1->next = temp->next;
	temp->next = temp1;
}

void Traverse()
{
	Node* temp = head;
	while(temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int Size()
{
	int count = 0;
	Node* temp = head;
	while(temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	return count;
}

int main()
{
	InsertAtLast(2);
	InsertAtLast(3);
	InsertAtLast(4);
	InsertAtBeginning(5);
	InsertAtLast(6);
	InsertAtN(70,6);
	Traverse();
	cout << Size();
	return 0;
}