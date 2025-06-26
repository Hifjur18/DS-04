#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};


void createList() {
    struct Node* head = NULL, * newNode, * temp;
    int choice = 1;

    // Create the linked list
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


    int pos, data;
    printf("Enter the position after which you want to insert a node: ");
    scanf("%d", &pos);
    printf("Enter the data of the new node: ");
    scanf("%d", &data);


    insertAfterPosition(&head, pos, data);


    printf("\nUpdated linked list: ");
    temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


void insertAfterPosition(struct Node** head, int pos, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = *head;
    int i = 0;

    newNode->data = data;
    newNode->next = NULL;


    while (temp != NULL && i < pos) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Position not found!\n");
        return;
    }


    newNode->next = temp->next;
    temp->next = newNode;
}

int main() {
    createList();
    return 0;
}
