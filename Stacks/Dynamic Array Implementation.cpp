#include<iostream>
using namespace std;

struct DStack
{
	int *arr;
	int top;
	int capacity;
};

DStack *CreateNewStack()
{
	DStack *S = new DStack();
	if(!S)
		return NULL;
	S->top = -1;
	S->capacity = 1;
	S->arr = new int(S->capacity);
	if(!S->arr)
		return NULL;
	return S;
}

int* IsArrayFull(DStack *st)
{
	st->capacity *= 2;
	int* arr = new int(st->capacity);
	for(int i=0;i<=st->top;i++)
		arr[i] = st->arr[i];
	delete st->arr;
	return arr;
}

bool IsStackFull(DStack *st)
{
	return (st->top == st->capacity-1);
}

bool IsStackEmpty(DStack *st)
{
	return (st->top == -1);
}

int Top(DStack *st)
{
	if(IsStackEmpty(st))
		return -1;
	return st->arr[st->top];
}

void Push(DStack *st,int data)
{
	if(st->top == st->capacity)
		st->arr = IsArrayFull(st);
	st->arr[++st->top] = data;
}

int Pop(DStack *st)
{
	if(IsStackEmpty(st))
		return -1;
	return st->arr[st->top--];
}

void Print(DStack *st)
{
	for(int i=0;i<=st->top;i++)
		cout << st->arr[i] << " ";
	cout << endl;
}

void DeleteStack(DStack *st)
{
	if(st)
	{
		if(st->arr)
			delete st->arr;
		delete st;
	}
}

int main()
{
	DStack *st = CreateNewStack();
	Push(st,4);
	// DeleteStack(st);
	Push(st,7);
	Push(st,9);
	cout << Pop(st) << endl;
	Print(st);
	cout << Top(st);
	return 0;
}