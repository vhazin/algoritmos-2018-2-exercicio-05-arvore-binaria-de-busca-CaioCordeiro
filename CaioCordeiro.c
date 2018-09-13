#include <stdio.h>
typedef struct Noo{
    int info;
    No *esquerda;
    No *direita;
    No *pai;
}No;
No *criararvore(int info,No* esq,No* dir){
    No *raiz;
    raiz = malloc(sizeof(No));
    raiz->info = info;
    raiz->esquerda = esq;
    raiz->direita = dir;
    esq->pai=raiz;
    dir->pai=raiz;
    return raiz; 
}
No *inserir(int info,No *arvore){
    if(info<arvore->info){
        arvore->esquerda = inserir(info,arvore->esquerda);
        arvore->esquerda->pai = arvore;
    }
    else{
        arvore->direita = inserir(info, arvore->direita);
        arvore->direita->pai = arvore;
    }
    return arvore;
}
