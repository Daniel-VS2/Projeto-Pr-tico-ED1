#ifndef NOTICIA_H
#define NOTICIA_H

typedef enum {
    EmAnalise, //0
    Confiavel, //1
    Suspeita   //2
} Classificacao;

typedef struct noticia {
    int id;
    char data[11];
    char titulo[40];
    char conteudo[100];
    char fonte[40];
    Classificacao classificacao;

} Noticia;

Noticia* criarNoticia();

void imprimirNoticia(Noticia *n);

void liberarNoticia(Noticia *n);

#endif 