 #include<stdio.h>
 #include <stdlib.h>

 // 노드 구조체 정의
 typedef struct NODE{
   int data;             // 노드가 저장하는 데이터
   struct NODE* next;   // 다음 노드를 가리키는 포인터
 }node;

 // 새로운 노드를 추가하는 함수
 void addNode(node* pnode, int _data)
 {
   // 새로운 노드 동적 할당 및 초기화
   node* newNode = (node*)malloc(sizeof(node));
   newNode->data = _data;        // 데이터 할당
   newNode->next = pnode->next;  // 새 노드의 next를 pnode의 next로 설정
   pnode->next = newNode;        // pnode의 next를 새 노드로 설정
 }

 int main()
 {
   // 헤드 노드 생성 및 초기화
   node* head = (node*)malloc(sizeof(node));
   head->next = NULL;  // 헤드 노드의 다음 노드를 NULL로 초기화

   // 노드 추가
   addNode(head, 10);   // 첫번째 노드로 삽입
   addNode(head, 20);
   addNode(head, 30);
   addNode(head, 40);
   addNode(head, 50);

   // 연결 리스트 출력
   node* curr = head->next;
   while(curr != NULL) {
     printf("%d\n", curr->data);  // 현재 노드의 데이터 출력
     curr = curr->next;           // 다음 노드로 이동
   }
   
   // 연결 리스트의 메모리 해제
   curr = head->next;
   node* temp;
   head->next = NULL;  // 헤드 노드의 다음 노드를 NULL로 설정
   while(curr != NULL){
     temp = curr->next;  // 현재 노드의 다음 노드 저장
     free(curr);         // 현재 노드 메모리 해제
     curr = temp;        // 다음 노드로 이동
   }
   
   // 헤드 노드의 메모리 해제
   printf("%p, %p\n", (void*)head->next, (void*)curr);
   free(head);
   
   return 0;
 }
