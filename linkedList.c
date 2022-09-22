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

    /*
    LinkedList 선언
    Node의 사이즈 만큼 메모리 할당
    노드의 next는 Null을 가르킴
    헤드 노드에 있는 값은 1로 임의 지정
    헤드 노드에는 값을 넣지 않는 경우도 많음
    */
    Node *head = malloc(sizeof(Node));
    head->next = NULL;
    head->data = 1;

    while(!run){
        printf("1. Append At First\n");
        printf("2. Append\n");
        printf("3. Show List\n");
        printf("4. Delete List\n");
        printf("5. Insert\n");
        printf("6. Swap the Node\n");
        printf("7. Buuble Sort\n");
        printf("8. Show List Memory\n");
        printf("9. Array To List\n");
        printf("10. Search In List\n");
        printf("11. Get List Length\n");
        printf("12. Exit\n");
        printf("Choose Menu");
        
        int choice;

        scanf("%d",&choice);
        if(choice == 1){
            printf("Data : ");
            int data = scanf("%d");
            appendFirst(head, data);
        }
        else if(choice == 2){
            printf("Data : ");
            int data = scanf("%d");
            append(head,data);
        }
        else if(choice == 3){
            showList(head);
        }
        else if(choice == 12){
            run = true;
        }
    }

    return 0;
}

/**
 * @brief Append Data At the first of List
 * 
 * @param ptr 
 * @param data 
 */
void appendFirst(Node *ptr, int data){
    struct Node *newNode = malloc(sizeof(Node));
    newNode->next = ptr->next;
    newNode->data = data;

    ptr->next = newNode;
}

void append(Node* ptr, int data){
    Node *cur = ptr;

    // 마지막 index 까지 노드 이동
    while(cur->next != NULL){
        cur = cur->next;
    }

    struct Node *newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    cur->next = newNode;
}

void showList(Node* ptr){
    Node *cur = ptr;
    printf("[ ");
    // 포인터가 가르키는 곳이 NULL 일때 종료
    while(cur != NULL){
        printf("%d ",cur->data);
        cur = cur->next;
    }
    printf("]\n");
}

void deleteList(Node *ptr){
    Node* cur = ptr;
    Node* next;

    // 루프문을 돌면서 하나씩 메모리 해제
    while(cur != NULL){
        next = cur->next;
        free(cur);
        cur = next;
    }
}

void insertList(Node *ptr, int position, int data){
    Node* cur = ptr;
    for(int i = 1; i < position; i++){
        cur = cur->next;
    }
    Node *newNode = malloc(sizeof(Node));
    Node *next = cur->next;
    cur->next = newNode;
    newNode->next = next;
}