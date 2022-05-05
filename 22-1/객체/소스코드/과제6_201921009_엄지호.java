import java.util.ArrayList;
import java.util.Scanner;
import java.lang.*;

public class 과제6_201921009_엄지호 {
    // 숫자입력을 string형으로 입력받아 계산하는 프로그램(계산기)
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        System.out.println("계산값: " + Calculator(str));
    }

    public static int Calculator(String str) {
        char[] arr = str.toCharArray();
        int result = 0;
        String num1 = new String();
        String num2 = new String();
        char operator = '1';
        // string -> char array, for(char array), char array -> string, string -> int
        int i;
        for (i = 0; i < str.length(); i++) {
            if (arr[i] == '+' || arr[i] == '-' || arr[i] == '*' || arr[i] == '/') {
                operator = arr[i];
                i++;
                break;
            } else {
                num1 = num1 + arr[i];
            }
        }
        for (int k = i; k < str.length(); k++) {
            num2 = num2 + arr[k];
        }
        int a = Integer.parseInt(num1);
        int b = Integer.parseInt(num2);
        switch (operator) {
            case '-':
                result = a - b;
                break;
            case '+':
                result = a + b;
                break;
            case '*':
                result = a * b;
                break;
            case '/':
                result = a / b;
                break;
        }
        return result;
    }
}
