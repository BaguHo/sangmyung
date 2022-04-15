import java.util.ArrayList;
import java.util.Scanner;

public class 과제6_201921009_엄지호 {
    // 숫자입력을 string형으로 입력받아 계산하는 프로그램
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        System.out.println("계산값: " + Calculator(str));
    }

    public static int Calculator(String str) {
        char[] arr = str.toCharArray();
        int result = 0;
        char ch;
        int num1 = arr[0] - '0';
        int num2 = arr[2] - '0';
        switch (arr[1]) {
            case '-':
                result = num1 - num2;
                break;
            case '+':
                result = num1 + num2;
                break;
            case '*':
                result = num1 * num2;
                break;
            case '/':
                result = num1 / num2;
                break;
        }
        return result;
    }
}