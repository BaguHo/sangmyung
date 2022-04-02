#include<stdio.h>
#define MAX_TERM 101

typedef struct{
    int row;
    int column;
    int data;
}element;

typedef struct{
    element data[MAX_TERM];
    int row_term; // 행의 개수
    int column_term; // 열의 개수
    int terms; // 값의 개수
}SparseMatrix;

void PrintSparseMatrix(SparseMatrix p){
    int idx = 0;

    for(int i = 0; i < p.row_term; i++){
        if(p.data[idx].row != i){
            for(int k = 0; k < p.column_term; k++){
                printf("0 ");
            }
            printf("\n");
        }
        else{ // p.data[idx].row == i
            for(int k = 0; k < p.column_term; k++){
                if(p.data[idx].column == k && p.data[idx].row == i){
                    printf("%d ", p.data[idx++].data);
                }
                else{
                    printf("0 ");
                }
            }
            printf("\n");
        }
    }
    printf("==============================\n");
}

// SparseMatrix에서 마지막 항에 들어가는게 행의 항, 열의 항, 0이 아닌 항의 개수
SparseMatrix TransposeMatrix(int p[8][10], int row_term, int column_term){
    SparseMatrix result;
    int data_idx = 0;
    result.row_term = row_term;
    result.column_term = column_term;
    result.terms = 0;

    for(int i = 0; i < row_term; i++){
        for(int k = 0; k < column_term; k++){
            if(p[i][k] != 0){
                result.data[data_idx].row = i;
                result.data[data_idx].column = k;
                result.data[data_idx++].data = p[i][k];
                result.terms++;
            }
        }
    }
    return result;
}

SparseMatrix PlusSparseMatrix(SparseMatrix a, SparseMatrix b){
    SparseMatrix temp;
    int cur_a = 0, cur_b = 0, cur_temp = 0;
    temp.row_term = a.row_term;
    temp.column_term = a.column_term;
    temp.terms = 0;

    while(cur_a < a.terms && cur_b < b.terms){
        if(a.data[cur_a].row < b.data[cur_b].row){
            temp.data[cur_temp++] = a.data[cur_a++];
        }
        else if(a.data[cur_a].row == b.data[cur_b].row){
            if(a.data[cur_a].column == b.data[cur_b].column){
                if(a.data[cur_a].data + b.data[cur_b].data != 0){
                    temp.data[cur_temp].row = a.data[cur_a].row;
                    temp.data[cur_temp].column = a.data[cur_a].column;
                    temp.data[cur_temp++].data = a.data[cur_a++].data + b.data[cur_b++].data;
                }
                else{
                    cur_a++;
                    cur_b++;
                }
            }
            else if(a.data[cur_a].column < b.data[cur_b].column){
                temp.data[cur_temp++] =  a.data[cur_a++];
            }
            else{
                temp.data[cur_temp++] =  b.data[cur_b++];
            }
        }
        else{
            temp.data[cur_temp++] = b.data[cur_b++];
        }
    }
    for(;cur_a < a.terms; cur_a++){
        temp.data[cur_temp++] = a.data[cur_a];
    }
    for(;cur_b < b.terms; cur_b++){
        temp.data[cur_temp++] = b.data[cur_b];
    }

    temp.terms = cur_temp;
    return temp;
}

int main(){
    int qurter;
    int temp;
    int a[8][10] = {
        { 0, 0, 0, 0, 2, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0,-3, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0,-1, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    };
    int row_a = 8, column_a = 10;
 
    int b[8][10] = {
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0,-1, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 2, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 2, 0, 0, 0 }
    };
    int row_b = 8, column_b = 10;

    int c[8][10] = { 
        { 0, 0, 0, 0,-2, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 3 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0,-2, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 4, 0, 0, 0 }
    };
    int row_c = 8, column_c = 10;
    SparseMatrix sparse_a, sparse_b, sparse_c, result_sparse;

    sparse_a = TransposeMatrix(a, row_a, column_a);
    sparse_b = TransposeMatrix(b, row_b, column_b);
    sparse_c = TransposeMatrix(c, row_c, column_c);

    printf("희소행렬 A\n");
    PrintSparseMatrix(sparse_a);
    printf("희소행렬 B\n");
    PrintSparseMatrix(sparse_b);
    printf("희소행렬 C\n");
    PrintSparseMatrix(sparse_c);

    printf("0. 프로그램 종료\n");
    printf("1. 희소행렬 덧셈\n");
    scanf("%d", &qurter);
    printf("=========================\n");
    switch(qurter){
        case 0:
            return 0;
            break;
        case 1:
            printf("1. A + B \n");
            printf("2. A + C \n");
            printf("3. B + C \n");
            printf("=========================\n");
            scanf("%d", &temp);
            switch (temp)
            {
            case 1:
                result_sparse = PlusSparseMatrix(sparse_a, sparse_b);
                PrintSparseMatrix(result_sparse);
                break;
            case 2:
                result_sparse = PlusSparseMatrix(sparse_a, sparse_c);
                PrintSparseMatrix(result_sparse);
                break;
            case 3:
                result_sparse = PlusSparseMatrix(sparse_b, sparse_c);
                PrintSparseMatrix(result_sparse);
                break;
            default:
                printf("1. A + B \n");
                printf("2. A + C \n");
                printf("3. B + C \n");
                printf("=========================\n");
                scanf("%d", &temp);
                break;            
            }
            break;
        default:
            printf("0. 프로그램 종료\n");
            printf("1. 희소행렬 덧셈\n");
            scanf("%d", &qurter);
            break;
    }

}