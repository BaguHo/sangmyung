import java.util.Scanner;

// 2021 중간고사
public class TV {
    public static void main(String[] args) {
        TV prod1 = new TV(TV.lastProdNo);
        TV prod2 = new TV(TV.lastProdNo);
        TV prod3 = new TV(TV.lastProdNo);
        TV prod4 = new TV(TV.lastProdNo);
        TV prod5 = new TV(TV.lastProdNo);
        TV prod6 = new TV(TV.lastProdNo);

        if (prod1.getProdNo() % 2 == 0 || prod1.getProdNo() % 5 == 0 && prod1.getProdNo() != 0) {
            System.out.print("생산번호 : " + prod1.prodNo + "  ");
            if (prod1.color == true) {
                System.out.println("color :  흰색");
            } else {
                System.out.println("color :  검정");
            }
        }
        if (prod2.getProdNo() % 2 == 0 || prod2.getProdNo() % 5 == 0 && prod2.getProdNo() != 0) {
            System.out.print("생산번호 : " + prod2.prodNo + "  ");
            if (prod2.color == true) {
                System.out.println("color :  흰색");
            } else {
                System.out.println("color :  검정");
            }
        }
        if (prod3.getProdNo() % 2 == 0 || prod3.getProdNo() % 5 == 0 && prod3.getProdNo() != 0) {
            System.out.print("생산번호 : " + prod3.prodNo + "  ");
            if (prod3.color == true) {
                System.out.println("color :  흰색");
            } else {
                System.out.println("color :  검정");
            }
        }
        if (prod4.getProdNo() % 2 == 0 || prod4.getProdNo() % 5 == 0 && prod4.getProdNo() != 0) {
            System.out.print("생산번호 : " + prod4.prodNo + "  ");
            if (prod4.color == true) {
                System.out.println("color :  흰색");
            } else {
                System.out.println("color :  검정");
            }
        }
        if (prod5.getProdNo() % 2 == 0 || prod5.getProdNo() % 5 == 0 && prod5.getProdNo() != 0) {
            System.out.print("생산번호 : " + prod5.prodNo + "  ");
            if (prod5.color == true) {
                System.out.println("color :  흰색");
            } else {
                System.out.println("color :  검정");
            }
        }
        if ((prod6.getProdNo() % 2 == 0 || prod6.getProdNo() % 5 == 0) && prod6.getProdNo() != 0) {
            System.out.print("생산번호 : " + prod6.prodNo + "  ");
            if (prod6.color == true) {
                System.out.println("color :  흰색");
            } else {
                System.out.println("color :  검정");
            }
        }
    }

    // 채널번호
    int channel;
    // 최종생산번호
    static int lastProdNo = 0;
    // 생산번호
    int prodNo;
    // 볼륨
    int volume;
    // 색깔 true - 흰색, false: 검정
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