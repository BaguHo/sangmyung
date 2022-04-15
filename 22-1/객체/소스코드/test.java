import javax.security.auth.callback.ChoiceCallback;

public class test {
    public static void main(String[] args) {
        Point p = new Point(); // 객체이자 인스턴스
        Point q = new Point();
        Point3D r = new Point3D();
        r.x = 1;
        r.y = 2;
        r.z = 3;
        p.x = 10;
        p.y = 20;
        q.x = 10;
        q.y = 20;
        System.out.println(p.x);
        System.out.println(p.y);
        System.out.println(q.x);
        System.out.println(q.y);
        System.out.println(r.x);
        System.out.println(r.y);
        System.out.println(r.z);
    }

    // 구조체
    static class Point {
        int x;
        int y;
    }

    static class Point3D extends Point {
        int z;
    }
}


