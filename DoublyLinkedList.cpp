#include <iostream>

struct DNode
{
     int data;
     DNode* pPrev;
     DNode* pNext;
};

struct DList
{
     DNode* pHead;
     DNode* pTail;
};

// insertion
void insertHead(DList& list, int x) {
     DNode* newNode = new DNode;
     newNode->data = x;
     newNode->pNext = list.pHead
     newNode->pPrev = NULL;

     if (list.pHead != NULL) {
          list.pHead->pPrev = newNode;
     }
     list.pHead = newNode;
}

void insertTail(DList& list, int x) {
    // 1. tao node moi
     DNode* newNode = new DNode;
    // 2. gan data cho node moi
     newNode->data = newData;
     // 3. gan gia tri 2 dau cua node thanh null
     newNode->pNext = NULL;
     newNode->pPrev = NULL;
    // 4. neu dll trong thi tao list moi va node duoc them se vua la node head & tail
     if (List.pHead == NULL) {
          List.pHead = newNode;
     }
     else {
         // 5. duyet den tail cua dll
          DNode* temp = List.pHead;
          while (temp->pNext != NULL) {
               temp = temp->pNext;
          }
          // 6. dieu chinh con tro 
          temp->pNext = newNode;
          newNode->pPrev = temp;
     }
     return newNode;
}

void insertAfter(DList& list, int x) {
     DNode* prev = nullptr;
     if (prev == NULL) {
          return;
     }

     DNode* newNode = new DNode;
     newNode->data = x;
     newNode->pNext = prev->pNext;
     prev->pNext = newNode;
     newNode->pPrev = prev;

     if (newNode->pNext != NULL) {
          newNode->pNext->pPrev = newNode;
     }
}