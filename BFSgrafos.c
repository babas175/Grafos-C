
#include<stdio.h>
int a[20][20], q[20], visitado[20], n, i, j, f = 0, r = -1;

void bfs(int v) {
	for(i = 1; i <= n; i++)
		if(a[v][i] && !visitado[i])
			q[++r] = i;
	if(f <= r) {
		visitado[q[f]] = 1;
		bfs(q[f++]);
	}
}

void main() {
	int v;
	printf("\n Digite o numero de vertice:");
	scanf("%d", &n);
	
	for(i=1; i <= n; i++) {
		q[i] = 0;
		visitado[i] = 0;
	}
	
	printf("\n entrar os dados do grafo e a forma da matriz:\n");
	for(i=1; i<=n; i++) {
		for(j=1;j<=n;j++) {
			scanf("%d", &a[i][j]);
		}
	}
	
	printf("\n start o vertice:");
	scanf("%d", &v);
	bfs(v);
	printf("\n .................\n");
	
	for(i=1; i <= n; i++) {
		if(visitado[i])
			printf("%d\t", i);
		else {
			printf("\n Bfs nao for possivel !!!");
			break;
		}
	}
}