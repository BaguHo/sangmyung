import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class document_12_3 extends JFrame implements ActionListener{
    int index = 0;
    String[] msg = {"첫 번째 문장", "두 번째 문장", "세 번째 문장"};
    JButton button1 = new JButton("<<");
    JButton button2 = new JButton(">>");
    JButton button3 = new JButton(msg[0]);

    public document_12_3(){
        BorderLayout layout = new BorderLayout();
        setLayout(layout);
        button1.addActionListener(this);
        button2.addActionListener(this);
        button3.setEnabled(false);
        add(button1, BorderLayout.WEST);
        add(button2, BorderLayout.EAST);
        add(button3, BorderLayout.CENTER);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setSize(300, 200);
        setVisible(true);
    }
    public static void main(String[] args){
        document_12_3 app = new document_12_3();
    }
}

public class EventHandler implements ActionListener{
    @Override
    public void actionPerformed(ActionEvent e){
        Object obj = e.getSource();
        if(obj == button1)
            index--;
        else if(obj == button2)
            index++;
        if(index > 2)
            index = 0;
        else if (index < 0)
            index = 2;
        button3.setText(msg[index]);
    }
}
