import java.util.Scanner;

// 2021 �߰����
public class TV {
    public static void main(String[] args) {
        TV prod1 = new TV(TV.lastProdNo);
        TV prod2 = new TV(TV.lastProdNo);
        TV prod3 = new TV(TV.lastProdNo);
        TV prod4 = new TV(TV.lastProdNo);
        TV prod5 = new TV(TV.lastProdNo);
        TV prod6 = new TV(TV.lastProdNo);

        if (prod1.getProdNo() % 2 == 0 || prod1.getProdNo() % 5 == 0 && prod1.getProdNo() != 0) {
            System.out.print("�����ȣ : " + prod1.prodNo + "  ");
            if (prod1.color == true) {
                System.out.println("color :  ���");
            } else {
                System.out.println("color :  ����");
            }
        }
        if (prod2.getProdNo() % 2 == 0 || prod2.getProdNo() % 5 == 0 && prod2.getProdNo() != 0) {
            System.out.print("�����ȣ : " + prod2.prodNo + "  ");
            if (prod2.color == true) {
                System.out.println("color :  ���");
            } else {
                System.out.println("color :  ����");
            }
        }
        if (prod3.getProdNo() % 2 == 0 || prod3.getProdNo() % 5 == 0 && prod3.getProdNo() != 0) {
            System.out.print("�����ȣ : " + prod3.prodNo + "  ");
            if (prod3.color == true) {
                System.out.println("color :  ���");
            } else {
                System.out.println("color :  ����");
            }
        }
        if (prod4.getProdNo() % 2 == 0 || prod4.getProdNo() % 5 == 0 && prod4.getProdNo() != 0) {
            System.out.print("�����ȣ : " + prod4.prodNo + "  ");
            if (prod4.color == true) {
                System.out.println("color :  ���");
            } else {
                System.out.println("color :  ����");
            }
        }
        if (prod5.getProdNo() % 2 == 0 || prod5.getProdNo() % 5 == 0 && prod5.getProdNo() != 0) {
            System.out.print("�����ȣ : " + prod5.prodNo + "  ");
            if (prod5.color == true) {
                System.out.println("color :  ���");
            } else {
                System.out.println("color :  ����");
            }
        }
        if ((prod6.getProdNo() % 2 == 0 || prod6.getProdNo() % 5 == 0) && prod6.getProdNo() != 0) {
            System.out.print("�����ȣ : " + prod6.prodNo + "  ");
            if (prod6.color == true) {
                System.out.println("color :  ���");
            } else {
                System.out.println("color :  ����");
            }
        }
    }

    // ä�ι�ȣ
    int channel;
    // ���������ȣ
    static int lastProdNo = 0;
    // �����ȣ
    int prodNo;
    // ����
    int volume;
    // ���� true - ���, false: ����
    boolean color;

    TV(int no) {
        this.lastProdNo++;
        this.prodNo = no;
        if (prodNo % 2 == 0) {
            this.color = true;
        } else {
            this.color = false;
        }
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

}