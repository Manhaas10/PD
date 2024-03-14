#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct queue {
    int head;
    int tail;
    char** a;
};
typedef struct queue* queue;
int queue_full(queue q,int n) {
    if((q->head==0&&q->tail==n-1)||(q->head==q->tail+1))return -1;return 1;
}
int queue_empty(queue q){
    if(q->head==-1 &&q->tail==-1)return -1;return 1;
}
void enqueue(queue q,char s[],int n){
    if(queue_full(q,n)==-1){printf("-1\n");return;}
    if(q->head==-1) q->head=0;
    q->tail=(q->tail+1)%n;
    q->a[q->tail]=strdup(s);

}
void dequeue(queue q,int n){
    if(queue_empty(q)==-1){printf("-1\n");return;}
    else{
    printf("%s\n",q->a[q->head]);
    free(q->a[q->head]);
     if (q->head==q->tail) q->head=q->tail=-1; 
     else q->head=(q->head+1)%n;  
}}
int main(){
    int n;
    scanf("%d",&n);
    queue q=malloc(sizeof(struct queue));
    q->head=-1;
    q->tail=-1;
    q->a=(char**)malloc(n* sizeof(char*));
    char choice;
char s[21];
    do{
        scanf(" %c",&choice);
        switch(choice){
            case 'i':
                scanf("%s", s);
                enqueue(q,s,n);
                break;

            case 'd':
               dequeue(q,n);
               break;
            case 'f':
                if (queue_full(q,n)==-1)
                    printf("-1\n");
                else
                    printf("1\n");
                break;
            case 'e':
                if (queue_empty(q)==-1)
                    printf("-1\n");
                else
                    printf("1\n");
                break;
            case 't':
                break;
        }

    }while(choice!='t');
return 1;
}