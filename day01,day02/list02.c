#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
    int data;            // 노드가 저장하는 데이터
    struct NODE *next;   // 다음 노드를 가리키는 포인터
} node;

void main() {
    // 첫 번째 노드 생성 및 초기화
    node *head = (node*)malloc(sizeof(node)); // 첫 번째 노드를 동적으로 할당
    head->data = 10;                          // 첫 번째 노드에 데이터 10을 저장
    head->next = NULL;                        // 첫 번째 노드의 다음 노드를 NULL로 초기화

    // 두 번째 노드 생성 및 초기화
    node *second = (node*)malloc(sizeof(node)); // 두 번째 노드를 동적으로 할당
    second->data = 20;                          // 두 번째 노드에 데이터 20을 저장
    second->next = NULL;                        // 두 번째 노드의 다음 노드를 NULL로 초기화
    head->next = second;                        // 첫 번째 노드의 다음 노드로 두 번째 노드를 연결

    // 세 번째 노드 생성 및 초기화
    node *third = (node*)malloc(sizeof(node)); // 세 번째 노드를 동적으로 할당
    third->data = 30;                          // 세 번째 노드에 데이터 30을 저장
    third->next = NULL;                        // 세 번째 노드의 다음 노드를 NULL로 초기화
    second->next = third;                      // 두 번째 노드의 다음 노드로 세 번째 노드를 연결

    // 연결 리스트 출력
    node *curr = head;            // 현재 노드를 첫 번째 노드로 설정
    while (curr != NULL) {        // 현재 노드가 NULL이 아닌 동안 반복
        printf("%d ", curr->data); // 현재 노드의 데이터를 출력
        curr = curr->next;         // 다음 노드로 이동
    }
    printf("\n"); // 출력이 끝난 후 줄바꿈

    // 메모리 해제
    free(head);   // 첫 번째 노드의 메모리를 해제
    free(second); // 두 번째 노드의 메모리를 해제
    free(third);  // 세 번째 노드의 메모리를 해제
}