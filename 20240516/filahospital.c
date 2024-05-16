#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filahospital.h"

void trocar(Paciente *a, Paciente *b) {
  Paciente temp = *a;
  *a = *b;
  *b = temp;
}

void subirNoHeap(FilaDePrioridade *fila, int index) {
  while (index > 0 && fila->pacientes[(index - 1) / 2].urgencia < fila->pacientes[index].urgencia) {
      trocar(&fila->pacientes[(index - 1) / 2], &fila->pacientes[index]);
      index = (index - 1) / 2;
  }
}

void descerNoHeap(FilaDePrioridade *fila, int index) {
  int maior = index;
  int esquerda = 2 * index + 1;
  int direita = 2 * index + 2;

  if (esquerda < fila->tamanho && fila->pacientes[esquerda].urgencia > fila->pacientes[maior].urgencia) {
      maior = esquerda;
  }

  if (direita < fila->tamanho && fila->pacientes[direita].urgencia > fila->pacientes[maior].urgencia) {
      maior = direita;
  }

  if (maior != index) {
      trocar(&fila->pacientes[index], &fila->pacientes[maior]);
      descerNoHeap(fila, maior);
  }
}

void inserirPaciente(FilaDePrioridade *fila, char *nome, char *telefone, int urgencia) {
  if (fila->tamanho >= MAX_PATIENTS) {
      printf("Fila de pacientes está cheia!\n");
      return;
  }

  Paciente novo;
  strcpy(novo.nome, nome);
  strcpy(novo.telefone, telefone);
  novo.urgencia = urgencia;

  fila->pacientes[fila->tamanho] = novo;
  subirNoHeap(fila, fila->tamanho);
  fila->tamanho++;
}

Paciente removerPaciente(FilaDePrioridade *fila) {
  if (fila->tamanho == 0) {
      printf("Fila de pacientes está vazia!\n");
      Paciente vazio = {"", "", -1};
      return vazio;
  }

  Paciente pacienteRemovido = fila->pacientes[0];
  fila->pacientes[0] = fila->pacientes[fila->tamanho - 1];
  fila->tamanho--;
  descerNoHeap(fila, 0);

  return pacienteRemovido;
}

void imprimirFila(FilaDePrioridade *fila) {
  printf("Fila de Espera:\n");
  for (int i = 0; i < fila->tamanho; i++) {
      printf("Nome: %s, Telefone: %s, Urgência: %d\n", fila->pacientes[i].nome, fila->pacientes[i].telefone, fila->pacientes[i].urgencia);
  }
}