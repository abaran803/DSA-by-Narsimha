#include<stdio.h>
#include<stdlib.h>

struct Graph
{
	int V;
	int E;
	int **Adj;
};

int arr[100] = {0};

struct Graph *CreateGraph()
{
	struct Graph* G = (struct Graph *)malloc(sizeof(struct Graph));
	if(!G)
	{
		printf("Memory not Alloted\n");
		return NULL;
	}
	scanf("%d%d",&G->V,&G->E);
	int u,v;
	G->Adj = (int **)malloc(sizeof(G->V)*G->V*G->V);
	if(!G->Adj)
	{
		printf("Memory not Alloted\n");
		return NULL;
	}
	for(int i=0;i<G->V;i++)
	{
		G->Adj[i] = (int *)malloc(sizeof(G->V)*G->V*G->V);
		if(!G->Adj[i])
		{
			printf("Memory not Alloted\n");
			return NULL;
		}
		for(int j=0;j<G->V;j++)
			G->Adj[i][j] = 0;
	}
	for(int j=0;j<G->E;j++)
	{
		scanf("%d%d",&u,&v);
		G->Adj[u][v] = 1;
		G->Adj[v][u] = 1;
	}
	return G;
}

void DFS(struct Graph* G,int arr[],int j)
{
	arr[j] = 1;
	for(int i=0;i<G->V;i++)
	{
		if(!arr[i])
		{
			if(G->Adj[j][i] == 1)
			{
				printf("%d %d\n",j,i);
				arr[i] = 1;
				DFS(G,arr,i);
			}
		}
	}
}

void DFSTRAVERSAL(struct Graph* G,int arr[])
{
	for(int i=0;i<G->V;i++)
	{
		arr[i] = 1;
		DFS(G,arr,i);
	}
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
	struct Graph* G = CreateGraph();
	for(int i=0;i<G->V;i++)
	{
		for(int j=0;j<G->V;j++)
			printf("%d",G->Adj[i][j]);
		printf("\n");
	}
	printf("\n");
	DFSTRAVERSAL(G,arr);
	return 0;
}