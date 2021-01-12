#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Node{
    int score;
    Node *next;//merujuk ke node selanjtunya
}*head, *tail, *head2, *tail2;// global variabelnya, head dan tail
// head : node pertama dalam linked list
// tail : node terakhir dalam linked list

//char *name sama dengan char name[]

Node *createNode( int score){
    Node *newNode = (Node*)malloc(sizeof(Node));
    // strcpy(newNode->name, name);
    newNode ->score = score;
    newNode->next = NULL;
    return newNode;

}

//push head, push tail

void pushHead( int score){
    //1. buat dulu nodenya
    //2. cek kondisi
    // jika tidak ada head,maka node menjadi head dan tail
    // jika ada head , node akan menjadi head baru dan node->next = head lama

    Node *temp = createNode(score);//buat dulu nodenya

    if(!head){
        head = tail = temp; //maka nodneya akan menjadi head dan tail
    }else{ // jika ada head
        temp->next = head; // node menunjuk ke head yang lama
        head = temp;    //node akan menjadi head yang baru
    }

}

void pushHead2( int score){
    //1. buat dulu nodenya
    //2. cek kondisi
    // jika tidak ada head,maka node menjadi head dan tail
    // jika ada head , node akan menjadi head baru dan node->next = head lama

    Node *temp = createNode(score);//buat dulu nodenya

    if(!head2){
        head2 = tail2 = temp; //maka nodneya akan menjadi head dan tail
    }else{ // jika ada head
        temp->next = head2; // node menunjuk ke head yang lama
        head2 = temp;    //node akan menjadi head yang baru
    }

}
void pushTail( int score){
    //1. buat dulu nodenya
    //2. cek kondisi
    // jika tidak ada head,maka node menjadi head dan tail
    // jika ada head , node akan menjadi head baru dan node->next = head lama

    Node *temp = createNode(score);//buat dulu nodenya

    if(!head){
        head = tail = temp; //maka nodneya akan menjadi head dan tail
    }else{ // jika ada tail
        tail->next = temp; // tail menunjuk ke node
        tail = temp;    //node akan menjadi tail yang baru
    }
}

void pushTail2( int score){
    //1. buat dulu nodenya
    //2. cek kondisi
    // jika tidak ada head,maka node menjadi head dan tail
    // jika ada head , node akan menjadi head baru dan node->next = head lama

    Node *temp = createNode(score);//buat dulu nodenya

    if(!head2){
        head2 = tail2 = temp; //maka nodneya akan menjadi head dan tail
    }else{ // jika ada tail
        tail2->next = temp; // tail menunjuk ke node
        tail2 = temp;    //node akan menjadi tail yang baru
    }
}

void printList(){
    Node *curr = head; //53(curr,head) -> 70 -> 40 (tail) ->NULL

    while(curr){
        printf("%d ",curr->score);
        curr = curr->next;
    }
}

int main()
{
    pushHead(1);
    pushTail(2);
    pushTail(3);

    pushHead2(4);
    pushTail2(5);

    pushTail(4);
    pushTail(5);

    printList();

    return 0;
}
