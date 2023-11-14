/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package de5;

/**
 *
 * @author hoang
 */
import java.io.FileWriter;
import java.io.IOException;

public class SinhvienHTTT extends Sinhvien {
    private double hocPhi;

    public SinhvienHTTT(String maSv, String hoTen, String ngaySinh, String gioiTinh, double diemTb, double hocPhi) {
        super(maSv, hoTen, ngaySinh, gioiTinh, diemTb);
        this.hocPhi = hocPhi;
    }

    public double getHocPhi() {
        return hocPhi;
    }

    public void setHocPhi(double hocPhi) {
        this.hocPhi = hocPhi;
    }

    @Override
    public String toString() {
        return "SinhvienHTTT{" + "hocPhi=" + hocPhi + '}';
    }

    
}
