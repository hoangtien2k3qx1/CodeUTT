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

public class SinhvienHTTT extends Sinhvien {
    private final double hocPhi;

    public SinhvienHTTT(String maSv, String hoTen, String ngaySinh, String gioiTinh, double diemTb, double hocPhi) {
        super(maSv, hoTen, ngaySinh, gioiTinh, diemTb);
        this.hocPhi = hocPhi;
    }

    @Override
    public void hienThiThongTin() {
        super.hienThiThongTin();
        System.out.println("Học phí: " + hocPhi);
    }

    public void luuDuLieu() {
        try {
            try (FileWriter writer = new FileWriter("svhttt.dat")) {
                String line = maSv + "," + hoTen + "," + ngaySinh + "," + gioiTinh + "," + diemTb + "," + hocPhi + "\n";
                writer.write(line);
            }
        } catch (IOException e) {
        }
    }
}