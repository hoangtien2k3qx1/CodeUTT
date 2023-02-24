package JavaUTT.Bai14;

import java.util.Scanner;

public class bai14 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        // Nhập kích thước của ma trận
        System.out.print("Nhập số dòng của ma trận: ");
        int n = input.nextInt();
        System.out.print("Nhập số cột của ma trận: ");
        int m = input.nextInt();

        // Khởi tạo ma trận A
        int[][] A = new int[n][m];

        // Nhập giá trị cho ma trận A
        System.out.println("Nhập giá trị cho ma trận A:");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                System.out.printf("A[%d][%d] = ", i, j);
                A[i][j] = input.nextInt();
            }
        }

        // Tìm phần tử lớn nhất của ma trận và chỉ số của số đó
        int max = A[0][0];
        int row = 0;
        int col = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (A[i][j] > max) {
                    max = A[i][j];
                    row = i;
                    col = j;
                }
            }
        }
        System.out.printf("Phần tử lớn nhất của ma trận là %d tại vị trí A[%d][%d]\n", max, row, col);

        // Tìm và in ra các phần tử là số nguyên tố của ma trận
        System.out.println("Các phần tử là số nguyên tố của ma trận:");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (isPrime(A[i][j])) {
                    System.out.printf("%d ", A[i][j]);
                } else {
                    System.out.print("0 ");
                }
            }
            System.out.println();
        }

        // Sắp xếp tất cả các cột của ma trận theo thứ tự tăng dần
        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n - 1; i++) {
                for (int k = i + 1; k < n; k++) {
                    if (A[i][j] > A[k][j]) {
                        int temp = A[i][j];
                        A[i][j] = A[k][j];
                        A[k][j] = temp;
                    }
                }
            }
        }

        // In ma trận sau khi sắp xếp
        System.out.println("Ma trận sau khi sắp xếp:");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                System.out.printf("%d ", A[i][j]);
            }
            System.out.println();
        }
    }

    // Phương thức kiểm tra số nguyên tố
    public static boolean isPrime(int n) {
        if (n < 2) {
            return false;
        }
        for (int i = 2; i <= Math.sqrt(n); i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }

}
