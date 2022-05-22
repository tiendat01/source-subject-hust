package bai2;

import java.awt.Graphics;

interface CanMove {
	public abstract void run(); 
	public abstract void back(Graphics g, int x, int y);
	public abstract void getVelocity(Graphics g);
}
