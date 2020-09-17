#include<iostream>
#include<queue>
using namespace std;

struct Graph
{
	int V;
	int E;
	vector<int> *Adj;
};

Graph* CreateNewNode()
{
	Graph* G = new Graph();
	cin >> G->V >> G->E;
	G->Adj = new vector<int>[G->V];
	for(int i=0;i<G->V;i++)
		for(int j=0;j<G->V;j++)
			G->Adj[i].push_back(0);
	int u,v;
	for(int i=0;i<G->E;i++)
	{
		cin >> u >> v;
		G->Adj[u][v] = 1;
		G->Adj[v][u] = 1;
	}
	return G;
}

void ShortestPath(Graph* G,int n)
{
	queue<int> q;
	int Dist[G->V];
	for(int i=0;i<G->V;i++)
		Dist[i] = -1;
	Dist[n] = 0;
	q.push(n);
	while(!q.empty())
	{
		int v = q.front();
		q.pop();
		for(int i=0;i<G->V;i++)
		{
			if(G->Adj[v][i] == 1 && Dist[i] == -1)
			{
				Dist[i] = Dist[v]+1;
				q.push(i);
			}
		}
	}
	for(int i=0;i<G->V;i++)
		cout << Dist[i] << " ";
}

int main()
{
	Graph* G = CreateNewNode();
	int q;
	cin >> q;
	ShortestPath(G,q);
	return 0;
}