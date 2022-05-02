public class test2 {
    public static void main(String[] args) {
        Circle c = new Circle();
        c = new Circle();
        System.out.println(c.center.x + "," + c.center.y);
        c.center.x = 10;
        c.center.y = 10;
        c.r = 5;
        System.out.println(c.center.x + "," + c.center.y);
        c.draw();
    }

    static class Shape extends Point {
        String color = "blue";

        void draw() {
            System.out.println("draw the shape");
        }
    }

    static class Circle extends Shape {
        Point center;
        int r;

        Circle() {
            // this(new Point(0, 0), 10);
            center = new Point();
            r = 10;
        }

        Circle(Point center, int r) {
            this.center = center;
            this.r = r;
        }

        void draw() {
            System.out.println("draw the circle");
        }
    }

    static class Point {
        int x;
        int y;

        // »ý¼ºÀÚ
        Point() {
            this(0, 0);
        }

        Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    static class SuoerMan {

    }
}