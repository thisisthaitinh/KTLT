#include <stdio.h>
#include <stdlib.h>

// struct
typedef struct
{
     int a, b;
} fraction;

// locai variable
int choice;
fraction phanso, phanso1, phanso2;

// output
fraction output(fraction phanso)
{
     printf("%d/%d", phanso.a, phanso.b);
}

// greatest common divisor (gcd means ucln)
int gcd(int a, int b)
{
     if (b != 0)
     {
          return gcd(b, a % b);
     }
     else
          return a;
}

// fraction simplification function
fraction FractionSimplification(fraction phanso)
{
     int divisor = gcd(phanso.a, phanso.b);
     phanso.a /= divisor;
     phanso.b /= divisor;
     return phanso;
}

// input and output
fraction InAndOut(fraction phanso)
{
     printf("\n\tNhap phan so: ");
     scanf("%d/%d", &phanso.a, &phanso.b);
     printf("\n\tPhan so vua nhap: %d/%d", phanso.a, phanso.b);
}

// plus 2 fractions
fraction FractionsSum(fraction phanso1, fraction phanso2)
{
     int sum, denominator, a1, a2;
     printf("\n\tNhap phan so thu 1 (a/b): ");
     scanf("%d/%d", &phanso1.a, &phanso1.b);
     printf("\n\tNhap phan so thu 2 (a/b): ");
     scanf("%d/%d", &phanso2.a, &phanso2.b);
     sum = (phanso1.a * phanso2.b) + (phanso1.b * phanso2.a);
     denominator = (phanso1.b * phanso2.b);
     a1 = sum / gcd(sum, denominator);
     a2 = denominator / gcd(sum, denominator);
     if (a1 > 0 && a2 < 0)
     {
          a1 *= (-1);
          a2 *= (-1);
     }
     printf("\n\tTong 2 phan so: %d/%d.", a1, a2);
}

// minus/subtract 2 fractions
fraction FractionsSubtract(fraction phanso1, fraction phanso2)
{
     int sub, denominator, a1, a2;
     printf("\n\tNhap phan so thu 1 (a/b): ");
     scanf("%d/%d", &phanso1.a, &phanso1.b);
     printf("\n\tNhap phan so thu 2 (a/b): ");
     scanf("%d/%d", &phanso2.a, &phanso2.b);
     sub = ((phanso1.a * phanso2.b) - (phanso1.b * phanso2.a));
     denominator = (phanso1.b * phanso2.b);
     a1 = sub / gcd(sub, denominator);
     a2 = denominator / gcd(sub, denominator);
     if (a1 > 0 && a2 < 0)
     {
          a1 *= (-1);
          a2 *= (-1);
     }
     printf("\n\tHieu 2 phan so: %d/%d.", a1, a2);
}

// multiply 2 fractions
fraction FractionsMultiply(fraction phanso1, fraction phanso2)
{
     int mul, denominator, a1, a2;
     printf("\n\thap phan so thu 1 (a/b): ");
     scanf("%d/%d", &phanso1.a, &phanso1.b);
     printf("\n\tNhap phan so thu 2 (a/b): ");
     scanf("%d/%d", &phanso2.a, &phanso2.b);
     mul = (phanso1.a * phanso2.a);
     denominator = (phanso1.b * phanso2.b);
     a1 = mul / gcd(mul, denominator);
     a2 = denominator / gcd(mul, denominator);
     if (a1 > 0 && a2 < 0)
     {
          a1 *= (-1);
          a2 *= (-1);
     }
     printf("\n\tTich 2 phan so: %d/%d.", a1, a2);
}

// divide 2 fractions
fraction FractionsDivide(fraction phanso1, fraction phanso2)
{
     int div, denominator, a1, a2;
     printf("\n\tNhap phan so thu 1 (a/b): ");
     scanf("%d/%d", &phanso1.a, &phanso1.b);
     printf("\n\tNhap phan so thu 2 (a/b): ");
     scanf("%d/%d", &phanso2.a, &phanso2.b);
     div = (phanso1.a * phanso2.b);
     denominator = (phanso1.b * phanso2.a);
     a1 = div / gcd(div, denominator);
     a2 = denominator / gcd(div, denominator);
     if (a1 > 0 && a2 < 0)
     {
          a1 *= (-1);
          a2 *= (-1);
     }
     printf("\n\tThuong 2 phan so: %d/%d.", a1, a2);
}

// dash
void dash() {
	char ch = '-';
	int n = 44, i;
	for (i = 0; i <= n; ++i) {
		printf("%c", ch);
	}
}

// hien thi chuong trinh
fraction display()
{
     printf("---------- CHUONG TRINH VE PHAN SO ----------");
     printf("\n1. Tinh tong, hieu, tich, thuong 2 phan so.\n");
     printf("2. Kiem tra phan so toi gian.\n");
     printf("3. Quy dong 2 phan so.\n");
     printf("4. Kiem tra phan so am hay duong.\n");
     printf("5. So sanh 2 phan so.\n");
     printf("6. Nhap/xuat phan so.\n");
     printf("7. Rut gon phan so.\n");
}

// kiem tra phan so da duoc toi gian or not
int check(fraction phanso)
{
     if (gcd(phanso.a, phanso.b) == 1)
     {
          return 1;
     }
     else
          return 0;
}

