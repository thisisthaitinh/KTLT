#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100
void input(int arr[], int n)
{
     srand((int)time(0));
     for (int i = 0; i < n; ++i)
     {
          arr[i] = rand() % 20;
     }
}

void output(int arr[], int n)
{
     for (int i = 0; i < n; ++i)
     {
          printf("%5d", arr[i]);
     }
}

int sumOfArray(int arr[], int n)
{
     if (n == 0)
     {
          return 0;
     }
     return arr[n - 1] + sumOfArray(arr, n - 1);
}

int maxOfArray(int arr[], int n)
{
     if (n == 1)
     {
          return arr[0];
     }
     else
          return (arr[n - 1] > maxOfArray(arr, n - 1)) ? arr[n - 1] : maxOfArray(arr, n - 1);
}

int minOfArray(int arr[], int n)
{
     if (n == 1)
     {
          return arr[0];
     }
     else
          return (arr[n - 1] < minOfArray(arr, n - 1)) ? arr[n - 1] : minOfArray(arr, n - 1);
}

int main()
{
     srand((int)time(0));
     int n = rand() % 30, arr[MAX];
     printf("Mang ngau nhien co %d phan tu: ", n);
     input(arr, n);
     output(arr, n);
     printf("\nTong cac phan tu ngau nhien trong mang la: %d.", sumOfArray(arr, n));
     printf("\nPhan tu lon nhat trong mang ngau nhien la: %d.", maxOfArray(arr, n));
     printf("\nPhan tu nho nhat trong mang ngau nhien la: %d.", minOfArray(arr, n));
     return 0;
}