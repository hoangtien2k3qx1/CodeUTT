/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package bai1;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author hoang
 */
public class Bai1 {

    private static ArrayList<NhanVien> docFileNhanVien(String filePath) throws IOException {
        ArrayList<NhanVien> danhSachNhanVien = new ArrayList<>();
        
        try (BufferedReader br = new BufferedReader(new FileReader(new File(filePath)))) {
            
            String line;
            while((line = br.readLine()) != null) {
                String[] data = line.split("\\$");
                
                String hoTen = data[0];
                String ngaySinh = data[1];
                String diaChi = data[2];
                String gioiTinh = data[3];
                String phongBan = data[4];
                double heSoLuong = Double.parseDouble(data[5]);
                int thamNien = Integer.parseInt(data[6]);
                double luongCoBan = Double.parseDouble(data[7]);
                
                NhanVien nhanVien = new NhanVien(hoTen, ngaySinh, diaChi, gioiTinh, phongBan, heSoLuong, thamNien, luongCoBan);
                danhSachNhanVien.add(nhanVien);
            }

        } catch(IOException e) {
            
        }

        return danhSachNhanVien;
    }
    
    
    private static void ghiFileNhanVien(ArrayList<NhanVien> danhSachNhanVien, String filePath) throws IOException {
        
        try (BufferedWriter bw = new BufferedWriter(new FileWriter(new File(filePath)))) {
            for(NhanVien nv : danhSachNhanVien) {
                String line = nv.getHoTen() + "$" +
                        nv.getNgaySinh() + "$" +
                        nv.getDiaChi() + "$" +
                        nv.getGioiTinh() + "$" +
                        nv.getPhongBan() + "$" +
                        nv.getHeSoLuong() + "$" +
                        nv.getThamNien() + "$" +
                        nv.getLuongCoBan() + "$";
                
                bw.write(line + System.lineSeparator());
            }
            
        } catch(IOException e) {
            throw new IOException();
        }
    }
    
    
    private static void saoChepFile(String tenFileGoc, String tenFileMoi) throws IOException {
        try (BufferedReader br = new BufferedReader(new FileReader(new File(tenFileGoc)));
             BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(new File(tenFileMoi)))) {
                String line;
                while ((line = br.readLine()) != null) {
                    bufferedWriter.write(line + System.lineSeparator());
                }
                
            System.out.println("Đã Sao Chép File " + tenFileGoc + " Sang File " + tenFileMoi + " Thành Công !!!");
        } catch (IOException e) {
            throw new IOException();
        }
    }
    
    
    public static void main(String[] args) throws IOException{
        
        // a
        ArrayList<NhanVien> danhSachNhanVien = docFileNhanVien("nhanvien.dat");

        
        // b
        // Hiển thị danh sách nhân viên trên màn hình console
        
        System.out.println("+----------------------+-----------------+-----------------------+-----------------+-----------------+-----------------+------------+-----------------+----------------------+");
        String format = "| %-20s | %-15s | %-21s | %-15s | %-15s | %-15s | %-10s | %-15s | %-20s |\n";
        System.out.format(format, "Họ Tên", "Ngày Sinh", "Địa Chỉ", "Giới Tính", "Phòng Ban", "Hệ Số Lương", "Thâm Niên", "Lương Cơ Bản", "Lương Thực Lĩnh");
        System.out.println("+----------------------+-----------------+-----------------------+-----------------+-----------------+-----------------+------------+-----------------+----------------------+");

        for (NhanVien nhanVien : danhSachNhanVien) {
            System.out.println(nhanVien.toString());
            System.out.println("+----------------------+-----------------+-----------------------+-----------------+-----------------+-----------------+------------+-----------------+----------------------+");
        }
        
        ghiFileNhanVien(danhSachNhanVien, "nhanvien.txt");
        
        
        // c
        System.out.println("Copy file dang file khac, ten file nhap tu ban phim!");
        Scanner scanner = new Scanner(System.in);
        System.out.print("\t+ Nhap ten file moi: ");
        String tenFileMoi = scanner.nextLine();
        
        saoChepFile("nhanvien.txt", tenFileMoi);
        
    }
    
}
