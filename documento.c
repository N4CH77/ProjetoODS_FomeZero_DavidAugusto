// -- Bibliotecas utilizadas --
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "documento.h"

// 1. [CRIAR]
void criarDocumento() {

struct Documento novoDocumento;
FILE *arquivo;

printf("\n--Criando um novo Documento--\n");

getchar();

// --- Pedindo os dados ---
printf("Digite o CPF (numero): ");
fgets(novoDocumento.cpf, 15, stdin);
novoDocumento.cpf[strcspn(novoDocumento.cpf, "\n")] = '\0';

printf("Digite o Nome: ");
fgets(novoDocumento.nome, 100, stdin);

printf("Digite a idade (numero): ");
scanf("%d", &novoDocumento.idade);

getchar();

printf("Digite o sexo (masculino/feminino): ");
fgets(novoDocumento.sexo, 20, stdin);
novoDocumento.sexo[strcspn(novoDocumento.sexo, "\n")] = '\0';

// ___ Abertura de arquivo ___
arquivo = fopen("documento.txt", "a");

if (arquivo == NULL) {
    printf("ERRO! Nao foi possivel abrir o arquivo.\n");
    return;
}

// ___ Dados do arquivo ___
fprintf(arquivo, "Cpf: %s\n", novoDocumento.cpf);
fprintf(arquivo, "Nome: %s\n", novoDocumento.nome);
fprintf(arquivo, "Idade: %d\n", novoDocumento.idade);
fprintf(arquivo, "Sexo: %s\n", novoDocumento.sexo);
fprintf(arquivo, "---------------------\n");

fclose(arquivo);

printf("\n>>> Documento salvo com sucesso no nosso banco de dados! <<<\n");
}

// 2. [LER]
void lerDocumentos() {
    FILE *arquivo;
    char linha[500];

// ___ Abertura de arquivo ___
arquivo = fopen("documento.txt", "r");

if (arquivo == NULL) {
    printf("\nERRO! Nao foi possivel abrir o arquivo.\n");
    printf("Talvez voce ainda nao criou seu documento?\n");
    return;
}

printf("\n--- TODOS OS DOCUMENTOS SALVOS ---\n\n");

while (fgets(linha, 500, arquivo) != NULL) {
        printf("%s", linha);
}

printf("\n--- FIM DOS DOCUMENTOS ---\n");

fclose(arquivo);
}

// 3. [ATUALIZAR]
void atualizarDocumento() {
    char cpfBusca[20];
    char novaLinha[500];
    int documentoEncontrado = 0;

    printf("\n--- Atualizar Documento ---\n");
    printf("\nDigite o CPF do documento que deseja atualizar: ");
    getchar();
    fgets(cpfBusca, 20, stdin);
    cpfBusca[strcspn(cpfBusca, "\n")] = '\0';

// ___ Abertura de arquivo ___
    FILE *arquivoOriginal = fopen("documento.txt", "r");
    FILE *arquivoTemp = fopen("documento_temp.txt", "w");

    if (arquivoOriginal == NULL || arquivoTemp == NULL) {
        printf("\nERRO! Nao foi possivel abrir o arquivo.\n");
        return;
    }

    while (fgets(novaLinha, 500, arquivoOriginal) != NULL) {
        
        if (strstr(novaLinha, cpfBusca) != NULL) {
            documentoEncontrado = 1;
            printf("\nDocumento encontrado! Insira os novos dados:\n");

            struct Documento docAtualizado;

            printf("Digite o novo Nome: ");
            fgets(docAtualizado.nome, 100, stdin);
            docAtualizado.nome[strcspn(docAtualizado.nome, "\n")] = '\0'; 

            printf("Digite a nova idade (numero): ");
            scanf("%d", &docAtualizado.idade);
            getchar();

            printf("Digite o novo sexo (masculino/feminino): ");
            fgets(docAtualizado.sexo, 20, stdin);
            docAtualizado.sexo[strcspn(docAtualizado.sexo, "\n")] = '\0'; 

            fprintf(arquivoTemp, "Cpf: %s\n", cpfBusca); 
            fprintf(arquivoTemp, "Nome: %s\n", docAtualizado.nome);
            fprintf(arquivoTemp, "Idade: %d\n", docAtualizado.idade);
            fprintf(arquivoTemp, "Sexo: %s\n", docAtualizado.sexo);
            fprintf(arquivoTemp, "---------------------\n");

            for (int i = 0; i < 4; i++) {
                fgets(novaLinha, 500, arquivoOriginal);
            }
        } else {
            fputs(novaLinha, arquivoTemp);
        }
    } 

    fclose(arquivoOriginal);
    fclose(arquivoTemp);

    remove("documento.txt");
    rename("documento_temp.txt", "documento.txt");
    
    if (documentoEncontrado) {
        printf("\n>>> Documento atualizado com sucesso! <<<\n");
    } else {
        printf("\n>>> Documento com CPF %s nao encontrado. <<<\n", cpfBusca);
    }
} 

// 0. LIMPAR TELA
void limparTela() {
    #ifdef _WIN32
        system("cls");
    #endif
}