#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Node{
    int score;
    Node *next;//merujuk ke node selanjtunya
}*head, *tail;// global variabelnya, head dan tail
// head : node pertama dalam linked list
// tail : node terakhir dalam linked list

//char *name sama dengan char name[]

int count = 0;

Node *createNode( int score){
    count++;
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

int main()
{
  
    pushHead(5);
    pushTail(6);
    pushTail(7);
    pushTail(8);
    pushTail(9);

     Node *pointer = head;
    
    for(int i=0;i<=count;i++){    
        if(i==count/2){
            printf("%d",pointer->score);
            break;
        }
        pointer = pointer -> next;
    }
   

    return 0;
}
