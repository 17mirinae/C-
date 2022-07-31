
public class Food {
	private int food_id;
	private String food_name;
	private int food_price;
	private String food_img;

	public int getFood_id() {
		return food_id;
	}

	public void setFood_id(int food_id) {
		this.food_id = food_id;
	}

	public String getFood_name() {
		return food_name;
	}

	public void setFood_name(String food_name) {
		this.food_name = food_name;
	}

	public int getFood_price() {
		return food_price;
	}

	public void setFood_price(int food_price) {
		this.food_price = food_price;
	}

	public String getFood_img() {
		return food_img;
	}

	public void setFood_img(String food_img) {
		this.food_img = food_img;
	}

	public Food(int food_id, String food_name, int food_price, String food_img) {
		this.setFood_id(food_id);
		this.setFood_name(food_name);
		this.setFood_price(food_price);
		this.setFood_img(food_img);
	}

	@Override
	public String toString() {
		return "" + this.getFood_id() + " " + this.getFood_name() + " " + this.getFood_price() + " "
				+ this.getFood_img();
	}
}
