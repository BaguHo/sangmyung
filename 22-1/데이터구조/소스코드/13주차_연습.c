#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<memory.h>

typedef struct{
    int count;
    char str[20];
}Element;

typedef struct __node{
    Element key;
    struct __node* left, *right;   
}TreeNode;

TreeNode* NewNode(Element item){
    TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
    strcpy(temp->key.str, item.str); 
    temp->key.count = item.count;
    temp->left = temp->right = NULL;
    return temp;
}

TreeNode* Search(TreeNode* root, char *key){
    TreeNode* p = root;
    while(p != NULL){
        if(strcmp(key, p->key.str) == 0)
            return p;
        else if(strcmp(key, p->key.str) == -1)
            p = p->left;
        else if(strcmp(key, p->key.str) == 1)
            p = p->right;
    }
    return p;
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
    if(strcmp(target.count, root->key.count) == -1)
        root->left = DeleteNode(root->left, target);
    else if(strcmp(target.count, root->key.count) == 1)
        root->right = DeleteNode(root->right, target);
    // target == root->key
    else{
        // 단말노드 이거나, 서브트리가 하나인 경우
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
        // 오른쪽 서브트리에서 가장 작은 값을 가져와서 삭제한 노드 대체
        TreeNode* temp = GetMinimumValueNode(root->right);

        root->key = temp->key;
        root->right = DeleteNode(root->right, temp->key);
    }
    return root;
}

void Inorder(TreeNode* root){
    if(root != NULL){
        Inorder(root->left);
        printf("word = %s\ncount = %d \n", root->key.str, root->key.count);
        printf("=============================\n");
        Inorder(root->right);
    }
}

int IsBalancedTree(TreeNode* root, int* height){
    int l = 0;
    int r = 0;
    int left_height = 0, right_height = 0;
    
    if(root == NULL){
        *height = 0;
        return 1;
    }

    l = IsBalancedTree(root->left, &left_height);
    r = IsBalancedTree(root->right, &right_height);
    
    if(left_height > right_height)
        *height = left_height + 1;
    else
        *height = right_height + 1;

    if(left_height - right_height > 1 || right_height - left_height > 1)
        return 0;
    else
    // ???
        return l && r;
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

void Fileout(TreeNode* p, FILE *fp_out) {
    if (p != NULL) {
        Fileout(p->left,fp_out);
        fprintf(fp_out, "word: %-6s \ncount: %2d\n", p->key.str, p->key.count);
        Fileout(p->right,fp_out);
    }
}

int main(){
    TreeNode* root = NULL;
    FILE *fp_in = fopen("bst_in.txt", "r");
    FILE *fp_out = fopen("bst_out.txt", "w+");
    char *target[11] = {"break", "case", "do", "else", "for", "if", "int", "return", "struct", "switch", "while"};
    while(!feof(fp_in)){
        char buf[300];  
        fgets(buf, sizeof(buf), fp_in);
        char *ptr = strtok(buf, " ");
        while(ptr != NULL){
            char reserve[200] = {0, };
            int index = 0;
            for(int i = 0; i < strlen(ptr); i++){
                if(ptr[i] >= 'a' && ptr[i] <= 'z'){
                    reserve[index++] = ptr[i];
                }
            }
            for(int i = 0; i < 11; i++){
                if(strcmp(reserve, target[i]) == 0){
                    TreeNode* temp = Search(root, reserve);
                    // 단어를 파일에서 찾았는데 트리에 없는 경우
                    if(temp != NULL){
                        temp->key.count++;
                    }
                    else{
                        Element new_node;
                        new_node.count = 1;
                        strcpy(new_node.str, reserve);
                        root = Insert(root, new_node);
                    }
                }
            }
            ptr = strtok(NULL, " ");                
        }
    }
    Fileout(root, fp_out);

    int num;
    while(1){
        
        printf("===========================================\n");
        printf("0. 프로그램 종료\n");
        printf("1. 예약어 찾기\n");
        printf("2. 중위순회 출력\n");
        printf("3. 특정한 예약어 삭제\n");
        printf("4. 가장 자주 나온 단어\n");
        scanf("%d", &num);
        switch (num)
        {
        case 0:
            return 0;
            break;
        case 1:
        {
            
            fclose(fp_in);
            fclose(fp_out);
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
            printf("삭제하고 싶은 예약어를 입력해주세요\n");
            scanf("%s", del_node.str);
            printf("삭제하고 싶은 예약어의 개수를 입력해주세요\n");
            scanf("%d", &del_node.count);

            DeleteNode(root, del_node);
            break;
        }
        case 4:
            max = root->key.count;
            GetMaxWord(root);
            printf("가장 많이 나온 개수: %d\n", max);
            break;
        default:
            break;
        }
    }
}
