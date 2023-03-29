#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 1000
// in hoa
void firstUppercaseLetter(char *name, int n)
{
     int i;
     printf("\nChuoi sau khi xu ly: ");
     for (i = 0; i < n; ++i)
     {
          if (i == 0 && name[i] != ' ' || name[i - 1] == ' ')
          {
               if (name[i] >= 'a' && name[i] <= 'z')
               {
                    name[i] = (char)(name[i] - 32);
               }
          }
          else if (name[i] >= 'A' && name[i] <= 'Z')
          {
               name[i] = (char)(name[i] + 32);
          }
     }
     puts(name);
}

// remove white space
void removeWhiteSpace(char *name)
{
     printf("Chuoi sau khi loai bo khoang trang: ");
     int len = strlen(name), i, j;

     // remove white space at the beginning
     i = 0;
     while (isspace(name[i]))
     {
          i++;
     }
     memmove(name, name + i, len - i + 1);

     // remove white space at the end
     j = len - 1;
     while (j >= 0 && isspace(name[i]))
     {
          j--;
     }
     name[j + 1] = '\0';

     // remove white space in the middle
     i = 0;
     j = 0;
     while (name[j])
     {
          if (!isspace(name[j]))
          {
               name[i++] = name[j];
          }
          j++;
     }
     name[i] = '\0';
     puts(name);
}

// count
int count(char *name, int n)
{
     int count = 0, i = 0;
     while (name[i] != '\0')
     {
          if (name[i] == ' ' && name[i - 1] != ' ')
          {
               count++;
          }
          i++;
     }
     printf("\nSo tu co trong chuoi la: %d", count + 1);
     return count;
}

// print each word
void printWord(char *name, int n)
{
	int i;
     printf("\nXuat cac tu tren cac dong lien tiep: \n");
     for (i = 0; name[i] != '\0'; ++i)
     {
          printf("%c", name[i]);
          if (name[i] == ' ' && name[i - 1] != ' ')
          {
               printf("\n");
          }
     }
}

// tim tu dai nhat co trong chuoi
void findTheLongestWord(char *name)
{
     char longest[MAX];
     int length, i, index = 0, max_word_len = 0, word_len = 0;
     printf("\n\tNhap chuoi: ");
     gets(name);

     length = strlen(name);

     for (i = 0; i <= length; ++i) {
          if (name[i] != ' ' && name[i] != '\0') {
               word_len++;
               continue;
          }

          if (word_len > max_word_len) {
               max_word_len = word_len;
               index = i - max_word_len;
          }

          word_len = 0; // set word length to 0
     }

     for (i = 0; i < max_word_len; i++) {
          longest[i] = name[index + i];
     }

     longest[i] = '\0';

     printf("\n\tTu dai nhat trong chuoi la: %s", longest);
}

// // trich ra n ky tu dau tien/cuoi cung/bat dau tai vi tri pos
// void extractFirstChar(char *name)
// {
//      int pos, n, len;
//      do
//      {
//           printf("Nhap so ky tu can trich xuat: ");
//           scanf("%d", &n);
//           printf("Nhap vi tri trich xuat: ");
//           scanf("%d", &pos);
//           len = strlen(name);
//           if (pos >= len)
//           {
//                printf("\nKhong hop le. Hay thu lai!\n");
//           }
//      } while (pos >= len);
//      char first_n[n];
//      strncpy(first_n, name + pos, n);
//      first_n[n] = '\0';
//      printf("%d ky tu dau tien tai vi tri %d la: %s", n, pos, first_n);
// }
int main()
{
     system("cls");
     char name[MAX];
     int n = sizeof(name) / sizeof(name[0]);
     findTheLongestWord(name);
     return 0;
}
