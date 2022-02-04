#include <stdio.h>
#include <stdlib.h>


struct vertex 
{
  int value;
};
typedef struct vertex Vertex;

struct lista_vertex
{
  Vertex *v;
  struct lista_vertex *proximo;
};
typedef  struct lista_vertex Lista_Vertex;

struct edge
{
  int value;
  int numero_vertice;
  int GrauMaximo;
  int ponderado;
  int**arresta;
  int* grau;
  int peso;
};

typedef struct edge Edge;
struct lista_edge
{
  Edge *e;
  struct lista_edge *proximo;
};

typedef struct lista_edge Lista_Edge;

typedef struct {
  Lista_Vertex *V;
  Lista_Edge *E;
} Grafos;

Grafos *grafosInit(){
  Grafos * grafos = malloc (sizeof(Grafos));
  grafos->E =NULL;
  grafos->V = NULL;
  return grafos;
}

// funcoes Lista Vertices
Lista_Vertex *insertVertex(Lista_Vertex *head, int value){
  Lista_Vertex *aux, *novoElemento = malloc (sizeof(Lista_Vertex));
  novoElemento->v = malloc (sizeof(Vertex));
  novoElemento->v->value = value;

  if (head == NULL){
    head = novoElemento;
  }else{
    aux = head;
    while ( aux->proximo != NULL) {
      aux=aux->proximo;
    }
    aux->proximo = novoElemento;
    novoElemento->proximo=NULL;
  }
  return head;
}


void printListaVertex(Lista_Vertex *head) {
  Lista_Vertex *aux = head;
  printf("\n ----- Lista Vertex------ \n");
  while (aux != NULL){
    printf("(%d),", aux->v->value);
    aux= aux->proximo;
  }
  printf("\n ------------\n");
}


//funcoes Lista Edges

Grafos *grafos= grafos(int numero_vertice, int GrauMaximo, int ponderado){
  Grafos *grafos = malloc (sizeof(grafos));
  if(grap!=NULL){
    grafos->nro_vertice=nro_vertice;
    grafos->GrauMaximo= GrauMaximo;
    grafos->ponderado=(ponderado!=0)?1:0;
    grafos->grau=(int*)calloc(numero_vertice,sizeof(int));
    grafos->arresta=(int**)malloc(numero_vertice*sizeof(int*));
    int i;
    for( i=0; i<numero_vertice;i++){
      grafos->arresta[i]=(int*)malloc(GrauMaximo*sizeof(int));
      if(grafos->ponderado){
        grafos->peso=(float**)malloc(numero_vertice*sizeof(float*));

        for(i=0;i<numero_vertice;i++){
          grafos->peso[i]=(float*)malloc(GrauMaximo*sizeof(float));
        }
      }
    }
  }
  //grafos->E = NULL;
	//grafos->V = NULL;
  return grafos;
}

void printListaEdge(Lista_Edge *head){
	Lista_Edge *aux = head;
	printf("\n------Lista_Edge-------\n");
	while (aux != NULL){
		printf("(%d),", aux->e->value);
		aux= aux->proximo;
	}
	printf("\n-------------\n");
	
}

//funcão para liberar 
void libera_Grafos(Grafos* grafos){
  if(grafos==NULL){
    for(int i=0;i<grafos->numero_vertice;i++){
      free(grafos->arrestas[i]);

      if(grafos->ponderado){
        for(int i=0;i<grafos->numero_vertice)
        free(grafos->peso[i]);
        free(grafos->peso);
      }
      free(grafos->grau);
      free(grafos);
    }

  }
}

int main(){
	Grafos *grafos = grafosInit();
	int insereAressta(Grafos *grafos, int origine,int destino, int digrafo, float peso);


	grafos->V = insertVertex(grafos->V, 1);
	grafos->V = insertVertex(grafos->V, 2);
	grafos->V = insertVertex(grafos->V, 3);
	grafos->V = insertVertex(grafos->V, 4);

	printListVertex(graph->V);

  grafos= cria_Graph(8,7,0);
  grafos= insereArrasta(grafos,2,4,0,2);
  grafos= insereArrasta(grafos,1,8,0,0);


  libera_Grafos(grafos);

	return 1;
};

