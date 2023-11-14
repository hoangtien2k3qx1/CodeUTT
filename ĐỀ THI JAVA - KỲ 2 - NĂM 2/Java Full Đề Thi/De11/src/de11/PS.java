/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package de11;

/**
 *
 * @author hoang
 */
public class PS {
    private int tu;
    private int mau;

    // Phương thức khởi tạo có tham số
    public PS(int tu, int mau) {
        this.tu = tu;
        this.mau = mau;
    }

    // Phương thức khởi tạo không tham số
    public PS() {
        this.tu = 0;
        this.mau = 1;
    }

    // Phương thức cộng hai phân số
    public PS cong(PS ps) {
        int newTu = this.tu * ps.mau + this.mau * ps.tu;
        int newMau = this.mau * ps.mau;
        return new PS(newTu, newMau);
    }

    // Phương thức trừ hai phân số
    public PS tru(PS ps) {
        int newTu = this.tu * ps.mau - this.mau * ps.tu;
        int newMau = this.mau * ps.mau;
        return new PS(newTu, newMau);
    }

    // Phương thức nhân hai phân số
    public PS nhan(PS ps) {
        int newTu = this.tu * ps.tu;
        int newMau = this.mau * ps.mau;
        return new PS(newTu, newMau);
    }

    // Phương thức chia hai phân số
    public PS chia(PS ps) {
        int newTu = this.tu * ps.mau;
        int newMau = this.mau * ps.tu;
        return new PS(newTu, newMau);
    }

    public int getTu() {
        return tu;
    }

    public void setTu(int tu) {
        this.tu = tu;
    }

    public int getMau() {
        return mau;
    }

    public void setMau(int mau) {
        this.mau = mau;
    }
    
    
}