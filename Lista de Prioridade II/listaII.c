
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaII.h"

void swap(Offer* a, Offer* b) {
    Offer temp = *a;
    *a = *b;
    *b = temp;
}

void push(PriorityQueue* pq, Offer offer) {
    pq->offers[pq->size] = offer;
    int current = pq->size++;
    while (current > 0) {
        int parent = (current - 1) / 2;
        if (pq->offers[current].price <= pq->offers[parent].price) break;
        swap(&pq->offers[current], &pq->offers[parent]);
        current = parent;
    }
}

Offer pop(PriorityQueue* pq) {
    Offer top = pq->offers[0];
    pq->offers[0] = pq->offers[--pq->size];
    int current = 0;
    while (1) {
        int left = 2 * current + 1;
        int right = 2 * current + 2;
        int largest = current;
        if (left < pq->size && pq->offers[left].price > pq->offers[largest].price)
            largest = left;
        if (right < pq->size && pq->offers[right].price > pq->offers[largest].price)
            largest = right;
        if (largest == current) break;
        swap(&pq->offers[current], &pq->offers[largest]);
        current = largest;
    }
    return top;
}
