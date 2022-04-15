import java.util.Scanner;

public class document_6_1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("인사말을 골라주세요");
        System.out.println("1. 한국");
        System.out.println("2. 중국");
        System.out.println("3. 일본");
        int n = sc.nextInt();
        Hello(n);
    }

    public static void Hello(int n) {
        if (n == 1) {
            System.out.println("안녕하세요");
        } else if (n == 2) {
            System.out.println("니하오");
        } else if (n == 3) {
            System.out.println("곤지치와");
        }
    }
}
