#include "ListaCabCau.h"
#include "Noticia.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void criarListaCab(ListaCab* l){
    l->cab = (NoListaCab*) malloc(sizeof(NoListaCab));
    l->cau = (NoListaCab*) malloc(sizeof(NoListaCab));
    l->cab->prox = l->cau;
    l->cau->prox = NULL;
}

int estaVaziaCab(ListaCab* l){
    return (l->cab->prox == l->cau);
}

void InsereInicioCab(ListaCab* l, Noticia n){
    NoListaCab* novo = (NoListaCab*) malloc(sizeof(NoListaCab));
    
    if (novo != NULL) {
        novo->info = n;
        if (!estaVazia(l)) {
            novo->prox = l->cab->prox;
        }
        else {
            novo->prox = l->cau;
        }
        l->cab->prox = novo;
    }
}

void removerPorId(ListaCab* l, int id) {
    NoListaCab* p;
    NoListaCab* ant = l->cab;
    for (p = l->cab->prox; p->info.id != id && p != l->cau; p = p->prox) {
        ant = p;
    }
    if (p == l->cau) {
        printf("Noticia nao encotrada!\n");
    }
    else {
        ant->prox = p->prox;
        free(p);
    }
}

void buscarNoticiasCab(ListaCab* l, char* palavra){
    NoListaCab* p = l->cab->prox;

    int achou = 0;

    while(p != l->cau) {

        if(strstr(p->info.titulo, palavra) != NULL ||  strstr(p->info.conteudo, palavra) != NULL) {
            imprimirNoticia(&(p->info));
           

            achou = 1;
        }
         
        p = p->prox;                
    }    

    if(!achou) {
        printf("Nenhuma noticia encontrada!\n");
    }      
}

void imprimirListaCab(ListaCab* l){
    if(!estaVazia(l)){
        NoListaCab* p;
        for(p = l->cab->prox; p != l->cau; p = p->prox){
            imprimirNoticia(p);
        }
        printf("\n");
    }else{
        printf("Esta Vazio!\n");
    }
}


int qtdPendente(ListaCab* l) {
    int qtd = 0;
    for (NoListaCab* p = l->cab->prox; p != l->cau; p = p->prox) {
        qtd++;
    }
    return qtd;
}







