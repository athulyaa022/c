#include <stdio.h>

#define SIZE 5

int queue[SIZE];
int front = 0, rear = 0;
int count = 0;

void enqueue(int value) 
{
    if (count == SIZE)
    {
        printf("Queue Overflow\n");
        return;
    }
    queue[rear] = value;
    rear = (rear + 1) % SIZE;
    count++;
    printf("%d enqueued\n",value);
}

void dequeue()
{
    if (count == 0)
    {
        printf("Queue Underflow\n");
        return;
    }
    printf("%d dequeued\n", queue[front]);
    front = (front + 1) % SIZE;
    count--;
}

void display() 
{
    if (count == 0) 
    {
        printf("Queue is empty\n");
        return;
    }
    int i = front;
    printf("Queue: ");
    for (int j = 0; j < count; j++) 
    {
        printf("%d ", queue[i]);
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

void peek() 
{
    if (count == 0) 
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Front element: %d\n",queue[front]);
}

int main() 
{
    int choice, value;
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display\n");
    printf("4. Peek\n");
    printf("5. Exit\n");
    while (1) 
    {
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d",&value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                peek();
                break;
            case 5:
            printf("Exited\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;

}
