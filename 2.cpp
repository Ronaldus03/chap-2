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

int max=0;
int min=50;

Node *createNode( int score){
    Node *newNode = (Node*)malloc(sizeof(Node));
    // strcpy(newNode->name, name);
    newNode ->score = score;

    if(max<score){
        max=score;
    }
    if(min>score){
        min=score;
    }
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

void popHead(){
    if(!head){
        return;
    }else if(head == tail){
        free(head);
        head = tail = NULL;
    }else{ // misal 53(head) -> 70 -> 40 -> 25
        Node *temp = head -> next; //53(head) -> 70(temp) -> 40 -> 25
        head -> next = NULL; // 53(head) -> NULL || 70 (temp) -> 40 -> 25
        free(head);
        head = temp; // 70(head,temp) ->40 ->25
    }
}

void popTail(){
    if(!head){ //0node
        return; // langsung return aja
    }else if(head == tail){//kalo node cuma 1
        free(head);
        head = tail = NULL;
    }else{ // misal 53(head) -> 70 -> 40 -> 25 (tail) ->NULL
        Node *temp = head -> next; //53(head) -> 70(temp) -> 40 -> 25
        
        while(temp->next != tail){
            temp = temp->next;
        }
        temp -> next = NULL; // 53(head) -> NULL || 70 (temp) -> 40 -> 25
        free(head);
        tail = temp; //53 (head)->70 -> 40 (temp,tail) -> NULL 
    }

}



int main()
{
  
    pushHead(5);
    pushTail(6);
    pushTail(7);
    pushTail(8);
    
   printf("%d ",max-min);

    return 0;
}
