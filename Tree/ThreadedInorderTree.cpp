#include<iostream>
using namespace std;

struct Node
{
	int data;
	bool RTag;
	bool LTag;
	Node* left;
	Node* right;
};

void InTraverse(Node* root)
{
	if(!root)
		return;
	while(1)
	{
		if(!root)
			return;
		if(root->left == NULL)
		{
			cout << root->data << " ";
			if(!root->right)
				return;
			root = root->right;
		}
		else
		{
			if(!root->LTag)
			{
				root->LTag = 1;
				root = root->left;
			}
			else
			{
				cout << root->data << " ";
				root = root->right;
			}
		}
	}
}

Node* CreateNewNode(int data)
{
	Node* temp = new Node();
	temp->data = data;
	temp->RTag = 1;
	temp->left = temp->right = NULL;
	return temp;
}

Node* Threaded(Node* root)
{
	if(root == NULL)
		return NULL;
	if(root->left == NULL && root->right == NULL)
		return root;
	if(root->left)
	{
		Node* left = Threaded(root->left);
		left->right = root;
		left->RTag = 0;
	}
	if(root->right == NULL)
		return root;
	return Threaded(root->right);
}

void Traverse(Node* root)
{
	if(root)
	{
		cout << root->data << " ";
		Traverse(root->left);
		Traverse(root->right);
	}
}

int main()
{
	Node *root = CreateNewNode(1);
	root->left = CreateNewNode(2);
	root->right = CreateNewNode(3);
	root->left->left = CreateNewNode(4);
	root->left->right = CreateNewNode(5);
	root->right->left = CreateNewNode(6);
	root->right->right = CreateNewNode(7);
	Threaded(root);
	InTraverse(root);
	return 0;
}