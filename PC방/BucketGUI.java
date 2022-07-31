import java.awt.*;
import java.awt.event.*;
import java.sql.*;

import javax.swing.*;

public class BucketGUI extends JFrame {
	Connection conn = null;
	Statement stmt = null;

	public BucketGUI() {
		JFrame frame = new JFrame();
		frame.setPreferredSize(new Dimension(650, 500));
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setLayout(new BorderLayout());

		JPanel tableInformation = new JPanel();
		tableInformation.setLayout(new FlowLayout(FlowLayout.LEFT, 40, 20));

		JLabel order_table = new JLabel("���̺� ��ȣ");
		JLabel order_food = new JLabel("�ֹ��� ����");
		JLabel order_count = new JLabel("�ֹ� ����");
		JLabel order_price = new JLabel("����");
		JButton delet_all = new JButton("��ü ���");

		tableInformation.add(order_table);
		tableInformation.add(order_food);
		tableInformation.add(order_count);
		tableInformation.add(order_price);
		tableInformation.add(delet_all);

		JPanel tablePanel = new JPanel();
		tablePanel.setLayout(new BoxLayout(tablePanel, BoxLayout.Y_AXIS));

		JScrollPane scroll = new JScrollPane(tablePanel);

		try {
			conn = DBConnection.getConnection();
			stmt = conn.createStatement();

			String query = "SELECT * FROM ORDER_TABLE ORDER BY FOOD_ORDER_ID DESC";

			ResultSet rs = stmt.executeQuery(query);

			while (rs.next()) {
				int food_order_id = rs.getInt("FOOD_ORDER_ID");
				int food_table_num = rs.getInt("FOOD_TABLE_NUMBER");
				String food_name_order = rs.getString("FOOD_NAME_ORDER");
				int food_count_order = rs.getInt("FOOD_COUNT_ORDER");
				int food_price_order = rs.getInt("FOOD_PRICE_ORDER");

				JPanel labelPanel = new JPanel();
				labelPanel.setLayout(new FlowLayout(FlowLayout.LEFT, 70, 10));
				labelPanel.setBorder(BorderFactory.createLineBorder(Color.BLACK, 2));

				JLabel table_num = new JLabel(String.valueOf(food_table_num));
				JLabel food_name = new JLabel("" + food_name_order);
				JLabel food_count = new JLabel(String.valueOf(food_count_order));
				JLabel food_price = new JLabel(String.valueOf(food_price_order * food_count_order));
				JButton delet_btn = new JButton("���");

				labelPanel.add(table_num);
				labelPanel.add(food_name);
				labelPanel.add(food_count);
				labelPanel.add(food_price);
				labelPanel.add(delet_btn);

				tablePanel.add(labelPanel);

				// ��� ��ư ���� ��
				delet_btn.addActionListener(new ActionListener() {

					public void actionPerformed(ActionEvent e) {
						try {
							conn = DBConnection.getConnection();
							stmt = conn.createStatement();

							String query = "DELETE FROM ORDER_TABLE WHERE FOOD_ORDER_ID=" + food_order_id;
							stmt.executeUpdate(query);

							frame.dispose();
						} catch (SQLException e1) {
							e1.printStackTrace();
						}
						new BucketGUI();
					}
				});
			}
		} catch (SQLException sqle) {
			sqle.printStackTrace();
		}

		JPanel buttonPanel = new JPanel();
		JButton orderBtn = new JButton("�ֹ��ϱ�");
		JButton backBtn = new JButton("�ڷ�");

		delet_all.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				try {
					conn = DBConnection.getConnection();
					stmt = conn.createStatement();
					String delete_query = "DELETE FROM ORDER_TABLE";
					// System.out.println(delete_query);
					stmt.executeUpdate(delete_query);
					frame.dispose();
					new BucketGUI();
				} catch (SQLException e1) {
					e1.printStackTrace();
				}
			}
		});

		// �ֹ��ϱ� ��ư
		orderBtn.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				int result = JOptionPane.showConfirmDialog(null, "�ֹ��Ͻðڽ��ϱ�?", "�ֹ� Ȯ��", JOptionPane.YES_NO_OPTION);

				if (result == JOptionPane.YES_OPTION) {
					JOptionPane.showMessageDialog(null, "�ֹ��Ǿ����ϴ�.", "�ֹ�", JOptionPane.INFORMATION_MESSAGE);

					try {
						conn = DBConnection.getConnection();
						stmt = conn.createStatement();

						String query = "INSERT INTO MANAGE_TABLE SELECT * FROM ORDER_TABLE";
						stmt.executeUpdate(query);
						query = "DELETE FROM ORDER_TABLE";
						stmt.executeUpdate(query);
						frame.dispose();
					} catch (SQLException e1) {
						e1.printStackTrace();
					}
					frame.dispose();
					new MainGUI();
				}
			}
		});

		// �ڷ� ��ư
		backBtn.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				frame.dispose();
				new MainGUI();
			}
		});

		buttonPanel.add(orderBtn);
		buttonPanel.add(backBtn);

		frame.add(tableInformation, BorderLayout.NORTH);
		frame.add(scroll, BorderLayout.CENTER);
		frame.add(buttonPanel, BorderLayout.SOUTH);

		frame.pack();
		frame.setVisible(true);
	}
}
