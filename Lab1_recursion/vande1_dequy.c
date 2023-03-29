/* Tong, tich va luy thua */
// su dung de quy tuyen tinh (linear recursion)
#include <stdio.h>
#include <math.h>
// tong
int tong(int n)
{
     if (n == 1)
          return 1;
     return n + tong(n - 1);
}
// tich
int tich(int n)
{
     if (n == 1)
          return 1;
     return n * tich(n - 1);
}
// luy thua
int luythua(int n, int m)
{
     if (m == 0)
     {
          return 1;
     }
     return n * luythua(n, m - 1);
}
int main()
{
     int n, m;
     printf("Nhap n: ");
     scanf("%d", &n);
     printf("Tong: %d\n", tong(n));
     printf("Tich: %d", tich(n));
     fflush(stdin);
     printf("\nNhap n, m: ");
     scanf("%d%d", &n, &m);
     printf("%d ^ %d = %d", n, m, luythua(n, m));
     return 0;
}
