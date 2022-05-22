package bt_chuong2;

import java.util.Random;
import java.util.Scanner;

public class BT {
    public static void main(String[] args) {
        // bai 1:
        System.out.println("Bai 1:");
        int[] arr = {1, 2, 3, 4, 5};
        int n = arr.length;
        
        for (int j = 0; j < n; j++) {
            // lay random vi tri
            Random generator = new Random();
            int i = generator.nextInt(n); // from 0 to n-1

            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        for (int item : arr) {
            System.out.print(item + " ");
        }

        // bai 2:
        System.out.println();
        System.out.println("Bai 2:");
        for (int i = 0; i < n-1; i++) {
            for (int j = i+1; j < n; j++) {
                if (arr[i] > arr[j]) {
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
        System.out.println();
        for (int item : arr) {
            System.out.print(item + " ");
        }
        System.out.println();

        // bai 3:
        System.out.println();
        System.out.println("Bai 3:");
        int h;
        Scanner sc = new Scanner(System.in);
        do {
            System.out.print("Nhap chieu cao h: ");
            h = sc.nextInt();
            if (h < 2 || h > 10) System.out.println("h ko thoa man dk. Moi nhap lai!!!");
        } while(h < 2 || h > 10);

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < 2*h-1; j++) {
                if (j >= h-i-1 && j < h+i) System.out.print("*");
                else System.out.print(" ");
            }
            System.out.println();
        }
        System.out.println();

        // bai 4:
        System.out.println();
        System.out.println("Bai 4:");
        int m;
        do {
            System.out.print("Nhap kich thuoc o vuong m: ");
            m = sc.nextInt();
            if (m < 3 || m > 8) System.out.println("h ko thoa man dk. Moi nhap lai!!!");
        } while(m < 3 || m > 8);

        int[][] two_dimension_arr = new int[m][m];
        int row = m-1, col = m-1;
        int value = 1;
        int d = 0; // cap cua duong cheo vd: m = 5; d=0 o 1, d=1 o 17, d=2 o 25
        int i;
        while (d <= n/2) {
            for (i = d; i <= col; i++) two_dimension_arr[d][i] = value++; // tien hang dau tien
            for (i = d+1; i <= row; i++) two_dimension_arr[i][col] = value++; // tien cot cuoi cung
            for (i = col-1; i >= d; i--) two_dimension_arr[row][i] = value++; // lui hang cuoi cung
            for (i = row-1; i > d; i--) two_dimension_arr[i][d] = value++; // lui cot dau tien
            d++;
            row--;
            col--;
        }

        // in ra ma tran
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < m; k++) {
                // System.out.print(two_dimension_arr[j][k] + "    ");
                System.out.printf("%5d", two_dimension_arr[j][k]);
            }
            System.out.println();
        }

    }
}