/*
    Câu 1 (2 điểm)
        Hãy định nghĩa class Book gồm các thuộc tính id, authors, title, category 
        (nhận 1 trong các giá trị: tạp chí, KHXH, KHTN, luận văn) và các phương thức khởi 
        tạo, các getters/setters.
    Câu 2 (6 điểm)
        a. (2 điểm) Hãy thiết kế phương thức cho phép nhập thông tin để thêm sách
        b. (3 điểm) Nếu người dùng Thêm sách thì thực hiện khởi tạo đối tượng 
        sách với các thuộc tính lấy từ bàn phím do người dùng nhập, đồng thời 
        lưu dữ liệu vào file books.dat
        c. (1 điểm) Nếu người dùng yêu cầu xóa file thì hãy backup dữ liệu sang file 
        khác trước khi xóa, sinh viên tự bắt lỗi đầu vào và bổ sung menu chức 
        năng nếu cần thiết.
 */

package de9;

/**
 *
 * @author hoangtien2k3
 */

import java.io.*;
import java.util.Scanner;

public class De9 {
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int count = 0;
        while (true) {
            if (count != 0) System.out.println("\n\n");
            System.out.println("+---------------------------------------+");
            System.out.println("|                 Menu                  |");
            System.out.println("|---------------------------------------|");
            System.out.println("|   1.   Nhập Sách và lưu file          |");
            System.out.println("|   2.   Backup dữ liệu và xóa file     |"); 
            System.out.println("|   3.   Thoát chương trình             |"); 
            System.out.println("+---------------------------------------+");

            System.out.print("\t=> Lựa chọn: ");
            int luaChon = scanner.nextInt();
            scanner.nextLine();
        
            switch (luaChon) {
                case 1: {
                    // Thêm sách
                    System.out.println("Thêm sách:");
                    System.out.print("\t+ Nhập ID sách: ");
                    int id = scanner.nextInt();
                    scanner.nextLine(); // Đọc dòng trống sau khi nhập số
                    System.out.print("\t+ Nhập tác giả: ");
                    String authors = scanner.nextLine();
                    System.out.print("\t+ Nhập tiêu đề: ");
                    String title = scanner.nextLine();
                    System.out.print("\t+ Nhập thể loại (Chọn: 1. tạp chí, 2. KHXH, 3. KHTN, 4. luận văn): ");
                    int index = scanner.nextInt();
                    String category = null;
                    switch (index) {
                        case 1:
                            category = "tạp chí";
                            break;
                        case 2:
                            category = "KHXH";
                            break;
                        case 3:
                            category = "KHTN";
                            break;
                        case 4:
                            category = "luận văn";
                            break;
                        default:
                            category = "";
                            break;
                    }

                    // Tạo đối tượng sách từ thông tin nhập từ bàn phím
                    Book book = new Book(id, authors, title, category);
                    // Lưu dữ liệu vào tệp books.dat
                    luuDuLieu(book);
                    
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

                        xoaFile("books.dat", backupFilePath, fileName);
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

    public static void luuDuLieu(Book book) {
        try {
            File file = new File("books.dat");
            FileWriter fileWriter = new FileWriter(file, true);
            BufferedWriter bufferedWriter = new BufferedWriter(fileWriter);

            // Ghi thông tin sách vào tệp
            bufferedWriter.write(book.getId() + ";" + book.getAuthors() + ";" + book.getTitle() + ";" + book.getCategory());
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
