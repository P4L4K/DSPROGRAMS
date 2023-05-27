//C Program to Implement a Stack using Linked List and develop functions to perform push and pop operations.
#include <stdio.h>
#include <stdlib.h>

// Structure to create a node with data and the next pointer
struct node {
    int info;
    struct node *ptr;
}*top,*top1,*temp;

int count = 0;
// Push() operation on a  stack
void push(int data) {
     if (top == NULL)
    {
        top =(struct node *)malloc(1*sizeof(struct node));
        top->ptr = NULL;
        top->info = data;
    }
    else
    {
        temp =(struct node *)malloc(1*sizeof(struct node));
        temp->ptr = top;
        temp->info = data;
        top = temp;
    }
    count++;
    printf("Node is Inserted\n\n");
}

int pop() {
     top1 = top;

    if (top1 == NULL)
    {
        printf("\nStack Underflow\n");
        return -1;
    }
    else
        top1 = top1->ptr;
    int popped = top->info;
    free(top);
    top = top1;
    count--;
    return popped;
}

void display() {
    // Display the elements of the stack
    top1 = top;

    if (top1 == NULL)
    {
        printf("\nStack is empty!\n");
        return;
    }

    printf("The stack is \n");
    while (top1 != NULL)
    {
        printf("%d\t", top1->info);
        top1 = top1->ptr;
    }
    

}

int main() {
    int choice=0, value;
    while (choice!=4) {
        printf("\nMenu:\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("\nEnter the value to insert: ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            printf("Popped element is :%d", pop());
            break;
        case 3:
            display();
            break;
        case 4:
            break;
        default:
            printf("Invalid Choice\n");
        }
    }
}