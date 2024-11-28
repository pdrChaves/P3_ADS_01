#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Funções/funcoes.h"

int main() {
    int opcao;

    do {
        printf("\n=== Bem-vindo ao HelpDesk ===\n\n");
        printf("=== Menu Principal ===\n");
        printf("1. Lancar Chamados\n");
        printf("2. Exibir total de ocorrencias do dia\n");
        printf("3. Exibir ocorrencia mais solicitada\n");
        printf("4. Listar arquivo TXT com ocorrencias\n");
        printf("5. Finalizar programa\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        printf("\n");

        switch (opcao) {
            case 1:
                cadastrarChamado();
                break;
            case 2:
                printf("Total de chamados do dia: %d\n", totalChamados);
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
                printf("Opcao invalida!\n");
        }
    } while (opcao != 5);

    return 0;
}
