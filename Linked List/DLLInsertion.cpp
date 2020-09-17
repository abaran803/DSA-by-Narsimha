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

void Insert(int data,int n)
{

	Node* temp1 = CreateNewNode(data);
	if(n == 0)
	{
		temp1->next = head;
		if(head != NULL)
			head->prev = temp1;
		head = temp1;
		return;
	}
	Node* temp = head;
	for(int i=0;i<n-1 && temp != NULL;i++)
		temp = temp->next;
	if(temp == NULL)
	{
		cout << "Can't Possible" << endl;
		return;
	}
	temp1->next = temp->next;
	temp1->prev = temp;
	if(temp->next != NULL)
		temp->next->prev = temp1;
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
	Insert(5,0);
	Insert(7,1);
	Insert(9,2);
	Insert(11,3);
	Insert(13,2);
	Traverse();
	ReverseTraverse();
	return 0;
}