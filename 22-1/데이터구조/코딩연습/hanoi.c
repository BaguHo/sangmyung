#include<stdio.h>

void hanoi(int n, char from, char via, char to){
    if(n == 1) printf("���� 1�� %c���� %c�� �ű��\n", from, to);
    else{
        hanoi(n-1, from, to, via);
        printf("���� %d�� %c���� %c�� �ű��\n", n, from, to);
        hanoi(n-1, via, from, to);
    }
}

int main(){
    hanoi(3, 'A', 'B', 'C');
}

