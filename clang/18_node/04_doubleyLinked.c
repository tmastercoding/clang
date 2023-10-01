#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* nextNode;
    struct Node* prevNode;
};

struct Node *CreateNode(int data);
struct Node *InsertNode(int data, struct Node* current);
// void DestroyNode(struct Node *destroy, struct Node *head);
// void PrintNodeFrom(struct Node* from);
// int CountNode(struct Node* head);
// int SearchNode(struct Node* head, struct Node* search);

int main(){
    struct Node* Node1 = CreateNode(100);
    struct Node* Node2 = InsertNode(200, Node1);
    // struct Node* Node3 = InsertNode(300, Node2);

    //put node4 before node2

    // struct Node* Node4 = InsertNode(400, Node1);
    // PrintNodeFrom(Node1);
    // DestroyNode(Node1, Node1);
    return 0;
}

// void PrintNodeFrom(struct Node* from){
//     while(from){
//         printf("node\'s data: %d \n", from ->data);
//         from = from ->nextNode;
//     }
// }

struct Node *CreateNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prevNode = newNode;
    newNode->nextNode = NULL;

    return newNode;
}

struct Node *InsertNode(int data, struct Node* current){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    struct Node* next = current->nextNode;

    newNode->data = data;
    
    newNode->prevNode = next->prevNode;
    newNode->nextNode = current->nextNode;

    current->nextNode = newNode;
    next->prevNode = newNode;

    return newNode;
}

// void DestroyNode(struct Node *destroy, struct Node *head){
//     struct Node *next = head;

//     if(destroy == head){
//         free(destroy);
//         return;
//     }

//     while(next){
//         if(next->nextNode == destroy){
//             next->nextNode = destroy->nextNode;
//             struct Node *after = destroy->nextNode;
//             after->prevNode = next;
//             break;
//         }
//         next = next->nextNode;
//     }
//     free(destroy);
// }
