
public class Drink {
	private int drink_id;
	private String drink_name;
	private int drink_price;
	private String drink_img;

	public int getDrink_id() {
		return drink_id;
	}

	public void setDrink_id(int drink_id) {
		this.drink_id = drink_id;
	}

	public String getDrink_name() {
		return drink_name;
	}

	public void setDrink_name(String drink_name) {
		this.drink_name = drink_name;
	}

	public int getDrink_price() {
		return drink_price;
	}

	public void setDrink_price(int drink_price) {
		this.drink_price = drink_price;
	}

	public String getDrink_img() {
		return drink_img;
	}

	public void setDrink_img(String drink_img) {
		this.drink_img = drink_img;
	}

	public Drink(int drink_id, String drink_name, int drink_price, String drink_img) {
		this.setDrink_id(drink_id);
		this.setDrink_name(drink_name);
		this.setDrink_price(drink_price);
		this.setDrink_img(drink_img);
	}

	@Override
	public String toString() {
		return "" + this.getDrink_id() + " " + this.getDrink_name() + " " + this.getDrink_price() + " "
				+ this.getDrink_img();
	}
}
