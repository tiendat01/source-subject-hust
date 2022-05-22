public class App {
    public static void main(String[] args) {
        short l, m = 5;
        int n = 6;
        // l = (short)n + m; // loi do toan tu + lam xuat hien numeric promotions
        l = (short)(n+m);
        System.out.print(l);

    }
}
