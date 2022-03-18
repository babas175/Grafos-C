#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//este codigo baseada sobre um esqueleto que eu achei no geeksforgeeks e implementado com alguns videos do youtube

typedef struct {
    int valor;
} Node;

typedef struct {
    int weigth;
    Node *origem;
    Node *destino;
} Edge;

struct list_edges{
    Edge *edge;
    struct list_edges *prev;
    struct list_edges *next;
};

typedef struct list_edges Edges;

struct tabela_edges{
    Edges * head;
    Edges * tail;
};

typedef struct tabela_edges Tab;

void insira(Node * origem, Node * destino, int weigth, Tab * tabela){
    Edge * newEdge = malloc(sizeof(Edge));
    newEdge->origem = origem;
    newEdge->destino = destino;
    newEdge->weigth = weigth; 

    Edges * addEdge = malloc(sizeof(Edges));
    addEdge->edge = newEdge;
    addEdge->next = NULL;
    addEdge->prev = NULL;
     if(tabela->head == NULL && tabela->tail == NULL){
        addEdge->next = NULL;
        addEdge->prev = NULL;
        tabela->head = addEdge;
        tabela->tail = addEdge;
    }
     else{
        Edges * aux = tabela->tail;
        
        
        if(newEdge->weigth >= aux->edge->weigth){
            aux->next = addEdge;
            addEdge->prev = aux;
            addEdge->next = NULL;
            tabela->tail = addEdge;
        }
        else{
            do{
                
                if(aux == tabela->head && newEdge->weigth < aux->edge->weigth){
                    addEdge->prev = NULL;
                    addEdge->next = aux;
                    aux->prev = addEdge;
                    tabela->head = addEdge;
                    break;
                }
                if(aux->prev == NULL){
                    break;
                }
                aux = aux->prev;
                if(newEdge->weigth >= aux->edge->weigth){
                    addEdge->next = aux->next;
                    addEdge->prev = aux;
                    addEdge->next->prev = addEdge;
                    aux->next = addEdge;
                    break;
                }
            }while (aux);
        }
    }
    return;

}

void createList(int ** matAdj, int n, Tab * tabela){
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            if(matAdj[i][j] > 0){
                Node * origem = malloc(sizeof(Node));
                 Node * destino = malloc(sizeof(Node));
                origem->valor = i;
                destino->valor = j;
                insira(origem, destino, matAdj[i][j], tabela);
            }
        }
    }
}

void printList(Tab * tabela, int visitado){
    Edges * aux = tabela->head;
    int count = 0;
    printf("\n\n************ Estado atual %d *************\n", visitado+1);

    printf("\n|\tpe\t|\tvi\t|\tva\t|\n");
    printf("|-------------------------------------|\n");

    do {
        printf("|\t%d\t|\t%d\t|\t%d\t|", aux->edge->weigth, aux->edge->origem->valor, aux->edge->destino->valor);
        if(count == visitado){
            printf(" ← visitado");
        }
         printf("\n");
        if(aux->next != NULL){
            aux = aux->next;
        }
        else{
            break;
        }
        count++;
    }while (aux);
    printf("\n");
}

void printVControl(int * vControl, int n, int vi, int vj){
    char imp[100] = "";
    char h[100] = "";
    char head[100] = "";
    char line[100] = "";
    strcat(head, "Vert\t|");
    strcat(line, "P\t|");
    strcat(h, "--------");
    strcat(imp, " \t");

    for(int i = 0; i < n; i++){
        if(i == vi || i == vj){
            strcat(imp, " ↓\t");
        }
        else{
            strcat(imp, "\t");
        }

        char ver[5] = "";
        sprintf(ver, "%d", i);
        strcat(head, ver);
        strcat(head, "\t|");
        char p[5] = "";
        sprintf(p, "%d", vControl[i]);
        strcat(line, p);
        strcat(line, "\t|");

        strcat(h, "-------");
    }
    strcat(h, "|");
    printf("%s\n", imp);
    printf("%s\n", head);
    printf("%s\n", h);
    printf("%s\n", line); 


}
int findRoot(int * vControl, int pos){
    int node = vControl[pos];
    int root = pos;
    while(node >= 0){
        root = node;
        node = vControl[node];
    }
    return root;
}

void kruskal(Tab * tabela, int n, int *vControl){
    Edges * aux = tabela->head;
    char path[100] = "\nCaminho até:\n\t";
    int visitado = 0;
    int cost = 0;
    while (aux) {
        int vi = aux->edge->origem->valor;
        int vj = aux->edge->destino->valor;

        int rooti = findRoot(vControl, vi);
        int rootj = findRoot(vControl, vj);

        if(rooti == rootj){

        }
        else{
            if(vControl[rootj] == vControl[rooti] || vControl[rootj] < vControl[rooti]){
                vControl[rootj]+= vControl[rooti];
                vControl[rooti] = rootj;
            }
            else if(vControl[rootj] > vControl[rooti]){
                vControl[rooti] += vControl[rootj];
                vControl[rootj] = rooti;
            }
            char temp[5] = "";
            strcat(path, "(");

            sprintf(temp, "%d", vi);
            strcat(path, temp);
            strcat(path, ",");

            sprintf(temp, "%d", vj);
            strcat(path, temp);
            strcat(path, ") ");

            cost+= aux->edge->weigth;
        }
        printList(tabela, visitado);
        printVControl(vControl, n, vi, vj);
        printf("%s\n", path);

        if(vControl[rootj] == n*(-1) || vControl[rooti] == n*(-1)){
            printf("\n\t→ Caminho até :\n");
            printf("\tCusto: %d\n", cost);
            return;
        }

        if(aux->next != NULL){
            aux = aux->next;
        }
        else{
            return;
        }
        visitado++;
    }
}

int main(){
    int ** matAdj;
    int n;
    int * vControl;

    printf("Digita o número de vértices: ");
    scanf("%d", &n);

    //Criando a Matriz de adjacencia
    matAdj = (int **) malloc(sizeof(int *)*n);
    for(int i = 0; i < n; i++){
        matAdj[i] = malloc(sizeof(int)*n);
    }
    //criar a matriz aqui
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("Digita o valor %d, %d: ", i,j);
            scanf("%d", &matAdj[i][j]);
        }
    }

     vControl = malloc(sizeof(int)*n);


    printf("\n************************Matriz****** *********************\n");

    for(int i = 0; i < n; i++){
        vControl[i] = -1;  
        for(int j = 0; j < n; j++){
            printf("%d\t|", matAdj[i][j]);
        }
        printf("\n");
    }
    Tab * tabela = malloc(sizeof (Tab));
    tabela->head = NULL;
    tabela->tail = NULL;

    createList(matAdj, n, tabela);  

    kruskal(tabela, n, vControl);


}