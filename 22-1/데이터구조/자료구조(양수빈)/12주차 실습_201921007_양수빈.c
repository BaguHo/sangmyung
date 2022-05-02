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
/*
   이중연결리스트 프로그래밍
   영화정보 프로그램을 단순연결리스트에서 이중연결리스트로 변경하여 구현하시오.
   (주1) 데이터필드에 재생시간(1~10초)이 정수타입으로 추가된다.
   (주2) 교재 230-231쪽에 제시된 헤드노드를 갖는다.

   실행메뉴에는 다음과 같은 기능이 수정 또는 추가된다.

   (1) 삽입, 삭제, 검색, 출력 기능 등을 이중연결리스트에 맞도록 수정한다.
   (2) 재생메뉴 'P'를 추가한다:
       - 호출함수는 현재 노드의 재생시간만큼 대기한다(재생시간이 0이 될 때까지 감소)
         시각적 효과를 위해 progressive bar(예..........) 출력 권장
       - 재생이 완료되면 자동으로 다음 노드로 이동한다.
   (3) 현재 노드의 다음 노드로 이동해서 재생하는 '>'를 추가한다.
   (4) 현재 노드의 이전 노드로 이동해서 재생하는 '<'를 추가한다.
   (5) 맨 앞의 영화로 이동해서 재생하는 'F/f'가 추가한다.
   (6) 맨 뒤의 영화로 이동해서 재생하는 'L/l'를 추가한다.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<windows.h>

#define ARRAY 100 
//노드 타입
typedef struct Element {
    char title[ARRAY];
    char genre;
    int year;
    int time;
}Element;

typedef struct DListNode {
    Element data;
    struct DListNode* llink;
    struct DListNode* rlink;
}DListNode;

DListNode* current;

//오류 함수
void error(char* message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

//이중 연결 리스트의 초기화 함수
void init(DListNode* phead) {
    phead->llink = phead;
    phead->rlink = phead;
}

//이중 연결 리스트의 프린트 함수
void print_dlist(DListNode* phead) {
    DListNode* p;
    for (p = phead->rlink; p != phead; p = p->rlink) {
        if (current == p) {
            printf("*{%s %c %d %d초}*\n", p->data.title, p->data.genre, p->data.year, p->data.time);
            p = p->rlink;
            if (p == phead) {//p가 head에 올경우 이 if문을 걸어주지 않으면 다음 128번째 줄이 실행되면서 쓰레기값이 출력된다.
                return;
            }
        }
        printf("-{%s %c %d %d초}-\n", p->data.title, p->data.genre, p->data.year,p->data.time);
    }
    printf("\n");
}

//길이 계산 함수
int list_length(DListNode* phead) {
    int num = 0;
    DListNode* p;
    for (p = phead->rlink; p != phead; p = p->rlink) {
        num++;
    }
    return num;
}

//영화 찾는 함수
void find_movie(DListNode* phead) {
    char name[ARRAY] = { NULL };// [ARRAY] ;//영화제목 자료를 검색받을 문자열
    printf("영화 제목입력: ");
    scanf("%s", name);


    DListNode* search = phead->rlink;

    printf("\n");

    if (search == NULL)
        return 0;
    while (search != phead) {
        if (strcmp(search->data.title, name) != 0) {
            search = search->rlink;
        }
        else if (strcmp(search->data.title, name) == 0) {
            printf("검색 결과: {%s %c %d %d초}\n", search->data.title, search->data.genre, search->data.year, search->data.time);
            break;
        }
        else
            return NULL;
    }
}

//입력받은 장르와 같은 영화 출력 함수
void find_genre(DListNode* phead) {
    char genre_name;//원하는 장르를 검색받을 문자
    printf("영화 장르입력('A','C','F','R' 중 하나): ");
    getchar();
    scanf("%c", &genre_name);
    DListNode* search = phead->rlink;

    printf("\n");

    if (search == NULL)
        return 0;
    while (search != phead) {
        if (search->data.genre == genre_name) {
            printf("{%s %c %d %d초}\n", search->data.title, search->data.genre, search->data.year, search->data.time);
        }
        search = search->rlink;
    }
}

//가장 최근에 개봉된 영화를 찾는 함수
void find_current(DListNode* phead) {
    int curyear;
    DListNode* search = phead->rlink;

    if (search == NULL)
        return 0;

    curyear = search->data.year;//curyear=리스트의 첫 번째 year
    for (; search != phead; search = search->rlink) {
        if (curyear <= search->data.year) {//curyear보다 리스트의 year이 더 크면 값 갱신
            curyear = search->data.year;
        }
    }
    
    search = phead->rlink;

    for (; search != phead; search = search->rlink) {
        if (curyear == search->data.year) {//curyear이 리스트의 year과 같으면 출력
            printf("\n{%s %c %d %d초}     ", search->data.title, search->data.genre, search->data.year, search->data.time);
        }
    }
    printf("\n");
}

//plist는 연결 리스트의 헤더를 가리키는 포인터
void insert_node(DListNode* phead, int choice1) {
    DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));
    printf("저장할 영화제목, 영화장르('A','C','F','R' 중 하나), 개봉년도, 재생시간을 입력하세요: ");
    scanf("%s %c %d %d", newnode->data.title, &newnode->data.genre, &newnode->data.year, &newnode->data.time);


    DListNode* p = phead;

    switch (choice1) {
    case 1://제일 앞에 노드 연결
        newnode->llink = p;//1
        newnode->rlink = p->rlink;//2
        p->rlink->llink = newnode;//3
        p->rlink = newnode;//4
        break;
    case 2://제일 뒤에 노드 연결
        newnode->rlink = p;//1
        newnode->llink = p->llink->rlink;//2
        p->llink->rlink = newnode;//3
        p->llink = newnode;//4
        break;
    case 3://오름차순 노드 연결
        if(strcmp(p->rlink->data.title, newnode->data.title) == 1)//연결리스트 현재위치 뒤 > newnode
        {
            newnode->llink = p;//1
            newnode->rlink = p->rlink;//2
            p->rlink->llink = newnode;//3
            p->rlink = newnode;//4
        }

        else if (strcmp(p->llink->data.title, newnode->data.title) == -1)//연결리스트 맨뒤 < newnode
        {
            newnode->rlink = p;//1
            newnode->llink = p->llink->rlink;//2
            p->llink->rlink = newnode;//3
            p->llink = newnode;//4
        }

        else {//중간에 연결리스트 붙이기
            do {
                if (strcmp(newnode->data.title, p->rlink->data.title) == -1 && strcmp(newnode->data.title, p->data.title) == 1) { //연결리스트 현재위치 뒤 > newnode && 연결리스트 현재위치 < newnode
                    newnode->llink = p;//1
                    newnode->rlink = p->rlink;//2
                    p->rlink->llink = newnode;//3
                    p->rlink = newnode;//4
                    break;
                }
                p = p->rlink;
            } while (p != phead);
        }
        break;
    }
}

//삭제 함수
void delete_node(DListNode* phead) {
    char delete_name[ARRAY];//삭제할 영화를 입력받을 변수
    printf("삭제할 영화의 이름을 입력하세요: ");
    scanf("%s", delete_name);
    DListNode* removed = phead;

    //노드가 하나밖에 없을 때 삭제(헤드노드제외)
    if (strcmp(removed->rlink->data.title, delete_name) == 0) {
        phead = phead->llink->rlink = phead->rlink->llink;
        free(removed);//삭제
        return;
    }

    removed = removed->rlink;

    do {
        if (strcmp(removed->data.title, delete_name) == 0) {
            removed->llink->rlink = removed->rlink;
            removed->rlink->llink = removed->llink;
            free(removed);
            return;
            break;
        }
            removed = removed->rlink;
    }while (removed != phead);

    printf("삭제할 노드가 없습니다.");
    return;
}

void menu() {
    printf("\n<==================메뉴===================>\n");
    printf("1.삽입\n");
    printf("2.출력\n");
    printf("3.노드의 개수 계산\n");
    printf("4.영화 검색\n");
    printf("5.노드 삭제\n");
    printf("6.가장 최근에 개봉된 영화 검색\n");
    printf("7.원하는 장르 영화 검색\n");
    printf("0.종료\n");
}

void menu_p() {
    printf("\n<=================재생메뉴=================>\n");
    printf("p.현재 위치 재생\n");
    printf(">.다음 곡 재생\n");
    printf("<.이전 곡 재생\n");
    printf("F/f 재생리스트의 시작으로\n");
    printf("L/l 재생리스트의 마지막으로\n");
}

void play_node(DListNode* phead) {
    int count = current->data.time;
    print_dlist(phead);
    printf("\n");

    printf("==========={%s %c %d %d초}===========\n", current->data.title, current->data.genre, current->data.year, current->data.time);
    for (int i = 1; i <= count; i++) {
        printf("%d ", i);
        Sleep(1000);
    }
    current = current->rlink;
    if (current == phead)
        current = current->rlink;

    printf("\n");
}

void transfer_node(DListNode* phead,char ch) {
    switch (ch) {
    case '>':
        current = current->rlink;
        if (current == phead)
            current = current->rlink;
        play_node(phead);
        break;
    case '<':
        current = current->llink;
        if (current == phead)
            current = current->llink;
        play_node(phead);
        break;
    case 'F': case 'f':
        current = phead->rlink;
        play_node(phead);
        break;
    case 'L': case 'l':
        current = phead->llink;
        play_node(phead);
        break;
    }
}

int main(void) {
    DListNode* head = (DListNode *)malloc(sizeof(DListNode));
    init(head);
    char ch;

    int choice1;//데이터 정렬방법을 입력받을 변수
    printf("새로운 데이터 정렬 방법\n");
    printf("1. 제일 앞 2. 제일 뒤 3. 오름차순: ");
    scanf("%d", &choice1);


    while (1) {
        menu();
        menu_p();
        printf("\n");
        getchar();
        printf("선택: ");
        scanf("%c", &ch);
        switch (ch) {
        case '1':
            printf("\n<------------------삽입------------------->\n");
            insert_node(head, choice1);
            current = head->rlink;
            printf("삽입완료\n");
            break;
        case '2':
            printf("\n<---------------프린트호출---------------->\n");
            print_dlist(head);
            break;
        case '3':
            printf("\n<-------------노드의 개수----------------->\n");
            int num1;//list_length의 리턴값을 받을 변수
            num1 = list_length(head);
            printf("\n현재 연결된 노드의 개수: %d\n", num1);
            break;
        case '4':
            printf("\n<-----------------영화검색---------------->\n");
            find_movie(head);
            break;
        case '5':
            printf("\n<----------------노드 삭제---------------->\n");
            delete_node(head);
            printf("삭제 완료\n");
            break;
        case '6':
            printf("\n<-------------최신영화검색---------------->\n");
            find_current(head);
            break;
        case '7':
            printf("\n<-----------같은장르의영화---------------->\n");
            find_genre(head);
            break;
        case 'p':
            play_node(head);
            break;
        case '<': case '>': case 'L': case 'l': case 'F': case 'f':
            transfer_node(head, ch);
            break;
        case '0':
            break;
        }
        if (ch == '0')   break;
    }

    free(head);
    return 0;
}