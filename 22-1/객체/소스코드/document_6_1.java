import java.util.Scanner;

public class document_6_1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("�λ縻�� ����ּ���");
        System.out.println("1. �ѱ�");
        System.out.println("2. �߱�");
        System.out.println("3. �Ϻ�");
        int n = sc.nextInt();
        Hello(n);
    }

    public static void Hello(int n) {
        if (n == 1) {
            System.out.println("�ȳ��ϼ���");
        } else if (n == 2) {
            System.out.println("���Ͽ�");
        } else if (n == 3) {
            System.out.println("����ġ��");
        }
    }
}
