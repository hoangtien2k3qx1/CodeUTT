/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package bai2;

/**
 *
 * @author hoang
 */
public class Sinhvien {
    protected String maSv;
    protected String hoTen;
    protected String ngaySinh;
    protected String gioiTinh;
    protected double diemTb;

    public Sinhvien(String maSv, String hoTen, String ngaySinh, String gioiTinh, double diemTb) {
        this.maSv = maSv;
        this.hoTen = hoTen;
        this.ngaySinh = ngaySinh;
        this.gioiTinh = gioiTinh;
        this.diemTb = diemTb;
    }

    public void hienThiThongTin() {
        System.out.println("Mã sinh viên: " + maSv);
        System.out.println("Họ tên: " + hoTen);
        System.out.println("Ngày sinh: " + ngaySinh);
        System.out.println("Giới tính: " + gioiTinh);
        System.out.println("Điểm trung bình: " + diemTb);
    }

}
