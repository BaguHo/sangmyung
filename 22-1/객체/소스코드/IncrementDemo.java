public class IncrementDemo {
    public static void main(String[] args) {
        int x = 0;
        System.out.println("�ż��� ȣ�� ��: " + x);
        increment(x);
        System.out.println("�ż��� ȣ�� ��: " + x);
    }

    public static void increment(int n){
        System.out.println("�ż��� ȣ�� ��: " + n++);
        System.out.println("�ż��� ȣ�� ��: " + n);
    }
}
