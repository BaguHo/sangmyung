/*
(���� ����� ó���� ���̵��� ���Ƽ� ����� ���, Ű���� �Է����� ����� �� �ֽ��ϴ�)

�ڽ��� �ۼ��ϴ� c��� �ҽ��ڵ� ���Ͽ� �� ���� �󸶳� ���� �����ϴ����� ����ϴ� ���α׷��� ����Ž��Ʈ���� ����Ͽ� �����Ͻÿ�.

(1) �Է�: �ڽ��� �ۼ��� ������ c ���α׷� �ҽ������� "bst_in.txt"��� ���ϸ��� �����Ѵ�.
    ���: ������ ������� ������(�������� ��������) ȭ�� ����Ѵ�.
          �Ǵ� ��������� "bst_out.txt"�� �����Ѵ�.
(2) c����� ������ �߿��� ���� �������� ���� �󵵸� ����Ѵ�.
    {"break", "case", "do", "else", "for", "if", "int", "return", "switch", "while", "else if"}
    �� �ܿ��� �ڽ��� ���� ����ϴ� �ٸ� �������� �߰��� ���� ������.
(3) ����Ž��Ʈ�� �� ����� ������ �ʵ�� �����(���ڿ�)�� ������(����)�̴�.
(4) �Է������� ���ʷ� �����鼭
    - ó�� �����ϴ� ������ ����Ž��Ʈ���� �����ϰ� �����󵵸� 1�� �ʱ�ȭ�Ѵ�.
    - �˻� �� �̹� Ʈ���� �����ϴ� ������ �����󵵸� 1��ŭ ������Ų��.
(5) �ϼ��� ����Ž��Ʈ���� ������ȸ�ϸ鼭 ������� �����󵵸� �Բ� ����Ѵ�.
(6) ���� ���� ������ �����(�󵵼� �ִ밪)�� �������� ã�Ƽ� ����Ѵ�.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<memory.h>
#define MAX 1000 


typedef struct TreeNode {
    char key[MAX];
    int fre;
    struct TreeNode* left, * right;
}TreeNode;

TreeNode* root = NULL;
TreeNode* maximum;

//���˻�
TreeNode* search(TreeNode* node, char *key) {
    if (node == NULL) return NULL;
    
    if (strcmp(key, node->key) == 0) {
        node->fre++;
        return;
    }

    else if (strcmp(key, node->key) == -1) {
        return search(node->left, key);
    }
    else {
        return search(node->right, key);
    }
}

//������
TreeNode* new_node(char *item) {
    TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
    strcpy(temp->key,item);
    temp->fre = 1;//�� 1�� �ʱ�ȭ
    temp->left = temp->right = NULL;
    return temp;
}

//������
TreeNode* insert_node(TreeNode* node, char *key) {
    //Ʈ���� �����̸� ���ο� ��带 ��ȯ
    if (node == NULL) return new_node(key);
    //�׷��� ������ ��ȯ������ Ʈ�� �������鼭 �ڸ� ã��
    if (strcmp(key, node->key) == -1)   node->left = insert_node(node->left, key);
    else if (strcmp(key, node->key) == 1)  node->right = insert_node(node->right, key);
    //����� ��Ʈ ������ ��ȯ
    return node;
}

//������ȸ
void inorder(TreeNode* root,FILE* fp2) {
    if (root) {
        inorder(root->left,fp2); //���ʼ���Ʈ�� ��ȸ
        fprintf(fp2, "**[%s]: %d\n", root->key, root->fre);
        inorder(root->right,fp2); //�����ʼ���Ʈ�� ��ȸ
    }
}

//�� �ִ밪
TreeNode* findmax(TreeNode* node) {
    if (node != NULL) {
        findmax(node->left);//���ʼ�ȸ
        findmax(node->right);//�����ʼ�ȸ
        if (maximum->fre <= node->fre) {
            strcpy(maximum->key, node->key);
            maximum->fre = node->fre;
        }
    }
    return;
}

int main(void) {
    FILE* fp1 = fopen("bst_in.txt", "r");
    FILE* fp2 = fopen("bst_out.txt", "w");
    if (fp1 == NULL) {
        printf("������ �������� �ʽ��ϴ�.\n");
        exit(1);
    }

    char *p = malloc(sizeof(char) * MAX);
    char *arr[] = { "void","fprintf","printf","break","case","do", "else", "for", "if", "int", "return", "switch", "while" };

    while (!feof(fp1)) {
        fscanf(fp1, "%s", p);//��������� �޾ƿ�
        for (int i = 0; i < 13; i++) {
            if (strstr(p, arr[i])) {
                if (search(root, arr[i]) == NULL) {
                    root = insert_node(root, arr[i]);
                    break;//���� �ܾ� �޾ƿ���
                }
                else continue;
            }
        }
    }

    inorder(root,fp2);//������ȸ�� ���

    maximum = root;
    findmax(root);

    fprintf(fp2, "***************************\n");
    fprintf(fp2,"**�� �ִ� ��-> %s: %d\n", maximum->key,maximum->fre);

    free(p);
    fclose(fp2);
    fclose(fp1);

    printf("�Ϸ�\n");
    return 0;
}