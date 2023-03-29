#include <stdio.h>

float laiSuatKep(float tienVon, float soNam, float laiSuatHangNam)
{
     if (soNam == 0)
     {
          return tienVon;
     }
     float tienLaiHangNam = tienVon * laiSuatHangNam / 100;
     return laiSuatKep(tienVon + tienLaiHangNam, soNam - 1, laiSuatHangNam);
}

int main()
{
     printf("%.3fVND", laiSuatKep(120000, 5, 7));
}