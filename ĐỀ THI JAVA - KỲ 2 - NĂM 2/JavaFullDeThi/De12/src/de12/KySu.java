/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package de12;

/**
 *
 * @author hoang
 */
public class KySu extends CanBo {
    private String maNgach;
    private String bacLuong;
    private String heSoLuong;
    
    public KySu(String hoTen, String ngaySinh, String diaChi, String gioiTinh, 
                String maNgach, String bacLuong, String heSoLuong) {
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

    public String getHeSoLuong() {
        return heSoLuong;
    }

    public void setHeSoLuong(String heSoLuong) {
        this.heSoLuong = heSoLuong;
    }

    @Override
    public String toString() {
        String format = " %-18s | %-12s | %-12s |\n";
        return super.toString() + String.format(format, maNgach, bacLuong, heSoLuong);  
    }

}