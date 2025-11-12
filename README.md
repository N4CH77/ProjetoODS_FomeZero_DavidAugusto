# Projeto CRUD em C
![Linguagem C](https://img.shields.io/badge/Linguagem-C-00599C?style=for-the-badge&logo=c&logoColor=white)

> Versão: 2.0.0 (Código Modularizado | Funções C-R-U)

Este é um projeto de CRUD (Create, Read, Update, Delete) feito em linguagem C. Ele foi desenvolvido como um exercício para a matéria BASES DE PROGRAMAÇÃO do curso de Engenharia de Computação da UniJorge.

O programa simula o cadastro de documentos (CPF, Nome, Idade, Sexo) em uma empresa e salva os dados em um arquivo `documento.txt`.

---

## Arquitetura
Este projeto evoluiu de um script de arquivo único para uma arquitetura modular profissional, seguindo o princípio da "Separação de Preocupações".

* documento.h: Define a struct Documento e os protótipos de todas as funções.

* documento.c: Contém a implementação real de toda a lógica do CRUD (criarDocumento, lerDocumentos, atualizarDocumento, etc.).

* main.c: Ficou limpo e agora serve apenas como o "menu" (switch case) que chama as funções do "motor".

* Makefile: Automatiza o processo de compilação dos múltiplos arquivos-fonte.

---

## Tecnologias Utilizadas

* **Linguagem:** C
* **Compilador:** GCC (MinGW-w64)
* **Build**: Make

---

## Funcionalidades
**[1] Criar**: ✅ Implementado! - Adiciona um novo documento ao `documento.txt`.

**[2] Ler**: ✅ Implementado! - Lê e exibe todos os documentos salvos.

**[3] Atualizar**: ✅ Implementado! - Permite editar um documento existente, buscando pelo CPF.

**[4] Deletar**: (Planejado - Próximo passo)

**[5] Sair**: ✅ Implementado! - Encerra o programa.

---

## Demonstração
<img width="1126" height="900" alt="Captura de tela 2025-11-12 150757" src="https://github.com/user-attachments/assets/bd4ac148-dd72-4a78-a53c-30f267fe7298" />

---

## Desafios & Soluções
Durante o desenvolvimento, alguns desafios interessantes surgiram:

1.  **`int` vs `char[]` para CPF:** O CPF foi implementado como `char[20]` (texto) e não `int` (número).
    * **Problema:** Um `int` de 32 bits não armazena os 11 dígitos de um CPF (o limite é ~2.14 bilhões).
    * **Solução:** Tratar o CPF como um texto (`char[]`) resolve o problema de tamanho e permite salvar formatação (pontos e traço).

2.  **`scanf` vs `fgets` (Buffer do Teclado):**
    * **Problema:** O `scanf("%d", ...)` usado para ler a opção do menu e a idade deixava um `\n` (Enter) "sobrando" no buffer do teclado.
    * **Solução:** A função `getchar()` foi usada estrategicamente após cada `scanf` para "consumir" esse `\n` e limpar o buffer, permitindo que o `fgets()` seguinte funcionasse corretamente para ler os textos.
3. **Atualização de Arquivos (`temp.txt`)**: Para implementar a função "Atualizar", foi preciso criar uma lógica de "arquivo temporário": ler o original, escrever as mudanças em um `temp.txt` e, no final, remover() o original e renomear() o temporário.
---

## Como Compilar e Rodar

1.  Você precisa ter um compilador C (como o GCC) instalado.
2.  Abra o terminal e navegue até a pasta do projeto.
3.  Metódo 1 (Recomendado - via Makefile):
    ```bash
    make
    ```
4.  Metódo 2 (Manual):
    ```bash
    gcc -o crud.exe main.c documento.c
    ```
5.  Execute o programa:
    * No Linux/Mac: `./crud`
    * No Windows: `crud.exe`

---

## Autor

* **David Augusto (N4CH77)**
* [LinkedIn](https://www.linkedin.com/in/n4ch77/)
* [GitHub](https://github.com/N4CH77)
