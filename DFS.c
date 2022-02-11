
#include<stdio.h>
#include<stdlib.h>

int graph[10][10], visitado[10],total,arr[30];
static int k=0,count=0;

void DFS(int);
main()
{
	int i,j;
	printf("\n Por favor digite o numero de vertice \n");
	scanf("%d",&total);
	/*Adjacente matriz input*/
	printf("\n Digite a matriz adjacente \n");
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
	printf("\nDFS traversal é \n");
	DFS(0);
}
void DFS(int vertex)
{
	int j,c=0;
	count++;
	printf("%d\t",vertex);
	visitado[vertex] = 1;
	for(j=0;j<total;j++)
	{
		if(!visitado[j] && graph[vertex][j] == 1)
		{
			arr[++k] = j;
			c=1;
		}
		if(count == total)
		{
			exit(0);
		}
	}
	if(c==1)
	{
		DFS(arr[k]);
	}
	else
	{
		k--;
		DFS(arr[k]);
	}	
}