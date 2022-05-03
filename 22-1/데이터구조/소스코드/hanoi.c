#include<stdio.h>

void hanoi(int n, char from, char via, char to){
    if(n == 1) printf("원판 1을 %c에서 %c로 옮긴다\n", from, to);
    else{
        hanoi(n-1, from, to, via);
        printf("원판 %d를 %c에서 %c로 옮긴다\n", n, from, to);
        hanoi(n-1, via, from, to);
    }
}

int main(){
    hanoi(3, 'A', 'B', 'C');
}

