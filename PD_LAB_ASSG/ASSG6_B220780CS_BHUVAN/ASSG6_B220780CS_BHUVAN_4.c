#include <stdio.h>
#include <stdlib.h>

struct queue {
    int head;
    int tail;
    int size;
    unsigned capacity;
    int* a;
};
typedef struct queue* queue;
struct queue* createqueue(unsigned capacity)
{
 queue q= malloc(sizeof(struct queue));
    q->capacity = capacity;
    q->head = q->size = 0;
    q->tail = capacity - 1;
    q->a= (int*)malloc(q->capacity * sizeof(int));
    return q;
}
int queue_full(queue q) {
    if((q->tail==q->capacity))return 1;return 0;
}
int queue_empty(queue q){
    if(q->size==0)return 1;return 0;
}
void enqueue(queue q,int k){
    if(queue_full(q)){return;}
    if(q->head==-1)q->head=0;
    q->tail=(q->tail+1)%q->capacity;
    q->a[q->tail]=k;
    q->size++;
}
int dequeue(queue q){
    if(queue_empty(q))return -1;
    int k = q->a[q->head];
    q->head= (q->head+ 1)%q->capacity;
    q->size--;
    return k;
}
int front(queue q)
{
    if (queue_empty(q)) return -1;
    return q->a[q->head];
}
int size(queue q){
    return q->size;
}
void sol(queue q,int K){
    int a[K];int aa[(q->capacity)-K];
    for(int i=0;i< K;i++) a[i]=dequeue(q);
    
    for(int i=0;i<(q->capacity)-K;i++) aa[i]=dequeue(q);
    
    for(int i=K-1;i>=0;i--) enqueue(q,a[i]);
    
    for(int i=0;i<(q->capacity)-K;i++) enqueue(q,aa[i]);
    
    }
int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    queue q = createqueue(n);
    for (int i=0;i<n;i++) {
        int elem;
        scanf("%d", &elem);
        enqueue(q, elem);
    }
    sol(q,k);
    while (!queue_empty(q)) {
    printf("%d ",dequeue(q));
}
    return 1;
}


