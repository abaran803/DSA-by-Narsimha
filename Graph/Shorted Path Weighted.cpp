#include<bits/stdc++.h>
using namespace std;

struct Graph
{
	int V;
	int E;
	int **Dist;
	vector<int> *Adj;
};

Graph* CreateGraph()
{
	Graph* G = new Graph();
	cin >> G->V >> G->E;
	G->Dist = new int*[G->V];
	G->Adj = new vector<int>[G->V];
	for(int i=0;i<G->V;i++)
		for(int j=0;j<G->V;j++)
			G->Adj[i].push_back(0);
	int u,v,k;
	for(int i=0;i<G->V;i++)
	{
		G->Dist[i] = new int[G->V];
		for(int j=0;j<G->V;j++)
			G->Dist[i][j] = 0;
	}
	for(int i=0;i<G->E;i++)
	{
		cin >> u >> v >> k;
		G->Adj[u][v] = 1;
		G->Adj[v][u] = 1;
		G->Dist[u][v] = k;
		G->Dist[v][u] = k;
	}
	return G;
}

void ShortestPath(Graph* G,int n)
{	
	
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("inp.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
		
	int k;
	cin >> k;
	// Graph *G = CreateGraph();
	cout << "Hey" << k;
	return 0;
}