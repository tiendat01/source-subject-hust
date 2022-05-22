package bt_chuong8;

import java.util.Random;

public class Test {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		// tao page
//		Page p1 = new Page(1);
//		Page p2 = new Page(2);
//		Page p3 = new Page(3);
//		Page p4 = new Page(4);
//		Page p5 = new Page(5);
//		Page p6 = new Page(6);
//		Page p7 = new Page(7);
//		Page p8 = new Page(8);
//		Page p9 = new Page(9);
//		Page p10 = new Page(10);
//		
//		Chapter c1 = new Chapter();
//		Chapter c2 = new Chapter();
//		Chapter c3 = new Chapter();
//		c1.addPage(p1);
//		c1.addPage(p2);
//		c1.addPage(p3);
//		
//		c2.addPage(p4);
//		c2.addPage(p5);
//		c2.addPage(p6);
//		c2.addPage(p7);
//		
//		c3.addPage(p8);
//		c3.addPage(p9);
//		c3.addPage(p10);
//		
//		
//		Book b = new Book();
//		b.addChapter(c1);
//		b.addChapter(c2);
//		b.addChapter(c3);
//		
//		System.out.println("So chapter: " + b.getChapterCount());
//		System.out.println("So trang cua chapter 1: " + b.getBook().get(0).getPageCount());
//		System.out.println("So trang cua chapter 2: " + b.getBook().get(1).getPageCount());
//		System.out.println("So trang cua chapter 3: " + b.getBook().get(2).getPageCount());
		
		Book b = new Book();
		int nChapter = 3;
		Random rand = new Random();
		int stt = 1;
		
		for (int i = 0; i < nChapter; i++) {
			Chapter chapter = new Chapter(i+1);
			int nPage = 1 + rand.nextInt(5); // 1->5
			
			System.out.println("(" + nPage + ")");
			
			for (int j = 0; j < nPage; j++) {
				Page page = new Page(stt);
				stt++;
				chapter.addPage(page);
			}
			b.addChapter(chapter);
		}
		
		System.out.println("So chapter: " + b.getChapterCount());
		System.out.println("So trang cua chapter 1: " + b.getBook().get(0).getPageCount());
		System.out.println("So trang cua chapter 2: " + b.getBook().get(1).getPageCount());
		System.out.println("So trang cua chapter 3: " + b.getBook().get(2).getPageCount());
		System.out.println("Tong so trang: " + (stt-1));
		
	}

}
