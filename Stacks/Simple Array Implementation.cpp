#include<iostream>
#include <climits>
using namespace std;
#define MAX_SIZE 10

// Stack ADT
struct Stack
{
	int arr[MAX_SIZE];
	int capacity;
	int top;
};

// Function to create Stack
Stack *CreateNewStack()
{
	Stack* S = new Stack();
	if(!S)
		return NULL;
	S->capacity = MAX_SIZE;
	S->top = -1;
	return S;
}

bool IsEmptyStack(Stack *st)
{
	return (st->top == -1);
}

bool IsFullStack(Stack *st)
{
	return (st->top > MAX_SIZE-1);
}

void Push(Stack *st,int data)
{
	if(IsFullStack(st))
	{
		cout << "Overflow" << endl;
		return;
	}
	st->top++;
	st->arr[st->top] = data;
}

void Print(Stack *st)
{
	if(IsFullStack(st))
		return;
	for(int i=0;i<=st->top;i++)
		cout << st->arr[i] << " ";
	cout << endl;
}

void DeleteStack(Stack *st)
{
	if(st)
		delete st;
}

int Pop(Stack *st)
{
	if(IsEmptyStack(st))
	{
		cout << "Underflow" << endl;
		return INT_MIN;
	}
	return st->arr[st->top--];
}

int main()
{
	Stack *st = CreateNewStack();
	Push(st,9);
	Push(st,7);
	Push(st,9);
	Push(st,5);
	Push(st,7);
	cout << Pop(st) << endl;
	// DeleteStack(st);
	Print(st);
	return 0;
}