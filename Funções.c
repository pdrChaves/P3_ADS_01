Chamado;

Chamado chamados[MAX_CHAMADOS];
int totalChamados = 0;

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
        if  (novoChamado.codigo == 911 || novoChamado.codigo == 912 ||
            novoChamado.codigo == 913 || novoChamado.codigo == 914 ||
            novoChamado.codigo == 915){
        printf("Digite o setor ou departamento: ");
        fgets(novoChamado.setor, 50, stdin);
        novoChamado.setor[strcspn(novoChamado.setor, "\n")] = 0;

        printf("Digite o nome do solicitante: ");
        fgets(novoChamado.solicitante, 50, stdin);
        novoChamado.solicitante[strcspn(novoChamado.solicitante, "\n")] = 0;


        chamados[totalChamados++] = novoChamado;
        printf("Chamado cadastrado com sucesso!\n");
}
        else if ((chamados !=911) || (912) || (913) || (914) || (915)) {
            printf("Opcao invalida. \n");
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
        struct tm *tempo;
        time_t mytime;
        mytime = time(NULL);
        struct tm tm = *localtime(&mytime);
        printf("Data: %d/%d/%d\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);

        fprintf(arquivo, "Código: %d, Setor: %s, Solicitante: %s, Data: %d, Hora: %d \n",
                chamados[i].codigo, chamados[i].setor, chamados[i].solicitante);

        printf("Código: %d, Setor: %s, Solicitante: %s, Data: %d, Hora: %d \n",
               chamados[i].codigo, chamados[i].setor, chamados[i].solicitante);

    }

    fclose(arquivo);
    printf("Chamados salvos em 'chamados.txt'.\n");
}
