package JavaUTT.Bai9;

import java.util.Scanner;

public class bai9 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Nhập n: ");
        int n = input.nextInt();

        int f0 = 1, f1 = 1, fn = 0;
        for (int i = 2; i <= n; i++) {
            fn = f0 + f1;
            f0 = f1;
            f1 = fn;
        }

        System.out.println("Số Fibonacci thứ " + n + " là " + fn);
    }
}
