#define MAX_CHAMADOS 100

typedef struct {
int codigo;
char setor[50];
char solicitante[50];
struct tm horario;
} Chamado;

Chamado chamados[MAX_CHAMADOS];
    int totalChamados = 0;

    void exibirHoraAtual() {
    time_t agora = time(NULL);
    struct tm *horaAtual = localtime(&agora);
    printf("Data e hora atual: %02d/%02d/%04d %02d:%02d\n\n",
           horaAtual->tm_mday, horaAtual->tm_mon + 1, horaAtual->tm_year + 1900,
           horaAtual->tm_hour, horaAtual->tm_min, horaAtual->tm_sec);
}

    void cadastrarChamado() {
    if (totalChamados < MAX_CHAMADOS) {
        Chamado novoChamado;
        printf("Digite o tipo de ocorrencia:\n");
        printf("911 - Falha de conexao - Internet\n");
        printf("912 - Problema com impressora\n");
        printf("913 - Usuario sem senha\n");
        printf("914 - Problemas na rede interna\n");
        printf("915 - Computador nao liga\n");
        scanf("%d", &novoChamado.codigo);
        getchar();

        if (novoChamado.codigo >= 911 && novoChamado.codigo <= 915) {
            printf("Digite o setor ou departamento: ");
            fgets(novoChamado.setor, 50, stdin);
            novoChamado.setor[strcspn(novoChamado.setor, "\n")] = 0;

            printf("Digite o nome do solicitante: ");
            fgets(novoChamado.solicitante, 50, stdin);
            novoChamado.solicitante[strcspn(novoChamado.solicitante, "\n")] = 0;

            time_t agora = time(NULL);
            novoChamado.horario = *localtime(&agora);

            chamados[totalChamados++] = novoChamado;
            printf("Chamado cadastrado com sucesso\n");
            }
        else {
            printf("Opcao invalida.\n");
        }
    }
        else {
        printf("Limite de chamados atingido.\n");
    }
}

void exibirTotalChamados() {
    printf("Total de chamados do dia: %d\n", totalChamados);
}

void exibirOcorrenciaMaisSolicitada() {
    int contadores[916] = {0}, maxOcorrencias = 0, tipoMaisSolicitado = 0;

    for (int i = 0; i < totalChamados; i++) {
        contadores[chamados[i].codigo]++;
    }

    for (int i = 911; i <= 915; i++) {
        if (contadores[i] > maxOcorrencias) {
            maxOcorrencias = contadores[i];
            tipoMaisSolicitado = i;
        }
    }

    printf("Tipo de ocorrencia mais solicitada: %d com %d chamados.\n", tipoMaisSolicitado, maxOcorrencias);
}

    void listarChamados() {
    FILE *arquivo = fopen("chamados.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo para escrita.\n");
        return;
    }

    printf("Lista de chamados cadastrados:\n");
    for (int i = 0; i < totalChamados; i++) {
        fprintf(arquivo, "Codigo: %d\nSetor: %s\nSolicitante: %s\nData: %02d/%02d/%04d\nHora: %02d:%02d\n\n",
                chamados[i].codigo, chamados[i].setor, chamados[i].solicitante,
                chamados[i].horario.tm_mday, chamados[i].horario.tm_mon + 1, chamados[i].horario.tm_year + 1900,
                chamados[i].horario.tm_hour, chamados[i].horario.tm_min, chamados[i].horario.tm_sec);

        printf("Codigo: %d\nSetor: %s\nSolicitante: %s\nData: %02d/%02d/%04d\nHora: %02d:%02d\n\n",
               chamados[i].codigo, chamados[i].setor, chamados[i].solicitante,
               chamados[i].horario.tm_mday, chamados[i].horario.tm_mon + 1, chamados[i].horario.tm_year + 1900,
               chamados[i].horario.tm_hour, chamados[i].horario.tm_min, chamados[i].horario.tm_sec);
    }

    fclose(arquivo);
    printf("Chamados salvos em 'chamados.txt'.\n");
}
