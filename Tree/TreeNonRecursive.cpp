#include<iostream>
#include<stack>
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

void PreOrder(Node* root)
{
	stack<Node*> S;
	while(1)
	{
		while(root)
		{
			S.push(root);
			cout << root->data << " ";
			root = root->left;
		}
		if(S.empty())
		{
			cout << endl;
			return;
		}
		root = S.top();
		S.pop();
		root = root->right;
	}
}

void InOrder(Node* root)
{
	stack<Node*> S;
	while(1)
	{
		while(root)
		{
			S.push(root);
			root = root->left;
		}
		if(S.empty())
		{
			cout << endl;
			return;
		}
		root = S.top();
		cout << root->data << " ";
		S.pop();
		root = root->right;
	}
}

// void PostOrder(Node* root)
// {
// 	stack<Node*> S;
// 	while(1)
// 	{
// 		while(root)
// 		{
// 			S.push(root);
// 			root = root->left;
// 		}
// 		if(S.empty())
// 		{
// 			cout << endl;
// 			return;
// 		}
// 		root = S.top();
// 		// cout << root->data << " ";
// 		S.pop();
// 		root = root->right;
// 	}
// }

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
	InOrder(root);
	return 0;
}