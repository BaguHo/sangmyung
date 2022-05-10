import java.util.ArrayList;
import java.util.Scanner;
import java.lang.*;

public class 과제6_201921009_엄지호 {
    // 숫자입력을 string형으로 입력받아 계산하는 프로그램(계산기)
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        Calculator temp = new Calculator();
        System.out.println("계산값: " + temp.calculate(str));

    }

}

class Calculator{
    private int result;
    private String num1;
    private String num2;
    private char operator;

    Calculator(){
        result = 0;
        num1 = new String();
        num2 = new String();
        operator = '1';
    }

    public int calculate(String str){
        char[] arr = str.toCharArray();
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
