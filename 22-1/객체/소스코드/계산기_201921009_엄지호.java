import javax.swing.*;
import java.awt.Container;
import java.awt.*;
import java.awt.event.*;
import java.awt.BorderLayout.*;
import java.awt.GridLayout.*;

public class 계산기_201921009_엄지호 extends JFrame {
    JTextField input_text;
    int oper;
    int num;
    int total;

    public 계산기_201921009_엄지호() {
        oper = 0;
        num = 0;
        total = 0;
        String name[] = { "7", "8", "9", "/", "4", "5", "6", "*", "1", "2", "3", "-", "C", "0", "=", "+" };
        JButton button[] = new JButton[name.length];
        input_text = new JTextField("", SwingConstants.CENTER);
        input_text.setHorizontalAlignment(JTextField.RIGHT);
        input_text.setFont((new Font(Font.SERIF, Font.BOLD, 40)));
        BorderLayout layout = new BorderLayout(2, 2);
        setLayout(layout);
        Container c = getContentPane();
        JPanel p1 = new JPanel();

        for (int i = 0; i < name.length; i++) {
            button[i] = new JButton(name[i]);
            p1.add(button[i]);
            PadInput handler = new PadInput();
            button[i].addActionListener(handler);
        }

        p1.setLayout(new GridLayout(4, 4));
        c.add(input_text, BorderLayout.NORTH);
        c.add(p1, BorderLayout.CENTER);

        // for (int i = 0; i < button.length; i++) {
        // button[i].addActionListener(new PadInput() {

        // });
        // }

        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setSize(300, 400);
        setVisible(true);
    }

    private class PadInput implements ActionListener {
        public void actionPerformed(ActionEvent e) {
            String eventText = e.getActionCommand();
            // input_text.setText(input_text.getText() + e.getActionCommand());
            if (eventText.equals("C")) {
                total = 0;
                oper = 0;
                input_text.setText("");
            } else if (eventText.equals("+")) {
                input_text.setText("");
                total += num;
                oper = 0;
            } else if (eventText.equals("-")) {
                input_text.setText("");
                total += num;
                oper = 1;
            } else if (eventText.equals("*")) {
                input_text.setText("");
                total += num;
                oper = 2;
            } else if (eventText.equals("/")) {
                input_text.setText("");
                total += num;
                oper = 3;
            } else if (eventText.equals("=")) {
                if (oper == 0) {
                    total += num;
                    input_text.setText("" + total);
                    num = 0;
                } else if (oper == 1) {
                    total -= num;
                    input_text.setText("" + total);
                    num = 0;
                } else if (oper == 2) {
                    total *= num;
                    input_text.setText("" + total);
                    num = 0;
                } else if (oper == 3) {
                    total /= num;
                    input_text.setText("" + total);
                    num = 0;
                }
            } else {
                String count = input_text.getText() + e.getActionCommand();
                input_text.setText(count);
                num = Integer.parseInt(count);
            }
        }
    }

    public static void main(String[] args) {
        계산기_201921009_엄지호 c = new 계산기_201921009_엄지호();
    }
}
