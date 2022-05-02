public class IncrementDemo {
    public static void main(String[] args) {
        int x = 0;
        System.out.println("매서드 호출 전: " + x);
        increment(x);
        System.out.println("매서드 호출 후: " + x);
    }

    public static void increment(int n){
        System.out.println("매서드 호출 전: " + n++);
        System.out.println("매서드 호출 후: " + n);
    }
}
