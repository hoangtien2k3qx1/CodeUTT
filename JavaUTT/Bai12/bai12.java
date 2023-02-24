package JavaUTT.Bai12;

import java.util.Scanner;

public class bai12 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the size of the array: ");
        int n = sc.nextInt();
        int[] arr = new int[n];
        System.out.println("Enter the elements of the array:");
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        // a) Xuất giá trị các phần tử của mảng
        System.out.println("The elements of the array are:");
        printArray(arr);
        // b) Tìm phần tử có giá trị lớn nhất, nhỏ nhất
        int max = arr[0];
        int min = arr[0];
        for (int i = 1; i < n; i++) {
            if (arr[i] > max) {
                max = arr[i];
            }
            if (arr[i] < min) {
                min = arr[i];
            }
        }
        System.out.println("The maximum element of the array is: " + max);
        System.out.println("The minimum element of the array is: " + min);
        // c) Đếm số phần tử là số chẵn
        int countEven = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] % 2 == 0) {
                countEven++;
            }
        }
        System.out.println("The number of even elements in the array is: " + countEven);
        // d) Tìm các phần tử là số nguyên tố
        System.out.print("The prime elements in the array are: ");
        for (int i = 0; i < n; i++) {
            if (isPrime(arr[i])) {
                System.out.print(arr[i] + " ");
            }
        }
        System.out.println();
        // e) Sắp xếp mảng tăng dần
        sortArray(arr);
        System.out.println("The sorted array in ascending order is:");
        printArray(arr);
        // f) Tìm phần tử có giá trị x
        System.out.print("Enter the value of x: ");
        int x = sc.nextInt();
        int index = findElement(arr, x);
        if (index == -1) {
            System.out.println("Element " + x + " not found in the array.");
        } else {
            System.out.println("Element " + x + " found at index " + index + " in the array.");
        }
    }

    public static void printArray(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }

    public static boolean isPrime(int num) {
        if (num <= 1) {
            return false;
        }
        for (int i = 2; i <= Math.sqrt(num); i++) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }

    public static void sortArray(int[] arr) {
        for (int i = 0; i < arr.length - 1; i++) {
            for (int j = i + 1; j < arr.length; j++) {
                if (arr[i] > arr[j]) {
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }

    public static int findElement(int[] arr, int x) {
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == x) {
                return i;
            }
        }
        return -1;
    }
}


