public class inherience {
    public static void main(String[] args) {
        // parent p1 = new parent();
        // child c1 = new child();
        Point p1 = new Point();
        Point3D p2 = new Point3D();
    }
}

class Point {
    int x;

    Point() {
        x = 10;
        System.out.println("Point " + x);
    }
}

class Point3D extends Point {
    int x;

    Point3D() {
        super();
        System.out.println("super");
        this.x = 20;
        System.out.println("this " + this.x);
        super.x = 20;
        System.out.println("super " + super.x);
    }

}

class parent {
    parent() {
        System.out.println("parent 持失切");
    }
}

class child extends parent {
    child() {
        System.out.println("child 持失切");
    }
}
