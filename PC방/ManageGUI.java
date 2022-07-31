import java.awt.*;
import java.awt.event.*;
import java.sql.*;
import javax.swing.*;

public class ManageGUI extends JFrame {
	Connection conn = null;
	Statement stmt = null;

	public ManageGUI() {
		JFrame frame = new JFrame();
		frame.setPreferredSize(new Dimension(770, 500));
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
			String query = "SELECT * FROM MANAGE_TABLE ORDER BY ORDER_ID DESC"; // 역방향 순서
			ResultSet rs = stmt.executeQuery(query);
			while (rs.next()) {
				int food_order_id = rs.getInt("ORDER_ID");
				int food_table_num = rs.getInt("ORDER_TABLE");
				String food_name_order = rs.getString("ORDER_NAME");
				int food_count_order = rs.getInt("ORDER_COUNT");
				int food_price_order = rs.getInt("ORDER_PRICE");

				JPanel labelPanel = new JPanel();
				labelPanel.setLayout(new FlowLayout(FlowLayout.LEFT, 70, 10));
				labelPanel.setBorder(BorderFactory.createLineBorder(Color.BLACK, 2));

				JLabel table_num = new JLabel(String.valueOf(food_table_num));
				JLabel food_name = new JLabel("" + food_name_order);
				JLabel food_count = new JLabel(String.valueOf(food_count_order));
				JLabel food_price = new JLabel(String.valueOf(food_price_order * food_count_order));
				JButton fin_btn = new JButton("주문완료");
				// JButton delet_btn = new JButton("주문취소");

				labelPanel.add(table_num);
				labelPanel.add(food_name);
				labelPanel.add(food_count);
				labelPanel.add(food_price);
				labelPanel.add(fin_btn);
				// labelPanel.add(delet_btn);

				tablePanel.add(labelPanel);
				// 주문완료 버튼 클릭시 주문누적 테이블로 옯기고 현재 테이블에서 제거하기
				// 주문취소 버튼 선택 시
				fin_btn.addActionListener(new ActionListener() {

					public void actionPerformed(ActionEvent e) {
						try {
							conn = DBConnection.getConnection();
							stmt = conn.createStatement();

							String query = "DELETE FROM MANAGE_TABLE WHERE ORDER_ID=" + food_order_id;
							stmt.executeUpdate(query);

							frame.dispose();
						} catch (SQLException e1) {
							e1.printStackTrace();
						}
						new ManageGUI();
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
					String delete_query = "DELETE FROM MANAGE_TABLE";
					System.out.println(delete_query);
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
