#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
};

Node* head = NULL;

void Delete()
{
	Node* temp = head;
	while(temp != NULL)
	{
		Node* temp1 = temp;
		temp = temp->next;
		delete temp1;
	}
}

int main()
{
	Node* temp = head;
	for(int i=1;i<=5;i++)
	{
		temp = head;
		Node* temp1 = new Node();
		temp1->data = i;
		temp1->next = NULL;
		temp1->next = temp;
		head = temp1;
	}
	Delete();
	cout << head->data;
}