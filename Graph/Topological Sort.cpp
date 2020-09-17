#include<iostream>
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

queue<int> q;
vector<int> indegree;

Graph* CreateNewNode()
{
	Graph* G = new Graph();
	if(!G)
	{
		cout << "Memory not Allocated" << endl;
		return NULL;
	}
	cin >> G->V >> G->E;
	G->Adj = new vector<int>[G->V];
	if(!G->Adj)
	{
		cout << "Memory not Allocated";
		return NULL;
	}
	for(int i=0;i<G->V;i++)
		for(int j=0;j<G->V;j++)
			G->Adj[i].push_back(0);
	int u,v;
	for(int i=0;i<G->V;i++)
		indegree.push_back(-1);
	for(int i=0;i<G->E;i++)
	{
		cin >> u >> v;
		G->Adj[u][v] = 1;
		if(indegree[u] == -1)
			indegree[u] = 0;
		if(indegree[v] == -1)
			indegree[v] = 1;
		else
			indegree[v]++;
	}
	return G;
}

void Topological(Graph* G)
{
	while(1)
	{
		for(int i=0;i<G->V;i++)
		{
			if(indegree[i] == 0)
			{
				indegree[i]--;
				q.push(i);
			}
		}
		if(q.empty())
			return;
		while(!q.empty())
		{
			int temp = q.front();
			q.pop();
			cout << temp << " ";
			for(int i=0;i<G->V;i++)
				if(G->Adj[temp][i] == 1)
					indegree[i]--;
		}
	}
}

int main()
{
	Graph* G = CreateNewNode();
	Topological(G);
	return 0;
}