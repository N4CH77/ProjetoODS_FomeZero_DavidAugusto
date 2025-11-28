# Sistema de Gestão de Beneficiários (ODS 2 - Fome Zero)
![Linguagem C](https://img.shields.io/badge/Linguagem-C-00599C?style=for-the-badge&logo=c&logoColor=white)

> Versão: 2.1.0 (Código Modularizado | Funções C-R-U | Fome Zero)

Este projeto é um sistema de gestão (CRUD) desenvolvido em linguagem C como parte da disciplina **BASES DE PROGRAMAÇÃO** do curso de Engenharia de Computação da UniJorge.

O software foi projetado para atender ao **ODS 2 (Fome Zero e Agricultura Sustentável)** da ONU, simulando o cadastro e controle de beneficiários para uma ação social de distribuição de alimentos. Os dados são persistidos em um arquivo `beneficiario.txt`.

---

## Arquitetura
Este projeto evoluiu de um script de arquivo único para uma arquitetura modular profissional, seguindo o princípio da "Separação de Preocupações".

* **`beneficiario.h`:** Define a `struct Beneficiario` e os protótipos das funções, servindo como interface pública.
* **`beneficiario.c`:** Contém a implementação real da lógica de negócios (cadastrar, listar, atualizar, lógica de arquivos).
* **`main.c`:** Serve apenas como ponto de entrada e gerenciamento do menu, delegando a lógica para o motor.
* **`Makefile`:** Automatiza o processo de compilação dos múltiplos arquivos.

---

## Tecnologias Utilizadas

* **Linguagem:** C (Padrão ANSI/C99)
* **Compilador:** GCC (MinGW-w64)
* **Build System:** Make
* **Controle de Versão:** Git & GitHub

---

## Funcionalidades
* **[1] Cadastrar Beneficiário:** ✅ **Implementado!** - Adiciona um novo registro ao banco de dados `beneficiario.txt`.
* **[2] Listar Beneficiários:** ✅ **Implementado!** - Lê o arquivo e exibe todos os beneficiários cadastrados.
* **[3] Atualizar Dados:** ✅ **Implementado!** - Permite corrigir dados de um beneficiário buscando pelo CPF.
* **[4] Deletar Registro:** (Planejado - Próximo passo)
* **[5] Sair:** ✅ **Implementado!** - Encerra a execução com segurança.
---

## Demonstração
<img width="1005" height="900" alt="Captura de tela 2025-11-26 095326" src="https://github.com/user-attachments/assets/26a058db-bab5-4751-b1f3-b9dd095cf42a" />


---

## Desafios & Soluções
Durante o desenvolvimento, enfrentei e resolvi desafios técnicos importantes:

1.  **Persistência de Dados (ODS):**
    * **Desafio:** Adaptar a lógica para um contexto social real.
    * **Solução:** Estruturação dos dados (`struct Beneficiario`) para armazenar CPF, Nome, Idade e Sexo, salvando tudo em modo *append* (`"a"`) no arquivo de texto.

2.  **Manipulação de Buffer (`scanf` vs `fgets`):**
    * **Problema:** A leitura de números inteiros (`scanf`) deixava um caractere de nova linha (`\n`) no buffer, que "pulava" a leitura dos nomes subsequentes.
    * **Solução:** Implementação estratégica da função `getchar()` para limpeza de buffer e uso de `strcspn` para sanitizar as strings lidas.

3.  **Atualização de Arquivos Sequenciais:**
    * **Problema:** Arquivos `.txt` não permitem edição direta de linhas no meio do arquivo.
    * **Solução:** Implementação de um algoritmo de "Arquivo Temporário": o sistema lê o original, copia os dados válidos para `temp.txt`, substitui o registro editado e, ao final, realiza a troca atômica dos arquivos (`remove` / `rename`).
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
