#include <malloc.h>
#include <stdio.h>
#define true 1
#define false 0

typedef struct {
  int * A, * B;
  int tamanhoAtual;
  int tamanhoMaximo;
} HEAP;

void inicializarHeap(HEAP * h, int tamanhoMax){
  h->A = (int*) malloc(sizeof(int)*(tamanhoMax+1));
  h->B = (int*) malloc(sizeof(int)*(tamanhoMax+1));
  h->tamanhoAtual = 0;
  h->tamanhoMaximo = tamanhoMax;
}

void destruirHeap(HEAP * h){
  int tamanho = h->tamanhoMaximo;
  free(h->A);
  free(h->B);
  h->tamanhoMaximo=0;
  h->tamanhoAtual=0;
}

int pai(int i){
  return (i-1)/2;
}

int filhoEsquerda(int i){
  return 2*i + 1;
}

int filhoDireita(int i){
  return 2*i + 2;
}

void ReHeapUp(HEAP* h, int i) {
    int temp, temp2;
  printf("entrou aqui\n");
    while( i > 0 && h->A[i] < h->A[pai(i)])
    {
      printf("i: %d\n", i);
        temp = h->A[i];
        h->A[i] = h->A[pai(i)];
        h->A[pai(i)] = temp;

        temp2 = h->B[i];
        h->B[i] = h->B[pai(i)];
        h->B[pai(i)] = temp2;
        i = pai(i);
    }
}

void Insert(HEAP* h, int prio, int valor) 
{
    h->A[h->tamanhoAtual] = prio;
    h->B[h->tamanhoAtual] = valor;
    ReHeapUp(h,h->tamanhoAtual);
    h->tamanhoAtual = h->tamanhoAtual+1;
}

void ReHeapDown(HEAP* h,int i){
    int temp, temp2;
    int j;

    while(2*i + 1 < h->tamanhoAtual){
        j = 2*i + 1;

        if(j+1 < h->tamanhoAtual && h->A[j + 1] < h->A[j])
            j = j + 1;

        if(h->A[i] < h->A[j])
            break;
        else {
            temp = h->A[i];
            h->A[i] = h->A[j];
            h->A[j] = temp;

            temp = h->B[i];
            h->B[i] = h->B[j];
            h->B[j] = temp2;
            i = j;
        }
    }
}

void Delete_MaxVal(HEAP* h){
    int temp;

    temp = h->A[0];
    h->A[0] = h->A[h->tamanhoAtual -1];
    h->A[h->tamanhoAtual -1] = temp;

    temp = h->B[0];
    h->B[0] = h->B[h->tamanhoAtual -1];
    h->B[h->tamanhoAtual -1] = temp;

    (h->tamanhoAtual)--;
    ReHeapDown(h,0);
}

HEAP* Heapfy(int* A,int* B,int n){
    HEAP* h = (HEAP*)malloc(sizeof(HEAP));
    inicializarHeap(h,n);
    h->A = A;
    h->B = B;
    h->tamanhoAtual = n;
    h->tamanhoMaximo = n;

    int i;
    for(i = (n-1)/2 ; i >= 0 ; i--)
        ReHeapDown(h,i);

    return h;
}

void HeapSort(int * A,int * B, int n){
    HEAP *h = Heapfy(A,B,n);

    int i,j;
    int temp;

    int original_size = h->tamanhoAtual;

    for(i = (h->tamanhoAtual - 1) ; i >= 1 ; i--){

        temp = h->A[0];
        h->A[0] = h->A[i];
        h->A[i] = temp;

        h->tamanhoAtual--;

        ReHeapDown(h,0);
        for (j = 0; j < 10; j++)
        {
          printf(" %d", A[j]);
        }
        printf("\n");
    }
    
    
    h->tamanhoAtual = original_size;
}

// Imprime o arranjo (na ordem que estiver)
void imprimirHeapArray(HEAP* h){
  int tamanho;
  int i;
  tamanho = h->tamanhoAtual;
  for (i=0;i<tamanho;i++) 
  {
    printf("%d %d\n",h->A[i], h->B[i]);
  }
}
void HeapInt(HEAP* h, int * v){
  int tamanho;
  int i;
  tamanho = h->tamanhoAtual;
  for (i=0;i<tamanho;i++) v[i] = h->A[i];
  printf("\n");
}
void imprimirArray(int* A,int n){
    int i;
    
    for(i = 0 ; i<n ; i++){
        printf("%d ",A[i]);
    }
        
    printf("\n");
}

int percursoPreOrdem(HEAP* h, int atual){
  if (atual < h->tamanhoAtual){
    printf("%i ", h->A[atual]);
    percursoPreOrdem(h, filhoEsquerda(atual));
    percursoPreOrdem(h, filhoDireita(atual));
  }
}

int alturaHeap(HEAP* h){
  int altura = -1;
  int i = 1;
  while (i <= h->tamanhoAtual){
    i = filhoEsquerda(i);
    altura++;
  }
  return altura;
}

