#include<stdio.h>
#define MAX_SIZE 100

// (1) ������ �迭�� ����� �������� SparseMatrix ������ �����ϴ� �Լ�
// (2) �� ���� SparseMatrix�� �Ű������� �޾Ƽ� ������ ����� SparseMatrix�� ��ȯ�ϴ� �Լ�
// (3) SparseMatrix�� ����� ������ 0�� ������ ������ ���� ���·� ����ϴ� �Լ�

// main()���� �׽�Ʈ�ϱ�
// �� �迭 a[][], b[][], c[][]�� (1)�� �̿��Ͽ� ���� SparseMatrix A, B, C�� ��ȯ�ϱ�
// A+B�� (2)�� ����ϰ�,��ȯ�� ��� SparseMatrix�� (3)�� �̿��Ͽ� ����ϱ�
// A+C�� (2)�� ����Ͽ� ��ȯ�� ��� SparseMatrix�� (3)�� �̿��Ͽ� ����ϱ�
// B+C�� (2)�� ����Ͽ� ��ȯ�� ��� SparseMatrix�� (3)�� �̿��Ͽ� ����ϱ�

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