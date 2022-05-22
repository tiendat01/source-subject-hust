package bai1;

public class Book {
	private String name;
	private String author;
	private int numberOfPage;

	public Book(String name, String author, int nbrPage) {
		this.name = name;
		this.author = author;
		numberOfPage = nbrPage;
	}
	
	public Book() { }
	
	public String getName() { return name; }
	public void setName(String name) { this.name = name; }
	
	public String getAuthor() { return author; }
	public void setAuthor(String author) {this.author = author; }
	
	public int getNumberOfPage() { return numberOfPage; }
	public void setNumberOfPage(int nbr) {
		if (nbr > 0) numberOfPage = nbr;
	}
	
	public void outputInfo() {
		// System.out.println(getName() + "\t" + getAuthor() + "\t" + getNumberOfPage());
		System.out.printf("%20s%20s%10d\n", getName(), getAuthor(), getNumberOfPage());
	}
}
