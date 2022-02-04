#include <stdio.h>
#include <stdlib.h>

#define N 5 //define uma constante


/*
 Calcula o grau para um grafo simples, não direcionado.
*/
int grauGrafoSimples(int matAdj[N][N], int vertice){
	int grau = 0;

	for (int i=0; i<N;i++){
		grau+=matAdj[vertice][i];
	}

	return grau;
}

int menorCaminho(int matrixAdj[N][N],int *visitado[N], int NV){
  int i, menor=-1,primeiro=1;
  for(i=0; i<NV; i++){
    if(matrixAdj[i]>=0 && visitado[i]>=0){
      if(primeiro){
        menor=i;
        primeiro=0;
      }else{
        if(matrixAdj[menor]> matrixAdj[i]){
          menor=i;
        }
      }
    }
  }
  return menor;
}

int main(){
	
	int matrizAdj[N][N] = {	
              {0,1,0,1}, //1
							{0,0,1,0}, //2
							{0,0,0,0}, //3
							{1,1,1,0} //4
						};

	int opt;

	printf(" Digite se o grafo é simples ou dirigido (1 - simples, 2-dirigido)\n");
	scanf("%d", &opt);

	if (opt == 1){
		printf("d(1)=%d \n", grauGrafoSimples(matrizAdj,0));
		printf("d(2)=%d\n", grauGrafoSimples(matrizAdj,1));
		printf("d(3)=%d\n", grauGrafoSimples(matrizAdj,2));
		printf("d(4)=%d\n", grauGrafoSimples(matrizAdj,3));
	}else {
    int matrixAdj[N][N]={
              {0,1,0,0,0}, 
							{0,0,1,0,1}, 
							{0,0,0,0,1}, 
							{1,1,1,0,1}
    };
    printf("d(1)=%d \n", grauGrafoSimples(matrixAdj,0));
		printf("d(2)=%d\n", grauGrafoSimples(matrixAdj,1));
		printf("d(3)=%d\n", grauGrafoSimples(matrixAdj,2));
		printf("d(4)=%d\n", grauGrafoSimples(matrixAdj,3));

    


	}

	

}

//fonte de ajuda : youtube, Alura