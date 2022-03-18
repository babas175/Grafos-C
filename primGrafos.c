#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
// aqui estou printando os valores
void printPrim(int **matTab, int n, int visitado){
    printf("\tver\t|\tvis\t|\tval\t|\tant\t|\n");
    printf("----------------+---------------+---------------+---------------|\n");

    for(int i = 0; i < n; i++){
        for(int j = 0; j < 4; j++){
            if(matTab[i][j] == INT_MAX){
                printf("\tINF\t|");
            }
            else{
                printf("\t%d\t|", matTab[i][j]);
            }
        }
        if(i == visitado && visitado > -1 && visitado < n){
            printf(" ← visitado");
        }
        printf("\n");
    }
}

int smallest(int **matTab, int n){
    int menor = INT_MAX;
    int pos;
    for(int i = 0; i<n; i++){
        if (matTab[i][1] != 1 && matTab[i][2] < menor){
            menor = matTab[i][2];
            pos = i;
        }
    }
    if(menor == INT_MAX){
        return -1;
    }
    return pos;
}

void prim(int **matAdj, int **matTab, int n, int startValue){
    int i = startValue;
    matTab[i][2] = 0;
    while(i < n){
        printf("\n\n****************************** Visitando o vértice %d ******************************\n\n", i);
        matTab[i][1] = 1;

        for(int j = 0; j < n; j++){
            if(matAdj[i][j] != 0 && matTab[j][1] != 1 && matAdj[i][j] < matTab[j][2]){
                matTab[j][2] = matAdj[i][j];
                matTab[j][3] = i;
            }
        }

        printPrim(matTab, n, i);

        int menor = smallest(matTab, n);
        if(menor == -1 || menor > n){
            return;
        }
        i = menor;
        getc(stdin);
    }
}

int main(){
    int ** matAdj;
    int ** matTab;
    int n;
    printf("Digita o numero do vértices: ");
    scanf("%d", &n);

    matAdj = (int **) malloc(sizeof(int *)*n);
    for(int i = 0; i < n; i++){
        matAdj[i] = malloc(sizeof(int)*n);
    }

    matTab = (int **) malloc(sizeof(int *)*n);
    for(int i = 0; i < n; i++){
        matTab[i] = malloc(sizeof(int)*4);
        matTab[i][0] = i;
        matTab[i][1] = 0;
        matTab[i][2] = INT_MAX;
        matTab[i][3] = -1;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("Inira o valor %d, %d: ", i,j);
            scanf("%d", &matAdj[i][j]);
        }
    }

    printf("\n\n****************************** Matriz ******************************\n\n");

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%d\t|", matAdj[i][j]);
        }
        printf("\n");
    }

    int inicia;
    printf("\nDigita o valor inicial: ");
    scanf("%d", &inicia);

    prim(matAdj, matTab, n, inicia);

    printf("\n\n****************************** Prim ******************************\n\n");

    printPrim(matTab, n, -1);

    int preco = 0;
    printf("\n Resultado:\n\t");
    for(int i = 0; i < n; i++){
        preco+=matTab[i][2];
        if(matTab[i][3] == -1){

        }
        else{
            printf("(%d,%d) ", matTab[i][0], matTab[i][3]);
        }
    }
    printf("\n\n\tSoma: %d\n", preco);
}