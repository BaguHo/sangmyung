import java.util.Scanner;

public class swtich_test {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        System.out.println(how_many(n));
    }

    static String how_many(int n) {
        return switch (n) {
            case 1 -> "�Ѱ�";
            case 2 -> "�ΰ�";
            default -> "����";
        };
    }
}
