/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package de13;

/**
 *
 * @author hoang
 */
public class KySu extends CanBo {
    private String maNgach;
    private String bacLuong;
    private double heSoLuong;
    
    public KySu(String hoTen, String ngaySinh, String diaChi, String gioiTinh, 
                String maNgach, String bacLuong, double heSoLuong) {
        super(hoTen, ngaySinh, diaChi, gioiTinh);
        this.maNgach = maNgach;
        this.bacLuong = bacLuong;
        this.heSoLuong = heSoLuong;
    }

    public String getMaNgach() {
        return maNgach;
    }

    public void setMaNgach(String maNgach) {
        this.maNgach = maNgach;
    }

    public String getBacLuong() {
        return bacLuong;
    }

    public void setBacLuong(String bacLuong) {
        this.bacLuong = bacLuong;
    }

    public double getHeSoLuong() {
        return heSoLuong;
    }

    public void setHeSoLuong(double heSoLuong) {
        this.heSoLuong = heSoLuong;
    }

    @Override
    public String toString() {
        String format = " %-18s | %-12s | %-12s |\n";
        return super.toString() + String.format(format, maNgach, bacLuong, heSoLuong);  
    }

}