class TV {
    int channel;
    int prodNo;
    static int lastProdNo = 0;
    int volume;
    boolean color;

    TV(int lastProdNo) {

        this.channel = 0;
        this.volume = 0;
        this.prodNo = lastProdNo;
        if (this.prodNo % 2 == 0)
            this.color = true;
        else
            this.color = false;
    }
}

public class 동훈_TV {
    public static void main(String[] argv) {
        TV prod1 = new TV(++TV.lastProdNo);
        TV prod2 = new TV(++TV.lastProdNo);
        TV prod3 = new TV(++TV.lastProdNo);
        TV prod4 = new TV(++TV.lastProdNo);
        TV prod5 = new TV(++TV.lastProdNo);
        System.out.printf("생산번호 : %d  color : %s\n", getProNo(prod2), getColor(prod2));
        System.out.printf("생산번호 : %d  color : %s\n", getProNo(prod4), getColor(prod4));
        System.out.printf("생산번호 : %d  color : %s\n", getProNo(prod5), getColor(prod5));
        System.out.println("prod1의 채널은: " + getChannel(prod1));
        channelUp(prod1);
        channelUp(prod1);
        channelUp(prod1);
        System.out.println("prod1의 채널은: " + getChannel(prod1));
    }

    public static int getProNo(TV n) {
        return n.prodNo;
    }

    public static int getChannel(TV n) {
        return n.channel;
    }

    public static void channelUp(TV n) {
        n.channel++;
    }

    public static void channelDown(TV n) {
        n.channel--;
    }

    public static String getColor(TV n) {
        if (n.color)
            return "흰색";
        else
            return "검정";
    }
}