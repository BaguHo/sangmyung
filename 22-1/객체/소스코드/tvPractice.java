import javax.print.event.PrintJobAdapter;

public class tvPractice {
    public static void main(String[] args) {

        TV prod1 = new TV(++TV.lastProdNo);
        TV prod2 = new TV(++TV.lastProdNo);
        TV prod3 = new TV(++TV.lastProdNo);
        TV prod4 = new TV(++TV.lastProdNo);
        TV prod5 = new TV(++TV.lastProdNo);
        // printTV(prod1);
        // printTV(prod2);
        // printTV(prod3);
        // printTV(prod4);
        // printTV(prod5);

        if (prod1.getProdNo() % 2 == 0 || prod1.getProdNo() % 5 == 0) {
            System.out.println("�����ȣ: " + prod1.getProdNo() + " color: " +
                    prod1.getColorName());
        }
        if (prod2.getProdNo() % 2 == 0 || prod2.getProdNo() % 5 == 0) {
            System.out.println("�����ȣ: " + prod2.getProdNo() + " color: " +
                    prod2.getColorName());
        }
        if (prod3.getProdNo() % 2 == 0 || prod3.getProdNo() % 5 == 0) {
            System.out.println("�����ȣ: " + prod3.getProdNo() + " color: " +
                    prod3.getColorName());
        }
        if (prod4.getProdNo() % 2 == 0 || prod4.getProdNo() % 5 == 0) {
            System.out.println("�����ȣ: " + prod4.getProdNo() + " color: " +
                    prod4.getColorName());
        }
        if (prod5.getProdNo() % 2 == 0 || prod5.getProdNo() % 5 == 0) {
            System.out.println("�����ȣ: " + prod5.getProdNo() + " color: " +
                    prod5.getColorName());
        }
        // ����
        // char a = "a";

    }

    // public static void printTV(TV prod) {
    // if (prod.getProdNo() % 2 == 0 || prod.getProdNo() % 5 == 0) {
    // System.out.println("�����ȣ: " + prod.getProdNo() + " color: " +
    // prod.getColorName());
    // }
    // }
}

class TV {
    int channel;
    int prodNo;
    static int lastProdNo = 0;
    int volume;
    boolean color;

    TV(int no) {
        this.prodNo = no;
        if (this.getProdNo() % 2 == 0)
            this.color = true;
        else
            this.color = false;
    }

    int getProdNo() {
        return this.prodNo;
    }

    int getChannel() {
        return this.channel;
    }

    void channelUp() {
        this.channel++;
    }

    void channelDown() {
        this.channel--;
    }

    boolean getColor() {
        return this.color;
    }

    String getColorName() {
        if (this.getColor() == true) {
            return "���";
        } else {
            return "����";
        }
    }
}