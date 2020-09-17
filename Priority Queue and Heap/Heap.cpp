#include<iostream>
using namespace std;

int num = 0;

struct HeapNode
{
	int *arr;
	int capacity;
	int count;
};

void swap(int &a,int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void DestroyHeap(HeapNode* h)
{
	if(!h)
		return;
	delete h->arr;
	delete h;
	h = NULL;
}

HeapNode* CreateHeap(int capacity)
{
	HeapNode* h = new HeapNode();
	h->capacity = capacity;
	h->arr = new int(capacity);
	h->count = 0;
	return h;
}

int Parent(HeapNode* h,int i)
{
	if(i <= 0 || i >= h->count)
		return -1;
	return (i-1)/2;
}

int LeftChild(HeapNode* h,int i)
{
	int l = 2*i+1;
	if(l >= h->count)
		return -1;
	else
		return l;
}

int RightChild(HeapNode* h,int i)
{
	int r = 2*i+2;
	if(r >= h->count)
		return -1;
	return r;
}

void CorrectUp(HeapNode* h,int i)
{
	while(Parent(h,i) != -1)
	{
		if(h->arr[Parent(h,i)]<h->arr[i])
			swap(h->arr[Parent(h,i)],h->arr[i]);
		else
			i = Parent(h,i);
	}
}

void CorrectDown(HeapNode* h,int i)
{
	if(LeftChild(h,i) == -1)
		return;
	int max = i;
	if(LeftChild(h,i) != -1 && h->arr[LeftChild(h,i)] > h->arr[i])
		max = LeftChild(h,i);
	if(RightChild(h,i) != -1 && h->arr[RightChild(h,i)] > h->arr[max])
		max = RightChild(h,i);
	if(max == i)
		return;
	swap(h->arr[max],h->arr[i]);
	CorrectDown(h,max);
}

HeapNode* Insert(HeapNode* h,int data)
{
	h->arr[h->count++] = data;
	num++;
	CorrectUp(h,h->count-1);
	return h;
}

int Delete(HeapNode* h)
{
	if(h->count == 0)
		return -1;
	int data = h->arr[0];
	h->arr[0] = h->arr[--h->count];
	h->arr[h->count] = data;
	CorrectDown(h,0);
	return data;
}

void Traverse(HeapNode* h)
{
	for(int i=0;i<h->count;i++)
		cout << h->arr[i] << " ";
	cout << endl;
}

void MergeSortedArray(HeapNode* h)
{
	for(int i=0;i<num;i++)
		cout << h->arr[i] << " ";
	cout << endl;
}

int main()
{
	HeapNode* h = CreateHeap(7);
	h = Insert(h,25);
	h = Insert(h,42);
	h = Insert(h,33);
	// DestroyHeap(h);
	Traverse(h);
	Delete(h);
	Delete(h);
	Delete(h);
	MergeSortedArray(h);
	return 0;
}