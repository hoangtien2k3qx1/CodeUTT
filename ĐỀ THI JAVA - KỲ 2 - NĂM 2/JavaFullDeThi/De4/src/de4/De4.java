/*
    Câu 1 (2 điểm)
        a. (1 điểm) Hãy định nghĩa class Person với các thuộc tính: Họ tên, ngày 
        sinh, địa chỉ, giới tính và các phương thức khởi tạo, hiển thị thông tin.
        b. (1 điểm) Định nghĩa class Student kế thừa từ Person, có thêm các thuộc 
        tính: mã sinh viên, email, điểm tổng kết và các phương thức khởi tạo, 
        hiển thị thông tin.
    Câu 2 (6 điểm)
        a. (3 điểm) Hãy đọc file sinhvien.dat gồm danh sách các Sinh viên với định 
        dạng lưu trữ như sau: mỗi Sinh viên được lưu trên 1 dòng, mỗi thuộc tính 
        phân cách bởi ký tự “$”. Dữ liệu đọc được lưu dưới dạng một mảng các 
        đối tượng Sinh viên (arraylist).
        b. (3 điểm) Hiển thị danh sách trên console, sinh viên tự tạo file 
        nhanvien.dat và bổ sung menu chức năng nếu cần thiết.
*/

package de4;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author hoang
 */
public class De4 {
    public static ArrayList<Student> docFileNhanVien(String tenFile) {
        ArrayList<Student> danhSachNhanVien = new ArrayList<>();

        try (BufferedReader br = new BufferedReader(new FileReader(new File(tenFile)))) {
            String line;
            while ((line = br.readLine()) != null) {
                String[] data = line.split("\\$");
                String hoTen = data[0];
                String ngaySinh = data[1];
                String diaChi = data[2];
                String gioiTinh = data[3];
                String maSinhVien = data[4];
                String email = data[5];
                double diemTongKet = Double.parseDouble(data[6]);

                Student student = new Student(hoTen, ngaySinh, diaChi, gioiTinh, maSinhVien, email, diemTongKet);
                danhSachNhanVien.add(student);
            }
            System.out.println("\nĐọc file sinhvien.dat thành công !!!");
        } catch (IOException e) {
            System.out.println("Lỗi file rồi, kiểm tra lại");
        }

        return danhSachNhanVien;
    }
    
    private static void hienThiDanhSachNhanVien(ArrayList<Student> danhSachSinhVien) {
        // Hiển thị danh sách nhân viên trên màn hình console
        System.out.println("+----------------------+-----------------+----------------------+-----------------+----------------------+---------------------------+----------------------+");
        String format = "| %-20s | %-15s | %-20s | %-15s | %-20s | %-25s | %-20s |\n";
        System.out.format(format, "Họ Tên", "Ngày Sinh", "Địa Chỉ", "Giới Tính", "Mã Sinh Viên", "Email", "Điểm Tổng Kết");
        System.out.println("+----------------------+-----------------+----------------------+-----------------+----------------------+---------------------------+----------------------+");
        for(Student student : danhSachSinhVien) {
            System.out.print(student.toString());
            System.out.print("+----------------------+-----------------+----------------------+-----------------+----------------------+---------------------------+----------------------+\n");
        }
    }
    
    public static void main(String[] args) {
        ArrayList<Student> danhSachSinhVien = null;
        Scanner scanner = new Scanner(System.in);
        
        int count = 0;
        while (true) {
            if (count != 0) System.out.println("\n\n");
            System.out.println("+---------------------------------------+");
            System.out.println("|                 Menu                  |");
            System.out.println("|---------------------------------------|");
            System.out.println("|   1.   Đọc file sinhvien.dat          |");
            System.out.println("|   2.   Hiển thị danh sách sinh vien.  |"); 
            System.out.println("|   3.   Thoát Chương Trình.            |"); 
            System.out.println("+---------------------------------------+");

            System.out.print("\t=> Lựa chọn: ");
            int luaChon = scanner.nextInt();
            scanner.nextLine();

            switch (luaChon) {
                case 1:
                    danhSachSinhVien = docFileNhanVien("sinhvien.dat");
                    break;
                case 2:
                    hienThiDanhSachNhanVien(danhSachSinhVien);
                    break;
                case 3: 
                    System.out.println("\nĐã thoát chương trình !!!");
                    return;
                default: 
                    System.out.println("\nLựa chọn không hợp lệ.");
                    break;
            }
            count++;
        }
    
    }
}
