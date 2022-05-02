import java.util.Random;
import java.util.Scanner;

public class random {
    public static void main(String[] args) {
        Random random_num = new Random();
        Scanner sc = new Scanner(System.in);
        int n = random_num.nextInt(100);
        System.out.println("0 ~ 100사이의 수를 입력하세요");
        int input = sc.nextInt();
        System.out.println("=========================");
        GuessNum(n, input);
    }

    public static void GuessNum(int n, int input) {
        Scanner sc = new Scanner(System.in);
        while (true) {
            if (input < n) {
                System.out.println("UP");
                System.out.println("다시 입력해주세요");
                System.out.println("=========================");
                input = sc.nextInt();
            } else if (input > n) {
                System.out.println("DOWN");
                System.out.println("다시 입력해주세요");
                System.out.println("=========================");
                input = sc.nextInt();
            } else {
                System.out.println("정답입니다");
                System.out.println("정답: " + n);
                break;
            }
        }
    }
}
