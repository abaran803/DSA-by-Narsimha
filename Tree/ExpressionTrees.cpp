#include<iostream>
#include<stack>
using namespace std;

struct Node
{
	char data;
	Node* left;
	Node* right;
};

Node* CreateNewNode(char data)
{
	Node* temp = new Node();
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

Node* Convert(string str)
{
	stack<Node*> st;
	for(int i=0;i<str.size();i++)
	{
		if(str[i] >= 'A' && str[i] <= 'Z')
		{
			Node* temp = CreateNewNode(str[i]);
			st.push(temp);
		}
		else
		{
			Node* temp1 = CreateNewNode(str[i]);
			Node* temp2 = st.top();
			st.pop();
			Node* temp3 = st.top();
			st.pop();
			temp1->right = temp2;
			temp1->left = temp3;
			st.push(temp1);
		}
	}
	return st.top();
}

void Traverse(Node* root)
{
	if(root)
	{
		Traverse(root->left);
		cout << root->data << " ";
		Traverse(root->right);
	}
}

int main()
{
	string str = "ABC*+D/";
	Node* root = Convert(str);
	Traverse(root);
	return 0;
}