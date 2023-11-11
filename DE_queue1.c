// Output restricted DE_Queue
#include<stdio.h>
#include<stdlib.h>

struct DE_Queue{
    int size;
    int front;
    int rear;
    int *arr;
};

// struct DE_Queue*q=NULL;

int isEmpty(struct DE_Queue*q){
    if(q->front==-1 || q->front>q->rear) return 1;
    return 0;
}

int isFullfront(struct DE_Queue*q){
    if((q->front)==-1) return 1;
    else return 0;
}

int isFullrear(struct DE_Queue*q){
    if(q->rear==q->size-1) return 1;
    else return 0;
}


void enqueuefront(struct DE_Queue*q,int val){
    if(isFullfront(q)){
        printf("Insertion not posssible at front\n");
    }
    else{
//        if(q->front==-1 && q->rear==-1){
//            q->rear=0;
//            q->front++;
//            q->arr[q->front]=val;
//        }
//        if(q->front!=q->size-1){
//        	q->front
//		}
//        else{
            q->front--;
            q->arr[q->front]=val;
//        }
    }
}


void enqueuerear(struct DE_Queue*q,int val){
    if(isFullrear(q)){
        printf("Insertion not possible at rear end\n");
    }
    else{
        if(q->front==-1){
            q->front=0;
        }
        q->rear++;
        q->arr[q->rear]=val;
    }
}

void dequeuefront(struct DE_Queue*q){
    if(isEmpty(q)){
        printf("Queue underflow\n");
    }
    else{
        q->front++;
    }
}

void dequeuerear(struct DE_Queue*q){
    printf("Deletion at rear end restricted");
}

void display(struct DE_Queue*q){
    int i;
    for(i=q->front;i<=q->rear;i++){
        printf("%d ",q->arr[i]);
    }
    printf("\n");
}

int main(){
    struct DE_Queue* q=(struct DE_Queue*)malloc(sizeof(struct DE_Queue));
    q->size=5;
    q->front=q->rear=-1;
    q->arr=(int*)malloc(q->size*sizeof(int));
    while(1){
        int choice;
        printf("1.Enqueuefront\n");
        printf("2.Enqueuerear\n");
        printf("3.Dequeuefront\n");
        printf("4.Dequeuerear\n");
        printf("5.Display\n");
        printf("5.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: 
            {
			        int val;
                    printf("Enter a value to enqueue:");
                    scanf("%d",&val);
                    enqueuefront(q,val);
                    printf("Successfully Enqueued\n");
                    break;
            }
            case 2: 
            {
			        int val;
                    printf("Enter a value to enqueue:");
                    scanf("%d",&val);
                    enqueuerear(q,val);
                    printf("Successfully Enqueued\n");
                    break;
            }
            case 3: 
            {
			        dequeuefront(q);
			        printf("Successfully dequeued\n");
                    break;
            }
            case 4: 
            {
			        dequeuerear(q);
                    break;
            }

            case 5: 
            {
			        display(q);
                    break;
            }

            case 6:
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
