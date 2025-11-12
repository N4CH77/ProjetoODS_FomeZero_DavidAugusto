// -- Bibliotecas utilizadas --
#include <stdio.h>
#include <stdlib.h>

#include "documento.h"

// -- Opções (CRIAR, LER, ATUALIZAR, DELETAR E SAIR) --
int main() {
    int opcoes;
    while (1)
    {
        limparTela();
        printf("\nOpcoes:\n");
        printf("1 - Criar\n");
        printf("2 - Ler\n");  
        printf("3 - Atualizar\n");
        printf("4 - Deletar\n");
        printf("5 - Sair\n");
        printf("Escolha uma opcao: ");

        scanf("%d", &opcoes);

    switch (opcoes)
    {
        case 1:
            criarDocumento();
            break;
        case 2:
            lerDocumentos();
            break;
        case 3:
            atualizarDocumento();
            break;
        case 4:
            printf("\n>>> Você escolheu DELETAR\n");
            break;
        case 5:
            printf("\n>>> Saindo...\n");
            exit(0);    
        default:
            printf("\n>>> Opção inválida! Tente novamente.\n");
            break;
            }

    }
    return 0; 
}

