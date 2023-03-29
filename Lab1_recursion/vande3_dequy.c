#include <stdio.h>
#include <stdbool.h>
int decimalToBinary(int n)
{
     if (n == 0)
     {
          return 0;
     }
     return (n % 2) + 10 * decimalToBinary(n / 2);
}
int binaryToDecimal(int n)
{
     if (n == 0)
     {
          return 0;
     }
     return (n % 10) + 2 * binaryToDecimal(n / 10);
}
bool isEven(int n);
bool isOdd(int n);
int main()
{
     int n;
     printf("n: ");
     scanf("%d", &n);
     if (isEven(n))
     {
          printf("%d la so chan", n);
     }
     else
          printf("%d la so le", n);
     return 0;
}
bool isEven(int n)
{
     if (n == 0)
     {
          return true;
     }
     else
          return isOdd(n - 1);
}
bool isOdd(int n)
{
     return !isEven(n);
}