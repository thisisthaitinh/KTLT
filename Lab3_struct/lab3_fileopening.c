// library declaration
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

// SinhVien
typedef struct
{
     char name[MAX];
     int number;
     float diem_tk, diem_gk, diem_ck, diem_th, diem_tb;
} SinhVien;

// variable
int n, i;
SinhVien a[MAX];

// FailedStudents
void FailedStudents(SinhVien *a, int n)
{
     printf("\nSTT\tHo ten\t\tMa so sinh vien\tDiem trung binh\n");
     for (i = 0; i < n; ++i)
     {
          if (a[i].diem_tb < 4.0)
          {
               printf("%d\t%s\t%d\t%.2f", i + 1, a[i].name, a[i].number, a[i].diem_tb);
               printf("\n");
          }
     }
}

// TextDisplay
void TextDisplay(SinhVien *a, int n)
{
     printf("\n");
     for (i = 0; i < n; ++i)
     {
          printf("Ho ten: %s\n", a[i].name);
          printf("Ma so sinh vien: %d\n", a[i].number);
          printf("Diem thuong ky: %.2f\n", a[i].diem_tk); // or a[i].diem.diem_tk;
          printf("Diem giua ky: %.2f\n", a[i].diem_gk);
          printf("Diem cuoi ky: %.2f\n", a[i].diem_ck);
          printf("Diem thuc hanh: %.2f\n", a[i].diem_th);
          printf("Diem trung binh: %.2f\n", a[i].diem_tb);
     }
}

// StatusDisplay
const char *StatusDisplay(SinhVien a[])
{
     char *failStatus = "Hoc lai", *successStatus = "Dat";
     if (a[i].diem_tb < 4.0)
     {
          return failStatus;
     }
     else
          return successStatus;
}

// compare
int compare(const void *s1, const void *s2)
{
     const SinhVien *diem1 = s1;
     const SinhVien *diem2 = s2;
     if (diem1->diem_tb < diem2->diem_tb)
     {
          return 1;
     }
     else if (diem1->diem_tb > diem2->diem_tb)
     {
          return -1;
     }
     else
          return 0;
}

// TableDisplay
void TableDisplay(SinhVien *a, int n)
{
     FILE *file = fopen("output.txt", "w");
     if (file == NULL)
     {
          printf("Khong the mo file!\n");
          exit(1);
     }
     freopen("output.txt", "w", stdout); // redirect stdout to file
     fprintf(file, "%s\t %s\t\t %s\t\t %s\t %s\t %s\t %s\t %s\t %s\n", "STT", "Ho ten", "MSSV", "TK", "GK", "CK", "TH", "DTB", "Ghi chu");
     for (i = 0; i < n; ++i)
     {
          fprintf(file, "%d\t %s\t %d\t %.2f\t %.2f\t %.2f\t %.2f\t %.2f\t %s\n", i + 1, a[i].name, a[i].number, a[i].diem_tk, a[i].diem_gk, a[i].diem_ck, a[i].diem_th, a[i].diem_tb, StatusDisplay(a));
     }
     // close file
     fclose(file);

     // open file in notepad
     system("notepad.exe output.txt");
}

// FindStudent
void FindStudent(SinhVien *a, int n)
{
     char sv[MAX];
     int i, count = 0;
     printf("Nhap ten sinh vien can tim: ");
     gets(sv);
     for (i = 0; i < n; ++i)
     {
          if (strcmp(sv, a[i].name) == 0)
          {
               TextDisplay(a, n);
               count = 1;
          }
     }
     if (count == 0)
     {
          printf("Khong the tim thay sinh vien %s!", sv);
     }
     fflush(stdin);
}

// ThongTinSinhVien
void StudentInformation(SinhVien *a, int n)
{
     do
     {
          printf("Nhap thong tin cho bao nhieu sinh vien?: ");
          scanf("%d", &n);
          if (n <= 0)
          {
               printf("\nVui long nhap lai!\n\n");
          }
     } while (n <= 0);
     for (i = 0; i < n; ++i)
     {
          fflush(stdin);
          printf("\nSinh vien thu %d: \n", i + 1);
          printf("\n\tHo ten: ");
          gets(a[i].name);
          printf("\n\tMa so sinh vien: ");
          scanf("%d", &a[i].number);
          printf("\n\tNhap diem thuong ky, giua ky, cuoi ky va diem thuc hanh: ");
          scanf("%f %f %f %f", &a[i].diem_tk, &a[i].diem_gk, &a[i].diem_ck, &a[i].diem_th);
          a[i].diem_tb = (((((2 * a[i].diem_tk) + (3 * a[i].diem_gk) + (5 * a[i].diem_ck)) / 10) * 2 + a[i].diem_th)) / 3.0;
     }
     qsort(a, n, sizeof(SinhVien), compare);
     TableDisplay(a, n);
     free(a);
}

// Main program
int main()
{
     system("cls");
     // do
     // {
     //      StudentInformation(x, n);
     //      printf("\nBan co muon thoat khoi chuong trinh k? (0 for no, 1 for yes): ");
     //      scanf("%d", &choice);
     //      if (choice == 1)
     //      {
     //           printf("\nThoat chuong trinh thanh cong!");
     //      }
     // } while (choice == 0);
     StudentInformation(malloc(n * sizeof(SinhVien)), n);
     return 0;
}
