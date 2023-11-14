/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package de11;

import java.util.Scanner;

/**
 *
 * @author hoang
 */
public class MyDate {
    private int date;
    private int month;
    private int year;

    // Phương thức khởi tạo không tham số
    public MyDate() {
        // Khởi tạo giá trị mặc định
        this.date = 1;
        this.month = 1;
        this.year = 2023;
    }

    // Phương thức khởi tạo với tham số
    public MyDate(int date, int month, int year) {
        this.date = date;
        this.month = month;
        this.year = year;
    }

    // Phương thức nhập từ bàn phím
    public void inputDateFromConsole() {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Nhập ngày: ");
        this.date = scanner.nextInt();

        System.out.print("Nhập tháng: ");
        this.month = scanner.nextInt();

        System.out.print("Nhập năm: ");
        this.year = scanner.nextInt();

        scanner.close();
    }

    // Phương thức in ra màn hình
    public void printDate() {
        System.out.println("Ngày: " + this.date);
        System.out.println("Tháng: " + this.month);
        System.out.println("Năm: " + this.year);
    }
}
