package JavaUTT.Bai10;

import java.util.Scanner;

public class bai10 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Nhập số nguyên: ");
        int n = input.nextInt();

        int sum = 0;
        while (n != 0) {
            int digit = n % 10;
            sum += digit;
            n /= 10;
        }

        System.out.println("Tổng các chữ số của số nguyên là: " + sum);
    }
}
