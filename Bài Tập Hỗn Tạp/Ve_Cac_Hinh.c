
//  Viết chương trình in ra tam giác cân có độ dài h.

#include<stdio.h>
#include<stdlib.h>
#include<math.h>


/*  a. vẽ tam giác cân
                *                   1  |    i=1, j=1 ->[4, 4] ngược lại in khoảng trắng "   "    
            *   *   *               2  |    i=2, j=3 ->[3, 5] ngược loại in  "   "
        *   *   *   *   *           3  |    i=3, j=5 ->[2, 6] ngược lại in "   "
    *   *   *   *   *   *   *       4  |    i=4, j=7 ->[1, 7] 
    
    1   2   3   4   5   6   7               [a, b] = [h-i+1, h+i-1];
*/
void Tam_Giac_Can(int h) {
    printf ("Hinh_1:\t\n");
    for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= 2 * h - 1; j++) {
			if (h - i  + 1 <= j && j <= h + i - 1) { // [a, b] = [h-i+1, h+i-1];
				printf(" * ");
			} else {
                printf("   ");
            }
		}
		printf("\n");
	} 
}

/*  a.1 vẽ tam giác cân
    1   2   3   4   5   6   7

    *   *   *   *   *   *   *
        *   *   *   *   *
            *   *   *
                *
*/
void Tam_Giac_Can_Nguoc(int h) {
    printf ("Hinh_2:\t\n\n");
    for (int i=h; i>=1; i--) {
        for (int j=2*h -1; j>=1; j--) {
            if (h-i+1 <= j && j <= h+i-1) {
                printf (" * ");
            } else {
                printf ("   ");
            }
        }
        printf ("\n");
    }
}



/*  b.vẽ tam giác cân rỗng.
                *                      i=1, j=4
            *       *                  i=2, j=3,5
        *               *              i=3, j=2,6
    *   *   *   *   *   *   *          i=4, j=1,2,3,4,5,6,7

    1   2   3   4   5   6   7         
*/
void Tam_Giac_Can_Rong(int h) {
    printf ("Hinh_3:\n");
    for (int i = 1; i < h; i++) { // tại sao i < h , mục đích để nó không duyệt vòng cuối cùng
		for (int j = 1; j <= 2 * h - 1; j++) {
			if (j == (h - i  + 1) || j == (h + i - 1)) { // [a, b] = [h-i+1, h+i-1];
				printf(" * ");
			} else {
                printf("   ");
            }
		}
		printf("\n");
	} 
    for (int i=1; i<=2*h-1; i++) {
        printf (" * ");
    }
}

/* b.1 vẽ tam giác cân rỗng ngược.
    *   *   *   *   *   *   *
        *               *
            *       *
                *
*/
void Tam_Giac_Can_Rong_Nguoc(int h) {
    printf ("Hinh_4:\n\n");
    for (int i=1; i<=2*h-1; i++) {
        printf (" * ");
    }
    printf ("\n");
    for (int i=h-1; i>=1; i--) {
        for (int j=2*h-1; j >=1; j--) {
            if (j == h-i+1 || j==h+i-1) {
                printf (" * ");
            } else {
                printf ("   ");
            }
        }
        printf ("\n");
    }
}





/*  c. tam giác vuông cân đặc.

    *                       i=1, j=1
    *   *                   i=2, j=1,2
    *   *   *               i=3, j=1,2,3 
    *   *   *   *           i=4, j=1,2,3,4
    
    1   2   3   4
*/
void Tam_Giac_Vuong_Can(int h) {
    printf ("Hinh_5:\t\n\n");
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= i; j++) {
            printf (" * ");
        }
        printf ("\n");
    }
}

/*  c.1 tam giác vuông cân đặc ngược
    1   2   3   4

    *   *   *   *
    *   *   *
    *   *
    * 
*/
void Tam_Giac_Vuong_Can_Nguoc(int h) {
    printf ("Hinh_6:\t\n\n");
    for(int i=h; i>=1; i--) {
        for (int j=i; j>=1; j--) {
            printf (" * ");
        }
        printf ("\n");
    }
}




/* d. vẽ tam giác vuông cân rỗng.
    *                       i=1, j=1
    *   *                   i=2, j=1,2
    *       *               i=3, j=1,3
    *           *           i=4, j=1,4
    *   *   *   *   *       i=5, j=1,2,3,4,5
    1   2   3   4   5
*/
void Tam_Giac_Vuong_Can_Rong(int h) {
    printf ("Hinh_7:\t\n\n");
    for (int i = 1; i < h; i++) {
        for (int j = 1; j <= i; j++) {
            if (j == 1 || j == i) {
                printf (" * ");
            } else {
                printf ("   ");
            }
        }
        printf ("\n");
    }
    for (int i=1; i<=h; i++) {
        printf (" * ");
    }
}

