/*
����Ʈ�� ���α׷���

�Ʒ��� ���� ������ ����Ʈ���� ��带 �����ϰ�, 1~7�� �Լ����� �ۼ��ϰ�, ����� Ȯ���Ͻÿ�.
typedef struct TreeNode{
	int data;
	struct TreeNode *left,*right;
}TreeNode;

1~3. ����Ʈ���� ������ȸ, ������ȸ, ������ȸ ������ ����ϴ� �Լ��� ���� �ۼ�
4. ����Ʈ���� ��� ������ ������ ���� 1�� ������Ű�� �Լ��� �ۼ�(������ȸ �̿�)
5. ����Ʈ���� ��� ������ ������ ���� ������ ����Ͽ� ��ȯ�ϴ� �Լ��� �ۼ�(������ȸ �̿�)
6. ����Ʈ���� ������ ���� ������ ���� �� �ִ밪�� ã�� ��ȯ�ϴ� �Լ��� �ۼ�(������ȸ �̿�)
7. ����Ʈ���� ���� �߿��� �Է°� X���� ���� ���鸸 ����ϴ� �Լ��� �ۼ�(������ȸ �̿�)

void main(){
//�Ʒ��� ��� 6���� ���� �׽�Ʈ�� ����Ʈ���� ���̴�.
//���� ���ϴ� ���� �����ͷ� �׽�Ʈ�� ����Ʈ���� �����ؼ�(��� 10�� �̻�)
//�� �Լ����� ����� �׽�Ʈ�Ͻÿ�.

TreeNode n1={1,NULL,NULL);
TreeNode n2={4,&n1,NULL);
TreeNode n3={16,NULL,NULL);
TreeNode n4={25,NULL,NULL);
TreeNode n5={20,&n3,&n4);
TreeNode n6={15,&n2,&n5);
TreeNode *root=&n6;
*/

#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
}TreeNode;

TreeNode n1 = { 3,NULL,NULL };
TreeNode n2 = { 8,NULL,NULL };
TreeNode n3 = { 1,&n1,&n2 };
TreeNode n4 = { 9,NULL,NULL };
TreeNode n5 = { 6,&n4,NULL };
TreeNode n6 = { 4,&n3,&n5 };
TreeNode n7 = { 2,NULL,NULL };
TreeNode n8 = { 7,NULL,NULL };
TreeNode n9 = { 10,&n7,&n8 };
TreeNode n10 = { 5,&n6,&n9 };
TreeNode* root = &n10;
int max = 0;
int sum = 0;

/*
                       5
			    	/    ��
				   4      10
                 /  ��   /  ��
				1    6  2    7 
               / �� /
			   3  8 9
*/

//����
void inorder(TreeNode* root) {
	if (root != NULL) {
		inorder(root->left);//���ʼ�ȸ
		printf("[%d] ", root->data);
		inorder(root->right);//�����ʼ�ȸ
	}
}

//����
void preorder(TreeNode* root) {
	if (root != NULL) {
		printf("[%d] ", root->data);
		preorder(root->left);//���ʼ�ȸ
		preorder(root->right);//�����ʼ�ȸ
	}
}

//����
void postorder(TreeNode* root) {
	if (root != NULL) {
		postorder(root->left);//���ʼ�ȸ
		postorder(root->right);//�����ʼ�ȸ
		printf("[%d] ", root->data);
	}
}

void addone(TreeNode* root) {
	if (root != NULL) {
		root->data++;
		addone(root->left);//���ʼ�ȸ
		addone(root->right);//�����ʼ�ȸ
	}
}

int total(TreeNode* root) {
	if (root != NULL) {
		total(root->left);//���ʼ�ȸ
		total(root->right);//�����ʼ�ȸ
		sum += root->data;
	}
	return sum;
}

int findmax(TreeNode* root) {
	if (root != NULL) {
		findmax(root->left);//���ʼ�ȸ
		findmax(root->right);//�����ʼ�ȸ
		if (max <= root->data) {
			max = root->data;
		}
	}
	return max;
}

void under(TreeNode* root,int x) {
	if (root != NULL) {
		under(root->left,x);
		if (x > root->data) {
			printf("[%d] ", root->data);
		}
		under(root->right,x);
	}
}

void menu() {
	printf("1.������ȸ ���\n");
	printf("2.������ȸ ���\n");
	printf("3.������ȸ ���\n");
	printf("4.��� ������ ���� 1�� ������Ű��\n");
	printf("5.��� �������� ����\n");
	printf("6.�����͵� �� �ִ밪\n");
	printf("7.Ư�� ���� ���� �� ã��\n");
	printf("0.�����ϱ�\n");
	printf("\n");
}

int main(void) {
	while (1) {
		int ch;
		menu();
		printf("*************************************\n");
		printf("����: ");
		scanf("%d", &ch);
		printf("\n");

		switch (ch) {
		case 0:
			printf("�����մϴ�.\n");
			break;
		case 1:
			printf("============���� ��ȸ===========\n");
			inorder(root);
			printf("\n");
			break;
		case 2:
			printf("============���� ��ȸ===========\n");
			preorder(root);
			printf("\n");
			break;
		case 3:
			printf("============���� ��ȸ===========\n");
			postorder(root);
			printf("\n");
			break;
		case 4:
			printf("============��� ��+1===========\n");
			addone(root);
			printf("\n");
			break;
		case 5:
			printf("============��� ����===========\n");
			printf("��� ����: %d\n", total(root));
			printf("\n");
			break;
		case 6:
			printf("============�ִ밪 ã��==========\n");
			printf("�ִ밪: %d\n", findmax(root));
			printf("\n");
			break;
		case 7:
			printf("=========Ư���� ���� ã��========\n");
			int x;
			printf("ã������ ��: ");
			scanf("%d", &x);
			under(root,x);
			printf("\n");
			break;
		default:
			printf("�������� �����ϴ�.\n");
			break;
		}
		if (ch == 0) break;
	}
	return 0;
}
