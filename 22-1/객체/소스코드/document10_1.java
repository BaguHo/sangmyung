public class document10_1 {
    public static void main(String[] args) {
        Parent p = new Parent();
        Child c = new Child();
        Parent p2 = new Child();
        System.out.println("p.x = " + p.x);
        System.out.println("p2.x = " + p2.x);
        System.out.println("c.x = " + c.x);
    }
}

class Parent {
    int x = 100;

    void method() {
        System.out.println("Parent method");
    }
}

class Child extends Parent {
    int x = 200;

    void method() {
        System.out.println("Child method");
    }
}
