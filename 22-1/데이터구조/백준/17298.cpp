// 크기가 N인 수열 A = A1, A2, ..., AN이 있다. 
// 수열의 각 원소 Ai에 대해서 오큰수 NGE(i)를 구하려고 한다.
// Ai의 오큰수는 오른쪽에 있으면서 Ai보다 큰 수 중에서 가장 왼쪽에 있는 수를 의미한다. 
// 그러한 수가 없는 경우에 오큰수는 -1이다.

// 예를 들어, A = [3, 5, 2, 7]인 경우 NGE(1) = 5, NGE(2) = 7, NGE(3) = 7, NGE(4) = -1이다. 
// A = [9, 5, 4, 8]인 경우에는 NGE(1) = -1, NGE(2) = 8, NGE(3) = 8, NGE(4) = -1이다.

#include<iostream>
#include<stack>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    stack<int> s;
    int n;
    // n개 입력
    cin >> n;
    int num;
    int rigth_num;
    int* nge = new int[sizeof(n)];
    int* arr = new int[sizeof(n)];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    // 여기서 첫번째 수를 push하고 끝까지 for문 해주면서 s.top()보다 큰 수를 찾는 건 log(n^2)이라 런타임 에러 날 것 같다
    // 처음에 입력 받을 때 전부 s.push()하면? i == 0 일 때 -1을 삽입하고, 그렇지 않을 때는 s.top()
    for(int i = 0; i < n; i++){
        s.push(arr[i]);
        
    }
}