/*
    Câu 1 (2 điểm)
        a. (1 điểm) Hãy định nghĩa class Person với các thuộc tính: Họ tên, ngày 
        sinh, địa chỉ, giới tính và các phương thức khởi tạo, hiển thị thông tin.
        b. (1 điểm) Định nghĩa class NhanVien kế thừa từ Person, có thêm các
        thuộc tính: phòng ban, hệ số lương, thâm niên, lương cơ bản và các 
        phương thức khởi tạo, tính lương thực lĩnh, hiển thị thông tin cá nhân
        Trong đó: lương thực lĩnh = Lương cơ bản * hệ số (1 + thâm niên/100)
    Câu 2 (6 điểm)
        a. (3 điểm) Hãy đọc file nhanvien.dat gồm danh sách các nhân viên với định 
        dạng lưu trữ như sau: mỗi nhân viên được lưu trên 1 dòng, mỗi thuộc tính 
        phân cách bởi ký tự “$”. Dữ liệu đọc được lưu dưới dạng một mảng các 
        đối tượng nhân viên (arraylist)
        b. (3 điểm) Hiển thị danh sách trên console, sinh viên tự tạo file 
        nhanvien.dat và bổ sung menu chức năng nếu cần thiết.

*/

package de3;

import java.io.*;
import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author hoang
 */
public class De3 {
    
    public static ArrayList<NhanVien> docFileNhanVien(String tenFile) {
        ArrayList<NhanVien> danhSachNhanVien = new ArrayList<>();

        try (BufferedReader br = new BufferedReader(new FileReader(new File(tenFile)))) {
            String line;
            while ((line = br.readLine()) != null) {
                String[] data = line.split("\\$");
                String hoTen = data[0];
                String ngaySinh = data[1];
                String diaChi = data[2];
                String gioiTinh = data[3];
                String phongBan = data[4];
                double heSoLuong = Double.parseDouble(data[5]);
                int thamNien = Integer.parseInt(data[6]);
                double luongCoBan = Double.parseDouble(data[7]);

                NhanVien nhanVien = new NhanVien(hoTen, ngaySinh, diaChi, gioiTinh, phongBan, heSoLuong, thamNien, luongCoBan);
                danhSachNhanVien.add(nhanVien);
            }
            System.out.println("\nĐọc file nhanvien.dat thành công !!!");
        } catch (IOException e) {
            System.out.println("Lỗi file rồi, kiểm tra lại");
        }

        return danhSachNhanVien;
    }
    
    private static void hienThiDanhSachNhanVien(ArrayList<NhanVien> danhSachNhanVien) {
        // Hiển thị danh sách nhân viên trên màn hình console
        System.out.println("+----------------------+-----------------+----------------------+-----------------+----------------------+----------------------+-----------------+----------------------+----------------------+");
        String format = "| %-20s | %-15s | %-20s | %-15s | %-20s | %-20s | %-15s | %-20s | %-20s |\n";
        System.out.format(format, "Họ Tên", "Ngày Sinh", "Địa Chỉ", "Giới Tính", "Phòng Ban", "Hệ Số Lương", "Thâm Niên", "Lương Cơ Bản", "Lương Thực Lĩnh");
        System.out.println("+----------------------+-----------------+----------------------+-----------------+----------------------+----------------------+-----------------+----------------------+----------------------+");
        for(NhanVien nv : danhSachNhanVien) {
            System.out.print(nv.toString());
            System.out.print("+----------------------+-----------------+----------------------+-----------------+----------------------+----------------------+-----------------+----------------------+----------------------+\n");
        }
    }
    
    public static void main(String[] args) {
        ArrayList<NhanVien> danhSachNhanVien = null;
        Scanner scanner = new Scanner(System.in);
        
        int count = 0;
        while (true) {
            if (count != 0) System.out.println("\n\n");
            System.out.println("+---------------------------------------+");
            System.out.println("|                 Menu                  |");
            System.out.println("|---------------------------------------|");
            System.out.println("|   1.   Đọc file nhanvien.dat          |");
            System.out.println("|   2.   Hiển thị danh sách nhân viên.  |"); 
            System.out.println("|   3.   Thoát Chương Trình.            |"); 
            System.out.println("+---------------------------------------+");

            System.out.print("\t=> Lựa chọn: ");
            int luaChon = scanner.nextInt();
            scanner.nextLine();

            switch (luaChon) {
                case 1:
                    danhSachNhanVien = docFileNhanVien("nhanvien.dat");
                    break;
                case 2:
                    hienThiDanhSachNhanVien(danhSachNhanVien);
                    break;
                case 3: 
                    System.out.println("Đã thoát chương trình !!!");
                    return;
                default: 
                    System.out.println("Lựa chọn không hợp lệ.");
                    break;
            }
            count++;
        }
    
    }

}
