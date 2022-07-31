import javax.swing.*;
import javax.swing.border.*;
import java.awt.*;
import java.awt.event.*;
import java.sql.*;
import java.util.ArrayList;

public class MainGUI extends JFrame {
	Connection conn = null;
	Statement stmt = null;

	int number = 0;

	public MainGUI() {
		JFrame frame = new JFrame();
		frame.setPreferredSize(new Dimension(912, 500));
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setLayout(new BorderLayout());

		JLabel table = new JLabel("���̺� ��ȣ �Է�: ");
		JTextField table_num = new JTextField(5);

		// ����, �ַ� �г�
		JPanel typePanel = new JPanel();
		JButton foodBtn = new JButton("����");
		JButton drinkBtn = new JButton("�ַ�");

		drinkBtn.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				frame.dispose();
				new DrinkGUI();
			}
		});
		typePanel.add(table);
		typePanel.add(table_num);
		typePanel.add(foodBtn);
		typePanel.add(drinkBtn);

		// ������ �гο� �߰��� �޴� �г�
		JPanel menuPanel = new JPanel();
		menuPanel.setLayout(new BoxLayout(menuPanel, BoxLayout.X_AXIS));
		menuPanel.setAutoscrolls(true);

		// �޴� �гο� ����� ScrollPane
		JScrollPane scroll = new JScrollPane(menuPanel);
		scroll.setHorizontalScrollBarPolicy(JScrollPane.HORIZONTAL_SCROLLBAR_AS_NEEDED);
		scroll.setBounds(0, 0, 900, 380);

		// �޴� �г�
		JPanel contentPanel = new JPanel(null);
		contentPanel.setPreferredSize(new Dimension(100, 100));
		contentPanel.add(scroll);

		ArrayList<Food> foodList = new ArrayList<Food>();

		try {
			conn = DBConnection.getConnection();
			stmt = conn.createStatement();

			String query = "SELECT * FROM FOOD ORDER BY FOOD_ID";

			ResultSet rs = stmt.executeQuery(query);

			while (rs.next()) {
				int menu_id = rs.getInt("FOOD_ID");
				String menu_name = rs.getString("FOOD_NAME");
				int menu_price = rs.getInt("FOOD_PRICE");
				String menu_img = rs.getString("FOOD_IMG");

				Food food = new Food(menu_id, menu_name, menu_price, menu_img);
				foodList.add(food);

				// �� �޴� �г�
				JPanel menu = new JPanel();
				menu.setLayout(new BorderLayout());
				menu.setPreferredSize(new Dimension(300, 360));
				menu.setBorder(new TitledBorder(new LineBorder(Color.black, 5)));

				// �޴��� �̸��� ����
				JLabel menuNameLabel = new JLabel(
						" �޴� : " + menu_name + "   ���� : " + String.valueOf(menu_price) + " ��");

				// �޴��� ����
				JLabel imageIcon = new JLabel(new ImageIcon("./FOOD/" + menu_img));
				imageIcon.setPreferredSize(new Dimension(300, 100));

				// ���� ��ư
				JPanel count_panel = new JPanel();
				JButton Minbtn = new JButton("-");

				JLabel count_label = new JLabel("" + number);
				JButton Plusbtn = new JButton("+");

				Minbtn.addActionListener(new ActionListener() {
					@Override
					public void actionPerformed(ActionEvent e) {
						// TODO Auto-generated method stub

						if (number == 0)
							count_label.setText("" + number);
						else {
							number--;
							count_label.setText("" + number);
						}
					}
				});

				Plusbtn.addActionListener(new ActionListener() {
					@Override
					public void actionPerformed(ActionEvent e) {
						// TODO Auto-generated method stub

						number++;
						count_label.setText(number + "");
					}
				});

				count_panel.add(Minbtn);
				count_panel.add(count_label);
				count_panel.add(Plusbtn);
				// ��� ��ư
				JButton putBtn = new JButton("���");

				menu.add(menuNameLabel, BorderLayout.NORTH);
				menu.add(imageIcon, BorderLayout.CENTER);
				menu.add(count_panel, BorderLayout.AFTER_LINE_ENDS);
				menu.add(putBtn, BorderLayout.SOUTH);
				menuPanel.add(menu);

				// ��� ��ư
				putBtn.addActionListener(new ActionListener() {
					@Override
					public void actionPerformed(ActionEvent e) {
						try {
							conn = DBConnection.getConnection();
							stmt = conn.createStatement();

							// int val = 0; // �ش� �޴��� ������ Ȯ���ϱ� ���� ����

							String input_number = table_num.getText();

							if (input_number.equals("")) {
								JOptionPane.showMessageDialog(null, "���̺� ��ȣ�� �Է����ּ���.", "����", JOptionPane.ERROR_MESSAGE);
							} else if (number == 0) {
								JOptionPane.showMessageDialog(null, "������ �����ּ���.", "����", JOptionPane.ERROR_MESSAGE);
							} else {
								int table_number = Integer.parseInt(input_number);
								String order_menu_name = menu_name;
								if (number == 0) {
									JOptionPane.showMessageDialog(null, "������ �����ּ���.", "����", JOptionPane.ERROR_MESSAGE);
								} else {
									int order_count = number;
									int order_price = menu_price;
									String query = "INSERT INTO ORDER_TABLE VALUES(key_seq.NEXTVAL, " + table_number
											+ ", '" + order_menu_name + "', " + order_count + ", " + order_price + ")";

									stmt.executeUpdate(query);
									JOptionPane.showMessageDialog(null, "�����Ͻ� �޴��� ��ҽ��ϴ�.", "���",
											JOptionPane.INFORMATION_MESSAGE);
								}
							}
						} catch (SQLException e1) {
							// TODO Auto-generated catch block
							e1.printStackTrace();
						}

						number = 0;
						count_label.setText("" + number);
					}
				});
			}
		} catch (SQLException sqle) {
			sqle.printStackTrace();
		}

		// ��ư �г�
		JPanel buttonPanel = new JPanel();
		JButton bucketBtn = new JButton("�ֹ���");
		JButton manageBtn = new JButton("������");
		JPasswordField passwordField = new JPasswordField();
		passwordField.setPreferredSize(new Dimension(100, 25));

		// �ֹ��� ��ư
		bucketBtn.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				frame.dispose();
				new BucketGUI();
			}
		});

		// ������ �α��� ��ư
		manageBtn.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				try {
					conn = DBConnection.getConnection();
					stmt = conn.createStatement();

					String query = "SELECT * FROM ADMINPWD";

					ResultSet rs = stmt.executeQuery(query);

					if (rs.next()) {
						String enter_pwd = new String(passwordField.getPassword());
						String db_pwd = rs.getString("PWD");

						if (enter_pwd.equals(db_pwd)) {
							frame.dispose();
							new ManageGUI();
						} else {
							JOptionPane.showMessageDialog(null, "��й�ȣ�� Ʋ�Ƚ��ϴ�.", "����", JOptionPane.ERROR_MESSAGE);
							passwordField.setText("");
						}
					}
				} catch (SQLException sqle) {
					sqle.printStackTrace();
				}
			}
		});

		buttonPanel.add(bucketBtn);
		buttonPanel.add(manageBtn);
		buttonPanel.add(passwordField);

		frame.add(typePanel, BorderLayout.NORTH);
		frame.add(contentPanel, BorderLayout.CENTER);
		frame.add(buttonPanel, BorderLayout.SOUTH);

		frame.pack();
		frame.setVisible(true);

		// DB ������ �����Ѵ�.
		try {
			if (stmt != null) {
				stmt.close();
			}
			if (conn != null) {
				conn.close();
			}
		} catch (Exception e) {
			throw new RuntimeException(e.getMessage());
		}
	}

	public static void main(String[] args) {
		new MainGUI();
	}
}