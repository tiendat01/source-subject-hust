package practice_codelearn;

public class Book {
	private String name;
	private double price;
	private Author[] authors;

	public Book(String name, Author[] authors, double price) {
		this.name = name;
		this.price = price;
		this.authors = authors;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public double getPrice() {
		return price;
	}

	public void setPrice(double price) {
		this.price = price;
	}

	public String getAuthorNames() {
		String authorNames = "";
		for (int i = 0; i < authors.length - 1; i++) {
			authorNames += authors[i].getName() + ", ";
		}
		authorNames += authors[authors.length - 1].getName();
		return authorNames;
	}
}
