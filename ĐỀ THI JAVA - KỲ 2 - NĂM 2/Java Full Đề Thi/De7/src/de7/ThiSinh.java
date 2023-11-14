/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package de7;

import java.util.Scanner;

/**
 *
 * @author hoang
 */
public class ThiSinh {
    private String hoTen;
    private String ngaySinh;
    private String diaChi;
    
    public ThiSinh() {
        
    }
    
    public ThiSinh(String hoTen, String ngaySinh, String diaChi) {
        this.hoTen = hoTen;
        this.ngaySinh = ngaySinh;
        this.diaChi = diaChi;
    }
    
    public void nhapThongTin() {
        Scanner scanner = new Scanner(System.in);
        
        // Hàm nhập thông tin từ bàn phím
        System.out.print("Nhập Họ Tên: ");
        String hoTen = scanner.nextLine();
        
        System.out.print("Nhập Ngày Sinh: ");
        String ngaySinh = scanner.nextLine();
        
        System.out.print("Nhập Địa Chỉ: ");
        String diaChi = scanner.nextLine();
    }
    
    public void inThongTin() {
        System.out.println("Họ tên: " + hoTen);
        System.out.println("Ngày sinh: " + ngaySinh);
        System.out.println("Địa chỉ: " + diaChi);
    }

    public String getHoTen() {
        return hoTen;
    }

    public void setHoTen(String hoTen) {
        this.hoTen = hoTen;
    }

    public String getNgaySinh() {
        return ngaySinh;
    }

    public void setNgaySinh(String ngaySinh) {
        this.ngaySinh = ngaySinh;
    }

    public String getDiaChi() {
        return diaChi;
    }

    public void setDiaChi(String diaChi) {
        this.diaChi = diaChi;
    }
    
    
    
}
