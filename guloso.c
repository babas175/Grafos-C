#include <stdio.h>
#include <stdlib.h>

int menor(int **matrix, int i, int n){
    int min= 2147483647;
    int j;
    for( j=0; j < n; j++){
        if(matrix[i][j] < min && matrix[i][j] != 0 && j != i){
            min = matrix[i][j];
        }
    }
    return min;
}

int options(int **matrix, int i, int n, int destino){
    int contador = 0;
    printf("\n*** Opções Disponíveis ***\n");
    int j;
    for( j = 0; j < n; j++){
        if(matrix[i][j] > 0){
            printf("Vértice: %d | Custo: %d\n", j+1, matrix[i][j]);
            contador++;
        }
    }
    if(matrix[i][destino] > 0){
        return 1;
    }
    if (contador == 0){
        
        return 0;
    }
    return -1;
}

void guloso(int **matrix, int n, int init, int destino){
    int i = init, custoTotal = 0, count = 0;
    while(i < n){
        if(count > n){
            printf("Cansei! Impossível com o guloso :(\n");
            return;
        }
        int opt = options(matrix, i, n, destino);
        if (opt == 1){
            printf("\n*** Opção Escolhida ***\n");
            custoTotal+= matrix[i][destino];
            printf(" vertice %d | Custo: %d\n", destino+1, custoTotal);
        
            return;
        }
        if(opt == 0){
            return;
        }
        for(int j = 0; j < n; j++){
            if(matrix[i][j] == menor(matrix, i, n)){
                printf("\n*** Opção Escolhida ***\n");
                custoTotal+= matrix[i][j];
                printf("vértice %d | Custo: %d\n", j+1, custoTotal);
                i = j;
                break;
            }
        }
        count++;
    }
}

int main(){
      int n;
      int ** matAdj;
    printf("Digite o número de vértices: ");
    scanf("%d", &n);

    matAdj = (int *) malloc(sizeof(int *)*n);
    for(int i = 0; i < n; i++){
        matAdj[i] = malloc(sizeof(int)*n);
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("Digitanto\n");
            printf("%d, %d: ", i,j);
            scanf("%d", &matAdj[i][j]);
        }
    }

    printf("\n** Matriz**\n");
    int i;
    int j;

    for( i = 0; i < n; i++){
        for( j = 0; j < n; j++){
            printf("%d\t|", matAdj[i][j]);
        }
        printf("\n");
    }

    guloso(matAdj, n, 0, n-1);
}