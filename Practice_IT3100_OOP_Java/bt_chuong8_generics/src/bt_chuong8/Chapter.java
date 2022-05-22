package bt_chuong8;

import java.util.ArrayList;

public class Chapter {
	private ArrayList<Page> chapter;
	private int pageCount;
	private int stt;
	private String title;
	
	public Chapter() {
		super();
		chapter = new ArrayList<Page>();
	}
	
	public Chapter(int stt) {
		super();
		this.stt = stt;
		chapter = new ArrayList<Page>();
	}
	
	public Chapter(ArrayList<Page> chapter, int pageCount, int stt, String title) {
		super();
		this.chapter = chapter;
		this.pageCount = pageCount;
		this.stt = stt;
		this.title = title;
	}
	
	public String getTitle() {
		return title;
	}

	public void setTitle(String title) {
		this.title = title;
	}

	public int getStt() {
		return stt;
	}

	public void setStt(int stt) {
		this.stt = stt;
	}

	public ArrayList<Page> getChapter() {
		return chapter;
	}
	public void setChapter(ArrayList<Page> chapter) {
		this.chapter = chapter;
	}
	public int getPageCount() {
		return pageCount;
	}
	public void setPageCount(int pageCount) {
		this.pageCount = pageCount;
	}
	
	// phuong thuc them 1 trang vao chapter
	public void addPage(Page page) {
		chapter.add(page);
		pageCount++;
	}
	
}
