/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package de8;

import java.io.FileWriter;
import java.io.IOException;

/**
 *
 * @author hoang
 */
public class Number {
    private int value;
    private int min;
    private int max;

    public Number() {
        this.value = 0;
        this.min = Integer.MIN_VALUE;
        this.max = Integer.MAX_VALUE;
    }

    public Number(int value, int min, int max) {
        this.value = value;
        this.min = min;
        this.max = max;
    }

    public void setValue(int value) {
        this.value = value;
    }

    public void setMin(int min) {
        this.min = min;
    }

    public void setMax(int max) {
        this.max = max;
    }

    public int getValue() {
        return value;
    }

    public int getMin() {
        return min;
    }

    public int getMax() {
        return max;
    }

    // kiểm tra số nguyên tố
    public boolean isPrime() {
        if (value < 2) {
            return false;
        }
        for (int i = 2; i <= Math.sqrt(value); i++) {
            if (value % i == 0) {
                return false;
            }
        }
        return true;
    }

    // nhập vào thông tin
    public void inputNumber(int value, int min, int max) throws IllegalArgumentException {
        if (value <= min || value >= max) {
            throw new IllegalArgumentException("Giá trị không hợp lệ!");
        }
        this.value = value;
        this.min = min;
        this.max = max;
    }

    public void saveToFile() {
        if (isPrime()) {
            try {
                FileWriter writer = new FileWriter("number.txt");
                writer.write("Value: " + value + ", Min: " + min + ", Max: " + max);
                writer.close();
                System.out.println("Thông tin đã được lưu vào file number.txt");
            } catch (IOException e) {
                System.out.println("Lỗi: Không thể lưu thông tin vào file!");
            }
        } else {
            System.out.println("Không thể lưu thông tin vì giá trị không phải là số nguyên tố.");
        }
    }
}