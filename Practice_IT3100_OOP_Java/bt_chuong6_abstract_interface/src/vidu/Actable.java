package vidu;
import java.awt.Graphics;

public interface Actable {
	public abstract void draw(Graphics g);
	public abstract void moveTo(Graphics g, int x1, int y1);
	public abstract void erase(Graphics g);
	public abstract float calculateArea();
}
