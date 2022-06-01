#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

#define MAX_WORD 10
#define MAX_MEANING 200

typedef struct {
    char word[MAX_WORD];
    int count;
}Element;

typedef struct TreeNode {
    Element key;
    struct TreeNode* left, * right;
}TreeNode;

int Compare(char e1[], char e2[]) {
    return strcmp(e1, e2);
}

TreeNode* Search(TreeNode* root, char key[]) { 
    TreeNode* p = root;
    while (p != NULL) {
        if (Compare(key, p->key.word) == 0) return p;
        else if (Compare(key, p->key.word) < 0) p = p->left;
        else if (Compare(key, p->key.word) > 0) p = p->right;
    }
    return p; 
}

TreeNode* NewNode(Element item) {
    TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
    strcpy(temp->key.word, item.word);
    temp->key.count = item.count;
    temp->left = temp->right = NULL;
    return temp;
}

TreeNode* InsertNode(TreeNode* node, Element key) {
    if (node == NULL) return NewNode(key); 

    if (Compare(key.word, node->key.word) < 0)
        node->left = InsertNode(node->left, key); 

    else if (Compare(key.word, node->key.word) > 0)
        node->right = InsertNode(node->right, key);
    return node;
}

TreeNode* GetMinValueNode(TreeNode* node) { 
    TreeNode* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

TreeNode* DeleteAll(TreeNode* root) { 
    if (root == NULL) return root;

    root->left = DeleteAll(root->left);
    if (root->left != NULL) {
        free(root->left);
        root->left = NULL;
    }

    root->right = DeleteAll(root->right);
    if (root->right != NULL) {
        free(root->right);
        root->right = NULL;
    }

    return root;
}

TreeNode* DeleteNode(TreeNode* root, char key[]) {
    if (root == NULL) return root;

    if (Compare(key, root->key.word) < 0) 
        root->left = DeleteNode(root->left, key);

    else if (Compare(key, root->key.word) > 0)
        root->right = DeleteNode(root->right, key);

    else {
        if (root->left == NULL) {
            TreeNode* temp = root->right;
            free(root);
            return temp;
        }

        else if (root->right == NULL) {
            TreeNode* temp = root->left;
            free(root);
            return temp;
        }

        TreeNode* temp = GetMinValueNode(root->right);
        root->key = temp->key;
        root->right = DeleteNode(root->right, temp->key.word);
    }
    return root;
}

TreeNode* max_node = NULL;
int max;

void GetMaxWord(TreeNode* ptr) {
    if (ptr != NULL) {
        GetMaxWord(ptr->left);
        GetMaxWord(ptr->right);
        if (ptr->key.count > max) {
            max = ptr->key.count;
            max_node = ptr;
        }
    }
}

void Fileout(TreeNode* p, FILE *fw) {
    if (p != NULL) {
        Fileout(p->left,fw);
        fprintf(fw,"[ 예약어: %-6s  출현빈도: %2d번 ]\n", p->key.word, p->key.count);
        Fileout(p->right,fw);
    }
}

void Show(TreeNode* p) {
    if (p != NULL) {
        Show(p->left);
        printf("[ 예약어: %-6s  출현빈도: %2d번 ]\n\n", p->key.word, p->key.count);
        Show(p->right);
    }
}

int main(void) {
    FILE* fp = NULL;
    FILE* fw = NULL;
    fw = fopen("bst_out.txt", "w");
    fp = fopen("bst_in.txt", "r");

    if (fp == NULL) {
        printf("파일열기 실패\n");
        return 0;
    }

    if (fw == NULL) {
        printf("파일열기 실패\n");
        return 0;
    }

    Element w[11] = { {"break",0}, {"case",0}, {"do",0}, {"else",0}, {"for", 0}, {"if", 0},
        {"int",0}, {"return",0}, {"struct", 0}, {"switch", 0}, {"while", 0} }; 

    Element tmp;

    TreeNode* root = NULL;

    while (!feof(fp)) {
        char str[300];
        fgets(str, sizeof(str), fp); 
        char* ptr = strtok(str, " "); 
        while (ptr != NULL) {
            char reserve[200] = { 0, };
            int index = 0;
            for (int i = 0; i < strlen(ptr); i++) {
                if (ptr[i] >= 'a' && ptr[i] <= 'z') { 
                    reserve[index++] = ptr[i];
                }
            }
            for (int i = 0; i < 11; i++) {
                if (Compare(reserve, w[i].word) == 0) { 
                    TreeNode* temp = Search(root, reserve); 

                    if (temp != NULL)
                        temp->key.count++; 
                    else { 
                        tmp.count = 1;
                        strcpy(tmp.word, reserve);
                        root = InsertNode(root, tmp);
                    }
                }
            }
            ptr = strtok(NULL, " "); 
        }
    }
    Fileout(root, fw);

    while (1) {
        int n;
        char s[20];
        printf("\n[ 0. 종료 | 1. 트리출력 | 2. 자주 등장하는 예약어 | 3. 노드삭제 ] --- > ");
        scanf("%d", &n);
        if (n == 0) break;
        switch (n) {
        case 1:
            Show(root);
            printf("\n");
            break;

        case 2:
            max = root->key.count;
            GetMaxWord(root);
            printf("\n<--- 자주 출현한 예약어는 %d번 등장한 %s 입니다. --- >\n", max_node->key.count, max_node->key.word);
            break;

        case 3:
            printf("삭제할 예약어를 입력하시오 --- > ");
            scanf("%s", s);
            DeleteNode(root, s);
            break;
        }
    }
    root = DeleteAll(root);
    free(root);
    fclose(fp);
    fclose(fw);
    return 0;
}