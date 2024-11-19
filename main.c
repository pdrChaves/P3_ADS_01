#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
    struct tm *data_hora_atual;

int main(){
    int tip_ocorr,data,dep;
    char nome_sol[50];

    printf("Bem-vindo ao HelpDesk \n\n");
    printf("Digite o tipo de ocorrencia:\n");
    printf("911 - Falha de conexao - Internet \n912 - Problema com impressora \n913 - Usuario sem senha \n914 - Problemas na rede interna \n915 - Computador nao liga\n");
    scanf("%d",&tip_ocorr);

    switch(tip_ocorr){
        case 911:
        printf("Voce escolheu 911 - Falha de conexao.\n");
            break;
        case 912:
        printf("Voce escolheu 912 - Problema com impressora.\n");
            break;
        case 913:
        printf("Voce escolheu 913 - Usuario sem senha.\n");
            break;
        case 914:
        printf("Voce escolheu 914 - Problemas na rede interna.\n");
            break;
        case 915:
        printf("Voce escolheu 915 - Computador nao liga.\n");
            break;
        default:
            printf("Opcao invalida.\n");
            break;
    }
        printf("Identifique o seu departamento:\n");
        printf("1 - Recepcao.\n");
        printf("2 - Equipe de T.I.\n");
        printf("3 - Financeiro.\n");
        printf("4 - Desenvolvedores.\n");
        printf("5 - Recursos Humanos.\n");
        scanf("%d",&dep);
        printf("Nome do solicitante do chamado:");
        getchar();
        fgets(nome_sol, sizeof(nome_sol), stdin);
        if (nome_sol[strlen(nome_sol)] == '\n') {
        nome_sol[strlen(nome_sol)] = '\0';
        }
        scanf("%c",&nome_sol);
            struct tm *tempo;
    time_t mytime;
        mytime = time(NULL);
    struct tm tm = *localtime(&mytime);
        printf("Data: %d/%d/%d\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
        printf("Ocorrencia registrada para o departamento %d.\n", dep);
        printf("Solicitante: %s\n", nome_sol);
        printf("Obrigado por usar o HelpDesk!\n");

    return (0);
}
