// ũ�Ⱑ N�� ���� A = A1, A2, ..., AN�� �ִ�. 
// ������ �� ���� Ai�� ���ؼ� ��ū�� NGE(i)�� ���Ϸ��� �Ѵ�.
// Ai�� ��ū���� �����ʿ� �����鼭 Ai���� ū �� �߿��� ���� ���ʿ� �ִ� ���� �ǹ��Ѵ�. 
// �׷��� ���� ���� ��쿡 ��ū���� -1�̴�.

// ���� ���, A = [3, 5, 2, 7]�� ��� NGE(1) = 5, NGE(2) = 7, NGE(3) = 7, NGE(4) = -1�̴�. 
// A = [9, 5, 4, 8]�� ��쿡�� NGE(1) = -1, NGE(2) = 8, NGE(3) = 8, NGE(4) = -1�̴�.

#include<iostream>
#include<stack>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    stack<int> s;
    int n;
    // n�� �Է�
    cin >> n;
    int num;
    int rigth_num;
    int* nge = new int[sizeof(n)];
    int* arr = new int[sizeof(n)];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    // ���⼭ ù��° ���� push�ϰ� ������ for�� ���ָ鼭 s.top()���� ū ���� ã�� �� log(n^2)�̶� ��Ÿ�� ���� �� �� ����
    // ó���� �Է� ���� �� ���� s.push()�ϸ�? i == 0 �� �� -1�� �����ϰ�, �׷��� ���� ���� s.top()
    for(int i = 0; i < n; i++){
        s.push(arr[i]);
        
    }
}