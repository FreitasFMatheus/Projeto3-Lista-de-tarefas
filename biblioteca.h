
#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H



typedef enum {
    NAO_INICIADO,
    EM_ANDAMENTO,
    COMPLETO
} EstadoTarefa;

typedef struct {
    int prioridade;
    char descricao[300];
    char categoria[100];
    EstadoTarefa estado;
} Tarefa;

void limparBuffer();
void cadastrarTarefa(Tarefa *tarefas, int *numTarefas);
void listarTarefas(const Tarefa *tarefas, int numTarefas);
void deletarTarefa(Tarefa *tarefas, int *numTarefas);
void salvarTarefas(const char *filename, const Tarefa *tarefas, int numTarefas);
void carregarTarefas(const char *filename, Tarefa *tarefas, int *numTarefas);

void alterarTarefa(Tarefa *tarefas, int numTarefas);
void filtrarTarefasPorPrioridade(const Tarefa *tarefas, int numTarefas);
void filtrarTarefasPorEstado(const Tarefa *tarefas, int numTarefas);
void filtrarTarefasPorCategoria(Tarefa *tarefas, int numTarefas);
void filtrarTarefasPorPrioridadeECategoria(const Tarefa *tarefas, int numTarefas);
void exportarTarefasPorPrioridade(const Tarefa *tarefas, int numTarefas);
void exportarTarefasPorCategoria(Tarefa *tarefas, int numTarefas);
void exportarTarefasPorPrioridadeECategoria(const Tarefa *tarefas, int numTarefas);

#endif //BIBLIOTECA_H