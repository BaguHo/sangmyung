public class polynomial {
    public static void main(String[] args) {
        FireEngine fe = new FireEngine();

        if (fe instanceof FireEngine) {
            System.out.println("FireEngine instance");
        }
        if (fe instanceof Car) {
            System.out.println("Car instance");
        }
        if (fe instanceof Object) {
            System.out.println("Object instance");
        }
    }
}

class Car {
    String color;
    int door;

    void drive() {
        System.out.println("drive");
    }

    void stop() {
        System.out.println("stop");
    }
}

class FireEngine extends Car {
    void water() {
        System.out.println("water");
    }
}