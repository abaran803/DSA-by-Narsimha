#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
};

Node* CreateNewNode(int data)
{
	Node* temp = new Node();
	temp->data = data;
	temp->next = NULL;
	return temp;
}

struct LLQueue
{
	Node* front;
	Node* rear;
};

LLQueue *CreateNewQueue()
{
	LLQueue *Q = new LLQueue;
	Q->front = NULL;
	Q->rear = NULL;
	return Q;
}

bool IsEmptyQueue(LLQueue *Q)
{
	return (Q->front == NULL);
}

void EnQueue(LLQueue *Q,int data)
{
	Node* temp = CreateNewNode(data);
	if(Q->front == NULL)
	{
		Q->front = temp;
		Q->rear = temp;
		return;
	}
	// As next pointer of last or rear is NULL and temp->next is already NULL
	// If rear is not pointing to null
	if(Q->rear)
		Q->rear->next = temp;
	// Rear is moved one step or simply pointed to new node added
	Q->rear = temp;
	if(Q->front == NULL)
		Q->front = Q->rear;
}

int DeQueue(LLQueue *Q)
{
	int data = -1;
	if(IsEmptyQueue(Q))
		return data;
	Node* temp = Q->front;
	data = Q->front->data;
	Q->front = Q->front->next;
	delete temp;
	return data;
}

void Print(LLQueue *Q)
{
	Node* temp = Q->front;
	while(temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

void DeleteQueue(LLQueue* Q)
{
	Node* temp = new Node();
	while(Q->front)
	{
		// Storing current node to temporary Node
		temp = Q->front;
		Q->front = Q->front->next;
		delete temp;
	}
	delete Q;
}

int main()
{
	LLQueue *Q = CreateNewQueue();
	EnQueue(Q,5);
	EnQueue(Q,9);
	EnQueue(Q,2);
	cout << DeQueue(Q) << endl;
	// DeleteQueue(Q);
	Print(Q);
	return 0;
}