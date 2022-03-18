//package sec03;

public class NumberTypeDemo{
    public static void main(String[] args){
        int mach;
        int distance;
        mach = 340;
        distance = mach * 60 * 60;
        System.out.println("소리가 1시간 동안 가는 거리: " + distance + "m");

        double radius;
        double area;
        radius = 10.0;
        area = radius * radius * 3.14;
        System.out.println("반지름이 " + radius + "인 원의 길이: " + area);
        
        char c = 'a';
        //c = "A";
        // char c = 65;
        // char c = '\u0041';
        // char c = "A";
        
        boolean condition = true;
        boolean cham = true;
        boolean geojit = false;
        
        int var =1;
        
        final double PI;
        PI = 3.141592;
        System.out.println(PI);

        float f = (float)3.14;

        byte b = (byte)300;

        byte x = (byte)3.14;
    }
}