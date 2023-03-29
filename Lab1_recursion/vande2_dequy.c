/* Van de 2: Cap so cong va cap so nhan */
// su dung de quy tuyen tinh (linear recursion)
#include <stdio.h>
#include <math.h>
const int a, d, n;

// Cap so cong using recursion
double capSoCong(int a, int d, int n)
{
     if (n == 1)
     {
          return a;
     }
     if (n > 1)
     {
          return (a + ((n - 1) * d));
     }
}

// Cap so nhan using recursion
double capSoNhan(int a, int d, int n)
{
     if (n == 1)
     {
          return a;
     }
     if (n > 1)
     {
          return (a * pow(d, n - 1));
     }
}

// hien thi day so CSC function
int displaySeriesOfCSC(int a, int d, int n)
{
     printf("%6d", a);
     if (n > 1)
     {
          return displaySeriesOfCSC(a + d, d, n - 1);
     }
}

// hien thi day so CSN function
int displaySeriesOfCSN(int a, int d, int n)
{
     printf("%6d", a);
     if (n > 1)
     {
          return displaySeriesOfCSN(a * d, d, n - 1);
     }
}

// input function
void input()
{
     printf("\nNhap a, d, n: ");
     scanf_s("%d%d%d", &a, &d, &n);
}

// output of capSoCong
void outputOfCSC()
{
     printf("\n\tSo hang dau tien: %d\n", a);
     printf("\tCong sai: %d\n", d);
     printf("\tDay so: ");
     displaySeriesOfCSC(a, d, n);
     printf("\n\tGia tri phan tu thu %d: %.0lf\n", n, capSoCong(a, d, n));
}

// output of capSoNhan
void outputOfCSN()
{
     printf("\n\tSo hang dau tien: %d\n", a);
     printf("\tCong boi: %d\n", d);
     printf("\tDay so: ");
     displaySeriesOfCSN(a, d, n);
     printf("\n\tGia tri phan tu thu %d: %.0lf\n", n, capSoNhan(a, d, n));
}

// choice
void choice()
{
     int choice;
     printf("-----------------\n");
     printf("1. Cap so cong\n");
     printf("2. Cap so nhan\n");
     printf("Nhap lua chon cua ban: ");
     scanf_s("%d", &choice);
     switch (choice)
     {
     case 1:
          input();
          outputOfCSC();
          break;
     case 2:
          input();
          outputOfCSN();
          break;
     default:
          break;
     }
}

// outofProgram function
void outOfProgram()
{
     char yesOrNo;
     do
     {
          choice();
          fflush(stdin);
          printf("\nBan co muon thoat chuong trinh khong? (Y/N): ");
          scanf_s("%c", &yesOrNo);
          if (yesOrNo == 'Y' || yesOrNo == 'y')
          {
               printf("\nThoat chuong trinh hoan tat.");
          }
     } while (yesOrNo == 'N' || yesOrNo == 'n');
}

// main function
int main()
{
     outOfProgram();
     return 0;
}
