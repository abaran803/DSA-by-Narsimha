#include<iostream>
#include<math.h>
#include<stack>
#include<queue>
#include<vector>
using namespace std;

struct Graph
{
	int V;
	int E;
	vector<int> *Adj;
};

stack<int> st;
queue<int> q;
int arr[100] = {0};

Graph *CreateGraph()
{
	Graph* G = new Graph();
	if(!G)
	{
		cout << "Memory not Alloted" << endl;
		return NULL;
	}
	cin >> G->V >> G->E;
	int u,v;
	G->Adj = new vector<int>[G->V];
	if(!G->Adj)
	{
		cout << "Memory not Alloted" << endl;
		return NULL;
	}
	for(int i=0;i<G->V;i++)
	{
		for(int j=0;j<G->V;j++)
			G->Adj[i].push_back(0);
	}
	for(int j=0;j<G->E;j++)
	{
		cin >> u >> v;
		G->Adj[u][v] = 1;
		G->Adj[v][u] = 1;
	}
	return G;
}

void DFSNonRecursive(Graph* G)
{
	int temp = 0;
	cout << 0 << endl;
	arr[0] = 1;
	while(1)
	{
		int i;
		for(i=0;i<G->V;i++)
		{
			if(!arr[i])
			{
				if(G->Adj[temp][i])
				{
					arr[i] = 1;
					cout << i << " " << endl;
					st.push(temp);
					temp = i;
					break;
				}
			}
		}
		if(i == G->V)
		{
			if(st.empty())
				break;
			temp = st.top();
			st.pop();
		}
	}
}

void DFS(Graph* G,int arr[],int j)
{
	for(int i=0;i<G->V;i++)
	{
		if(!arr[i])
		{
			if(G->Adj[j][i] == 1)
			{
				cout << j << " " << i << endl;
				arr[i] = 1;
				DFS(G,arr,i);
			}
		}
	}
}

void BFS(Graph* G)
{
	int temp;
	q.push(0);
	while(!q.empty())
	{
		temp = q.front();
		cout << temp << " ";
		arr[temp] = 1;
		q.pop();
		for(int i=0;i<G->V;i++)
		{
			if(!arr[i] && G->Adj[temp][i])
			{
				arr[i] = 1;
				q.push(i);
			}
		}
	}
}

void DFSTRAVERSAL(Graph* G,int arr[])
{
	arr[0] = 1;
	DFS(G,arr,0);
}

void Destroy(struct Graph* G)
{
	if(G)
	{
		if(G->Adj)
			free(G->Adj);
		free(G);
	}
}

int main()
{
	Graph* G = CreateGraph();
	// for(int i=0;i<G->V;i++)
	// {
	// 	for(int j=0;j<G->V;j++)
	// 		cout << G->Adj[i][j];
	// 	cout << endl;
	// }
	// cout << endl;
	// DFSTRAVERSAL(G,arr);
	// DFSNonRecursive(G);
	BFS(G);
	Destroy(G);
	return 0;
}