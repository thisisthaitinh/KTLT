#include <iostream>

struct Node
{
     int data;
     Node *pNext;
};

struct List
{
     Node *head;
     Node *tail;
};

// empty linked list
void Init(List &list)
{
     list.head = list.tail = NULL;
}

// insertion
void insertHead(List &list, int x)
{
     Node *newNode = new Node;
     newNode->data = x;
     newNode->pNext = list.head;
     if (list.head == NULL)
     {
          list.tail = newNode;
     }
     list.head = newNode;
}
void insertTail(List &list, int x)
{
     Node *newNode = new Node;
     newNode->data = x;
     newNode->pNext = list.tail;
     if (list.tail == NULL)
     {
          list.head = newNode;
     }
     list.tail = newNode;
}

void insertAtGivenPos(List &list, Node *prevNode, int data)
{
     if (prevNode == NULL)
     {
          std::cout << "The previous node cant be NULL." << std::endl;
          return;
     }
     Node *newNode = new Node;
     newNode->data = data;
     newNode->pNext = prevNode->pNext;
     prevNode->pNext = newNode;
}

// display list
void display(List& list) {
     Node* curr = list.head;
     while (curr != NULL) {
          std::cout << curr->data << std::endl;
          curr = curr->pNext;
     }
     std::cout << std::endl;
}

// search in the list
void search(List& list, int key) {
     Node* newNode = list.head;
     while (newNode != NULL) {
          if (newNode->data == key) {
               return 1;
          }
          newNode = newNode->pNext;
     }
     return -1; // not found
}

// delete
void deleteHead(List& list, int key) {
     if (list.head == NULL) {
          return 0;
     }
     Node* old = list.head;
     key = old->data;
     list.head = old->pNext;

     if (list.head == NULL) {
          list.tail = NULL;
     }

     free(old);
     return key;
}

void deleteTail(List& list, Node* prev) {
     if (prev != NULL && prev->pNext != NULL) {
          Node* newNode = prev->pNext;
          prev->pNext = newNode->pNext;
          if (newNode == list.tail) {
               list.tail = prev;
          }
          free(newNode);
          return key;
     }
     else return 0;
}

void deletePos(List& list, int pos) {
     if (list.head == NULL) {
          return;
     }

     if (pos == 0) {
          deleteHead(list, pos);
          return;
     }

     Node *curr = list.head;
     for (int i = 0; i < pos - 1; ++i) {
          if (curr->pNext == NULL) {
               return;
          }
          curr = curr->pNext;
     }

     Node* temp = curr->pNext;
     curr->pNext = curr->pNext->pNext;
     delete temp;
}

void deleteTheWholeList(List& list) {
     Node *newNode;
     while (list.head != NULL) {
          newNode = list.head;
          list.head = list.head->pNext;
          free(newNode);
     }
     list.tail = NULL;
}

// count nodes
int counting(List& list) {
     Node* curr = list.head;
     int count = 0;
     while (curr != NULL) {
          count++;
          curr = curr->pNext;
     }
     return count
}

// count n nodes from list
void countNnodesFromList(List &list, int n) {
     Node* curr = list.head;
     int count = 0;
     while (curr != NULL && count < n) {
          std::cout << curr->data << std::endl;
          count++;
     }
}

// list apending
void AppendList(struct List& pList, int* arr, int size) {
    for (int i = 0; i < size; i++) {
        struct Node* newNode = new Node;
        newNode->data = arr[i];
        newNode->pNext = NULL;

        if (pList.pHead == NULL) {
            pList.pHead = newNode;
            pList.pTail = newNode;
        } else {
            pList.pTail->pNext = newNode;
            pList.pTail = newNode;
        }
    }
}

// list reversing
void reverse(List& list) {
     Node* prev = NULL;
     Node* curr = list.head;
     Node* next = NULL;

     while (curr != NULL) {
          next = curr->pNext;
          curr->pNext = prev;
          prev = curr;
          curr = next;
     }

     return prev;
}