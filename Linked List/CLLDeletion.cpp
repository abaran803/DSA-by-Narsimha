#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
};

Node* head = NULL;

void DeletionAtEnd()
{
	if(head == NULL)
	{
		cout << "Can't Possible" << endl;
		return;
	}
	Node* temp = head;
	Node* temp1 = new Node();
	if(head->next == head)
	{
		head = NULL;
		return;
	}
	while(temp->next != head)
	{
		temp1 = temp;
		temp = temp->next;
	}
	temp1->next = temp->next;
	delete temp;
}

void DeletionAtBeginning()
{
	if(head == NULL)
	{
		cout << "Can't Possible" << endl;
		return;
	}
	if(head->next == head)
	{
		head = NULL;
		return;
	}
	Node* temp = head;
	while(temp->next != head)
		temp = temp->next;
	temp->next = head->next;
	head = head->next;
}

void Traverse()
{
	Node* temp = head;
	if(temp == NULL)
		return;
	do
	{
		cout << temp->data << " ";
		temp = temp->next;
	}while(temp != head);
}

int main()
{
	Node* temp = head;
	for(int i=1;i<=5;i++)
	{
		temp = head;
		Node* temp1 = new Node();
		temp1->data = i;
		if(head == NULL)
		{
			head = temp1;
			temp1->next = head;
		}
		else
		{
			temp1->next = head;
			while(temp->next != head)
				temp = temp->next;
			head = temp1;
			temp->next = head;
		}
	}
	DeletionAtEnd();
	DeletionAtBeginning();
	DeletionAtBeginning();
	DeletionAtBeginning();
	Traverse();
	return 0;
}