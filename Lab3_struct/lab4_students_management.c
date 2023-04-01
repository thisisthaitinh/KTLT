// library declaration
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int n, i;

// StudentsName
typedef struct
{
     char ten_ho[30], ten[30];
} StudentsName;

// StudentsDayOfBirth
typedef struct
{
     char ngaySinh[10], noiSinh[40];
} StudentsDayOfBirth;

// StudentsPoints
typedef struct
{
     int diemWin, diemExcel, diemWord, tongDiem;
} StudentsPoints;

// StudentsManagement
typedef struct
{
     StudentsName tenSinhVien;
     StudentsDayOfBirth SinhVien;
     StudentsPoints diemSinhVien;
} StudentsManagement;

StudentsManagement a[MAX], svien;

// NameAndBirth
void nhapTTSV(StudentsName *tenSinhVien, StudentsDayOfBirth *SinhVien, StudentsPoints *diemSinhVien)
{
     printf("Ban muon nhap thong tin cho bao nhieu sinh vien?: ");
     scanf_s("%d", &n);
     for (i = 0; i < n; ++i)
     {
          fflush(stdin);
          printf("\nHoc vien thu %d:\n", i + 1);

          printf("\n\t- Nhap ho, ten dem: ");
          gets(a[i].tenSinhVien.ten_ho);

          printf("\n\t- Nhap ten: ");
          gets(a[i].tenSinhVien.ten);

          printf("\n\t- Nhap ngay sinh: ");
          gets(a[i].SinhVien.ngaySinh);

          printf("\n\t- Nhap noi sinh: ");
          gets(a[i].SinhVien.noiSinh);

          printf("\n\t- Nhap diem Windows: ");
          scanf_s("%d", &a[i].diemSinhVien.diemWin);

          printf("\n\t- Nhap diem Excel: ");
          scanf_s("%d", &a[i].diemSinhVien.diemWin);

          printf("\n\t- Nhap diem Word: ");
          scanf_s("%d", &a[i].diemSinhVien.diemWin);

          // finalPoint
          a[i].diemSinhVien.tongDiem = a[i].diemSinhVien.diemWin + a[i].diemSinhVien.diemExcel + a[i].diemSinhVien.diemWord;
     }
}

// XepLoaiSinhVien
const char *StatusDisplay(StudentsPoints *diemSinhVien)
{
     char *excellent = "Gioi", *good = "Kha", *average = "Trung binh", *bad = "Kem";
     if (a[i].diemSinhVien.tongDiem >= 24)
     {
          return excellent;
     }
     else if (18 <= a[i].diemSinhVien.tongDiem < 24)
     {
          return good;
     }
     else if (15 <= a[i].diemSinhVien.tongDiem < 18)
     {
          return average;
     }
     else if (diemSinhVien->tongDiem < 15)
     {
          return bad;
     }
}

// StudentsInfo
StudentsManagement StudentsInfo()
{
     nhapTTSV(&svien.tenSinhVien, &svien.SinhVien, &svien.diemSinhVien);
}

// StudentsDisplay
StudentsManagement StudentsDisplay()
{
     printf("%s\t %s\t %s\t %s\t %s\n", "STT", "Ho va ten", "Ngay sinh", "Noi sinh", "Ghi chu");
     for (i = 0; i < n; ++i)
     {
          printf("%d\t %s %s\t %s\t %s\t %s\n", i + 1, a[i].tenSinhVien.ten_ho, a[i].tenSinhVien.ten, a[i].SinhVien.ngaySinh, a[i].SinhVien.noiSinh, StatusDisplay(a));
     }
}

int main()
{
     system("cls");
     StudentsInfo();
     StudentsDisplay();
}
