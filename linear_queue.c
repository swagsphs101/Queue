#include<stdio.h>
#include<stdlib.h>

struct Queue{
    int size;
    int front;
    int rear;
    int *arr;
};

int isEmpty(struct Queue*q){
//    if(q->front==q->rear) return 1;
    if (q->front==-1 || q->front>q->rear) return 1;
    return 0;
}

int isFull(struct Queue*q){
    if(q->rear==q->size-1) return 1;
    else return 0; 
}

void enqueue(struct Queue*q,int val){
    if(isFull(q)){
        printf("Queue overflow\n");
    }
    else{
        if(q->front==-1){
            q->front=0;
        }
        q->rear++;
        q->arr[q->rear]=val;
    }
}

void dequeue(struct Queue* q){
    if(isEmpty(q)){
        printf("Queue underflow\n");
    }
    else{
        q->front++;
    }
}

void display(struct Queue* q){
    int i;
    for(i=q->front;i<=q->rear;i++){
        printf("%d ",q->arr[i]);
    }
    printf("\n");
}

int main(){
    struct Queue* q=(struct Queue*)malloc(sizeof(struct Queue));
    q->size=5   ;
    q->front=q->rear=-1;
    q->arr=(int*)malloc(q->size*sizeof(int));
    while(1){
        int choice;
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Display\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: 
            {
			        int val;
                    printf("Enter a value to enqueue:");
                    scanf("%d",&val);
                    enqueue(q,val);
                    printf("Successfully Enqueued\n");
                    break;
            }
            case 2: 
            {
			        dequeue(q);
			        printf("Successfully dequeued\n");
                    break;
            }

            case 3: 
            {
			        display(q);
                    break;
            }

            case 4:
            {
			        printf("Exiting the program");
                    exit(0);
                    break;
            }

            default:
                    printf("Not a valid choice");
        }
    }
    return 0;
}
