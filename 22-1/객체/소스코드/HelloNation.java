import java.util.Scanner;

import javax.lang.model.util.ElementScanner14;

public class HelloNation {

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        System.out.println("�λ縻�� ����ּ���");
        System.out.println("1. �ѱ�");
        System.out.println("2. �߱�");
        System.out.println("3. �Ϻ�");
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
        System.out.println("�ȳ��ϼ���");
    }

    public static void HelloChina() {
        System.out.println("���Ͽ�");
    }

    public static void HelloJapan() {
        System.out.println("����ġ��");
    }

}
