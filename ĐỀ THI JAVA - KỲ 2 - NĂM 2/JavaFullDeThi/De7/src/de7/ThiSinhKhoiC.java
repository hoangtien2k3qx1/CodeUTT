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
public class ThiSinhKhoiC extends ThiSinh {
    private double diemVan;
    private double diemSu;
    private double diemDia;
    
    public ThiSinhKhoiC() {
        
    }
    
    public ThiSinhKhoiC(String hoTen, String ngaySinh, String diaChi, double diemVan, double diemSu, double diemDia) {
        super(hoTen, ngaySinh, diaChi);
        this.diemVan = diemVan;
        this.diemSu = diemSu;
        this.diemDia = diemDia;
    }
    
    @Override
    public void nhapThongTin() {
        // Hàm nhập thông tin từ b
        super.nhapThongTin();
        // Nhập thêm điểm văn, sử, địa
        Scanner scanner = new Scanner(System.in);
        
        // Hàm nhập thông tin từ bàn phím
        System.out.print("Nhập Điểm Văn ");
        double diemVan = scanner.nextDouble();
        
        System.out.print("Nhập Điểm Sử: ");
        double diemSu = scanner.nextDouble();
        
        System.out.print("Nhập Điểm Địa: ");
        double diemDia = scanner.nextDouble();
    }
    
    @Override
    public void inThongTin() {
        super.inThongTin();
        System.out.println("Điểm văn: " + diemVan);
        System.out.println("Điểm sử: " + diemSu);
        System.out.println("Điểm địa: " + diemDia);
    }

    public double getDiemVan() {
        return diemVan;
    }

    public void setDiemVan(double diemVan) {
        this.diemVan = diemVan;
    }

    public double getDiemSu() {
        return diemSu;
    }

    public void setDiemSu(double diemSu) {
        this.diemSu = diemSu;
    }

    public double getDiemDia() {
        return diemDia;
    }

    public void setDiemDia(double diemDia) {
        this.diemDia = diemDia;
    }

    public double tongDiem() {
        return diemVan + diemSu + diemDia;
    }
    
    
}