#ifndef DOCUMENTO_H
#define DOCUMENTO_H

// -- Estrutura para leitura ou criação do documento (CPF, nome, idade e sexo) da empresa --
struct Documento
{
    char cpf[20]; // "char" guarda um texto. No exemplo, 15 caracteres
    char nome[100];
    int idade; // "int" guarda números
    char sexo[20];
};

// -- Declaração das funções p/ main() [3 funções] --
void criarDocumento();
void lerDocumentos(); 
void atualizarDocumento();
void limparTela();

#endif