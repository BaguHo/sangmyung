#include<stdio.h>
#include<stdlib.h>

typedef int Element;

typedef struct __node{
    Element key;
    struct __node* left;   
    struct __node* right;
}TreeNode;

TreeNode* InitTreeNode(){
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

TreeNode* Search(TreeNode* node, int key){
    while(!node){
        if(key == node->key) return node;
        else if (key < node->key)
            node = node->left;
        else
            node = node->right;
    }
    return NULL;
}

int main(){

}