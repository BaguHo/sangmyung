import java.util.Scanner;

public class PrintStar {
    public static void main(String[] args) {
        // 숫자를 입력받고 그 수 만큼 별을 찍어라
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        PrintStar(n);
    }

    public static void PrintStar(int n) {
        for (int i = 0; i < n; i++) {
            System.out.print("*");
        }
        System.out.println();
    }
}
