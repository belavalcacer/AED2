#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filahospital.h"



int main() {
    FilaDePrioridade fila;
    fila.tamanho = 0;

    inserirPaciente(&fila, "Sabrina", "123456789", 2);
    inserirPaciente(&fila, "Mel", "987654321", 5);
    inserirPaciente(&fila, "Ana", "555555555", 3);
    inserirPaciente(&fila, "Camila", "555555555", 4);


    imprimirFila(&fila);

    Paciente proximo = removerPaciente(&fila);
    printf("\nPróximo paciente para transplante: Nome: %s, Telefone: %s\n", proximo.nome, proximo.telefone);

    imprimirFila(&fila);

    return 0;
}
