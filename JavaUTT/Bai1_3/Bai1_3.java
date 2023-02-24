package JavaUTT.Bai1_3;

import java.util.Scanner;

public class Bai1_3 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Nhập số thứ nhất: ");
        double firstNumber = scanner.nextDouble();

        System.out.print("Nhập số thứ hai: ");
        double secondNumber = scanner.nextDouble();

        double sum = firstNumber + secondNumber;
        double difference = firstNumber - secondNumber;
        double product = firstNumber * secondNumber;
        double quotient = firstNumber / secondNumber;

        System.out.println("Tổng của hai số là: " + sum);
        System.out.println("Hiệu của hai số là: " + difference);
        System.out.println("Tích của hai số là: " + product);
        System.out.println("Thương của hai số là: " + quotient);
    }
}
