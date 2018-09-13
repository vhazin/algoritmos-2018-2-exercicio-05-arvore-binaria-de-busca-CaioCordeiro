#include <stdio.h>
#include <stdlib.h>
struct No{
    int info;
    struct No *esquerda;
    struct No *direita;
    struct No *pai;

};
struct No *criararvore(int info){
    struct No *raiz;
    raiz = (struct No *) malloc(sizeof(struct No));
    raiz->info = info;
    raiz->esquerda = NULL;
    raiz->direita = NULL;
    return raiz; 
}
struct No *inserir(int info,struct No *arvore){
    
    if(arvore==NULL){
        arvore=criararvore(info);
    }
    else if(info<arvore->info){
        arvore->esquerda = inserir(info,arvore->esquerda);
        arvore->esquerda->pai = arvore;
    }
    else{
        arvore->direita = inserir(info, arvore->direita);
        arvore->direita->pai = arvore;
    }
    return arvore;
}
int preordem(struct No *x){
    if(x!= NULL){
        printf(" %d",x->info);
        preordem(x->esquerda);
        preordem(x->direita);
    }
    return 0;
}
int inordem(struct No *x){
    if(x!=NULL){
        inordem(x->esquerda);
        printf(" %d",x->info);
        inordem(x->direita);
    }
}
int posordem(struct No *x){
    if(x!=NULL){
        posordem(x->esquerda);
        posordem(x->direita);
        printf(" %d",x->info);
    }
}
int main(){
 int c;
 int i = 0;
 int j = 0;
 int n;
 int values;
 struct No *arv=NULL;


    scanf("%d",&c);
    while(i<c){
        printf("Case %d:",(i+1));
        printf("\n");
        scanf("%d",&n);
        while(j<n){
            scanf("%d",&values);
            arv = inserir(values,arv);
            j=j+1;
        }
    printf("Pre.:");
    preordem(arv);
    printf("\n");
    printf("In..:");
    inordem(arv);
    printf("\n");
    printf("Post:");
    posordem(arv);
    printf("\n");
    printf("\n");
    arv = NULL;
    j = 0;
    i=i+1;
    }
    return 0;
}
