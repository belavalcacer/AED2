#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaII.h"

int main() {
    int N;
    scanf("%d", &N);
    PriorityQueue pq = {.size = 0};

    for (int i = 0; i < N; i++) {
        char event[MAX_NAME_LEN];
        scanf("%s", event);

        if (strcmp(event, "OFERTA") == 0) {
            Offer offer;
            scanf("%s %d", offer.name, &offer.price);
            push(&pq, offer);
        } else if (strcmp(event, "VENDA") == 0) {
            Offer bestOffer = pop(&pq);
            printf("%d %s\n", bestOffer.price, bestOffer.name);
        }
    }

    return 0;
}