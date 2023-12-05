#include <bits/stdc++.h>
using namespace std;

struct SANPHAM
{
    char MaSP[10];
    char TenSP[255];
    char NgaySX[11]; 
    int SoNamBH;
};

struct NODE
{
    SANPHAM data;
    NODE* pNext;
};

struct LIST
{
    NODE* pHead;
    NODE* pTail; 
};

void removeNode(LIST& L, int namHienTai)
{
    NODE* pCurrent = L.pHead;
    NODE* pPrevious = nullptr;

    while (pCurrent != nullptr)
    {
        // Chuyển chuỗi NgaySX thành số nguyên năm sản xuất
        int namSanXuat = atoi(pCurrent->data.NgaySX + 6) + pCurrent->data.SoNamBH;

        // Kiểm tra năm sản xuất + số năm bảo hành với năm hiện tại
        if (namSanXuat > namHienTai)
        {
            // Xóa node
            if (pPrevious == nullptr)
            {
                // Node cần xóa là node đầu danh sách
                L.pHead = pCurrent->pNext;
            }
            else
            {
                // Node cần xóa không phải là node đầu danh sách
                pPrevious->pNext = pCurrent->pNext;
            }

            // Nếu node cần xóa là node cuối danh sách
            if (pCurrent == L.pTail)
            {
                L.pTail = pPrevious;
            }

            NODE* pTemp = pCurrent;
            pCurrent = pCurrent->pNext;
            delete pTemp;
        }
        else
        {
            pPrevious = pCurrent;
            pCurrent = pCurrent->pNext;
        }
    }
}

// insertion in sll
void insert(SANPHAM* sp, int n) {
     for (int i = 0; i < n; ++i) {
          fflush(stdin);
          cout << "San pham thu " << i + 1 << ":" << endl;
          cout << "Ma SP: ";
          cin.getline(sp[i].MaSP, 10);
          cout << "Ten SP: ";
          cin.getline(sp[i].TenSP, 255);
          cout << "Ngay, thang, nam san xuat: ";
          cin.getline(sp[i].NgaySX, 11);
          cout << "So nam bao hanh: ";
          cin >> sp[i].SoNamBH;
     }
}

void init(LIST& list) {
     list.pHead = list.pTail = NULL;
}

void print(LIST& list) {
     NODE *node = list.pHead;
     while (node != NULL) {
          cout << node->data.MaSP << "\t" << node->data.TenSP << "\t" << node->data.NgaySX << "\t" << node->data.SoNamBH << endl;
          node = node->pNext;
     }
     return;
}

int main() {
     system("cls");
     LIST list;
     SANPHAM sp[100];
     init(list);
     insert(sp, 2);
     removeNode(list, 2023);
     print(list);
     return 0;
}