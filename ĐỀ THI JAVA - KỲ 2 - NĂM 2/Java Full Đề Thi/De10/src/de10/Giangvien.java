/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package de10;

/**
 *
 * @author hoang
 */
public class Giangvien {
    private String hoTen;
    private String maGiangVien;
    private String diaChi;
    private String gioiTinh;
    private String khoa;

    public Giangvien(String hoTen, String maGiangVien, String diaChi, String gioiTinh, String khoa) {
        this.hoTen = hoTen;
        this.maGiangVien = maGiangVien;
        this.diaChi = diaChi;
        this.gioiTinh = gioiTinh;
        this.khoa = khoa;
    }

    public String getHoTen() {
        return hoTen;
    }

    public void setHoTen(String hoTen) {
        this.hoTen = hoTen;
    }

    public String getMaGiangVien() {
        return maGiangVien;
    }

    public void setMaGiangVien(String maGiangVien) {
        this.maGiangVien = maGiangVien;
    }

    public String getDiaChi() {
        return diaChi;
    }

    public void setDiaChi(String diaChi) {
        this.diaChi = diaChi;
    }

    public String getGioiTinh() {
        return gioiTinh;
    }

    public void setGioiTinh(String gioiTinh) {
        this.gioiTinh = gioiTinh;
    }

    public String getKhoa() {
        return khoa;
    }

    public void setKhoa(String khoa) {
        this.khoa = khoa;
    }

    @Override
    public String toString() {
        return "Giangvien{" + "hoTen=" + hoTen + ", maGiangVien=" + maGiangVien + ", diaChi=" + diaChi + ", gioiTinh=" + gioiTinh + ", khoa=" + khoa + '}';
    }

}