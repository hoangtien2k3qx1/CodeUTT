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

public class SinhvienUTT extends Sinhvien {
    private String donVi;
    private double luong;

    public SinhvienUTT(String maSv, String hoTen, String ngaySinh, String gioiTinh, double diemTb, String donVi, double luong) {
        super(maSv, hoTen, ngaySinh, gioiTinh, diemTb);
        this.donVi = donVi;
        this.luong = luong;
    }

    public String getDonVi() {
        return donVi;
    }

    public void setDonVi(String donVi) {
        this.donVi = donVi;
    }

    public double getLuong() {
        return luong;
    }

    public void setLuong(double luong) {
        this.luong = luong;
    }

    @Override
    public String toString() {
        return "SinhvienUTT{" + "donVi=" + donVi + ", luong=" + luong + '}';
    }

    
    
}