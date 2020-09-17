#include<iostream>
#include<queue>
using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;
};

Node* CreateNewNode(int data)
{
	Node* temp = new Node();
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

void PreOrder(Node* curr)
{
	if(curr)
	{
		cout << curr->data << " ";
		PreOrder(curr->left);
		PreOrder(curr->right);
	}
}

void InOrder(Node *curr)
{
	if(curr)
	{
		InOrder(curr->left);
		cout << curr->data << " ";
		InOrder(curr->right);
	}
}

void PostOrder(Node* curr)
{
	if(curr)
	{
		PostOrder(curr->left);
		PostOrder(curr->right);
		cout << curr->data << " ";
	}
}

void LevelOrder(Node* curr)
{
	queue<Node*> Q;
	Node* temp = new Node();
	if(curr)
		Q.push(curr);
	while(!Q.empty())
	{
		temp = Q.front();
		Q.pop();
		cout << temp->data << " ";
		if(temp->left)
			Q.push(temp->left);
		if(temp->right)
			Q.push(temp->right);
	}
}

Node* Insert(Node* curr,int data)
{
	if(curr)
	{
		if(data > curr->data)
			curr->right = Insert(curr->right,data);
		else
			curr->left = Insert(curr->left,data);
	}
	else
	{
		Node* temp = CreateNewNode(data);
		return temp;
	}
	return curr;
}

int main()
{
	Node* root = NULL;
	root = Insert(root,3);
	root = Insert(root,1);
	root = Insert(root,8);
	root = Insert(root,2);
	root = Insert(root,5);
	root = Insert(root,7);
	root = Insert(root,6);
	PreOrder(root);
	cout << endl;
	InOrder(root);
	cout << endl;
	PostOrder(root);
	cout << endl;
	LevelOrder(root);
	return 0;
}

			// 			3
			// 1						8
			// 		2		5
			// 					7
			// 				6