/*  d.1 vẽ tam giác vuông cân rỗng ngược.
    1   2   3   4   5

    *   *   *   *   *
    *           *
    *       *
    *   *
    * 

*/

void Tam_Giac_Vuong_Can_Rong_Nguoc(int h) {
    printf ("Hinh_8:\t\n\n");
    for (int i=1; i<=h; i++) {
        printf (" * ");
    }
    printf ("\n");
    for (int i=h-1; i >=1; i--) {
        for (int j=i; j>=1; j--) {
            if (j == 1 || j == i) {
                printf (" * ");
            } else {
                printf ("   ");
            }
        }
        printf ("\n");
    }
}


/*  
    vẽ hình thoi đặc
                *
            *   *   *
        *   *   *   *   *
    *   *   *   *   *   *   *
        *   *   *   *   *
            *   *   *
                *
    cách làm: vẽ hai hình chóp gép vào nhau tạo ra hình thoi
*/
void Hinh_Thoi (int h) {
    printf ("Hinh_9:\t\n\n");
    for (int i=1; i<=h; i++) {
        for (int j=1; j<=2*h-1; j++) {
            if (h-i+1 <= j && j <= h+i-1) {
                printf (" * ");
            } else {
                printf ("   ");
            }
        }
        printf ("\n");
    }
    for (int i=h-1; i>=1; i--) {
        for (int j=2*h-1; j>=1; j--) {
            if (h-i+1 <= j && j <= h+i-1) {
                printf (" * ");
            } else {
                printf ("   ");
            }
        }
        printf ("\n");
    }
}

/*
    1   2   3   4   5   6   7
    *   *   *   *   *   *   *
        *   *   *   *   *
            *   *   *
                *
            *   *   *
        *   *   *   *   *
    *   *   *   *   *   *   *
*/

void Hinh_Chong_Nhau (int h) {
    printf ("Hinh_10:\t\n\n");
    for (int i=h; i>=1; i--) {
        for (int j=2*h-1; j>=1; j--) {
            if (h-i+1 <= j && j <= h+i-1) {
                printf (" * ");
            } else {
                printf ("   ");
            }
        }
        printf ("\n");
    }
    for (int i=2; i<=h; i++) {
        for (int j=1; j<=2*h-1; j++) {
            if (h-i+1 <= j && j <= h+i-1) {
                printf (" * ");
            } else {
                printf ("   ");
            }
        }
        printf ("\n");
    }
}

/*
    1   2   3   4   5   6   7
    *   *   *   *   *   *   *
        *               *
            *       *
                *
            *       *
        *               *
    *   *   *   *   *   *   *
*/
void Hinh_Chong_Nhau_Rong (int h) {
    printf ("Hinh_11:\t\n\n");
    for (int i=2*h-1; i>=1; i--) {
        printf (" * ");
    }
    printf ("\n");
    for (int i=h-1; i>=1; i--) {
        for (int j=2*h-1; j>=1; j--) {
            if (h-i+1 == j || j == h+i-1) {
                printf (" * ");
            } else {
                printf ("   ");
            }
        }
        printf ("\n");
    }
    for (int i=2; i < h; i++) {
        for (int j=1; j<=2*h-1; j++) {
            if (h-i+1 == j || j == h+i-1) {
                printf (" * ");
            } else {
                printf ("   ");
            }
        }
        printf ("\n");
    }
    for (int i=2*h-1; i>=1; i--) {
        printf (" * ");
    }
}

/*
    *   *   *   *   *   *   *   
    *   *   *       *   *   *
    *   *               *   *
    *                       *
    *   *               *   *
    *   *   *       *   *   *
    *   *   *   *   *   *   *
*/
void Hinh_Thoi_Rong_Trong(int h) {
    printf ("Hinh_12:\t\n\n");
    for (int i=1; i<=h; i++) {
        for (int j = 1; j <= 2*h-1; j++) {
            if (j == h-i+1 || j == h+i-1) {
                printf ("   ");
            } else {
                printf (" * ");
            }
        }
        printf ("\n");
    }
    for (int i = h-1; i >=1; i--) {
        for (int j = 2*h-1; j >=1; j--) {
            if (j == h-i+1 || j == h+i-1) {
                printf ("   ");
            } else {
                printf (" * ");
            }
        }
        printf ("\n");
    }
}




/*  vẽ hình thoi rỗng.
    1   2   3   4   5   6   7
                *
            *       *
        *               *
    *                       *
        *               *
            *       *
                *
*/
void Hinh_Thoi_Rong(int h) {
    printf ("Hinh_13:\t\n\n");
    for (int i=1; i<=h; i++) {
        for (int j = 1; j <= 2*h-1; j++) {
            if (j == h-i+1 || j == h+i-1) {
                printf (" * ");
            } else {
                printf ("   ");
            }
        }
        printf ("\n");
    }
    for (int i = h-1; i >=1; i--) {
        for (int j = 2*h-1; j >=1; j--) {
            if (j == h-i+1 || j == h+i-1) {
                printf (" * ");
            } else {
                printf ("   ");
            }
        }
        printf ("\n");
    }
}

