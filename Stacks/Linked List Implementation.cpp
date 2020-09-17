#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
};

struct LLStack
{
	Node* top = NULL;
};

Node* CreateNewNode(int data)
{
	Node* temp = new Node();
	temp->data = data;
	temp->next = NULL;
	return temp;
}

bool IsEmpty(LLStack *st)
{
	return (st->top == NULL);
}

void Push(LLStack *st,int data)
{
	Node* temp = CreateNewNode(data);
	temp->next = st->top;
	st->top = temp;
}

int Pop(LLStack *st)
{
	if(IsEmpty(st))
		return -1;
	Node* temp = st->top;
	int data = temp->data;
	st->top = temp->next;
	delete temp;
	return data;
}

void Print(LLStack *st)
{
	Node* temp = st->top;
	while(temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int Top(LLStack *st)
{
	if(IsEmpty(st))
		return -1;
	return st->top->data;
}

void DeleteStack(LLStack *st)
{
	if(IsEmpty(st))
		return;
	Node* temp = st->top;
	Node* temp1 = new Node();
	while(temp->next != NULL)
	{
		temp1 = temp;
		temp = temp->next;
		delete temp1;
	}
}

int main()
{
	LLStack *st = new LLStack();
	Push(st,7);
	Push(st,8);
	// DeleteStack(st);
	Push(st,9);
	cout << Pop(st) << endl;
	Print(st);
	cout << Top(st);
	return 0;
}