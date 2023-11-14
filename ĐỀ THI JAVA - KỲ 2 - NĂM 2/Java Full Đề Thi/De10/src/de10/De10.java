/*
    Câu 1 (2 điểm)
        Hãy định nghĩa class Giangvien gồm các thuộc tính: họ tên, mã giảng viên, 
        địa chỉ, giới tính, khoa (nhận 1 trong các giá trị: ĐTVT, CNTT, HTTT, CNM, 
        CNPM) và các phương thức khởi tạo.
    Câu 2 (6 điểm)
        a. (2 điểm) Hãy thiết kế các phương thức cho phép nhập thông tin giảng 
        viên
        b. (3 điểm) Nếu người dùng Lưu trữ thì thực hiện khởi tạo đối tượng sách 
        với các thuộc tính lấy từ bàn phím do người dùng nhập, đồng thời lưu dữ 
        liệu vào file giangvien.dat
        c. (1 điểm) Nếu người dùng yêu cầu xóa file thì hãy backup dữ liệu sang file 
        khác trước khi xóa, sinh viên tự bắt lỗi đầu vào và bổ sung menu chức 
        năng nếu cần thiết.

 */

package de10;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

/**
 *
 * @author hoang
 */
public class De10 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int count = 0;
        while (true) {
            if (count != 0) System.out.println("\n\n");
            System.out.println("+---------------------------------------+");
            System.out.println("|                 Menu                  |");
            System.out.println("|---------------------------------------|");
            System.out.println("|   1.   Nhập giảng viên và lưu file    |");
            System.out.println("|   2.   Backup dữ liệu và xóa file     |"); 
            System.out.println("|   3.   Thoát chương trình             |"); 
            System.out.println("+---------------------------------------+");

            System.out.print("\t=> Lựa chọn: ");
            int luaChon = scanner.nextInt();
            scanner.nextLine();

        
            switch (luaChon) {
                case 1: {
                    // Thêm sách
                    System.out.println("Thêm giảng viên:");
                    System.out.print("\t+ Nhập Họ Tên: ");
                    String hoTen = scanner.nextLine();
                    System.out.print("\t+ Nhập Mã Giảng Viên: ");
                    String maGiangVien = scanner.nextLine();
                    System.out.print("\t+ Nhập Địa Chỉ: ");
                    String diaChi = scanner.nextLine();
                    System.out.print("\t+ Nhập Giới Tính: ");
                    String gioiTinh = scanner.nextLine();
                    System.out.print("\t+ Nhập Khoa (Chọn: 1. ĐTVT, 2. CNTT, 3. HTTT, 4. CNM, 5. CNPM): ");
                    int index = scanner.nextInt();
                    String khoa = null;
                    switch (index) {
                        case 1:
                            khoa = "ĐTVT";
                            break;
                        case 2:
                            khoa = "CNTT";
                            break;
                        case 3:
                            khoa = "HTTT";
                            break;
                        case 4:
                            khoa = "CNM";
                            break;
                        case 5:
                            khoa = "CNPM";
                            break;
                        default:
                            khoa = "";
                            break;
                    }

                    // Tạo đối tượng sách từ thông tin nhập từ bàn phím
                    Giangvien giangvien = new Giangvien(hoTen, maGiangVien, diaChi, gioiTinh, khoa);
                    // Lưu dữ liệu vào tệp books.dat
                    luuDuLieu(giangvien);
                    
                    break;
                }
                case 2: {
                    // Kiểm tra yêu cầu xóa file
                    System.out.print("Bạn có muốn xóa file books.dat? (y/n): ");
                    String confirm = scanner.nextLine();
                    if (confirm.equalsIgnoreCase("y")) {
                        System.out.println("Nhập đường dẫn thư mục và tên file backup: ");

                        System.out.print("\t+ Đường dẫn đến thư mục: ");
                        String backupFilePath = scanner.nextLine();

                        System.out.print("\t+ Tên file muốn backup dữ liệu: ");
                        String fileName = scanner.nextLine();

                        xoaFile("giangvien.dat", backupFilePath, fileName);
                    }

                    scanner.close();
                    break;
                }
                case 3:
                    System.out.println("\nĐã thoát chương trình!");
                    return;
            }
            count++;
        }
    }

    public static void luuDuLieu(Giangvien giangvien) {
        try {
            File file = new File("giangvien.dat");
            FileWriter fileWriter = new FileWriter(file, true);
            BufferedWriter bufferedWriter = new BufferedWriter(fileWriter);

            // Ghi thông tin sách vào tệp
            bufferedWriter.write(giangvien.getHoTen() + ";" + giangvien.getMaGiangVien()+ ";" + giangvien.getDiaChi() + ";" + giangvien.getGioiTinh() + ";" + giangvien.getKhoa());
            bufferedWriter.newLine();

            bufferedWriter.close();
            System.out.println("Đã lưu thông tin sách vào tệp books.dat.");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void xoaFile(String filePath, String backupFilePath, String fileName) {
        File file = new File(filePath);
        File backupFile = new File(backupFilePath + "\\" + fileName); // lưu đường dẫn đến thư mục cần backupFile

        // Kiểm tra nếu tệp tồn tại thì tiến hành xóa
        if (file.exists()) {
            try {
                // Tạo luồng đọc tệp
                FileReader fileReader = new FileReader(file);
                BufferedReader bufferedReader = new BufferedReader(fileReader);

                // Tạo luồng ghi tệp sao lưu
                FileWriter fileWriter = new FileWriter(backupFile);
                BufferedWriter bufferedWriter = new BufferedWriter(fileWriter);

                String line;
                // Đọc từng dòng trong tệp và sao lưu vào tệp backup
                while ((line = bufferedReader.readLine()) != null) {
                    bufferedWriter.write(line);
                    bufferedWriter.newLine();
                }

                // Đóng luồng
                bufferedReader.close();
                bufferedWriter.close();

                // Xóa tệp gốc
                file.delete();

                System.out.println("Đã xóa tệp " + filePath + " và sao lưu dữ liệu vào " + backupFilePath);
            } catch (IOException e) {
                e.printStackTrace();
            }
        } else {
            System.out.println("Tệp " + filePath + " không tồn tại.");
        }
    }
}
