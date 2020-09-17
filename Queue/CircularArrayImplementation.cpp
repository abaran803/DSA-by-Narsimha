#include<iostream>
using namespace std;
#define SIZE 10

struct ArrayQueue
{
	int front,rear;
	int capacity;
	int* arr;
};

ArrayQueue* CreateNewQueue()
{
	ArrayQueue *Q = new ArrayQueue();
	if(!Q)
		return NULL;
	Q->front = Q->rear = -1;
	Q->capacity = SIZE;
	Q->arr = new int(Q->capacity);
	if(!Q->arr)
		return NULL;
	return Q;
}

bool IsEmptyQueue(ArrayQueue *Q)
{
	return (Q->front == -1);
}

bool IsFullQueue(ArrayQueue *Q)
{
	return ((Q->rear+1)%(Q->capacity) == Q->front);
}

void EnQueue(ArrayQueue *Q,int data)
{
	if(IsFullQueue(Q))
	{
		cout << "Overflow" << endl;
		return;
	}
	Q->arr[(++Q->rear)%Q->capacity] = data;
	if(Q->front == -1)
		Q->front = Q->rear;
}

int DeQueue(ArrayQueue *Q)
{
	int data;
	if(IsEmptyQueue(Q))
	{
		cout << "Underflow" << endl;
		return -1;
	}
	data = Q->front;
	if(Q->front == Q->rear)
		Q->front = Q->rear = -1;
	else
		(++Q->front)%Q->capacity;
	return data;
}

void Traverse(ArrayQueue *Q)
{
	if(IsEmptyQueue(Q))
		return;
	for(int i=Q->front;i<=Q->rear;i++)
		cout << Q->arr[i] << " ";
	cout << endl;
}

void DeleteQueue(ArrayQueue *Q)
{
	if(Q)
	{
		if(Q->arr)
			delete Q->arr;
		delete Q;
	}
}

int QueueSize(ArrayQueue *Q)
{
	// Q->capacity - Q->front = No of element from front
	// Q->rear + 1 = No of element till rear
	if(IsEmptyQueue(Q))
		return 0;
	return(Q->capacity - Q->front + Q->rear + 1)%Q->capacity;
}

int main()
{
	ArrayQueue *Q = CreateNewQueue();
	EnQueue(Q,9);
	EnQueue(Q,4);
	EnQueue(Q,1);
	EnQueue(Q,5);
	// DeleteQueue(Q);
	DeQueue(Q);
	Traverse(Q);
	cout << QueueSize(Q);
	return 0;
}