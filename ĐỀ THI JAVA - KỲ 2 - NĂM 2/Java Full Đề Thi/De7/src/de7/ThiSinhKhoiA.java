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
public class ThiSinhKhoiA extends ThiSinh {
    private double diemToan;
    private double diemLy;
    private double diemHoa;
    
    public ThiSinhKhoiA() {
        
    }
    
    public ThiSinhKhoiA(String hoTen, String ngaySinh, String diaChi, double diemToan, double diemLy, double diemHoa) {
        super(hoTen, ngaySinh, diaChi);
        this.diemToan = diemToan;
        this.diemLy = diemLy;
        this.diemHoa = diemHoa;
    }
    
    @Override
    public void nhapThongTin() {
        // Hàm nhập thông tin từ bàn phím
        super.nhapThongTin();
        // Nhập thêm điểm toán, lý, hóa
        
        Scanner scanner = new Scanner(System.in);
        
        // Hàm nhập thông tin từ bàn phím
        System.out.print("Nhập Điểm Toán ");
        double diemToan = scanner.nextDouble();
        
        System.out.print("Nhập Điểm Lý: ");
        double diemLy = scanner.nextDouble();
        
        System.out.print("Nhập Điểm Hóa: ");
        double diemHoa = scanner.nextDouble();
    }
    
    @Override
    public void inThongTin() {
        super.inThongTin();
        System.out.println("Điểm toán: " + diemToan);
        System.out.println("Điểm lý: " + diemLy);
        System.out.println("Điểm hóa: " + diemHoa);
    }

    public double getDiemToan() {
        return diemToan;
    }

    public void setDiemToan(double diemToan) {
        this.diemToan = diemToan;
    }

    public double getDiemLy() {
        return diemLy;
    }

    public void setDiemLy(double diemLy) {
        this.diemLy = diemLy;
    }

    public double getDiemHoa() {
        return diemHoa;
    }

    public void setDiemHoa(double diemHoa) {
        this.diemHoa = diemHoa;
    }

    public double tongDiem() {
        return diemToan + diemLy + diemHoa;
    }
    
    
}

