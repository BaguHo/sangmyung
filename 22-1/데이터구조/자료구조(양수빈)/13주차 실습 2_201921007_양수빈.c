/*
이진트리 프로그래밍

아래와 같은 구조로 이진트리의 노드를 정의하고, 1~7의 함수들을 작성하고, 결과를 확인하시오.
typedef struct TreeNode{
	int data;
	struct TreeNode *left,*right;
}TreeNode;

1~3. 이진트리의 중위순회, 전위순회, 후위순회 순서를 출력하는 함수를 각각 작성
4. 이진트리의 모든 노드들의 데이터 값을 1씩 증가시키는 함수를 작성(전위순회 이용)
5. 이진트리의 모든 노드들의 데이터 값의 총합을 계산하여 반환하는 함수를 작성(후위순회 이용)
6. 이진트리의 노드들이 갖는 데이터 값들 중 최대값을 찾아 반환하는 함수를 작성(후위순회 이용)
7. 이진트리의 노드들 중에서 입력값 X보다 작은 값들만 출력하는 함수를 작성(중위순회 이용)

void main(){
//아래는 노드 6개를 갖는 테스트용 이진트리의 예이다.
//각자 원하는 모양과 데이터로 테스트용 이진트리를 생성해서(노드 10개 이상)
//위 함수들의 결과를 테스트하시오.

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
			    	/    ＼
				   4      10
                 /  ＼   /  ＼
				1    6  2    7 
               / ＼ /
			   3  8 9
*/

//중위
void inorder(TreeNode* root) {
	if (root != NULL) {
		inorder(root->left);//왼쪽순회
		printf("[%d] ", root->data);
		inorder(root->right);//오른쪽순회
	}
}

//전위
void preorder(TreeNode* root) {
	if (root != NULL) {
		printf("[%d] ", root->data);
		preorder(root->left);//왼쪽순회
		preorder(root->right);//오른쪽순회
	}
}

//후위
void postorder(TreeNode* root) {
	if (root != NULL) {
		postorder(root->left);//왼쪽순회
		postorder(root->right);//오른쪽순회
		printf("[%d] ", root->data);
	}
}

void addone(TreeNode* root) {
	if (root != NULL) {
		root->data++;
		addone(root->left);//왼쪽순회
		addone(root->right);//오른쪽순회
	}
}

int total(TreeNode* root) {
	if (root != NULL) {
		total(root->left);//왼쪽순회
		total(root->right);//오른쪽순회
		sum += root->data;
	}
	return sum;
}

int findmax(TreeNode* root) {
	if (root != NULL) {
		findmax(root->left);//왼쪽순회
		findmax(root->right);//오른쪽순회
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
	printf("1.중위순회 출력\n");
	printf("2.전위순회 출력\n");
	printf("3.후위순회 출력\n");
	printf("4.모든 데이터 값을 1씩 증가시키기\n");
	printf("5.모든 데이터의 총합\n");
	printf("6.데이터들 중 최대값\n");
	printf("7.특정 값의 이하 값 찾기\n");
	printf("0.종료하기\n");
	printf("\n");
}

int main(void) {
	while (1) {
		int ch;
		menu();
		printf("*************************************\n");
		printf("선택: ");
		scanf("%d", &ch);
		printf("\n");

		switch (ch) {
		case 0:
			printf("종료합니다.\n");
			break;
		case 1:
			printf("============중위 순회===========\n");
			inorder(root);
			printf("\n");
			break;
		case 2:
			printf("============전위 순회===========\n");
			preorder(root);
			printf("\n");
			break;
		case 3:
			printf("============후위 순회===========\n");
			postorder(root);
			printf("\n");
			break;
		case 4:
			printf("============모든 값+1===========\n");
			addone(root);
			printf("\n");
			break;
		case 5:
			printf("============노드 총합===========\n");
			printf("노드 총합: %d\n", total(root));
			printf("\n");
			break;
		case 6:
			printf("============최대값 찾기==========\n");
			printf("최대값: %d\n", findmax(root));
			printf("\n");
			break;
		case 7:
			printf("=========특정값 이하 찾기========\n");
			int x;
			printf("찾으려는 값: ");
			scanf("%d", &x);
			under(root,x);
			printf("\n");
			break;
		default:
			printf("선택지가 없습니다.\n");
			break;
		}
		if (ch == 0) break;
	}
	return 0;
}
