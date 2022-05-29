import java.awt.*;
import javax.swing.*;

public class document11_2 extends Frame {
    public document11_2(){
        super("AWT 기본 예제");
        setLayout(new BorderLayout());
        Label t1 = new Label("ID");
        Label t2 = new Label("Passwd");
        TextField id = new TextField(10);
        TextField pwd = new TextField(10);
        Button btn = new Button("Login");

        Panel p1 = new Panel();
        p1.add(t1);
        p1.add(id);

        Panel p2 = new Panel();
        p2.add(t2);
        p2.add(pwd);
        p2.add(btn);

        add(p1, BorderLayout.NORTH);
        add(p2, BorderLayout.SOUTH);
        setSize(250,100);
        setVisible(true);
        // setDefaultCloseOperation((EXIT_ON_CLOSE));
    }
    public static void main(String[] args){
        // MyFrame2 mf = new MyFrame2();
        // document11_2 app = new document11_2();
        Calc c = new Calc();
    }
}

class MyFrame extends JFrame{
    MyFrame(){
        super("AWT 기본예제");
        getContentPane().setLayout(new BorderLayout());
        JLabel label = new JLabel("AWT 기본예제");
        JLabel t1 = new JLabel("ID");
        JLabel t2 = new JLabel("Passwd");
        JTextField id = new JTextField(10);
        JTextField pwd = new JTextField(10);
        JButton btn = new JButton("Login");
        getContentPane().add(label);
        getContentPane().add(t1);
        getContentPane().add(t2);

        JPanel p1 = new JPanel();
        p1.add(t1);
        p1.add(id);

        JPanel p2 = new JPanel();
        p2.add(t2);
        p2.add(pwd);
        p2.add(btn);
        
        add(p1, BorderLayout.NORTH);
        add(p2, BorderLayout.SOUTH);

        setSize(300,300);
        setVisible(true);
        setDefaultCloseOperation((EXIT_ON_CLOSE));
    }
}

class MyFrame2 extends JFrame{
    MyFrame2(){
        setLayout(new BorderLayout(10,5));
        JButton btn1 = new JButton("버튼1");
        JButton btn2 = new JButton("버튼2");
        JButton btn3 = new JButton("버튼3");
        JButton btn4 = new JButton("버튼4");
        JButton btn5 = new JButton("버튼5");
        add(btn1, BorderLayout.NORTH);
        add(btn2, BorderLayout.SOUTH);
        add(btn3, BorderLayout.CENTER);
        add(btn4, BorderLayout.WEST);
        add(btn5, BorderLayout.EAST);
        setSize(300,300);
        setVisible(true);
        setDefaultCloseOperation((EXIT_ON_CLOSE));
    }
}

// 레이아웃으로 계산기 만들기
class Calc extends JFrame{
    Calc(){
        setLayout(new GridLayout(4,3));
        JButton btn1 = new JButton("버튼1");
        JButton btn2 = new JButton("버튼2");
        JButton btn3 = new JButton("버튼3");
        JButton btn4 = new JButton("버튼4");
        JButton btn5 = new JButton("버튼5");
        add(btn1);
        add(btn2);
        add(btn3);
        add(btn4);
        add(btn5);
        setSize(300,300);
        setVisible(true);
        setDefaultCloseOperation((EXIT_ON_CLOSE));
    }
}