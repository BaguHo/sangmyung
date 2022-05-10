public class document10_2 {
    public static void main(String[] args) {
        TV t1 = new TV();
        Computer c1 = new Computer();
        Buyer b1 = new Buyer();

        b1.buy(t1);
        b1.buy(c1);
        System.out.println(b1.money);
    }
}

class Product {
    int price;
    int bonusPoint;
}

class TV extends Product {
    TV() {
        this.price = 200;
        this.bonusPoint = 100;

    }
}

class Computer extends Product {
    Computer() {
        this.price = 250;
        this.bonusPoint = 50;
    }
}

class Audio extends Product {
    Audio() {
        this.price = 100;
        this.bonusPoint = 10;
    }
}

class Buyer {
    int money = 1000;
    int bonusPoint = 0;

    void buy(Product t) {
        if (money < t.price) {
            System.out.println("ÀÜ¾×ºÎÁ·");
            return;
        }
        money -= t.price;
        bonusPoint += t.bonusPoint;
    }
}
