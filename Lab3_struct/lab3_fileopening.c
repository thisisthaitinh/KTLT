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
     char ngaySinh[20], noiSinh[40];
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

StudentsManagement svien[MAX];

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
          gets(svien[i].tenSinhVien.ten_ho);

          printf("\n\t- Nhap ten: ");
          gets(svien[i].tenSinhVien.ten);

          printf("\n\t- Nhap ngay sinh: ");
          gets(svien[i].SinhVien.ngaySinh);

          printf("\n\t- Nhap noi sinh: ");
          gets(svien[i].SinhVien.noiSinh);

          printf("\n\t- Nhap diem Windows: ");
          scanf("%d", &svien[i].diemSinhVien.diemWin);

          printf("\n\t- Nhap diem Excel: ");
          scanf("%d", &svien[i].diemSinhVien.diemExcel);

          printf("\n\t- Nhap diem Word: ");
          scanf("%d", &svien[i].diemSinhVien.diemWord);

          // finalPoint
          svien[i].diemSinhVien.tongDiem = svien[i].diemSinhVien.diemWin + svien[i].diemSinhVien.diemExcel + svien[i].diemSinhVien.diemWord;
     }
}

// XepLoaiSinhVien
const char *StatusDisplay(StudentsManagement svien[])
{
     char *excellent = "Gioi", *good = "Kha", *average = "Trung binh", *bad = "Kem";
     if (svien[i].diemSinhVien.tongDiem >= 24)
     {
          return excellent;
     }
     if (18 <= svien[i].diemSinhVien.tongDiem < 24)
     {
          return good;
     }
    if (15 <= svien[i].diemSinhVien.tongDiem < 18)
     {
          return average;
     }
     if (svien[i].diemSinhVien.tongDiem < 15)
     {
          return bad;
     }
}

// StudentsInfo
StudentsManagement StudentsInfo()
{
	StudentsManagement svien;
     nhapTTSV(&svien.tenSinhVien, &svien.SinhVien, &svien.diemSinhVien);
}

// StudentsDisplay
StudentsManagement StudentsDisplay()
{
	FILE *file = fopen("display.txt", "w");
	if (file == NULL) {
		printf("Khong the mo file!");
	}
	freopen("display.txt", "w", stdout);
    fprintf(file, "%s\t %s\t %s\t %s\t %s\t %s\n", "STT", "Ho va ten", "Ngay sinh", "Noi sinh", "DTB", "Ghi chu");
     for (i = 0; i < n; ++i)
     {
          fprintf(file, "%d\t %s %s\t %s\t %s\t %d\t %s\n", i + 1, svien[i].tenSinhVien.ten_ho, svien[i].tenSinhVien.ten, svien[i].SinhVien.ngaySinh, svien[i].SinhVien.noiSinh, svien[i].diemSinhVien.tongDiem, StatusDisplay(svien));
     }
    // close file
    fclose(file);
    
    // open file in notepad
    system("notepad.exe display.txt");
}

int main()
{
     system("cls");
     StudentsInfo();
     StudentsDisplay();
}
