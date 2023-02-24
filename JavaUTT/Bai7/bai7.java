package JavaUTT.Bai7;

import java.util.Scanner;

public class bai7 {

//    int factorial = 1;
//      for (int i = 1; i <= n; i++) {
//        factorial *= i;
//    }

    public static int factorial(int n) {
        if (n == 0 || n == 1) { // Trường hợp cơ bản
            return 1;
        } else { // Trường hợp đệ qui
            return n * factorial(n-1);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Nhập số nguyên dương n: ");
        int n = sc.nextInt();

        System.out.println(n + "! = " + factorial(n));
    }
}
