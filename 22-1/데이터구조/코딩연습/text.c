#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX_EXPONENT 101

typedef struct polynomial {
   double coef;
   int exponent;
}polynomial;

polynomial p[MAX_EXPONENT];
int avil = 0;

void print_poly(int start, int end){
   for (int i = start; i <= end; i++){
      if (i != start)
         printf(" + ");
      if (p[i].exponent == 1)
         printf("%.1lfx", p[i].coef);
      else if (p[i].exponent == 0)
         printf("%.1lf", p[i].coef);
      else 
         printf("%.1lfx^%d", p[i].coef, p[i].exponent);
   }
   printf("\n");
}

void attach(double coef, int exponent){
   p[avil].coef = coef;
   p[avil].exponent = exponent;
   avil++;
}

double insert_num(int start, int end, int n){
   double result = 0;
   for (int i = start; i <= end; i++){
      result += p[i].coef * pow(n, p[i].exponent);
   }
   return result;
}

void minus_poly(int As, int Ae, int Bs, int Be){
    double num;
    while (As <= Ae && Bs <= Be){
        if (p[As].exponent > p[Bs].exponent){
            attach(p[As].coef, p[As].exponent);
            As++;
        }
        else if (p[As].exponent == p[Bs].exponent){
            num = p[As].coef - p[Bs].coef;
            if (num != 0)
                attach(num, p[As].exponent);
            As++;
            Bs++;
        }
        else{
            attach(-1*p[Bs].coef, p[Bs].exponent);
            Bs++;
        }
   }
    for (; As <= Ae; As++){
        attach(p[As].coef, p[As].exponent);
        As++;
    }
    for (; Bs <= Be; Bs++){
        attach(p[Bs].coef, p[Bs].exponent);
        Bs++;
    }
}

int main(void){
   int As = 0, Ae, Bs, Be, Cs, Ce;
   int n;
   int temp;
   while(1){
      printf("0. ���α׷� ����\n");
      printf("1. ���׽� �Է�\n");
      scanf("%d", &temp);
      if(temp == 1){
         printf("1��° ���׽��� ���� �� ���Դϱ�?\n");
         scanf("%d", &temp);
         for(int i = 0; i < temp; i++){
            printf("���, ���� �Է�\n");
            scanf("%lf %d", &p[avil].coef, &p[avil].exponent);
            avil++;
         }
         Ae = avil - 1;
         Bs = avil;
         printf("2��° ���׽��� ���� �� ���Դϱ�?\n");
         scanf("%d", &temp);
         for(int i = 0; i < temp; i++){
            printf("���, ���� �Է�\n");
            scanf("%lf %d", &p[avil].coef, &p[avil].exponent);
            avil++;
         }
         Be = avil - 1;
         Cs = avil;
         print_poly(As, Ae);
         print_poly(Bs, Be);
         minus_poly(As, Ae, Bs, Be);
         Ce = avil - 1;
         printf("========================================\n");
         print_poly(Cs, Ce);
         temp = 1;
         while (temp != 0){
            printf("0. ����\n");
            printf("1. A - B ���׽Ŀ� x�� ����\n");
            scanf("%d", &temp);
            if(temp == 1){
               printf("x���� �Է����ּ���\n");
               scanf("%d", &n);
               printf("%1.lf\n", insert_num(Cs, Ce, n));
               printf("==============================\n");
            }
            else if(temp == 0){
               break;
            }
         }
         return 0;  
      }
      else if(temp == 0){
         return 0;
      }
      else{
         break;
      }
   }
}