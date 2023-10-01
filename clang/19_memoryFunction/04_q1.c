#include <stdio.h>
#include <stdlib.h>

// node struct
struct Node{
    struct Node* next;
    struct Node* prev;
    int data;
};

// insertFront
void insertFront(struct Node* head, int data);

// insertEnd
void insertEnd(struct Node* head, int data);

// insertBetween
// remove
// display

void displayList(struct Node* node);

int main(){
    struct Node* head = NULL;
    // insertEnd(head, 5);
    insertEnd(head, 5);
    insertFront(head, 10);

    displayList(head);

    return 0;
}

// insert Node at the front 
void insertFront(struct Node* head, int data){
    // allocate memory
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    // assign data
    newNode -> data = data;

    // make newNode next head
    newNode -> next = head;

    // assign null to prev
    newNode ->  prev = NULL;

    // prev of head(now head is the second node) is newNode
    if(head != NULL){
        head->prev = newNode;
    }

    // head points to newNode
    head = newNode;
    printf("success\n");
    displayList(head);
}

// insert node at the end
void insertEnd(struct Node* head, int data){
    // allocate memory
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    // assign data
    newNode -> data = data;
    if (head == NULL){
        newNode -> prev = NULL;
        head = newNode;
    }
    // go the end of the nodes
    struct Node* temp = head;
    if(temp != NULL){
        while(temp->next != NULL){
            temp = temp->next;
        }
    }

    // assign null to next
    newNode -> next = NULL;

    // assign temp to next
    if(temp != NULL){
        temp -> next = newNode;
    }
    displayList(head);
}

void displayList(struct Node* node){
    // temporary variable
    struct Node* temp = node;

    printf("------------ DISPLAY NODE -------------\n");
    // when temp is not null,
    // prints out data
    // temp becomes next node
    while(temp != NULL){
        printf("%d->\n", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
    printf("---------------------------------------\n");
}