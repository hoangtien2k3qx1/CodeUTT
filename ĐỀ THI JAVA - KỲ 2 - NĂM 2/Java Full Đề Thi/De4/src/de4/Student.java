/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package de4;

/**
 *
 * @author hoang
 */
public class Student extends Person{
    private String maSinhVien;
    private String email;
    private double diemTongKet;

    public Student(String hoTen, String ngaySinh, String diaChi, String gioiTinh, String maSinhVien, String email, double diemTongKet) {
        super(hoTen, ngaySinh, diaChi, gioiTinh);
        this.maSinhVien = maSinhVien;
        this.email = email;
        this.diemTongKet = diemTongKet;
    }

    public String getMaSinhVien() {
        return maSinhVien;
    }

    public void setMaSinhVien(String maSinhVien) {
        this.maSinhVien = maSinhVien;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public double getDiemTongKet() {
        return diemTongKet;
    }

    public void setDiemTongKet(double diemTongKet) {
        this.diemTongKet = diemTongKet;
    }

    @Override
    public String toString() {
        String format = " %-20s | %-25s | %-20s |\n";
        return super.toString() + String.format(format, maSinhVien, email, diemTongKet);
    }

}
