import java.sql.DriverManager;
import java.sql.Connection;
import java.sql.SQLException;

public class DBConnection {
	public static Connection dbConn;

	public static Connection getConnection() {
		String DRIVER = "oracle.jdbc.driver.OracleDriver";
		String URL = "jdbc:oracle:thin:@localhost:1521/orcl";
		String USER = "system"; // 사용자 system
		String PASS = "rootoor"; // 비밀번호 rootoor

		try {
			Class.forName(DRIVER);
			System.out.println("JDBC Driver 로딩 성공");
			dbConn = DriverManager.getConnection(URL, USER, PASS);
			System.out.println("오라클 연결 성공");
		} catch (ClassNotFoundException e) {
			System.out.println("JDBC Driver 로딩 실패");
		} catch (SQLException e) {
			System.out.println("오라클 연결 실패");
		}

		return dbConn;
	}
}