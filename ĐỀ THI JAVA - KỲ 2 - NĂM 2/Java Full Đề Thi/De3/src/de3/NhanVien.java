/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package de3;

/**
 *
 * @author hoangtien2k3
 */
public class NhanVien extends Person {
    private String phongBan;
    private double heSoLuong;
    private int thamNien;
    private double luongCoBan;

    public NhanVien(String hoTen, String ngaySinh, String diaChi, String gioiTinh, String phongBan, double heSoLuong, int thamNien, double luongCoBan) {
        super(hoTen, ngaySinh, diaChi, gioiTinh);
        this.phongBan = phongBan;
        this.heSoLuong = heSoLuong;
        this.thamNien = thamNien;
        this.luongCoBan = luongCoBan;
    }

    public String getPhongBan() {
        return phongBan;
    }

    public void setPhongBan(String phongBan) {
        this.phongBan = phongBan;
    }

    public double getHeSoLuong() {
        return heSoLuong;
    }

    public void setHeSoLuong(double heSoLuong) {
        this.heSoLuong = heSoLuong;
    }

    public int getThamNien() {
        return thamNien;
    }

    public void setThamNien(int thamNien) {
        this.thamNien = thamNien;
    }

    public double getLuongCoBan() {
        return luongCoBan;
    }

    public void setLuongCoBan(double luongCoBan) {
        this.luongCoBan = luongCoBan;
    }
    
    private double tinhLuongThucLinh() {
        return (double)(luongCoBan * heSoLuong * (1 + thamNien/100));
    }

    @Override
    public String toString() {
        String format = " %-20s | %-20s | %-15s | %-20s | %-20s |\n";
        return super.toString() + String.format(format, phongBan, heSoLuong, thamNien, luongCoBan, tinhLuongThucLinh());
    }

}
