
#include "biblioteca.h"
#include <stdio.h>
#include <string.h>

// Limpa o buffer de entrada para evitar leituras incorretas nas entradas subsequentes.
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

// Permite ao usuário cadastrar uma nova tarefa, verificando se ainda há espaço no array.
void cadastrarTarefa(Tarefa *tarefas, int *numTarefas) {
    if (*numTarefas >= 100) {
        printf("Não é possível cadastrar mais tarefas!\n");
        return;
    }

    Tarefa novaTarefa;
    limparBuffer();// Limpa o buffer antes de ler strings para evitar problemas de leitura.
    printf("Descrição: ");
    fgets(novaTarefa.descricao, 299, stdin);
    printf("Categoria: ");
    fgets(novaTarefa.categoria, 99, stdin);
    printf("Prioridade: ");
    scanf("%d", &novaTarefa.prioridade);
    printf("Estado (0-Não Iniciado, 1-Em Andamento, 2-Completo): ");
    scanf("%d", (int *)&novaTarefa.estado);

    tarefas[*numTarefas] = novaTarefa;
    (*numTarefas)++;
}

// Lista todas as tarefas cadastradas, mostrando seus detalhes.
void listarTarefas(const Tarefa *tarefas, int numTarefas) {
    for (int i = 0; i < numTarefas; i++) {
        printf("%d - %s, %s, Prioridade: %d, Estado: %d\n", i, tarefas[i].descricao, tarefas[i].categoria, tarefas[i].prioridade, tarefas[i].estado);
    }
}

// Permite ao usuário deletar uma tarefa existente, reorganizando o array após a exclusão.
void deletarTarefa(Tarefa *tarefas, int *numTarefas) {
    int index;
    printf("Indique o índice da tarefa a ser deletada: ");
    scanf("%d", &index);

    if (index < 0 || index >= *numTarefas) {
        printf("Índice inválido!\n");
        return;
    }

    for (int i = index; i < *numTarefas - 1; i++) {
        tarefas[i] = tarefas[i + 1];
    }

    (*numTarefas)--;
}

// Salva todas as tarefas cadastradas em um arquivo binário.
void salvarTarefas(const char *filename, const Tarefa *tarefas, int numTarefas) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Erro ao abrir o arquivo");
        return;
    }
    fwrite(&numTarefas, sizeof(int), 1, file);
    fwrite(tarefas, sizeof(Tarefa), numTarefas, file);
    fclose(file);
}

// Carrega tarefas de um arquivo binário para o array de tarefas.
void carregarTarefas(const char *filename, Tarefa *tarefas, int *numTarefas) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Erro ao abrir o arquivo");
        return;
    }
    fread(numTarefas, sizeof(int), 1, file);
    fread(tarefas, sizeof(Tarefa), *numTarefas, file);
    fclose(file);
}

// Permite ao usuário alterar detalhes de uma tarefa específica.
void alterarTarefa(Tarefa *tarefas, int numTarefas) {
    int index, opcao;
    printf("Selecione o índice da tarefa a ser alterada: ");
    scanf("%d", &index);
    if(index < 0 || index >= numTarefas) {
        printf("Índice inválido!\n");
        return;
    }

    printf("Escolha o campo para alterar (1-Descrição, 2-Categoria, 3-Prioridade, 4-Estado): ");
    scanf("%d", &opcao);
    limparBuffer();// Limpa o buffer antes de ler strings

    switch(opcao) {
        case 1:
            printf("Nova descrição: ");
            fgets(tarefas[index].descricao, 299, stdin);
            break;
        case 2:
            printf("Nova categoria: ");
            fgets(tarefas[index].categoria, 99, stdin);
            break;
        case 3:
            printf("Nova prioridade: ");
            scanf("%d", &tarefas[index].prioridade);
            break;
        case 4:
            printf("Novo estado (0-Não Iniciado, 1-Em Andamento, 2-Completo): ");
            scanf("%d", (int *)&tarefas[index].estado);
            break;
        default:
            printf("Opção inválida!\n");
    }
}

// Filtra e exibe tarefas com base na prioridade especificada pelo usuário.
void filtrarTarefasPorPrioridade(const Tarefa *tarefas, int numTarefas) {
    int prioridade;
    printf("Digite a prioridade para filtrar: ");
    scanf("%d", &prioridade);

    for(int i = 0; i < numTarefas; i++) {
        if(tarefas[i].prioridade == prioridade) {
            printf("%d - %s, %s, Prioridade: %d, Estado: %d\n", i, tarefas[i].descricao, tarefas[i].categoria, tarefas[i].prioridade, tarefas[i].estado);
        }
    }
}


// Filtra e exibe tarefas com base no estado especificado pelo usuário.
void filtrarTarefasPorEstado(const Tarefa *tarefas, int numTarefas) {
    int estado;
    printf("Digite o estado para filtrar (0-Não Iniciado, 1-Em Andamento, 2-Completo): ");
    scanf("%d", &estado);

    for(int i = 0; i < numTarefas; i++) {
        if(tarefas[i].estado == estado) {
            printf("%d - %s, %s, Prioridade: %d, Estado: %d\n", i, tarefas[i].descricao, tarefas[i].categoria, tarefas[i].prioridade, tarefas[i].estado);
        }
    }
}

