/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package bai2;

/**
 *
 * @author hoang
 */
import java.io.FileWriter;
import java.io.IOException;

public class SinhvienUTT extends Sinhvien {
    private final String donVi;
    private final double luong;

    public SinhvienUTT(String maSv, String hoTen, String ngaySinh, String gioiTinh, double diemTb, String donVi, double luong) {
        super(maSv, hoTen, ngaySinh, gioiTinh, diemTb);
        this.donVi = donVi;
        this.luong = luong;
    }

    @Override
    public void hienThiThongTin() {
        super.hienThiThongTin();
        System.out.println("Đơn vị: " + donVi);
        System.out.println("Lương: " + luong);
    }

    public void luuDuLieu() {
        try {
            try (FileWriter writer = new FileWriter("svutt.dat")) {
                String line = maSv + "," + hoTen + "," + ngaySinh + "," + gioiTinh + "," + diemTb + "," + donVi + "," + luong + "\n";
                writer.write(line);
            }
        } catch (IOException e) {
        }
    }
}