// toi gian phan so
fraction isSimplified(fraction phanso)
{
     printf("\n\tNhap phan so: ");
     scanf("%d/%d", &phanso.a, &phanso.b);
     if (check(phanso))
     {
          printf("\n\tPhan so da duoc toi gian!");
     }
     else
          printf("\n\tPhan so chua duoc toi gian!");
}

// quy dong 2 phan so
fraction QuyDong(fraction phanso1, fraction phanso2)
{
     int nom1, nom2, denominator;
     printf("\n\tNhap phan so thu 1 (a/b): ");
     scanf("%d/%d", &phanso1.a, &phanso1.b);
     printf("\n\tNhap phan so thu 2 (a/b): ");
     scanf("%d/%d", &phanso2.a, &phanso2.b);
     denominator = phanso2.a * phanso2.b;
     phanso1.a *= phanso2.b;
     phanso2.a *= phanso1.b;
     printf("\n\tPhan so sau khi duoc quy dong: %d/%d, %d/%d", phanso1.a, denominator, phanso2.a, denominator);
}

// kiem tra phan so am hay duong
fraction NegativeOrPositive(fraction phanso)
{
     printf("\n\tNhap phan so (a/b): ");
     scanf("%d/%d", &phanso.a, &phanso.b);
     if (phanso.b < 0)
     {
          phanso.a *= -1;
          phanso.b *= -1;
     }
     if (phanso.a > 0 && phanso.b > 0)
     {
          printf("\n\t%d/%d la phan so duong.", phanso.a, phanso.b);
     }
     else if (phanso.a < 0 && phanso.b < 0)
     {
          printf("\n\t%d/%d la phan so duong.", phanso.a, phanso.b);
     }
     else if (phanso.a < 0 && phanso.b > 0 || phanso.a > 0 && phanso.b < 0)
     {
          printf("\n\t%d/%d la phan so am.", phanso.a, phanso.b);
     }
}

// so sanh 2 phan so
fraction FractionsComparison(fraction phanso1, fraction phanso2)
{
     int nom1, nom2, denominator;
     printf("\n\tNhap phan so thu 1 (a/b): ");
     scanf("%d/%d", &phanso1.a, &phanso1.b);
     printf("\n\tNhap phan so thu 2 (a/b): ");
     scanf("%d/%d", &phanso2.a, &phanso2.b);
     phanso1.a *= phanso2.b;
     phanso2.a *= phanso1.b;
     if (phanso1.a > phanso2.a)
     {
          printf("\n\tPhan so thu 1 lon hon phan so thu 2.");
     }
     else if (phanso1.a < phanso2.a)
     {
          printf("\n\tPhan so thu 1 nho hon phan so thu 2.");
     }
     else
          printf("\n\t2 phan so bang nhau.");
}

// toi gian phan so
fraction toigian(fraction phanso)
{
     printf("\n\tNhap phan so: ");
     scanf("%d/%d", &phanso.a, &phanso.b);
     printf("\n\tPhan so vua nhap: %d/%d.\n", phanso.a, phanso.b);
     phanso = FractionSimplification(phanso);
     printf("\n\tPhan so sau khi toi gian: ");
     output(phanso);
}

// tinh toan
fraction calculate()
{
     char mathSign;
     do
     {
          fflush(stdin);
          printf("\n\tChon phep tinh (+, -, *, /): ");
          scanf("%c", &mathSign);
          if (mathSign != '+' && mathSign != '-' && mathSign != '*' && mathSign != '/')
          {
               printf("\n\tPhep tinh khong hop le!");
          }
     } while (mathSign != '+' && mathSign != '-' && mathSign != '*' && mathSign != '/');
     switch (mathSign)
     {
     case '+':
          FractionsSum(phanso1, phanso2);
          break;
     case '-':
          FractionsSubtract(phanso1, phanso2);
          break;
     case '*':
          FractionsMultiply(phanso1, phanso2);
          break;
     case '/':
          FractionsDivide(phanso1, phanso2);
          break;
     default:
          break;
     }
}

// choice
fraction choiceOf()
{
     char tinhs;
     do
     {
     	dash();
          printf("\nHay chon chuong trinh: ");
          scanf("%d", &choice);
          switch (choice)
          {
          case 1:
               calculate();
               break;
          case 2:
               isSimplified(phanso);
               break;
          case 3:
               QuyDong(phanso1, phanso2);
               break;
          case 4:
               NegativeOrPositive(phanso);
               break;
          case 5:
               FractionsComparison(phanso1, phanso2);
               break;
          case 6:
               InAndOut(phanso);
               break;
          case 7:
               toigian(phanso);
               break;
          default:
               printf("\n\tKhong hop le. Hay thu lai.");
               break;
          }
          fflush(stdin);
          printf("\n\nBan co muon thoat chuong trinh khong? (Y/N): ");
          scanf("%c", &tinhs);
          if (tinhs == 'Y' || tinhs == 'y')
          {
               printf("\n\tThoat chuong trinh thanh cong!");
          }
     } while (tinhs == 'N' || tinhs == 'n');
}

// main function
int main()
{
     system("cls");
     display();
     choiceOf();
     return 0;
}
