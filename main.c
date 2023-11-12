#include "biblioteca.h"
#include <stdio.h>

int main() {
    int opcao;
    int numTarefas = 0;
    Tarefa tarefas[100];

    do {
        printf("1. Cadastrar Tarefa\n");
        printf("2. Listar Tarefas\n");
        printf("3. Deletar Tarefa\n");
        printf("4. Salvar Tarefas\n");
        printf("5. Carregar Tarefas\n");
        printf("6. Alterar Tarefa\n");
        printf("7. Filtrar Tarefas por Prioridade\n");
        printf("8. Filtrar Tarefas por Estado\n");
        printf("9. Filtrar Tarefas por Categoria\n");
        printf("10. Filtrar Tarefas por Prioridade e Categoria\n");
        printf("11. Exportar Tarefas por Prioridade\n");
        printf("12. Exportar Tarefas por Categoria\n");
        printf("13. Exportar Tarefas por Prioridade e Categoria\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                cadastrarTarefa(tarefas, &numTarefas);
                break;
            case 2:
                listarTarefas(tarefas, numTarefas);
                break;
            case 3:
                deletarTarefa(tarefas, &numTarefas);
                break;
            case 4:
                salvarTarefas("tarefas.dat", tarefas, numTarefas);
                break;
            case 5:
                carregarTarefas("tarefas.dat", tarefas, &numTarefas);
                break;
            case 6:
                alterarTarefa(tarefas, numTarefas);
                break;
            case 7:
                filtrarTarefasPorPrioridade(tarefas, numTarefas);
                break;
            case 8:
                filtrarTarefasPorEstado(tarefas, numTarefas);
                break;
            case 9:
                filtrarTarefasPorCategoria(tarefas, numTarefas);
                break;
            case 10:
                filtrarTarefasPorPrioridadeECategoria(tarefas, numTarefas);
                break;
            case 11:
                exportarTarefasPorPrioridade(tarefas, numTarefas);
                break;
            case 12:
                exportarTarefasPorCategoria(tarefas, numTarefas);
                break;
            case 13:
                exportarTarefasPorPrioridadeECategoria(tarefas, numTarefas);
                break;
        }
    } while(opcao != 0);

    return 0;
}