/*
    Câu 1 (3 điểm)
        a) (1 điểm) Hãy định nghĩa class Thí sinh với các thuộc tính: họ tên, ngày 
        sinh, địa chỉ và các phương thức khởi tạo, nhập và in thông tin
        b) (1 điểm) Định nghĩa class Thí sinh khối A kế thừa từ Thí sinh, có thêm 
        các thuộc tính: điểm toán, lý, hóa và các phương thức khởi tạo, nhập, in 
        thông tin
        c) (1 điểm) Định nghĩa class Thí sinh khối C kế thừa từ Thí sinh, có thêm 
        các thuộc tính: điểm văn, sử, địa và các phương thức khởi tạo, nhập, in 
        thông tin.
    Câu 2 (5 điểm)
        a) (2 điểm) Thiết kế các phương thức thực hiện nhập danh sách n thí sinh của 
        cả 2 khối A, C từ bàn phím.
        b) (1.5 điểm) In danh sách thí sinh trúng tuyển (tổng điểm > 20) ra màn hình.
        c) (1.5 điểm) Ghi toàn bộ thông tin thí sinh của 3 khối vào file thisinh.txt, sinh 
        viên tự bắt lỗi đầu vào và bổ sung menu chức năng nếu cần thiết.

 */

package de7;

import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author hoang
 */
public class De7 {
    
    public static void luuThiSinhVaoFile(ArrayList<ThiSinhKhoiA> danhSachThiSinhKhoiA, ArrayList<ThiSinhKhoiC> danhSachThiSinhKhoiC, String filePath) {
        // Mã code đã có từ trước
        
        // Ghi toàn bộ thông tin thí sinh của 3 khối vào file thisinh.txt
        try {
            FileWriter fileWriter = new FileWriter(filePath);
            
            // Ghi danh sách thí sinh khối A
            fileWriter.write("Danh sách thí sinh khối A:\n");
            for (ThiSinhKhoiA thiSinhKhoiA : danhSachThiSinhKhoiA) {
                fileWriter.write("Họ tên: " + thiSinhKhoiA.getHoTen() + "\n");
                fileWriter.write("Ngày sinh: " + thiSinhKhoiA.getNgaySinh() + "\n");
                fileWriter.write("Địa chỉ: " + thiSinhKhoiA.getDiaChi() + "\n");
                fileWriter.write("Điểm toán: " + thiSinhKhoiA.getDiemToan() + "\n");
                fileWriter.write("Điểm lý: " + thiSinhKhoiA.getDiemLy() + "\n");
                fileWriter.write("Điểm hóa: " + thiSinhKhoiA.getDiemHoa() + "\n");
                fileWriter.write("--------------------\n");
            }
            
            // Ghi danh sách thí sinh khối C
            fileWriter.write("Danh sách thí sinh khối C:\n");
            for (ThiSinhKhoiC thiSinhKhoiC : danhSachThiSinhKhoiC) {
                fileWriter.write("Họ tên: " + thiSinhKhoiC.getHoTen() + "\n");
                fileWriter.write("Ngày sinh: " + thiSinhKhoiC.getNgaySinh() + "\n");
                fileWriter.write("Địa chỉ: " + thiSinhKhoiC.getDiaChi() + "\n");
                fileWriter.write("Điểm văn: " + thiSinhKhoiC.getDiemVan() + "\n");
                fileWriter.write("Điểm sử: " + thiSinhKhoiC.getDiemSu() + "\n");
                fileWriter.write("Điểm địa: " + thiSinhKhoiC.getDiemDia() + "\n");
                fileWriter.write("--------------------\n");
            }
            
            fileWriter.close();
            System.out.println("Đã ghi thông tin thí sinh vào file thisinh.txt");
        } catch (IOException e) {
            System.out.println("Lỗi khi ghi file");
        }
    }
    
    
    public static void inDanhSachThiSinhTrungTuyenLonHon20(ArrayList<ThiSinhKhoiA> danhSachThiSinhKhoiA, ArrayList<ThiSinhKhoiC> danhSachThiSinhKhoiC) {
        System.out.println("Danh sách thí sinh trúng tuyển:");
        for (ThiSinhKhoiA thiSinhKhoiA : danhSachThiSinhKhoiA) {
            if (thiSinhKhoiA.tongDiem() > 20) {
                thiSinhKhoiA.inThongTin();
            }
        }

        for (ThiSinhKhoiC thiSinhKhoiC : danhSachThiSinhKhoiC) {
            if (thiSinhKhoiC.tongDiem() > 20) {
                thiSinhKhoiC.inThongTin();
            }
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
            System.out.println("|   1.   Nhập thí sinh khối A.          |");
            System.out.println("|   2.   Nhập thí sinh khối C.          |"); 
            System.out.println("|   3.   DS thí sinh trúng tuyển.       |"); 
            System.out.println("|   4.   Ghi thông tin vào file.        |"); 
            System.out.println("+---------------------------------------+");

            System.out.print("\t=> Lựa chọn: ");
            int luaChon = scanner.nextInt();
            scanner.nextLine();
                   
            
            ArrayList<ThiSinhKhoiA> danhSachThiSinhKhoiA = new ArrayList<>();
            ArrayList<ThiSinhKhoiC> danhSachThiSinhKhoiC = new ArrayList<>();
            
            switch (luaChon) {
                case 1: {
                    // Nhập danh sách thí sinh khối A
                    System.out.print("Nhập số lượng thí sinh khối A: ");
                    int nA = scanner.nextInt();
                    
                    for (int i = 0; i < nA; i++) {
                        System.out.println("Nhập thông tin thí sinh khối A thứ " + (i + 1) + ":");
                        ThiSinhKhoiA thiSinhKhoiA = new ThiSinhKhoiA();
                        thiSinhKhoiA.nhapThongTin();
                        danhSachThiSinhKhoiA.add(thiSinhKhoiA);
                    }
                    break;
                }
                case 2: {
                    // Nhập danh sách thí sinh khối C
                    System.out.print("Nhập số lượng thí sinh khối C: ");
                    int nC = scanner.nextInt();
                    
                    for (int i = 0; i < nC; i++) {
                        System.out.println("Nhập thông tin thí sinh khối C thứ " + (i + 1) + ":");
                        ThiSinhKhoiC thiSinhKhoiC = new ThiSinhKhoiC();
                        thiSinhKhoiC.nhapThongTin();
                        danhSachThiSinhKhoiC.add(thiSinhKhoiC);
                    }
                    break;
                }
                case 3:
                    inDanhSachThiSinhTrungTuyenLonHon20(danhSachThiSinhKhoiA, danhSachThiSinhKhoiC);
                    return;
                case 4:
                    luuThiSinhVaoFile(danhSachThiSinhKhoiA, danhSachThiSinhKhoiC, "thisinh.txt");
                    break;
                default: 
                    System.out.println("\nLựa chọn không hợp lệ.");
                    break;
            }
            count++;
        }
  
    }
}
