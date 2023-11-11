#include<stdio.h>
#include<stdlib.h>

struct Node* front=NULL;
struct Node* rear=NULL;


struct Node{
    int data;
    struct Node* next;
    
};

int isEmpty(struct Node* ptr){
    if(front==NULL) return 1;
    return 0;
}

int isFull(struct Node* ptr){
    if(ptr==NULL) return 1;
    else return 0;
}

void enqueue(int val){
    struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));
    if(isFull(ptr)){
        printf("Queue overflow\n");
    }
    else{
        ptr->data=val;
        ptr->next=NULL;
        if(front==NULL){
            front=rear=ptr;
        }
        else{
            rear->next=ptr;
            rear=ptr;
        }
    }
}

void dequeue(){
    struct Node* ptr=front;
    if(isEmpty(front)){
        printf("Queue underflow\n");
    }
    else{
        front=front->next;
        free(ptr);
    }
}

void display(struct Node* ptr){
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}

int main(){
    while(1){
        int choice;
        printf("Enter your choice:");
        scanf("%d",&choice);
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Display\n");
        printf("4.Exit\n");
        switch(choice)
        {
            case 1: 
            {
			        int val;
                    printf("Enter a value to enqueue:");
                    scanf("%d",&val);
                    enqueue(val);
                    printf("Successfully Enqueued\n");
                    break;
            }
            case 2: 
            {
			        dequeue();
			        printf("Successfully dequeued\n");
                    break;
            }

            case 3: 
            {
			        display(front);
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
