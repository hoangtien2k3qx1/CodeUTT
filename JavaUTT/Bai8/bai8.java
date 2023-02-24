package JavaUTT.Bai8;

import java.util.Scanner;

public class bai8 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Nhập n: ");
        int n = input.nextInt();

        double sum = 0;
        double factorial = 1;
        for (int i = 1; i <= n; i++) {
            factorial *= i;
            sum += (double) i / factorial;
        }

        System.out.println("Tổng S = " + sum);
    }
}
