#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<memory.h>

typedef struct{
    char str[30];
    int count;
}Element;

typedef struct __node{
    Element key;
    struct __node* left, *right;   
}TreeNode;

TreeNode* NewNode(Element item){
    TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
    temp->key = item;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

TreeNode* Search(TreeNode* root, char *key){
    if(root == NULL)
        return NULL;
    if(strcmp(key, root->key.str) == 0) 
        return root;
    else if (strcmp(key, root->key.str) == 1)
        return Search(root->left, key);
    else
        return Search(root->right, key);
}

TreeNode* Insert(TreeNode* root, Element key){
    if(root == NULL)
        return NewNode(key);

    if(strcmp(key.str, root->key.str) == -1)
        root->left = Insert(root->left, key);
    else if(strcmp(key.str, root->key.str) == 1) 
        root->right = Insert(root->right, key);
    
    return root;
}

TreeNode* GetMinimumValueNode(TreeNode* root){
    TreeNode* current = root;
    while(current->left != NULL)
        current = current->left;
    return current;
}

TreeNode* GetMaximumValueNode(TreeNode* root){
    TreeNode* current = root;
    while(current->right != NULL)
        current = current->right;
    return current;
}

TreeNode* DeleteNode(TreeNode* root, Element target){
    if(root == NULL)    return root;
    if(target.count < root->key.count)
        root->left = DeleteNode(root->left, target);
    else if(target.count > root->key.count)
        root->right = DeleteNode(root->right, target);
    // target == root->key
    else{
        // �ܸ���� �̰ų�, ����Ʈ���� �ϳ��� ���
        if(root->left == NULL){
            TreeNode* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            TreeNode*  temp = root->left;
            free(root);
            return temp;
        }
        // ������ ����Ʈ������ ���� ���� ���� �����ͼ� ������ ��� ��ü
        TreeNode* temp = GetMinimumValueNode(root->right);

        root->key = temp->key;
        root->right = DeleteNode(root->right, temp->key);
    }
    return root;
}

void Inorder(TreeNode* root){
    if(root != NULL){
        Inorder(root->left);
        printf("str = %s\ncount = %d \n", root->key.str, root->key.count);
        printf("=============================\n");
        Inorder(root->right);
    }
}

int Compare(char e1[], char e2[]) {
    return strcmp(e1, e2);
}
void Fileout(TreeNode* p, FILE *fw) {
    if (p != NULL) {
        Fileout(p->left,fw);
        fprintf(fw,"[ �����: %-6s  ������: %2d�� ]\n", p->key.str, p->key.count);
        Fileout(p->right,fw);
    }
}

int main(){
    TreeNode* root = NULL;
    char temp[30];
    int num;

    while(1){
        printf("===========================================\n");
        printf("0. ���α׷� ����\n");
        printf("1. ����� ã��\n");
        printf("2. ������ȸ ���\n");
        printf("3. Ư���� ����� ����\n");
        scanf("%d", &num);
        switch (num)
        {
        case 0:
            return 0;
            break;
        case 1:
        {
            FILE* fp = NULL;
            FILE* fw = NULL;
            fw = fopen("bst_out.txt", "w+");
            fp = fopen("bst_in.txt", "r");

            if (fp == NULL) {
                printf("���Ͽ��� ����\n");
                return 0;
            }

            if (fw == NULL) {
                printf("���Ͽ��� ����\n");
                return 0;
            }

            char* arr[11] = { {"break"}, {"case"}, {"do"}, {"else"}, {"for"}, {"if"},
                {"int"}, {"return"}, {"struct"}, {"switch"}, {"while"} }; 

            Element tmp;

            TreeNode* root = NULL;

            while (!feof(fp)) {
                char str[300];
                fgets(str, sizeof(str), fp); 
                char* ptr = strtok(str, " "); 
                while (ptr != NULL) {
                    char temp[200] = { 0, };
                    int index = 0;

                    for (int i = 0; i < strlen(ptr); i++) {
                        if (ptr[i] >= 'a' && ptr[i] <= 'z') { 
                        temp[index++] = ptr[i];
                        }
                    }

                    for (int i = 0; i < 11; i++) {
                        if (Compare(temp, arr[i]) == 0) { 
                            TreeNode* temp = Search(root, temp); 

                            if (temp != NULL)
                                temp->key.count++; 
                            else { 
                                tmp.count = 1;
                                strcpy(tmp.str, temp);
                                root = Insert(root, tmp);
                            }
                        }
                    }
                    ptr = strtok(NULL, " "); 
                }
            }
            Fileout(root, fw);
            break;
        }
        case 2:
        {
            Inorder(root);
            break;
        }
        case 3:
        {
            Element del_node;
            printf("�����ϰ� ���� ���� �Է����ּ���\n");
            scanf("%s", del_node.str);
            printf("�����ϰ� ���� ������� ������ �Է����ּ���\n");
            scanf("%d", &del_node.count);

            DeleteNode(root, del_node);
            break;
        }
        default:
            break;
        }
    }
}