/*  vẽ hình vuông.
    *   *   *   *   
    *   *   *   *   
    *   *   *   *   
    *   *   *   *   
*/
void Hinh_Vuong(int h) {
    printf ("Hinh_14:\t\n\n");
    for (int i=1; i<=h; i++) {
        for (int j=1; j<=h; j++) {
            printf (" * ");
        }
        printf ("\n");
    }
}


/*  hình vuông rỗng
    *   *   *   *
    *           *
    *           *
    *   *   *   *
*/
void Hinh_Vuong_Rong(int h) {
    printf ("Hinh_15:\t\n\n");
    for (int i=1; i<=h ; i++) {
        printf (" * ");
    }
    printf ("\n");
    for (int i=1; i<h-1; i++) {
        for (int j=1; j <= h; j++) {
            if (j == 1 || j == h) {
                printf (" * ");
            } else {
                printf ("   ");
            }
        }
        printf ("\n");
    }
    for (int i=1; i <=h; i++) {
        printf (" * ");
    }
}



/*  Vẽ hình bình hành
    1   2   3   4   5   6   7
                *   *   *   *
            *   *   *   *
        *   *   *   *
    *   *   *   *

*/
void Hinh_Binh_Hanh(int h) {
    printf ("Hinh_16:\t\n\n");
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= 2*h - 1; j++) {
            if (j >= h-i+1 && j <= 2*h-i) {
                printf (" * ");
            } else {
                printf ("   ");
            }
        }
        printf ("\n");
    }
}

/*  vẽ Hình bình hành ngược
    1   2   3   4   5   6   7
    *   *   *   *
        *   *   *   *
            *   *   *   *
                *   *   *   *
*/
void Hinh_Binh_Hanh_Nguoc(int h) {
    printf ("Hinh_17:\t\n\n");
    for (int i = h; i >=1; i--) {
        for (int j = 1; j <= 2*h - 1; j++) {
            if (j >= h-i+1 && j <= 2*h-i) {
                printf (" * ");
            } else {
                printf ("   ");
            }
        }
        printf ("\n");
    }
}

/*
    1   2   3   4   5   6   7
    *                       *
    *   *               *   *
    *   *   *       *   *   *
    *   *   *   *   *   *   *
    *   *   *       *   *   *
    *   *               *   *
    *                       * 
*/
void Hinh_Nguoc_Trong_Dong (int h) {
    printf ("Hinh_18:\t\n\n");
    for (int i=h; i>=1; i--) {
        for (int j=2*h-1; j>=1; j--) {
            if (h-i+1 >= j || j >= h+i-1) {
                printf (" * ");
            } else {
                printf ("   ");
            }
        }
        printf ("\n");
    }
    for (int i=2; i<=h; i++) {
        for (int j=1; j<=2*h-1; j++) {
            if (h-i+1 >= j || j >= h+i-1) {
                printf (" * ");
            } else {
                printf ("   ");
            }
        }
        printf ("\n");
    }
}

int main() {
    int h;
    do {
        printf ("\nNhap vao do dai h = ");
        scanf("%d", &h);
    }while(h < 0 && printf("Nhap lai chieu cao h: "));

    Tam_Giac_Can(h);
    printf ("\n\n\n");

    Tam_Giac_Can_Nguoc(h);
    printf("\n\n\n");

    Tam_Giac_Can_Rong(h);
    printf ("\n\n\n");

    Tam_Giac_Can_Rong_Nguoc(h);
    printf ("\n\n\n");

    Tam_Giac_Vuong_Can(h);
    printf ("\n\n\n");

    Tam_Giac_Vuong_Can_Nguoc(h);
    printf ("\n\n\n");

    Tam_Giac_Vuong_Can_Rong(h);
    printf ("\n\n\n");

    Tam_Giac_Vuong_Can_Rong_Nguoc(h);
    printf ("\n\n\n");

    Hinh_Thoi(h);
    printf ("\n\n\n");

    Hinh_Chong_Nhau(h);
    printf ("\n\n\n");

    Hinh_Chong_Nhau_Rong(h);
    printf ("\n\n\n");

    Hinh_Thoi_Rong_Trong(h);
    printf ("\n\n\n");

    Hinh_Thoi_Rong(h);
    printf("\n\n\n");

    Hinh_Vuong(h);
    printf ("\n\n\n");

    Hinh_Vuong_Rong(h);
    printf ("\n\n\n");

    Hinh_Binh_Hanh(h);
    printf ("\n\n\n");

    Hinh_Binh_Hanh_Nguoc(h);
    printf ("\n\n\n");

    Hinh_Nguoc_Trong_Dong(h);
    printf ("\n\n\n");


    return 0;
}
