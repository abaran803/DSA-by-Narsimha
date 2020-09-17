#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node* next;
};

struct Graph
{
	int V;
	int E;
	struct Node* *Adj;
};

struct Graph* CreateNewGraph()
{
	struct Graph* G = (struct Graph*)malloc(sizeof(struct Graph));
	int u,v;
	scanf("%d%d",&G->V,&G->E);
	G->Adj = (struct Node**)malloc(sizeof(struct Node*) * G->V);
	for(int i=0;i<G->V;i++)
	{
		G->Adj[i] = (struct Node*)malloc(sizeof(struct Node));
		Node* temp = new Node();
		temp->data = i;
		temp->next = NULL;
		G->Adj[i] = temp;
		G->Adj[i]->next = G->Adj[i];
	}
	for(int i=0;i<G->E;i++)
	{
		scanf("%d%d",&u,&v);
		int j=0;
		while(j<G->V && G->Adj[j]->data != u)
			j++;
		if(G->Adj[j])
		{
			struct Node* temp = G->Adj[j];
			while(temp->next != G->Adj[j])
			{
				temp = temp->next;
			}
			struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node));
			temp1->data = v;
			temp1->next = NULL;
			temp->next = temp1;
			temp1->next = G->Adj[j];
		}
		else
			printf("Memory Error");
	}
	return G;
}

int main()
{
	struct Graph* G = CreateNewGraph();
	for(int i=0;i<G->V;i++)
	{
		Node* temp = G->Adj[i];
		do
		{
			printf("%d ",temp->data);
			temp = temp->next;
		}while(temp != G->Adj[i]);
		printf("\n");
	}
	return 0;
}