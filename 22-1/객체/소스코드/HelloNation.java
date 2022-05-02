import java.util.Scanner;

import javax.lang.model.util.ElementScanner14;

public class HelloNation {

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        System.out.println("인사말을 골라주세요");
        System.out.println("1. 한국");
        System.out.println("2. 중국");
        System.out.println("3. 일본");
        int n = s.nextInt();
        switch (n) {
            case 1:
                HelloKorea();
            case 2:
                HelloChina();
            case 3:
                HelloJapan();
        }
    }

    public static void HelloKorea() {
        System.out.println("안녕하세요");
    }

    public static void HelloChina() {
        System.out.println("니하오");
    }

    public static void HelloJapan() {
        System.out.println("곤지치와");
    }

}
