#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node 구조체 선언
typedef struct Node
{
    struct Node *next;
    int data;
}Node;

// 만들 링크드 리스트 예제 목록
void appendFirst(Node *ptr, int data);
void append(Node *ptr, int data);
void showList(Node *ptr);
void deleteList(Node *ptr);
void insert(Node *ptr, int position, int data);
void swapNodeData(Node *ptr1, Node *ptr2);
void bubbleSortData(Node *ptr);
void showListMemory(Node *ptr);
void arrayToList(Node *ptr, int arr[], int arrSize);
bool searchList(Node *ptr, int number);
Node* getList();
int getNodeLength(Node *ptr);

int main(){
    bool run;
    Node *head = NULL;
    while(!run){

    }

    return 0;
}

void appendFirst(Node *ptr, int data){
    
}