/*
연결리스트 실습 (준비)

(1)  데이터 { 문자열 영화제목, 문자 장르, 정수 개봉년도 }를 저장하는 연결리스트 노드의
   자료구조 정의하시오 (여기서 장르는 ‘A’, ‘C’, ‘F’, ‘R’ 중 하나)

(2)  새 노드를 현재 리스트의 특정 위치에 삽입하는 함수 insert_node( ) 작성하시오
   (교재의 예제처럼 insert_first( )와 특정 위치를 지정해서 삽입하는 insert( )를 따로 작성할 수 있음)

(3)  현재 리스트에 연결된 노드의 개수를 계산해서 반환하는 함수 list_length( ) 를 작성하시오

(4)  현재 리스트에 연결된 각 노드에서 { 영화제목, 장르, 개봉년도 }를 차례로 출력하는 함수
   print_list( ) 를 작성하시오


main() 함수에서는 : 빈 리스트에서 시작하여 아래와 같은 메뉴로 테스트하시오.

   - insert_node( )를 호출하여 좋아하는 영화의 데이터를 저장한 새 노드를 만들고,
     현재 리스트에 삽입하여 연결.
    (이 때, ‘제목’의 오름차순을 유지하도록 연결하거나, 항상 맨 앞, 또는 맨 뒤에 연결하는
     방법 중 선택할 수 있음)

   - list_length( )를 호출하여, 현재 리스트에 연결된 노드의 개수를 계산
   - print_list( )를 호출하여 현재 리스트에 연결된 각 노드의 데이터를 출력
 //////////////////////////////////////////////////////////////////////////////////////
   연결리스트 실습 (5/25)

⊙(1) 새로운 영화에 대한 노드를 삽입하는 함수 (준비완료) 

⊙(2) 모든 노드에 저장된 영화정보를 차례로 출력 (준비 일부 완료)

⊙   순환호출을 이용해서, 차례로 출력하는 함수 print_list_2 ( )를 작성하시오

⊙  순환호출을 이용해서, 역순으로 출력하는 함수 print_list_3 ( ) 을 작성하시오.

⊙(3) 현재 리스트에 연결된 영화정보 노드의 개수를 계산 (준비 일부 완료)

⊙            순환호출을 이용해서 list_length_2 ( ) 로 다시 작성하시오.

⊙(4)  영화제목으로 자료 검색하는 함수 :
    리스트에서 찾으면 해당 노드를 반환하고, 리스트에 존재하지 않으면 NULL 반환

⊙(5)  특정 영화에 대한 노드를 삭제하는 함수.

⊙(6)  가장 최근에 개봉된 영화 검색하는 함수.

⊙------(7)  원하는 장르의 영화들만 출력하는 함수:
     함수의 매개변수 중 하나가 ‘A’, ‘C’, ‘F’, ‘R’ 값을 갖는 것으로 구분,




main() 함수는 아래의 아래와 같은 메뉴 중 선택하면서 반복 진행하며, 원할 때 마치도록 한다.

-  새로운 영화에 대한 노드를 만들어 원하는 위치에 삽입
-  현재 리스트에 연결된 모든 노드의 영화정보를 출력
    : 연결된 순서의 역순으로 출력하도록 선택 가능.
-  현재 리스트의 노드 개수를 계산해서 출력
-  영화 제목으로 특정 영화를 검색해서 노드의 내용을 출력
-  영화 제목으로 검색해서 해당 노드를 삭제
-  가장 최근에 개봉된 영화를 찾아서 그 노드의 내용을 출력
-  특정 장르의 영화들을 골라서 그 노드의 내용을 출력
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define ARRAY 100 
//노드 타입
typedef struct Element {
    char title[ARRAY];
    char genre;
    int year;
}Element;

typedef struct ListNode {
    Element data;
    struct ListNode* link;
}ListNode;

//연결 리스트 헤더
typedef struct ListType {
    int size;
    ListNode* head;
    ListNode* tail;
}ListType;

//오류 함수
void error(char* message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

//리스트 헤더 생성 함수
ListType* create() {
    ListType* plist = (ListType*)malloc(sizeof(ListType));
    plist->size = 0;
    plist->head = plist->tail = NULL;
    return plist;
}

//프린트 함수
void print_list(ListType* plist) {
    ListNode* a = plist->head;
    for (; a != NULL; a = a->link) {
        printf("{%s %c %d}   ", a->data.title, a->data.genre, a->data.year);
    }
}

//순환호출 프린트 함수
void print_list2(ListType* plist,ListNode* a) {
   if (a !=NULL){
        printf("{%s %c %d}   ", a->data.title, a->data.genre, a->data.year);
        return print_list2(plist, a->link);
   }
}

//순환호출 역순 프린트 함수
void print_list3(ListType* plist, ListNode* a) {
    if (a != NULL) {
        print_list3(plist, a->link);
        printf("{%s %c %d}   ",a->data.title, a->data.genre, a->data.year);
    }
}

//길이 계산 함수
int list_length(ListType* plist) {
    return plist->size;
}

//순환 호출 길이 계산 함수 
int list_length2(ListType* plist,ListNode *a,int num) {
    if (a != NULL) {
        num++;
        return list_length2(plist, a->link, num);
    }
    else return num;
}

//영화 찾는 함수
void find_movie(ListType* plist) {
    char name[ARRAY] = { NULL };// [ARRAY] ;//영화제목 자료를 검색받을 문자열
    printf("영화 제목입력: ");
    scanf("%s",name);

    
    ListNode* search = plist->head;

    if (plist == NULL)
        return 0;
    while (search != NULL) {
        if (strcmp(search->data.title, name)!=0) {
            search = search->link;
        }
        else if (strcmp(search->data.title, name) == 0) {
            printf("검색 결과: {%s %c %d}\n", search->data.title, search->data.genre, search->data.year);
            break;
        }
        else
            return NULL;
    }
}

//입력받은 장르와 같은 영화 출력 함수
void find_genre(ListType* plist) {
    char genre_name;//원하는 장르를 검색받을 문자
    printf("영화 장르입력('A','C','F','R' 중 하나): ");
    getchar();
    scanf("%c", &genre_name);
    ListNode* search = plist->head;

    if (plist == NULL)
        return 0;
    while (search != NULL) {
        if (search->data.genre == genre_name) {
            printf("{%s %c %d}\n",search->data.title, search->data.genre, search->data.year);
        }
        search = search->link;
    }
}

//가장 최근에 개봉된 영화를 찾는 함수
void find_current(ListType* plist) {
   int curyear;
   ListNode* search = plist->head;

   if (plist == NULL)
       return 0;

   curyear = search->data.year;//curyear=리스트의 첫 번째 year
   for (; search != NULL; search = search->link) {
       if (curyear <= search->data.year) {//curyear보다 리스트의 year이 더 크면 값 갱신
           curyear = search->data.year;
       }
   }
   printf("%d", curyear);
   search = plist->head;

   for (; search != NULL; search = search->link) {
       if (curyear == search->data.year) {//curyear이 리스트의 year과 같으면 출력
           printf("{%s %c %d}     ", search->data.title, search->data.genre, search->data.year);
       }
   }
}

//plist는 연결 리스트의 헤더를 가리키는 포인터
void insert_node(ListType* plist,int choice1) {
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));
    printf("저장할 영화제목, 영화장르('A','C','F','R' 중 하나), 개봉년도 를 입력하세요: ");
    scanf("%s %c %d", p->data.title, &p->data.genre, &p->data.year);

    ListNode* a = plist->head;

    switch (choice1) {
    case 1://제일 앞에 노드 연결
        p->link = plist->head;
        plist->head = p;
        plist->size++;
        break;
    case 2://제일 뒤에 노드 연결
        p->link = NULL;//초기화
        if (plist->tail == NULL) {//빈공간일 때
            plist->head = plist->tail = p;
        }
        else {
            plist->tail->link = p;
            plist->tail = p;
        }
        plist->size++;
        break;
    case 3://오름차순 노드 연결
        p->link = NULL;//초기화
        if (plist->tail == NULL) {//첫 번째 넣는 경우
            plist->head = plist->tail = p;
            plist->size++;
        }

        else if (strcmp(plist->head->data.title, p->data.title) == 1)//연결리스트 머리 > p
        {
            p->link = plist->head;
            plist->head = p;
            plist->size++;
        }

        else if (strcmp(plist->tail->data.title, p->data.title) == -1)//연결리스트 꼬리 < p
        {
            plist->tail->link = p;
            plist->tail = p;
            plist->size++;
        }

        else {//중간에 연결리스트 붙이기
            while (a->link != NULL) {
                if (strcmp(p->data.title, a->link->data.title) == -1) {
                    p->link = a->link;
                    a->link = p;
                    plist->size++;
                    break;
                }
                a = a->link;
            }
        }
        break;
    }
}

//삭제 함수
void delete_node(ListType* plist) {
    char delete_name[ARRAY];//삭제할 영화를 입력받을 변수
    printf("삭제할 영화의 이름을 입력하세요: ");
    scanf("%s", delete_name);
    ListNode* search = plist->head;

    if (plist->head == NULL) {
        error("error");
        return;
    }


    //헤드값 삭제
    if (strcmp(search->data.title, delete_name) == 0) {//head==delete_name
        plist->head = search->link;//search의 다음 노드와 head연결
        plist->size--;//size 줄이기
        free(search);//삭제
        return;
    }


    while (search != NULL) {
        if (strcmp(search->link->data.title, delete_name) == 0) {
            ListNode* removed = search->link;//현재 search 위치의 다음링크값을 가리키는 removed
            search->link = removed->link;//removed가 가리키는 다음 노드의 링크를 search에 연결
            if (removed->link != NULL) {//중간 값 삭제 (뒤에 노드가 있을 때)
                search->link = removed->link;
                plist->size--;
                free(removed);
            }
            else {//마지막 값 삭제 (removed->link==NULL)
                search->link = NULL;
                plist->size--;
                free(removed);
            }
                
            return;
            break;
        }
        search = search->link;
    }
}

void menu() {
    printf("\n<------------------메뉴------------------->\n");
    printf("1.삽입\n");
    printf("2.출력\n");
    printf("3.순환출력\n");
    printf("4.역순순환출력\n");
    printf("5.노드의 개수 계산\n");
    printf("6.노드의 개수 순환계산\n");
    printf("7.영화 검색\n");
    printf("8.노드 삭제\n");
    printf("9.가장 최근에 개봉된 영화 검색\n");
    printf("10.원하는 장르 영화 검색\n");
    printf("0.종료\n");
}

int main(void) {
    ListType* list1;
    list1 = create();
    int ch;
    ListNode* a = list1->head;

    int choice1;//데이터 정렬방법을 입력받을 변수
    printf("새로운 데이터 정렬 방법\n");
    printf("1. 제일 앞 2. 제일 뒤 3. 오름차순: ");
    scanf("%d", &choice1);

    while (1) {
        menu();
        printf("\n");
        printf("선택: ");
        scanf("%d", &ch);
        switch (ch) {
        case 1:
            printf("\n<------------------삽입------------------->\n");
            insert_node(list1,choice1);
            printf("삽입완료\n");
            a = list1->head;
            break;
        case 2:
            printf("\n<---------------프린트호출---------------->\n");
            print_list(list1);
            break;
        case 3:
            printf("\n<----------------순환호출----------------->\n");
            print_list2(list1, a);
            break;
        case 4:
            printf("\n<------------역순순환호출----------------->\n");
            print_list3(list1, a);
            break;
        case 5:
            printf("\n<-------------노드의 개수----------------->\n");
            int num1;//list_length의 리턴값을 받을 변수
            num1 = list_length(list1);
            printf("현재 연결된 노드의 개수: %d\n", num1);
            break;
        case 6:
            printf("\n<----------노드의 개수 순환호출----------->\n");
            int num = 0;//순환호출로 셀 노드의 개수를 나타내는 변수
            int num2;//list_length2의 리턴값을 받을 변수
            num2 = list_length2(list1, a, num);
            printf("현재 연결된 노드의 개수(순환호출): %d\n", num2);
            break;
        case 7:
            printf("\n<-----------------영화검색---------------->\n");
            find_movie(list1);
            break;
        case 8:
            printf("\n<----------------노드 삭제---------------->\n");
            delete_node(list1);
            printf("삭제 완료\n");
            break;
        case 9:
            printf("\n<-------------최신영화검색---------------->\n");
            find_current(list1);
            break;
        case 10:
            printf("\n<-----------같은장르의영화---------------->\n");
            find_genre(list1);
            break;
        case 0:
            break;
        }
        if (ch == 0)   break;
    }

    free(list1);
    return 0;
}