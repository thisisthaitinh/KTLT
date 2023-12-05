#include <bits/stdc++.h>
using namespace std;
struct Product
{
     char PID[8], PName[12];
};

struct Node
{
     Product data;
     Node *next;
};

struct Queue
{
     Node *front, *rear;
};

// initialize an empty queue
void Init(Queue &q)
{
     q.front = q.rear = NULL;
}

// check the queue is empty
int isEmpty(Queue &q)
{
     return (q.front == NULL) ? 1 : 0;
}

// get data (product)
Node *GetNode(Product *p)
{
     Node *newNode = new Node;
     strcpy(newNode->data.PID, p->PID);
     strcpy(newNode->data.PName, p->PName);
     newNode->next = NULL;
     return newNode;
}

// nhap 1 mat hang (enqueue)
void Enqueue(Queue &q, Node *newNode)
{
     if (isEmpty(q))
     {
          q.front = q.rear = newNode;
     }
     else
     {
          q.rear->next = newNode;
          q.rear = newNode;
     }
}

// xuat 1 mat hang (dequeue)
void Dequeue(Queue& q) {
     if (isEmpty(q)) {
          return;
     }
     Node* newNode = q.front;
     q.front = q.front->next;
     if (q.front == NULL) {
          q.rear = NULL;
     }
     free(newNode);
}


// xem mat hang chuan bi xuat (show queue)
void showQueue(Queue& q) {
     if (isEmpty(q)) {
          return;
     }
     Node* temp = q.front;
     while (temp != NULL) {
          cout << "PID: " << temp->data.PID << ", Name: " << temp->data.PName << "\n";
          temp = temp->next;
     }
}

void Dequeues(Queue& q) {
     Node* temp = q.front;
     while (temp != NULL) {
          Dequeue(q);
          temp = temp->next;
     }
}

void getFront(Queue& q) {
     if (!isEmpty(q)) {
          return;
     }
     cout << "Ma SP: " << q.front->data.PID << ", Ten SP: " << q.front->data.PName << "\n";
}

