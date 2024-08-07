#include <stdio.h>
#include <stdlib.h>

// node creation
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// insert node at front
void insertFront(struct Node** head, int data);

// insert a node after a specific node
void insertAfter(struct Node* prev_node, int data);

// insert a newNode at the end of the list
void insertEnd(struct Node** head, int data);

// delete a node from the doubly linked list
void deleteNode(struct Node** head, struct Node* del_node);

// print the doubly linked list
void displayList(struct Node* node);

// count the number of nodes
int countNode(struct Node** head);

// return the data of the node provided
int searchNode(struct Node** head, struct Node** search);

int main(){
    struct Node* head = NULL;
    printf("count: %d\n", countNode(&head));

    insertEnd(&head, 5);
    insertFront(&head, 1);
    insertFront(&head, 6);
    insertEnd(&head, 9);

    // order should be 6->1->5->9

    // insert 11 after head
    insertAfter(head, 11);

    // insert 15 after the second node
    insertAfter(head->next, 15);

    // order should be 6->11->15->1->5->9

    displayList(head);

    deleteNode(&head, head->next->next->next->next->next);

    displayList(head);

    printf("count: %d\n", countNode(&head));
    printf("data: %d\n", searchNode(&head, &head));
}

// insert node at front
void insertFront(struct Node** head, int data){
    // allocate memory for newNode
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    // assign data to newNode
    newNode->data = data;

    // make newNode as a head
    newNode->next = (*head);

    // assign null to prev
    newNode->prev = NULL;

    // prev of head(now head is the second node)
    // is newNode
    if((*head) != NULL){
        (*head)->prev = newNode;
    }

    // head points to newNode
    (*head) = newNode;
}

// insert a node after a specific node
void insertAfter(struct Node* prev_node, int data){
    // check if previous node is null
    if(prev_node == NULL) {
        printf("previous node cannot be null\n");
        return;
    }

    // allocate memory for newNode
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    // assign data to newNode
    newNode->data = data;

    // set next of newNode to next of prev node
    newNode->next = prev_node->next;

    // set next of prev node to newNode
    prev_node->next = newNode;

    // set prev of newNode to the previous node
    newNode->prev = prev_node;

    // set prev of newNode's next to newNode
    if(newNode-> next != NULL){
        newNode->next->prev = newNode;
    }
}

void displayList(struct Node* node) {
    struct Node* last;
    
    while(node != NULL) {
        printf("%d->", node->data);
        last = node;
        node = node->next;
    }
    if(node == NULL){
        printf("NULL\n");
    }
}

// insert a newNode at the end of the list
void insertEnd(struct Node** head, int data){
    // allocate memory for node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
   
    // assign data to newNode
    newNode->data = data;

    // assign null to next of newNode
    newNode->next = NULL;

    // store the head node temporarily (for later use)
    struct Node* temp = *head;

    // if the linked list is empty, make the newNode as head node
    if(*head == NULL){
        newNode->prev = NULL;
        *head = newNode;
        return;
    }

    // if the linked list is not empty,
    // traverse to the end of the linked list
    while(temp->next != NULL){
        temp = temp->next;
    }

    // now, the last node of the linked list is temp

    // assign next of the last node(temp) to newNode
    temp->next = newNode;

    // assign prev of newNode to temp
    newNode->prev = temp;
}

// delete a node from the doubly linked list
void deleteNode(struct Node** head, struct Node* del_node){
    // if head or del is null,
    // deletion is not possible
    if (*head == NULL || del_node == NULL){
        return;
    }
    // if del_node is the head node,
    // point the head pointer to the next of del_node
    if(*head == del_node){
        *head = del_node->next;
    }

    // if del_node is not at the last node,
    // point the prev of node next to del_node
    // to the previous of del_node
    if(del_node->next != NULL){
        del_node->next->prev = del_node->prev;
    }

    // if del_node is not the first node, 
    // point the next of previous node to the next node of del_node
    if(del_node->prev != NULL){
        del_node->prev->next = del_node->next;
    }

    // free the memory of del_node
    free(del_node);
}

// count the number of nodes
int countNode(struct Node** head){
    // if head is null, return 0
    if(*head == NULL){
        return 0;
    }

    // create a temporary variable of head
    struct Node* temp = *head;

    // create a count variable
    int count = 1;

    // while temp's next isn't null,
    // increase count and make temp the next of temp
    while(temp->next != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}

// return the data of the node provided
int searchNode(struct Node** head, struct Node** search){
    return (*search)->data;
}