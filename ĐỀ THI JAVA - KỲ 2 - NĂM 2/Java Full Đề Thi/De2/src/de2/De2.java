/*
    Câu 1 (2 điểm)
        a. (1 điểm) Hãy định nghĩa class Person với các thuộc tính: Họ tên, ngày 
        sinh, địa chỉ, giới tính và các phương thức khởi tạo, hiển thị thông tin.
        b. (1 điểm) Định nghĩa class NhanVien kế thừa từ Person, có thêm các thuộc 
        tính: phòng ban (nhận 1 trong các giá trị: Thiết bị, nhân sự, R&D, Kinh 
        doanh), hệ số lương, thâm niên, lương cơ bản và các
        phương thức khởi tạo, tính lương thực lĩnh, hiển thị thông tin cá nhân 
        Trong đó: lương thực lĩnh = Lương cơ bản * hệ số (1 + thâm niên/100)
    Câu 2 (6 điểm)
        a. (2 điểm) Thiết kế các phương thức cho phép nhập các thông tin nhân viên 
        như định nghĩa ở trên.
        b. (2 điểm) Khi người dùng Thêm nhân viên thì chương trình khởi tạo đối 
        tượng nhân viên với các giá trị thuộc tính lấy từ bàn phím người dùng 
        nhập và hiển thị thông tin lên màn hình console.
        c. (2 điểm) Khi người dùng chọn chức năng Lưu dữ liệu thì ghi toàn bộ 
        thông tin vào file nhanvien.dat, sinh viên tự bắt lỗi đầu vào và bổ sung 
        menu chức năng nếu cần thiết.
        

*/

package de2;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author hoangtien2k3
 */
public class De2 {
    
    private static void nhapThongTinNhanVien(Scanner scanner) {
        System.out.println("\n");
        System.out.println("+--------Thêm Thông Tin Nhân Viên-------+");
        System.out.print("\t+ Họ tên: ");
        String hoTen = scanner.nextLine();

        System.out.print("\t+ Ngày sinh: ");
        String ngaySinh = scanner.nextLine();

        System.out.print("\t+ Địa chỉ: ");
        String diaChi = scanner.nextLine();

        System.out.print("\t+ Giới tính: ");
        String gioiTinh = scanner.nextLine();

        System.out.print("\t+ Phòng Ban - (Lựa chọn: 1. Thiết bị, 2. nhân sự, 3. R&D, 4. Kinh doanh): ");
        int index = scanner.nextInt();
        String phongBan = "";
        switch(index) {
            case 1: 
                phongBan = "Thiết bị";
                break;
            case 2: 
                phongBan = "nhân sự";
                break;
            case 3: 
                phongBan = "R&D";
                break;
            case 4: 
                phongBan = "Kinh doanh";
                break;
        }

        System.out.print("\t+ Hệ Số Lương: ");
        double heSoLuong = scanner.nextDouble();

        System.out.print("\t+ Thâm Niên: ");
        int thamNien = scanner.nextInt();
        
        System.out.print("\t+ Lương Cơ Bản: ");
        double luongCoBan = scanner.nextDouble();

        NhanVien nhanVien = new NhanVien(hoTen, ngaySinh, diaChi, gioiTinh, phongBan, heSoLuong, thamNien, luongCoBan);
        danhSachNhanVien.add(nhanVien);

        System.out.println("+------Đã thêm nhân viên danh sách------+");
    }
    
    
    private static void hienThiDanhSachNhanVien() {
        System.out.println("\n");
        System.out.println("\t\t\t\t\t\t+------Hiển thị danh sách nhân viên-----+");
        if (danhSachNhanVien.isEmpty()) {
            System.out.println("Không có nhân viên nào trong danh sách!!!");
        } else {
            
            System.out.println("+----------------------+-----------------+----------------------+-----------------+----------------------+----------------------+-----------------+----------------------+----------------------+");
            String format = "| %-20s | %-15s | %-20s | %-15s | %-20s | %-20s | %-15s | %-20s | %-20s |\n";
            System.out.format(format, "Họ Tên", "Ngày Sinh", "Địa Chỉ", "Giới Tính", "Phòng Ban", "Hệ Số Lương", "Thâm Niên", "Lương Cơ Bản", "Lương Thực Lĩnh");
            System.out.println("+----------------------+-----------------+----------------------+-----------------+----------------------+----------------------+-----------------+----------------------+----------------------+");
            for(NhanVien nv : danhSachNhanVien) {
                System.out.print(nv.toString());
                System.out.print("+----------------------+-----------------+----------------------+-----------------+----------------------+----------------------+-----------------+----------------------+----------------------+");
            }
        }
    }
    
    private static void luuThongTinNhanVien(String filePath) {
        try (BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(filePath, true))){
            for (NhanVien nhanVien : danhSachNhanVien) {
                String line = nhanVien.getHoTen() + ", " +
                        nhanVien.getNgaySinh() + ", " +
                        nhanVien.getDiaChi() + ", " +
                        nhanVien.getGioiTinh() + ", " +
                        nhanVien.getPhongBan() + ", " +
                        nhanVien.getHeSoLuong() + ", " +
                        nhanVien.getThamNien() + ", " +
                        nhanVien.getLuongCoBan();

                bufferedWriter.write(line + System.lineSeparator());
            }
            
            System.out.println("\n");
            System.out.println("+     Đã Lưu SV vào File Thành Công     +");
            
        } catch (IOException e) {
            System.out.println("Lưu dữ liệu thất bại");
        }
    }
    
    
    private static ArrayList<NhanVien> danhSachNhanVien = new ArrayList<>();
    public static void main(String[] args) {
        
        Scanner scanner = new Scanner(System.in);
        
        int count = 0;
        while (true) {
            if (count != 0) System.out.println("\n\n");
            System.out.println("+---------------------------------------+");
            System.out.println("|                 Menu                  |");
            System.out.println("|---------------------------------------|");
            System.out.println("|   1.   Thêm nhân viên mới             |");
            System.out.println("|   2.   Hiển thị danh sách nhân viên.  |"); 
            System.out.println("|   3.   Lưu dữ liệu vào fiel.          |");
            System.out.println("|   4.   Thoát chương trình.            |");
            System.out.println("+---------------------------------------+");

            System.out.print("\t=> Lựa chọn: ");
            int luaChon = scanner.nextInt();
            scanner.nextLine();

            switch (luaChon) {
                case 1:
                    nhapThongTinNhanVien(scanner);
                    break;
                case 2:
                    hienThiDanhSachNhanVien();
                    break;
                case 3:
                    luuThongTinNhanVien("nhanvien.dat");
                    break;
                case 4: {
                    System.out.println("\n");
                    System.out.println("+   Bạn Đã Chọn Thoát Chương Trình.   +");
                    return;
                }
                default:
                    System.out.println("Lựa chọn không hợp lệ.");
                    break;
            }
            count++;
        }
                
        
    }
    
}
