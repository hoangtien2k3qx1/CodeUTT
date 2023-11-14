/*
    Câu 1 (2 điểm)
        Hãy định nghĩa class Word với các thuộc tính: id, en(từ tiếng anh), vn(nghĩa 
        tiếng việt) và các phương thức khởi tạo, hiển thị thông tin, các phương thức 
        getters/setters.
    Câu 2 (6 điểm)
        Định nghĩa class Dictionary cho phép
        a. (1 điểm) Khởi tạo một danh sách (> 10 từ), có thể tự khởi tạo hoặc nhập 
        dữ liệu
        b. (3 điểm) Tạo một phương thức tìm kiếm, thực hiện tìm kiếm một từ trong 
        từ điển (sử dụng thuật toán tìm nhị phân, tìm tuần tự được ½ số điểm).
        Nếu tìm thấy thì hiển thị nghĩa tiếng việt lên màn hình console, trái lại 
        thực hiện theo câu 2.c
        c. (2 điểm) Bổ sung một từ vào từ điển nếu từ đó chưa có trong từ điển, sinh 
        viên tự bắt lỗi đầu vào và bổ sung menu chức năng nếu cần thiết.
    Chú ý: các từ trong danh sách phải đúng thứ tự từ điển (theo từ tiếng anh)

 */
package de6;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

/**
 *
 * @author hoang
 */
public class De6 {
    private ArrayList<Word> wordList;
    
    public De6() {
        wordList = new ArrayList<Word>();
    }
    
    public void addWord(Word word) {
        wordList.add(word);
        Collections.sort(wordList, (w1, w2) -> w1.getEn().compareToIgnoreCase(w2.getEn()));
    }
    
    public void addMultipleWords(ArrayList<Word> words) {
        wordList.addAll(words);
        Collections.sort(wordList, (w1, w2) -> w1.getEn().compareToIgnoreCase(w2.getEn()));
    }
    
    public void searchWord(String en) {
        int index = binarySearch(en);
        if (index != -1) {
            Word word = wordList.get(index);
            System.out.println("English: " + word.getEn() + " - Tiếng Việt: " + word.getVn());
        } else {
            System.out.println("Không tìm thấy từ cần tìm.");
        }
    }
    
    private int binarySearch(String en) {
        int left = 0;
        int right = wordList.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            Word word = wordList.get(mid);
            int comparison = word.getEn().compareToIgnoreCase(en);
            
            if (comparison == 0) {
                return mid;
            } else if (comparison < 0) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return -1;
    }
    
    public static void main(String[] args) {
        
        Scanner scanner = new Scanner(System.in);
        De6 dictionary = new De6();
        
        
        // Khởi tạo danh sách từ điển
        ArrayList<Word> wordList = new ArrayList<Word>();
        wordList.add(new Word(1, "apple", "quả táo"));
        wordList.add(new Word(2, "banana", "quả chuối"));
        wordList.add(new Word(3, "cat", "con mèo"));
        wordList.add(new Word(4, "dog", "con chó"));
        wordList.add(new Word(5, "elephant", "con voi"));

        // Thêm danh sách từ điển
        dictionary.addMultipleWords(wordList);
        System.out.println("\nĐã thêm 1 danh sách từ mặc định vào hệ từ điển");
        
        int count = 0;
        while (true) {
            if (count != 0) System.out.println("\n\n");
            System.out.println("+---------------------------------------+");
            System.out.println("|                 Menu                  |");
            System.out.println("|---------------------------------------|");
            System.out.println("|   1.   Thêm từ vào từ điển.           |");
            System.out.println("|   2.   Tìm kiếm từ trong từ điển      |"); 
            System.out.println("|   3.   Thoát Chương Trình.            |"); 
            System.out.println("+---------------------------------------+");

            System.out.print("\t=> Lựa chọn: ");
            int luaChon = scanner.nextInt();
            scanner.nextLine();
                   
            switch (luaChon) {
                case 1: {
                    // Thêm từ vào từ điển
                    System.out.println("\nThêm từ vào trong từ điển: ");
                    System.out.print("\t+ Id: ");
                    int id = scanner.nextInt();

                    scanner.nextLine();
                    System.out.print("\t+ Englist: ");
                    String themTuEnglist = scanner.nextLine();

                    System.out.print("\t+ Viet Nam: ");
                    String themTuVietNam = scanner.nextLine();
                    dictionary.addWord(new Word(id, themTuEnglist, themTuVietNam));
                    break;
                }
                case 2: 
                    // Tìm kiếm từ 
                    System.out.print("\n\t+ Từ cần tìm là: ");
                    String strSearch = scanner.nextLine();
                    dictionary.searchWord(strSearch);
                    break;
                case 3:
                    System.out.println("\nĐã thoát chương trình !!!");
                    return;
                default: 
                    System.out.println("\nLựa chọn không hợp lệ.");
                    break;
            }
            count++;
        }

    }
}
