import java.sql.Array;

public class test {
    public static void main(String[] args) {
        int a = 1, b = 2;
        switch (a++) {
            case 1:
                b += a;
                System.out.println("case 1");
            case 2:
                b += 5;
                System.out.println("case 2");
        }
        int i = 100;
        char c = (char) i; // d���
        System.out.println(i + " " + c);
        // �ڹٿ����� float���¸� �ʱ�ȭ�� �� �ڿ� f�� �ٿ���� �Ѵ�
        // float f = 100.0;
        // System.out.println(f);

        int _ayte = 0;
        System.out.println(_ayte);
    }

    // �Ҽ����� �ƴ����� �Ǵ��ϴ� �Լ�
    boolean isPrime(int num) {
        int count = 0;
        for (int i = 1; i <= num; i++) {
            if (num % i == 0) {
                count++;
            }
        }
        if (count == 2) {
            return true;
        } else {
            return false;
        }
    }

    int factorial(int n) {
        int[] dp = new int[100];
        dp[1] = 1;
        for (int i = 2; i < n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n - 1];
    }
}