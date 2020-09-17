#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
};

Node* head = NULL;

int Size()
{
	Node* temp = head;
	int count = 0;
	while(temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	return count;
}

void Deletion(int n)
{
	Node* temp1 = head;
	if(temp1 == NULL)
	{
		cout << "Can't Possible" << endl;
		return;
	}
	if(n == 0)
	{
		head = head->next;
		delete temp1;
		return;
	}
	for(int i=0;i<n-1 && temp1 != NULL;i++)
		temp1 = temp1->next;
	if(temp1->next == NULL)
	{
		cout << "Can't Possible" << endl;
		return;
	}
	Node* temp = temp1->next;
	temp1->next = temp1->next->next;
	delete temp;
}

void Traversing()
{
	Node* temp = head;
	while(temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
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
	Deletion(3);
	Traversing();
	return 0;
}