// Filtra e exibe tarefas com base na categoria especificada, ordenadas por prioridade.
void filtrarTarefasPorCategoria(Tarefa *tarefas, int numTarefas) {
    char categoria[100];
    printf("Digite a categoria para filtrar: ");
    limparBuffer();
    fgets(categoria, 99, stdin);

    // Bubble Sort para ordenar as tarefas por prioridade
    for (int i = 0; i < numTarefas-1; i++) {
        for (int j = 0; j < numTarefas-i-1; j++) {
            if (tarefas[j].prioridade < tarefas[j+1].prioridade) {
                // Troca
                Tarefa temp = tarefas[j];
                tarefas[j] = tarefas[j+1];
                tarefas[j+1] = temp;
            }
        }
    }

    // Exibe as tarefas filtradas
    for (int i = 0; i < numTarefas; i++) {
        if (strcmp(tarefas[i].categoria, categoria) == 0) {
            printf("%d - %s, %s, Prioridade: %d, Estado: %d\n", i, tarefas[i].descricao, tarefas[i].categoria, tarefas[i].prioridade, tarefas[i].estado);
        }
    }
}


void filtrarTarefasPorPrioridadeECategoria(const Tarefa *tarefas, int numTarefas) {
    int prioridade;
    char categoria[100];
    printf("Digite a prioridade para filtrar: ");
    scanf("%d", &prioridade);
    printf("Digite a categoria para filtrar: ");
    limparBuffer();
    fgets(categoria, 99, stdin);

    for (int i = 0; i < numTarefas; i++) {
        if (tarefas[i].prioridade == prioridade && strcmp(tarefas[i].categoria, categoria) == 0) {
            printf("%d - %s, %s, Prioridade: %d, Estado: %d\n", i, tarefas[i].descricao, tarefas[i].categoria, tarefas[i].prioridade, tarefas[i].estado);
        }
    }
}

// Exporta as tarefas de uma categoria específica, ordenadas por prioridade, para um arquivo de texto.
void exportarTarefasPorPrioridade(const Tarefa *tarefas, int numTarefas) {
    int prioridade;
    printf("Digite a prioridade das tarefas a serem exportadas: ");
    scanf("%d", &prioridade);

    FILE *file = fopen("tarefas_por_prioridade.txt", "w");
    if (!file) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    for (int i = 0; i < numTarefas; i++) {
        if (tarefas[i].prioridade == prioridade) {
            fprintf(file, "Prioridade: %d, Categoria: %s, Estado: %d, Descrição: %s\n", tarefas[i].prioridade, tarefas[i].categoria, tarefas[i].estado, tarefas[i].descricao);
        }
    }

    fclose(file);
    printf("Tarefas exportadas com sucesso!\n");
}

// Exporta tarefas que correspondem a uma prioridade e categoria específicas para um arquivo de texto.
void exportarTarefasPorCategoria(Tarefa *tarefas, int numTarefas) {
    char categoria[100];
    printf("Digite a categoria das tarefas a serem exportadas: ");
    limparBuffer();
    fgets(categoria, 99, stdin);

    // Ordenação por prioridade usando Bubble Sort
    for (int i = 0; i < numTarefas-1; i++) {
        for (int j = 0; j < numTarefas-i-1; j++) {
            if (tarefas[j].prioridade < tarefas[j+1].prioridade) {
                Tarefa temp = tarefas[j];
                tarefas[j] = tarefas[j+1];
                tarefas[j+1] = temp;
            }
        }
    }

    FILE *file = fopen("tarefas_por_categoria.txt", "w");
    if (!file) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    for (int i = 0; i < numTarefas; i++) {
        if (strcmp(tarefas[i].categoria, categoria) == 0) {
            fprintf(file, "Prioridade: %d, Categoria: %s, Estado: %d, Descrição: %s\n", tarefas[i].prioridade, tarefas[i].categoria, tarefas[i].estado, tarefas[i].descricao);
        }
    }

    fclose(file);
    printf("Tarefas exportadas com sucesso!\n");
}

// Filtra e exibe tarefas com base em uma prioridade e categoria específicas.
void exportarTarefasPorPrioridadeECategoria(const Tarefa *tarefas, int numTarefas) {
    int prioridade;
    char categoria[100];
    printf("Digite a prioridade das tarefas a serem exportadas: ");
    scanf("%d", &prioridade);
    printf("Digite a categoria das tarefas a serem exportadas: ");
    limparBuffer();
    fgets(categoria, 99, stdin);

    FILE *file = fopen("tarefas_por_prioridade_e_categoria.txt", "w");
    if (!file) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    for (int i = 0; i < numTarefas; i++) {
        if (tarefas[i].prioridade == prioridade && strcmp(tarefas[i].categoria, categoria) == 0) {
            fprintf(file, "Prioridade: %d, Categoria: %s, Estado: %d, Descrição: %s\n", tarefas[i].prioridade, tarefas[i].categoria, tarefas[i].estado, tarefas[i].descricao);
        }
    }

    fclose(file);
    printf("Tarefas exportadas com sucesso!\n");
}
