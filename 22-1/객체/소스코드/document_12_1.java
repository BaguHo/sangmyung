import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class document_12_1 extends JFrame{
    JButton button1 = new JButton("버튼1");
    JButton button2 = new JButton("버튼2");
    JButton button3 = new JButton("버튼3");
    JButton button4 = new JButton("버튼4");
    JButton button5 = new JButton("버튼5");
    
    Panel p1 = new Panel();
    Panel p2 = new Panel();

    public void flowLayout(){
        p1.setLayout(new FlowLayout());
        p1.add(button1);
        p1.add(button2);
        p1.add(button3);
        p1.add(button4);
    }
    public void gridLayout(){
        p1.setLayout(new GridLayout());
        p1.add(button1);
        p1.add(button2);
        p1.add(button3);
        p1.add(button4);
    }
    public void borderLayout(){
        p1.setLayout(new BorderLayout());
        p1.add(button1, BorderLayout.NORTH);
        p1.add(button1, BorderLayout.WEST);
        p1.add(button1, BorderLayout.EAST);
        p1.add(button1, BorderLayout.CENTER);
    }
    public void cardLayout(){
        final CardLayout card = new CardLayout();
        setLayout(card);
        p1.add(button1);
        p1.add(button2);
        p1.add(button3);
        p2.add(button4);
        p2.add(button5);
        add("p1", p1);
        add("p2", p2);
        // **중요**
        // Listener에게 위임 
        button1.addListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvevnt arg0){
                card.show(getContentPane()."p2");
            }
        });

        button2.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent arg0){
                card.show(getContentPane(), "p2");
            }
        });
        button3.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent arg0){
                card.show(getContentPane(), "p2");
            }
        });
    }
    public document_12_1(){
        super("Layout Showcase");
        getContentPane().add(p1);
        // flowLayout();
        // gridLayout();
        // borderLayout();
        cardLayout();
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setSize(300,200);
        setVisible(true);
    }

    // 내부클래스를 만들어서 구현시킬 때 card를 어떻게 가져와야 할까?
    /*
    class EventHandler implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent arg0){
            
        }
    }
    */
    public static void main(String[] args){
        document_12_1 app = new document_12_1();
    }
}
