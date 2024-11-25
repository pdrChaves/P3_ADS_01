#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Funções/funcoes.h"

int main() {
    int opcao;
    char tip_ocorr;

    do {
        printf("\n===Bem-vindo ao HelpDesk ===\n");
        printf("\n=== Menu Principal ===\n");
        printf("1. Lancar Chamados\n");
        printf("2. Exibir total de ocorrencias do dia\n");
        printf("3. Exibir ocorrencia mais solicitada\n");
        printf("4. Listar arquivo TXT com ocorrencias\n");
        printf("5. Finalizar programa\n");
        printf("Escolha uma opcao:");
        scanf("%d", &opcao);
        printf("\n");

        switch (opcao) {
            case 1:
                cadastrarChamado();
                    switch(opc){
             case 911:
        printf("\nVoce escolheu 911 - Falha de conexao.\n");
            break;
        case 912:
        printf("\nVoce escolheu 912 - Problema com impressora.\n");
            break;
        case 913:
        printf("\nVoce escolheu 913 - Usuario sem senha.\n");
            break;
        case 914:
        printf("\nVoce escolheu 914 - Problemas na rede interna.\n");
            break;
        case 915:
        printf("\nVoce escolheu 915 - Computador nao liga.\n");
            break;
                    }
            case 2:
                exibirTotalChamados();
                break;
            case 3:
                exibirOcorrenciaMaisSolicitada();
                break;
            case 4:
                listarChamados();
                break;
            case 5:
                printf("Encerrando programa...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while(opcao != 5);

    return (0);
}
