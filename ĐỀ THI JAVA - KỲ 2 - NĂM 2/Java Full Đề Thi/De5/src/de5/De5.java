/*
    Câu 1 (3 điểm)
        a. (1 điểm) Hãy định nghĩa class Sinhvien với các thuộc tính: mã sinh viên, 
        họ tên, ngày sinh, giới tính, điểm trung bình và các phương thức khởi tạo, 
        hiển thị thông tin.
        b. (1 điểm) Định nghĩa class SinhvienHTTT kế thừa từ sinhvien, có thêm 
        thuộc tính: học phí và phương thức khởi tạo, hiển thị thông tin.
        c. (1 điểm) Định nghĩa class SinhvienUTT kế thừa từ Sinhvien, có thêm 
        thuộc tính: đơn vị, lương và phương thức khởi tạo, hiển thị thông tin.
    Câu 2 (5 điểm)
        Hãy tạo các phương thức cho phép nhập dữ liệu sinh viên từ bàn phím. Sinh 
        viên UTT thì lưu dữ liệu vào file svutt.dat, sinh viên HTTT thì lưu dữ liệu vào file 
        svhttt.dat, sinh viên tự bắt lỗi đầu vào và bổ sung menu chức năng nếu cần thiết.

 */
package de5;

import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author hoang
 */
public class De5 {
    
    public static ArrayList<SinhvienHTTT> nhapSinhVienHTTT(Scanner scanner) {
        ArrayList<SinhvienHTTT> danhSachSinhVienHTTT = new ArrayList<>();
        
        System.out.print("Nhập mã sinh viên: ");
        String maSinhVien = scanner.nextLine();

        System.out.print("Nhập họ tên: ");
        String hoTen = scanner.nextLine();

        System.out.print("Nhập ngày sinh: ");
        String ngaySinh = scanner.nextLine();

        System.out.print("Nhập giới tính: ");
        String gioiTinh = scanner.nextLine();

        System.out.print("Nhập điểm trung bình: ");
        double diemTrungBinh = Double.parseDouble(scanner.nextLine());

        System.out.print("Nhập học phí: ");
        double hocPhi = Double.parseDouble(scanner.nextLine());
        
        danhSachSinhVienHTTT.add(new SinhvienHTTT(maSinhVien, hoTen, ngaySinh, gioiTinh, diemTrungBinh, hocPhi));
        return danhSachSinhVienHTTT;
    }

    public static ArrayList<SinhvienUTT> nhapSinhVienUTT(Scanner scanner) {        
        ArrayList<SinhvienUTT> danhSachSinhVienUTT = new ArrayList<>();
        
        System.out.print("Nhập mã sinh viên: ");
        String maSinhVien = scanner.nextLine();

        System.out.print("Nhập họ tên: ");
        String hoTen = scanner.nextLine();

        System.out.print("Nhập ngày sinh: ");
        String ngaySinh = scanner.nextLine();

        System.out.print("Nhập giới tính: ");
        String gioiTinh = scanner.nextLine();

        System.out.print("Nhập điểm trung bình: ");
        double diemTrungBinh = Double.parseDouble(scanner.nextLine());

        System.out.print("Nhập đơn vị: ");
        String donVi = scanner.nextLine();

        System.out.print("Nhập lương: ");
        double luong = Double.parseDouble(scanner.nextLine());

        danhSachSinhVienUTT.add(new SinhvienUTT(maSinhVien, hoTen, ngaySinh, gioiTinh, diemTrungBinh, donVi, luong));
        return danhSachSinhVienUTT;
    }
    
    public static void luuDuLieuSvUTT(ArrayList<SinhvienUTT> danhSachSinhVienUTT, String filePath) {
        try {
            FileWriter writer = new FileWriter(filePath, true);
            if (danhSachSinhVienUTT.isEmpty()) {
                System.out.println("Không có sinh viên UTT nào trong danh sách");
            } else {
                for(SinhvienUTT svutt : danhSachSinhVienUTT) {
                    writer.write(svutt.getMaSv() + "," + svutt.getHoTen() + "," + svutt.getNgaySinh() + "," + svutt.getGioiTinh() + "," + svutt.getDiemTb() + "," + svutt.getDonVi() + ", " + svutt.getLuong() + "\n");
                }
            }
            writer.close();
        } catch (IOException e) {
            System.out.println("Lỗi, không ghi được file sinhvienutt.dat");
        }
    }
    
    public static void luuDuLieuSvHTTT(ArrayList<SinhvienHTTT> danhSachSinhVienHTTT, String filePath) {
        try {
            FileWriter writer = new FileWriter(filePath, true);
            if (danhSachSinhVienHTTT.isEmpty()) {
                System.out.println("Không có sinh viên UTT nào trong danh sách");
            } else {
                for(SinhvienHTTT svhttt : danhSachSinhVienHTTT) {
                    writer.write(svhttt.getMaSv() + "," + svhttt.getHoTen() + "," + svhttt.getNgaySinh() + "," + svhttt.getGioiTinh() + "," + svhttt.getDiemTb() + "," + svhttt.getHocPhi() + "\n");
                }
            }
            writer.close();
        } catch (IOException e) {
            System.out.println("Lỗi, không ghi được file sinhvienhttt.dat");
        }
    }
 
    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);
        
        int count = 0;
        while (true) {
            if (count != 0) System.out.println("\n\n");
            System.out.println("+---------------------------------------+");
            System.out.println("|                 Menu                  |");
            System.out.println("|---------------------------------------|");
            System.out.println("|   1.   Nhập SVHTTT và lưu vào file    |");
            System.out.println("|   2.   Nhập SVUTT và lưu vào file     |"); 
            System.out.println("|   3.   Thoát Chương Trình.            |"); 
            System.out.println("+---------------------------------------+");

            System.out.print("\t=> Lựa chọn: ");
            int luaChon = scanner.nextInt();
            scanner.nextLine();

            switch (luaChon) {
                case 1: {
                    ArrayList<SinhvienHTTT> danhSachSinhVienHTTT = nhapSinhVienHTTT(scanner);
                    luuDuLieuSvHTTT(danhSachSinhVienHTTT, "svhttt.dat");
                    break;
                }
                case 2: {
                    ArrayList<SinhvienUTT> danhSachSinhVienUTT = nhapSinhVienUTT(scanner);
                    luuDuLieuSvUTT(danhSachSinhVienUTT, "svutt.dat");
                    break;
                }
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
