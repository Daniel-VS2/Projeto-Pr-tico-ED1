#include <stdio.h>
#include <stdlib.h>
#include "Noticia.h"
#include "ListaCabCau.h"
#include "ListaEncadeada.h"

int main(void){
    
    int opcao;
    
    ListaCab lista_pendentes;
    ListaEncad* lista_verificadas;

    criarListaCab(&lista_pendentes);
    criarListaEncad(&lista_verificadas);
    
    do{

        printf(
        "----------------MENU------------------\n"
        "1 - Adicionar nova noticia\n"
        "2 - Remover noticia pendente por id\n"
        "3 - Remover noticia verificada por palavra-chave\n"
        "4 - Buscar noticias pendentes por palavra-chave\n"
        "5 - Imprimir as noticias\n"
        "6 - Classificar noticias\n"
        "7 - Imprimir quantidade de noticias por categoria\n"
        "8 - Sair\n"
        "Escolha uma opcao:\n"
        "--------------------------------------\n"
        );

        scanf("%d", &opcao);
        printf("\n");

        switch(opcao) {

            case 1: {
                Noticia* nova = criarNoticia();
                if (nova != NULL) {
                    InsereInicioCab(&lista_pendentes, *nova);
                    liberarNoticia(nova);
                }
                break;
            }
            case 2: { //remover noticia pendente por id
                int id;
                printf("Digite o id da noticia: ");
                scanf("%d", &id);
                removerPorId(&lista_pendentes, id);
                break;
            }
            case 3: { //remover verificada
                if(!estaVazioEncad(&lista_verificadas)){
                    char palavra[30];
                    printf("Digite a palavra chave: ");
                    scanf("%s", &palavra);
                    removerPorPalavra(&lista_verificadas, palavra);
                }
                else { 
                    printf("A lista esta vazia!");
                }
                break;
            }
            case 4: { // buscar pendente
                char palavra[30];
                printf("Digite a palavra chave: ");
                scanf("%s", &palavra);
                buscarNoticiasCab(&lista_pendentes, palavra);
                break;
            }
            case 5: {//imprimir 
                int notic;
                do { 
                    printf("Escolha quais noticias imprimir [1 - pendentes, 2 - verificadas, 3 - ambas]: ");
                    scanf("%d", &notic);
                    if (notic == 1) {
                        imprimirListaCab(&lista_pendentes);
                    }
                    else if (notic == 2) {
                        imprimeListaEncad(&lista_verificadas);
                    }
                    else if (notic == 3) {
                        imprimirListaCab(&lista_pendentes);
                        imprimeListaEncad(&lista_verificadas);
                    }
                } while (notic != 1 && notic != 2 && notic != 3);
                break;
            }
            case 6: { //classifcar 
                NoListaCab* p;
                NoListaCab* prox; 

                if (estaVaziaCab(&lista_pendentes)) {
                    printf("Nao ha noticias pendentes");
                    break;
                }

                for (p = lista_pendentes.cab->prox; p != lista_pendentes.cau; p = prox) {
                    prox = p->prox;
                    
                    printf("Analise a seguinte noticia:\n");
                    imprimirNoticia(&(p->info));

                    int classe;
                    do {
                        printf("Classificacao [1 - EmAnalise, 2 - Confiavel, 3 - Suspeita]: ");
                        scanf("%d", &classe);
                    } while (classe != 1 && classe != 2 && classe != 3);

                    if (classe == 2 || classe == 3) {
                        Noticia* nova_verificada = (Noticia*) malloc(sizeof(Noticia));
                        *nova_verificada = p->info;

                        if (classe == 2) {
                            nova_verificada->classificacao = Confiavel;
                        }
                        if (classe == 3) {
                            nova_verificada->classificacao = Suspeita;
                        }

                        insereNoinicioEncad(&lista_verificadas, nova_verificada);

                        removerPorId(&lista_pendentes, p->info.id);
                    }
                    else {
                        printf("Noticia nao classificada\n");
                    }
                }
                break;
            } 

            case 7: { // imprimir qtd de noticia por categoria
                    printf(
                        "Noticias:\n"
                        "Pendentes: %d\n"
                        "Confiaveis: %d\n"
                        "Suspeitas: %d\n",

                        qtdPendente(&lista_pendentes),
                        qtdConfiavel(&lista_verificadas),
                        qtdSuspeita(&lista_verificadas)
                    );
                    break;
            }
            case 8: {
                printf("Encerrando programa...\n");
                break;
            }
        }
    } while (opcao != 8);
    return 0;
}