#include<iostream>
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
	temp->right = temp->left = NULL;
	return temp;
}

Node* Insert(Node* root,int data)
{
	if(!root)
		root = CreateNewNode(data);
	if(root->data > data)
		root->left = Insert(root->left,data);
	else if(root->data < data)
		root->right = Insert(root->right,data);
	return root;
}

void InorderTraverse(Node* root)
{
	if(root)
	{
		InorderTraverse(root->left);
		cout << root->data << " ";
		InorderTraverse(root->right);
	}
}

Node* SearchRecursive(Node* root,int query)
{
	if(!root)
		return NULL;
	if(query < root->data)
		return SearchRecursive(root->left,query);
	else if(query > root->data)
		return SearchRecursive(root->right,query);
	return root;
}

Node* SearchNonRecursive(Node* root,int query)
{
	while(root)
	{
		if(!root)
			return NULL;
		if(query < root->data)
			root = root->left;
		else if(query > root->data)
			root = root->right;
		else
			return root;
	}
	return NULL;
}

Node* MinimumRecursive(Node* root)
{
	if(!root)
		return NULL;
	if(root->left)
		return MinimumRecursive(root->left);
	return root;
}

Node* MinimumNonRecursive(Node* root)
{
	if(!root)
		return NULL;
	while(root->left)
		root = root->left;
	return root;
}

Node* MaximumRecursive(Node*);

Node* Delete(Node* root,int query)
{
	if(!root)
		return NULL;
	if(root->data > query)
		root->left = Delete(root->left,query);
	else if(root->data < query)
		root->right = Delete(root->right,query);
	else
	{
		if(!root->right && !root->left)
			return NULL;
		Node* temp = new Node();
		if(root->right == NULL)
		{
			temp = root;
			root = root->left;
			delete temp;
		}
		if(root->left == NULL)
		{
			temp = root->right;
			root = root->right;
			delete temp;
		}
		if(root->right && root->left)
		{
			temp = MaximumRecursive(root->left);
			root->data = temp->data;
			root->left = Delete(root->left,root->data);
		}
	}
	return root;
}

Node* MaximumRecursive(Node *root)
{
	if(!root)
		return NULL;
	if(root->right)
		return MaximumRecursive(root->right);
	return root;
}

Node* MaximumNonRecursive(Node* root)
{
	if(!root)
		return NULL;
	while(root->right)
		root = root->right;
	return root;
}

int main()
{
	Node* root = NULL;
	root = Insert(root,97);
	root = Insert(root,95);
	root = Insert(root,72);
	root = Insert(root,52);
	root = Insert(root,93);
	InorderTraverse(root);
	cout << endl;
	cout << SearchNonRecursive(root,72)->data << endl;
	cout << MinimumRecursive(root)->data << endl;
	cout << MinimumNonRecursive(root)->data << endl;
	cout << MaximumRecursive(root)->data << endl;
	cout << MaximumNonRecursive(root)->data << endl;
	root = Delete(root,93);
	InorderTraverse(root);
	return 0;
}