#include <stdio.h>
#include <stdlib.h>
#include "Noticia.h"

static int id = 1;

Noticia* criarNoticia() {
    Noticia* nova = (Noticia*) malloc(sizeof(Noticia));
    if (nova == NULL) {
        printf("Erro de alocacao!\n");
    }
    else {
        nova->id = id;
        id++;
        
        printf("Escreva a data da noticia: ");
        scanf(" %[^\n]", nova->data);

        printf("Escreva o Titulo: ");
        scanf(" %[^\n]", nova->titulo);

        printf("Escreva o conteudo: ");
        scanf(" %[^\n]", nova->conteudo);

        printf("Escreva a fonte: ");
        scanf(" %[^\n]", nova->fonte);

        nova->classificacao = EmAnalise;

        return nova;
    }
}

void imprimirNoticia(Noticia *n){
    if (n == NULL) 
        return;

    printf("\n==================================\n");
    printf("ID: %d\n", n->id);
    printf("Titulo: %s\n", n->titulo);
    printf("Data: %s\n", n->data);
    printf("Fonte: %s\n", n->fonte);
    printf("-------------------------------------\n");
    printf("Conteudo:\n %s\n", n->conteudo);
    printf("-------------------------------------\n");
    printf("Status: ");
    switch(n->classificacao) {
        case EmAnalise: 
            printf("Em Analise\n"); 
            break;
        case Confiavel: 
            printf("Confiavel\n");
            break;
        case Suspeita:
            printf("Suspeita\n");
            break;
    }
    printf("===================================\n");

}

void liberarNoticia(Noticia* n){
    if (n != NULL) {
        free(n);
    }
}