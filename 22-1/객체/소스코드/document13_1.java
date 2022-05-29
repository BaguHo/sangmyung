import javax.swing.*;
import java.awt.Container;
import java.awt.*; 
import java.awt.event.*;

public class document13_1 extends JFrame{
    private JLabel la = new JLabel("Hello");
    public document13_1(){
        setTitle("Mouse 이벤트 예제");
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        Container c = getContentPane();
        JButton button1 = new JButton("Action");
        // button1.addActionListener(new EventHandler());
        c.add(button1);
        // c.addMouseListener(new MyMouseListener());
        button1.addMouseListener(new MouseAdapter(){
            public void mousePressed(MouseEvent e){
                JButton obj = (JButton)e.getSource();
                if(obj.getText().equals("Action")){
                    obj.setText("액션");
                }
                else{
                    obj.setText("Action");
                }
        }
        });
        // c.setLayout(null);
        // la.setSize(50,50);
        // la.setLocation(30,30);
        // c.add(la);
        
        setSize(300,300);
        setVisible(true);
    }

    // class MyMouseListener implements MouseListener{
    //     public void mousePressed(MouseEvent e){
    //         int x = e.getX();
    //         int y = e.getY();   
    //         la.setLocation(x,y);
    //     }
    
    //     public void mouseReleased(MouseEvent e){}
    //     public void mouseClicked(MouseEvent e){}
    //     public void mouseEntered(MouseEvent e){}
    //     public void mouseExited(MouseEvent e){}
    // }

    public static void main(String[] args){
        document13_1 frame = new document13_1();
    }
}

// public class EventHandler implements ActionListener{
//     @Override
//     public void actionPerformed(ActionEvent e){
//         JButton obj = (JButton)e.getSource();
//         if(obj.getText().equals("Action")){
//             obj.setText("액션");
//         }
//         else{
//             obj.setText("Action");
//         }
//     }
// }


