import java.awt.event.ActionEvent;

public class task_week_11 extends Frame {
    task_week_11(){
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
    }
    public static void main(String[] args){
        task_week_11 t1 = new task_week_11();
    }
}

public class EventHandler implements ActionListener{
    @Override
    public void action(ActionEvent e){
        Object obj = e.getSource();
        
    }
}