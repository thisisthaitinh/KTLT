// declaring library
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// struct
typedef struct
{
     int x, y;
} point;

// local variable
point p1, p2, p3, *ptr;

// inputFor2
void inputFor2()
{
     printf("------- Tinh dien tich da giac loi -------");
     printf("\nNhap toa do diem A (xA, yA): ");
     scanf("%d, %d", &p1.x, &p1.y);
     printf("\nNhap toa do diem B (xB, yB): ");
     scanf("%d, %d", &p2.x, &p2.y);
}

// inputFor3
void inputFor3()
{
     printf("\nNhap toa do diem A (xA, yA): ");
     scanf("%d, %d", &p1.x, &p1.y);
     printf("\nNhap toa do diem B (xB, yB): ");
     scanf("%d, %d", &p2.x, &p2.y);
     printf("\nNhap toa do diem C (xC, yC): ");
     scanf("%d, %d", &p3.x, &p3.y);
     if (collinearCheck(p1, p2, p3) == 0) {
          printf("\n3 diem toa do thang hang!");
     }
     else outputArea();
}

// triangleArea
float triangleArea()
{
     int first, second;
     float area;
     first = (p1.x * p2.y) + (p2.x * p3.y) + (p3.x + p1.y);
     second = (p2.x * p1.y) + (p3.x + p2.y) + (p1.x + p3.y);
     return area = (float)(0.5 * abs(first - second));
}

// area output
void outputArea()
{
     printf("Dien tich tam giac ABC la: %.2fcm2.", triangleArea(p1, p2, p3));
}

// locationReturn
float p1p2()
{
     float pointA, pointB, pointAB;
     pointA = pow((p1.x - p2.x), 2);
     pointB = pow((p1.y - p2.y), 2);
     return pointAB = sqrt(pointA + pointB);
}

// output
void output()
{
     printf("Do dai doan thang AB la: %.2fcm.", p1p2(p1, p2));
}

// slope1
int slope1(point p1, point p2)
{
     return (p2.y - p1.y) / (p2.x - p1.x);
}

// slope2
int slope2(point p3, point p2)
{
     return (p3.y - p2.y) / (p3.x - p2.x);
}

// collinearCheck
int collinearCheck(point p1, point p2, point p3)
{
     if (slope1(p1, p2) == 1 && slope2(p3, p2) == 1)
     {
          return 0;
     }
     else
          return 1;
}

int main()
{
     system("cls");
     inputFor3();
     return 0;
}
