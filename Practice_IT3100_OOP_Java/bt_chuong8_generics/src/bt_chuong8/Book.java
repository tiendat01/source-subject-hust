package bt_chuong8;

import java.util.ArrayList;

public class Book {
	private ArrayList<Chapter> book;
	private int chapterCount;
	private String title;
	private String author;
	private String nxb;

	public Book() {
		// TODO Auto-generated constructor stub
		super();
		book = new ArrayList<Chapter>();
	}

	public Book(ArrayList<Chapter> book, int chapterCount, String title, String author, String nxb) {
		super();
		this.book = book;
		this.chapterCount = chapterCount;
		this.title = title;
		this.author = author;
		this.nxb = nxb;
	}

	public ArrayList<Chapter> getBook() {
		return book;
	}

	public void setBook(ArrayList<Chapter> book) {
		this.book = book;
	}

	public int getChapterCount() {
		return chapterCount;
	}

	public void setChapterCount(int chapterCount) {
		this.chapterCount = chapterCount;
	}
	
	public String getTitle() {
		return title;
	}

	public void setTitle(String title) {
		this.title = title;
	}

	public String getAuthor() {
		return author;
	}

	public void setAuthor(String author) {
		this.author = author;
	}

	public String getNxb() {
		return nxb;
	}

	public void setNxb(String nxb) {
		this.nxb = nxb;
	}

	// them chapter
	public void addChapter(Chapter chapter) {
		book.add(chapter);
		chapterCount++;
	}

}
