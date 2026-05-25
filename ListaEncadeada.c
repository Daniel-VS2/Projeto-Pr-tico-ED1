#include "ListaEncadeada.h"
#include "Noticia.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void criarListaEncad(ListaEncad** l){
     *l=NULL;
}

int estaVazioEncad(ListaEncad** l){
    return *l == NULL;
}

void imprimeListaEncad(ListaEncad** l){
    if(!estaVazio(l)){
        for(ListaEncad* p = *l;p!=NULL;p = p->prox){
            imprimirNoticia(p->info);
        } printf("\n");
    } else{
        printf("Esta Vazia \n");
    }
}

void insereNoinicioEncad(ListaEncad** l, Noticia* v){
    ListaEncad* novo = (ListaEncad*) malloc(sizeof(ListaEncad));
    if(novo != NULL){
        novo->info = v;
        novo->prox = *l;
        *l = novo;

    }
    else printf("Nao foi possivel alocar memoria!");
}

void liberarListaEncad(ListaEncad** l){
    ListaEncad *p, *temp;
    for(p = *l; p!=NULL ; p=temp){
        temp = p->prox;
        liberarNoticia(p->info);
        free(p);
    }
    *l = NULL;
}

void removerPorPalavra(ListaEncad** l, char* palavra) {

    ListaEncad* ant = NULL;
    ListaEncad* p; 

    for(p = *l; p != NULL && strstr(p->info->titulo, palavra) == NULL &&
           strstr(p->info->conteudo, palavra) == NULL; p = p->prox)
        ant = p;
    if(p == NULL){
        printf("Elemento não encontrado.");
        }
    else{
        if(ant == NULL){
            *l = p->prox;
        }
        else{
            ant->prox = p->prox;
            free(p);
        }
    }
}

ListaEncad* buscaNoticiaEncad(ListaEncad **l, Noticia* v){
    if(!estaVazio(l)){
        for(ListaEncad*p = *l;p!=NULL;p = p->prox){
            if(p->info == v)
                return p;
        } 
        printf("Não encontrado!");
        return NULL;
    } else{
        printf("Esta Vazia \n");
        return NULL;
    }
}

ListaEncad* ultimaNoticiaEncad(ListaEncad** l){
    ListaEncad *p, *ant=NULL;
    
    for(p = *l;p!=NULL;p=p->prox){
        ant = p;
    }
    return ant;
}

int qtdConfiavel(ListaEncad** l){
    int qtd = 0;
    for(ListaEncad*p = *l; p !=NULL; p = p->prox){
        if(p->info->classificacao == Confiavel){
            qtd++;;
        }

    }
    return qtd;
    
}

int qtdSuspeita(ListaEncad ** l) {
    int qtd = 0;
    for (ListaEncad* p = *l; p != NULL; p = p->prox) {
        if (p->info->classificacao == Suspeita)
            qtd++;
    }
    return qtd;
}