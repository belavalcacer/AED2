#define MAX_EVENTS 10000
#define MAX_NAME_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    int price;
} Offer;

typedef struct {
    Offer offers[MAX_EVENTS];
    int size;
} PriorityQueue;

void swap(Offer* a, Offer* b);
void push(PriorityQueue* pq, Offer offer);
Offer pop(PriorityQueue* pq);
