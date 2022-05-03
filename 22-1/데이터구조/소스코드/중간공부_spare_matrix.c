#include<stdio.h>
#define MAX_SIZE 100

// (1) 이차원 배열에 저장된 희소행렬을 SparseMatrix 구조로 저장하는 함수
// (2) 두 개의 SparseMatrix를 매개변수로 받아서 덧셈한 결과로 SparseMatrix를 반환하는 함수
// (3) SparseMatrix에 저장된 내용을 0을 포함한 이차원 형렬 형태로 출력하는 함수

// main()에서 테스트하기
// 위 배열 a[][], b[][], c[][]를 (1)을 이용하여 각각 SparseMatrix A, B, C로 변환하기
// A+B를 (2)로 계산하고,반환된 결과 SparseMatrix를 (3)을 이용하여 출력하기
// A+C를 (2)로 계산하여 반환된 결과 SparseMatrix를 (3)을 이용하여 출력하기
// B+C를 (2)로 계산하여 반환된 결과 SparseMatrix를 (3)을 이용하여 출력하기

typedef struct{
    int row;
    int column;
    int data;
}element;

typedef struct{
    element data[MAX_SIZE];
    int row_term;
    int column_term;
    int terms;
}SpareMatrix;

SpareMatrix ConvertSpraeMatrix(int arr[][10], int row_term, int column_term){
    SpareMatrix temp;
    temp.column_term = column_term;
    temp.row_term = row_term;
    temp.terms = 0;
    int idx = 0;
    for(int i = 0; i < 8; i++){
        for(int k = 0; k < 10; k++){
            if(arr[i][k] != 0){
                temp.data[idx].row = i;
                temp.data[idx].column = k;
                temp.data[idx++].data = arr[i][k];
                temp.terms++;
            }
        }
    }
}

SpareMatrix PlusSpareMatrix(SpareMatrix a, SpareMatrix b){
    SpareMatrix temp;
    int cur_a = 0, cur_b = 0, cur_temp = 0;
    while(cur_a <= a.terms && cur_b <= b.terms){
        if(a.data[cur_a].row < b.data[cur_b].row){
            temp.data[cur_temp++] = a.data[cur_a++];
        }
        else if(a.data[cur_a].row == b.data[cur_b].row){
            if(a.data[cur_a].column == b.data[cur_b].column){
                if(a.data[cur_a++].data + b.data[cur_b++].data == 0){
                    cur_a++;
                    cur_b++;
                }
                else{
                    temp.data[cur_temp].row = b.data[cur_b].row;
                    temp.data[cur_temp].column = b.data[cur_b].column;
                    temp.data[cur_temp++].data = a.data[cur_a++].data + b.data[cur_b++].data;
                }
            }
            else if(a.data[cur_a].column < b.data[cur_b].column){
                temp.data[cur_temp++] = a.data[cur_a++];
            }
            else{
                temp.data[cur_temp++] = b.data[cur_b++];
            }
        }
        else{
            temp.data[cur_temp++] = b.data[cur_b++];
        }   
    }
    for(;cur_a < a.terms; cur_a++){
        temp.data[cur_temp++] = a.data[cur_a++];
    }
    for(;cur_b < b.terms; cur_b++){
        temp.data[cur_temp++] = b.data[cur_b++];
    }
    temp.terms = cur_temp;
    return temp;
}

int main(){
    int a[8][10] = { { 0, 0, 0, 0, 2, 0, 0, 0, 0, 0 },
                    { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 },
                    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                    { 0, 0, 0, 0, 0, 0, 0,-3, 0, 0 },
                    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                    { 0,-1, 0, 0, 0, 0, 0, 0, 0, 0 },
                    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }};

    int b[8][10] = { { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                    { 0, 0, 0,-1, 0, 0, 0, 0, 0, 0 },
                    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                    { 0, 0, 0, 0, 2, 0, 0, 0, 0, 0 },
                    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                    { 0, 0, 0, 0, 0, 0, 2, 0, 0, 0 }};

    int c[8][10] = { { 0, 0, 0, 0,-2, 0, 0, 0, 0, 0 },
                    { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 },
                    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 3 },
                    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                    { 0, 0, 0, 0,-2, 0, 0, 0, 0, 0 },
                    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                    { 0, 0, 0, 0, 0, 0, 4, 0, 0, 0 }};
}