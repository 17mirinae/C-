import java.sql.DriverManager;
import java.sql.Connection;
import java.sql.SQLException;

public class DBConnection {
	public static Connection dbConn;

	public static Connection getConnection() {
		String DRIVER = "oracle.jdbc.driver.OracleDriver";
		String URL = "jdbc:oracle:thin:@localhost:1521/orcl";
		String USER = "system"; // ����� system
		String PASS = "rootoor"; // ��й�ȣ rootoor

		try {
			Class.forName(DRIVER);
			System.out.println("JDBC Driver �ε� ����");
			dbConn = DriverManager.getConnection(URL, USER, PASS);
			System.out.println("����Ŭ ���� ����");
		} catch (ClassNotFoundException e) {
			System.out.println("JDBC Driver �ε� ����");
		} catch (SQLException e) {
			System.out.println("����Ŭ ���� ����");
		}

		return dbConn;
	}
}