#ifndef LISTACABCAU_H
#define LISTACABCAU_H
#include "Noticia.h"

typedef struct nolistacab{
    Noticia info;
    struct nolistacab* prox;
}NoListaCab;

typedef struct lista{
    NoListaCab* cab;
    NoListaCab* cau;
} ListaCab;

void criarListaCab(ListaCab* l);

int estaVaziaCab(ListaCab* l);

void InsereInicioCab(ListaCab* l, Noticia v);

void removerPorId(ListaCab* l, int id);

void buscarNoticiasCab(ListaCab* l, char* palavra);

void imprimirListaCab(ListaCab* l);

int qtdPendente(ListaCab* l);

#endif