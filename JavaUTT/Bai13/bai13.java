package JavaUTT.Bai13;

import java.util.Scanner;

public class bai13 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Nhập số dòng của ma trận: ");
        int n = input.nextInt();
        System.out.print("Nhập số cột của ma trận: ");
        int m = input.nextInt();
        int[][] matrix = new int[n][m];

        // Nhập ma trận
        inputMatrix(input, matrix);

        // In ma trận
        System.out.println("Ma trận vừa nhập:");
        printMatrix(matrix);

        // Tìm phần tử nhỏ nhất
        int min = findMin(matrix);
        System.out.println("Phần tử nhỏ nhất của ma trận là: " + min);

        // Tìm phần tử lẻ lớn nhất
        int oddMax = findMaxOdd(matrix);
        if (oddMax != Integer.MIN_VALUE) {
            System.out.println("Phần tử lẻ lớn nhất của ma trận là: " + oddMax);
        } else {
            System.out.println("Không có phần tử lẻ trong ma trận.");
        }

        // Tìm dòng có tổng lớn nhất
        int rowMaxSum = findRowMaxSum(matrix);
        System.out.println("Dòng có tổng lớn nhất của ma trận là dòng thứ " + rowMaxSum);
    }

    // Hàm nhập ma trận
    public static void inputMatrix(Scanner input, int[][] matrix) {
        System.out.println("Nhập giá trị các phần tử của ma trận:");
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[0].length; j++) {
                System.out.print("matrix[" + i + "][" + j + "] = ");
                matrix[i][j] = input.nextInt();
            }
        }
    }

    // Hàm in ma trận
    public static void printMatrix(int[][] matrix) {
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[0].length; j++) {
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println();
        }
    }

    // Hàm tìm phần tử nhỏ nhất
    public static int findMin(int[][] matrix) {
        int min = matrix[0][0];
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[0].length; j++) {
                if (matrix[i][j] < min) {
                    min = matrix[i][j];
                }
            }
        }
        return min;
    }

    // Hàm tìm phần tử lẻ lớn nhất
    public static int findMaxOdd(int[][] matrix) {
        int oddMax = Integer.MIN_VALUE;
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[0].length; j++) {
                if (matrix[i][j] % 2 != 0 && matrix[i][j] > oddMax) {
                    oddMax = matrix[i][j];
                }
            }
        }
        if (oddMax == Integer.MIN_VALUE) {
            System.out.println("Không tìm thấy phần tử lẻ trong ma trận");
        }
        return oddMax;
    }


    // Hàm tìm dòng có tổng lớn nhất
    public static int findRowMaxSum(int[][] matrix) {
        int rowMaxSum = 0;
        int maxSum = 0;
        for (int i = 0; i < matrix.length; i++) {
            int sum = 0;
            for (int j = 0; j < matrix[0].length; j++) {
                sum += matrix[i][j];
            }
            if (sum > maxSum) {
                maxSum = sum;
                rowMaxSum = i;
            }
        }
        return rowMaxSum;
    }
}

