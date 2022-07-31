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

		JLabel order_table = new JLabel("테이블 번호");
		JLabel order_food = new JLabel("주문한 음식");
		JLabel order_count = new JLabel("주문 수량");
		JLabel order_price = new JLabel("가격");
		JButton delet_all = new JButton("전체 취소");

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
				JButton delet_btn = new JButton("취소");

				labelPanel.add(table_num);
				labelPanel.add(food_name);
				labelPanel.add(food_count);
				labelPanel.add(food_price);
				labelPanel.add(delet_btn);

				tablePanel.add(labelPanel);

				// 취소 버튼 선택 시
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
		JButton orderBtn = new JButton("주문하기");
		JButton backBtn = new JButton("뒤로");

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

		// 주문하기 버튼
		orderBtn.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				int result = JOptionPane.showConfirmDialog(null, "주문하시겠습니까?", "주문 확인", JOptionPane.YES_NO_OPTION);

				if (result == JOptionPane.YES_OPTION) {
					JOptionPane.showMessageDialog(null, "주문되었습니다.", "주문", JOptionPane.INFORMATION_MESSAGE);

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

		// 뒤로 버튼
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
