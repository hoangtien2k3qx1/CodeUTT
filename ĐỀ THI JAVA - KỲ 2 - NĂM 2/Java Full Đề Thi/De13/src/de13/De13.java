/*
    Câu 1 (2 điểm)
        a. (1 điểm) Hãy định nghĩa class CanBo với các thuộc tính: Họ tên, ngày 
        sinh, địa chỉ, giới tính và các phương thức khởi tạo, hiển thị thông tin.
        b. (1 điểm) Định nghĩa class KySu kế thừa từ CanBo, có thêm các thuộc tính: 
        mã ngạch, bậc lương, hệ số lương và các phương thức khởi tạo, hiển thị 
        thông tin.
    Câu 2 (6 điểm)
        a. (3 điểm) Hãy đọc file kysu.dat gồm danh sách các Kỹ sư với định dạng lưu 
        trữ như sau: mỗi Kỹ sư được lưu trên 1 dòng, mỗi thuộc tính phân cách bởi 
        ký tự “#”. Dữ liệu đọc được lưu dưới dạng một mảng các đối tượng KySu
        (arraylist).
        b. (3 điểm) Hiển thị danh sách trên trong một table (hiển thị trên console chỉ 
        được 1.5 điểm)
 */
package de13;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;

/**
 *
 * @author hoang
 */
public class De13 {

    public static ArrayList<KySu> getListKySuFromFile(String fileName) throws IOException {
        ArrayList<KySu> listKySu = new ArrayList<>();
        FileReader fileReader = new FileReader(fileName);
        try (BufferedReader bufferedReader = new BufferedReader(fileReader)) {
            String line;
            while ((line = bufferedReader.readLine()) != null) {
                String[] data = line.split("#");
                String hoTen = data[0];
                String ngaySinh = data[1];
                String diaChi = data[2];
                String gioiTinh = data[3];
                String maNgach = data[4];
                String bacLuong = data[5];
                double heSoLuong = Double.parseDouble(data[6]);
                
                KySu ks = new KySu(hoTen, ngaySinh, diaChi, gioiTinh, maNgach, bacLuong, heSoLuong);
                listKySu.add(ks);
            }
        }
        return listKySu;
    }
    
    private static void xuatDanhSachKySu(ArrayList<KySu> listKS) {
        System.out.println("+----------------------+--------------+---------------------------+------------+--------------------+--------------+--------------+");
        String format = "| %-20s | %-12s | %-25s | %-10s | %-18s | %-12s | %-12s |\n";
        System.out.format(format, "Họ Tên", "Ngày Sinh", "Địa Chỉ", "Giới Tính", "Mã Ngạch", "Bậc Lương", "Hệ Số Lương");
        System.out.println("+----------------------+--------------+---------------------------+------------+--------------------+--------------+--------------+");
        for(KySu hs : listKS) {
            System.out.print(hs.toString());
            System.out.println("+----------------------+--------------+---------------------------+------------+--------------------+--------------+--------------+");;
        }    
    }
    
    public static void main(String[] args) {
        try {
            xuatDanhSachKySu(getListKySuFromFile("kysu.dat"));
        } catch (IOException e) {
            System.out.println("Lỗi, không đọc được file!");
        }
    }
}
