import java.util.Scanner;

public class hello_nation_stitch {
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
        switch (n) {
            case 1:
                System.out.println("안녕하세요");
                break;
            case 2:
                System.out.println("니하오");
                break;
            case 3:
                System.out.println("곤지치와");
                break;
        }
    }
}
