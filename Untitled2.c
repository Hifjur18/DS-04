#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};


void createList() {
    struct Node* head = NULL, * newNode, * temp;
    int choice = 1;


    while (choice) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter Data: ");
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }

        printf("Do you want to continue? Press 0 to stop, 1 to continue: ");
        scanf("%d", &choice);
    }


    temp = head;
    printf("\nThe linked list is: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");


    int data;
    printf("Enter the data of the new node to insert at the beginning: ");
    scanf("%d", &data);
    insertAtBeginning(&head, data);


    printf("\nUpdated linked list after insertion at the beginning: ");
    temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

int main() {
    createList();
    return 0;
}
