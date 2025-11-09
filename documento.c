// -- Bibliotecas utilizadas --
#include <stdio.h>
#include <stdlib.h>

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

printf("Digite o Nome: ");
fgets(novoDocumento.nome, 100, stdin);

printf("Digite a idade (numero): ");
scanf("%d", &novoDocumento.idade);

getchar();

printf("Digite o sexo (masculino/feminino): ");
fgets(novoDocumento.sexo, 20, stdin);

// ___ Abertura de arquivo ___
arquivo = fopen("documento.txt", "a");

if (arquivo == NULL) {
    printf("ERRO! Nao foi possivel abrir o arquivo.\n");
    return;
}

// ___ Dados do arquivo ___
fprintf(arquivo, "Cpf: %s", novoDocumento.cpf);
fprintf(arquivo, "Nome: %s", novoDocumento.nome);
fprintf(arquivo, "Idade: %d\n", novoDocumento.idade);
fprintf(arquivo, "Sexo: %s", novoDocumento.sexo);
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

// 0. LIMPAR TELA
void limparTela() {
    #ifdef _WIN32
        system("cls");
    #endif
}