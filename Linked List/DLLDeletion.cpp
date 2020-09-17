#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
	Node* prev;
};

Node* head = NULL;

Node* CreateNewNode(int data)
{
	Node* temp = new Node();
	temp->data = data;
	temp->next = temp->prev = NULL;
	return temp;
}

void Deletion(int n)
{
	if(head == NULL)
	{
		cout << "Can't Possible" << endl;
		return;
	}
	Node* temp = head;
	if(n == 0)
	{
		head = head->next;
		if(head != NULL)
			head->prev = NULL;
		delete temp;
		return;
	}
	for(int i=0;i<n-1 && temp->next != NULL;i++)
		temp = temp->next;
	if(temp->next == NULL)
	{
		cout << "Can't Possible" << endl;
		return;
	}
	temp->next = temp->next->next;
	if(temp->next != NULL)
		temp->next->prev = temp;
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

void ReverseTraverse()
{
	Node* temp = head;
	while(temp->next != NULL)
		temp = temp->next;
	while(temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->prev;
	}
	cout << endl;
}

int main()
{
	Node* temp = head;
	for(int i=1;i<=5;i++)
	{
		temp = head;
		Node* temp1 = CreateNewNode(i);
		if(temp == NULL)
			head = temp1;
		else
		{
			temp1->next = temp;
			temp->prev = temp1;
			head = temp1;
		}
	}
	Deletion(2);
	Traverse();
	ReverseTraverse();
	return 0;
}