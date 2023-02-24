package JavaUTT.Bai2_2;

public class Bai2_2 {
    public static void main(String[] args) {
        int sum = 0;
        int count = 0;

        for (int i = 2; count < 10; i += 2) {
            sum += i;
            count++;
        }

        System.out.println("Tổng của 10 số chẵn đầu tiên là: " + sum);
    }
}
