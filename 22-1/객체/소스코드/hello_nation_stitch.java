import java.util.Scanner;

public class hello_nation_stitch {
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
        switch (n) {
            case 1:
                System.out.println("�ȳ��ϼ���");
                break;
            case 2:
                System.out.println("���Ͽ�");
                break;
            case 3:
                System.out.println("����ġ��");
                break;
        }
    }
}
