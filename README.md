# Gerenciador de Tarefas em C

## Autor
Matheus Ferreira de Freitas [24.123.080.4]

## Descrição do Projeto
Este projeto implementa um sistema básico de gerenciamento de tarefas em linguagem C. Ele foi projetado para oferecer funcionalidades essenciais para o gerenciamento de uma lista de tarefas, incluindo adicionar, listar, modificar, excluir, salvar e carregar tarefas, bem como filtrar e exportar tarefas com base em critérios específicos.

## Estrutura do Código
O projeto consiste em três arquivos principais:

- `main.c`: Este arquivo contém a função principal (`main`) que executa o programa. Ele oferece um menu de interface do usuário para interagir com o sistema e chama as funções correspondentes com base na escolha do usuário.
- `biblioteca.h`: Define a estrutura `Tarefa` e declara todas as funções usadas no projeto. Essa abordagem modular facilita a organização e a manutenção do código.
- `biblioteca.c`: Contém as implementações das funções declaradas em `biblioteca.h`. As funções aqui permitem manipular as tarefas, como adicionar ou remover tarefas da lista, bem como salvar e carregar o estado atual das tarefas em um arquivo.

## Funcionamento do Código
- **Cadastrar Tarefa**: O usuário pode adicionar novas tarefas, especificando detalhes como descrição, categoria, prioridade e estado.
- **Listar Tarefas**: Exibe todas as tarefas cadastradas, junto com seus detalhes.
- **Alterar/Deletar Tarefa**: Permite ao usuário modificar ou remover tarefas existentes.
- **Salvar/Carregar Tarefas**: Salva o estado atual das tarefas em um arquivo e carrega tarefas de um arquivo, respectivamente.
- **Filtrar Tarefas**: Oferece a opção de visualizar tarefas com base em prioridade, estado ou categoria.
- **Exportar Tarefas**: Exporta as tarefas filtradas para um arquivo de texto, facilitando a visualização e compartilhamento.

## Considerações Finais
Orientado pelo professor Leonardo Anjoletto Ferreira, este projeto foi desenvolvido com o objetivo de praticar conceitos básicos de programação em C, estruturas de dados e manipulação de arquivos. Ele serve como um exemplo prático de como um sistema simples pode ser estruturado e implementado em C.

---