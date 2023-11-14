/*
    Câu 1 (2 điểm)
        Định nghĩa class Number với các thuộc tính: value, min, max và các phương 
        thức khởi tạo, nhập và kiểm tra nguyên tố của giá trị value.
    Câu 2 (6 điểm)
        a. (2 điểm) Thiết kế phương thức cho phép nhập thông tin Number.
        b. (2 điểm) Nếu người dùng tạo mới đối tượng Number thì hãy khởi tạo đối 
        tượng Number (có kiểm tra điều kiện nhập min < value < max, bắt các lỗi 
        exception).
        c. (2 điểm) Nếu người dùng muốn Lưu trữ thì hãy lưu thông tin vào file gồm 
        value, min, max nếu value là số nguyên tố, sinh viên tự bắt lỗi đầu vào và 
        bổ sung menu chức năng nếu cần thiết.
 */

package de8;

import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

/**
 *
 * @author hoang
 */
public class De8 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        Number number = new Number();
        
        System.out.println("Nhập vào các giá trị của number: ");
        System.out.print("\t+ nhập value: ");
        int value = scanner.nextInt();
        System.out.print("\t+ nhập max: ");
        int max = scanner.nextInt();
        System.out.print("\t+ nhập min: ");
        int min = scanner.nextInt();
        
        number.inputNumber(value, max, min);
        number.saveToFile();
        
    }
}
