#ifndef LISTAENCADEADA_H
#define LISTAENCADEADA_H
#include "Noticia.h"

typedef struct listaencad {
    Noticia* info;
    struct listaencad* prox;
} ListaEncad;

void criarListaEncad(ListaEncad** l);

int estaVazioEncad(ListaEncad**l);

void imprimeListaEncad(ListaEncad**l);

void insereNoinicioEncad(ListaEncad** l, Noticia* v);

void liberarListaEncad(ListaEncad**l);

void removerPorPalavra(ListaEncad** l, char* palavra);

int qtdConfiavel(ListaEncad** l);

int qtdSuspeita(ListaEncad ** l);

ListaEncad* buscaNoticiaEncad(ListaEncad**l, Noticia* v);

ListaEncad*  ultimaNoticiaEncad(ListaEncad** l);

#endif