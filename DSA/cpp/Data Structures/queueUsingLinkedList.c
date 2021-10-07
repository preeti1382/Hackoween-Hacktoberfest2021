#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*front , *rear;
void enqueue()
{
    struct node *ptr;
    int val;
    ptr = (struct node*)malloc(sizeof(struct node));
    printf("enter value:");
    scanf("%d",&val);
    ptr->data = val;
    ptr->next = NULL;
    if(front == NULL)
    {
        front = ptr;
        rear = ptr;
        front->next = NULL;
        rear->next = NULL;
        printf("first node inserted in queue..\n");
    }
    else
    {
        rear->next = ptr;
        rear = ptr;
        rear->next = NULL;
        printf("node inserted in queue..\n");
    }
}
void dequeue()
{
    struct node *temp;
    if(front == NULL)
    {
        printf("queue underflow...\n");
    }
    else
    {
        temp = front;
        front = front->next;
        printf("%d value deleted....\n",temp->data);
        free(temp);
    }
}
void display()
{
    struct node *temp;
    temp = front;
    if(front == NULL)
    {
        printf("queue is empty...\n");
    }
    else
    {
        while(temp != NULL)
        {
            printf("\t%d\t",temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
int main()
{
    int ch;
    do
    {
        printf("====QUEUE====\n");
        printf("1.EnQueue\n2.DeQueue\n3.Display\n4.Exit\n");
        printf("enter choice:");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            return 0;
            break;
        default:
            printf("enter valid choice...");
            break;
        }
    }while(ch!=4);
    return 0;
}
