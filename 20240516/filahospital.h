#define MAX_PATIENTS 100

typedef struct {
    char nome[100];
    char telefone[20];
    int urgencia;
} Paciente;

typedef struct {
    Paciente pacientes[MAX_PATIENTS];
    int tamanho;
} FilaDePrioridade;

//Assinaturas

void trocar(Paciente *a, Paciente *b);
void subirNoHeap(FilaDePrioridade *fila, int index);
void descerNoHeap(FilaDePrioridade *fila, int index);
void inserirPaciente(FilaDePrioridade *fila, char *nome, char *telefone, int urgencia);
Paciente removerPaciente(FilaDePrioridade *fila);
void imprimirFila(FilaDePrioridade *fila);
