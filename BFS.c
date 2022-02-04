#include <stdio.h>
#include <stdlib.h>



void BFS(int);
int graph[10][10], visitado[10],total;

main()
{
	int i,j;
	printf("\nnumero de vertice \n");
	scanf("%d",&total);
	/*Adjacency matrix input*/
	printf("\n matriz adjacente\n");
	for(i=0;i<total;i++)
	{
		for(j=0;j<total;j++)
		{
			scanf("%d",&graph[i][j]);
		}
	}
	for(i=0;i<total;i++)
	{
		visitado[i] = 0;
	}
	printf("\nBFS traversal é \n");
	BFS(0);
}
void BFS(int vertex)
{
	int j;
	printf("%d\t",vertex);
	visitado[vertex] = 1;
	for(j=0;j<total;j++)
	{
		if(!visitado[j] && graph[vertex][j] == 1 )
		{
			BFS(j);
		}
	}
}