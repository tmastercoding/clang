#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* nextNode; // points to next node
};

struct Node* CreateNode(int data);
struct Node* InsertNode(struct Node* current, int data);
void DestroyNode(struct Node *destroy, struct Node *head);
void PrintNodeFrom(struct Node* from);

int main(){
    struct Node* Node1 = CreateNode(100);
    struct Node* Node2 = InsertNode(Node1, 200);
    struct Node* Node3 = InsertNode(Node2, 300);

    //put node4 before node2

    struct Node* Node4 = InsertNode(Node1, 400);
    PrintNodeFrom(Node1);

    return 0;
}

void PrintNodeFrom(struct Node* from){
    while(from){
        printf("node\'s data: %d \n", from ->data);
        from = from ->nextNode;
    }
}

struct Node* CreateNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    newNode->data = data;
    newNode->nextNode = NULL;

    return newNode;
}


struct Node* InsertNode(struct Node* current, int data){
    struct Node* after = current->nextNode;

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->nextNode = after;

    current->nextNode = newNode;

    return newNode;
}

// head = first node
void DestroyNode(struct Node *destroy, struct Node *head){
    struct Node *next = head;

    if(destroy == head){
        free(destroy);
        return;
    }

    while(next){
        if(next->nextNode == destroy){
            next->nextNode = destroy->nextNode;

        }
        next = next->nextNode;
    }
    free(destroy);
}