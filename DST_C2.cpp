#include <bits/stdc++.h>

using namespace std;

struct NGAY {
     int ngay, thang, nam;
};

struct SANPHAM {
     char MaSP[10], TenSP[255];
     NGAY NgaySX;
     int SoNamBH;
};


// sort all the product ids in ascending order by using bubble sort
void bubbleSort(SANPHAM* sp, int n) {
     for (int i = 0; i < n; ++i) {
          for (int j = i + 1; j < n; ++j) {
               if (sp[j].MaSP < sp[i].MaSP) {
                    swap(sp[j], sp[i]);
               }
          }
     }
}

// print out all products
void print(SANPHAM sp[], int n) {
     // cout << "Ma SP\t" << "Ten SP\t\t" << "Nam SX\t" << "So nam BH\t" << endl;
     for (int i = 0; i < n; ++i) {
          cout << sp[i].MaSP << "\t" << sp[i].TenSP << "\t" << sp[i].NgaySX.ngay << "/" << sp[i].NgaySX.thang << "/" << sp[i].NgaySX.nam << "\t" << sp[i].SoNamBH << endl;
     }
}

// find and print out all the products that insurance-expired.
void find(SANPHAM* sp, int n, int currentYear) {
     for (int i = 0; i < n; ++i) {
          int expiredYear = sp[i].NgaySX.nam + sp[i].SoNamBH;
          if (expiredYear > currentYear) {
               cout << "Cac san pham da het han bao hanh: " << endl;
               cout << sp[i].MaSP << "\t" << sp[i].TenSP << "\t" << sp[i].NgaySX.ngay << "/" << sp[i].NgaySX.thang << "/" << sp[i].NgaySX.nam << "\t" << sp[i].SoNamBH << endl;
          }
     }
}

// insertion in sll
void insert(SANPHAM* sp, int n) {
     for (int i = 0; i < n; ++i) {
          cout << "Ma SP: ";
          cin >> sp[i].MaSP;
          fflush(stdin);
          cout << "Ten SP: ";
          cin.getline(sp[i].TenSP, 255);
          cout << "Ngay, thang, nam san xuat: ";
          cin >> sp[i].NgaySX.ngay >> sp[i].NgaySX.thang >> sp[i].NgaySX.nam;
          cout << "So nam bao hanh: ";
          cin >> sp[i].SoNamBH;
     }
}

// driver code
int main() {
     system("cls");
     SANPHAM dsSP[1000];
     int n;
     cout << "Nhap thong tin cho bao nhieu san pham?: ";
     cin >> n;
     insert(dsSP, n);
     bubbleSort(dsSP, n);
     find(dsSP, n, 2023);
}