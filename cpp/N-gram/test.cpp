#include <stdio.h>
#include <string.h>

typedef struct Student {
    char name[50];
    int score;
} STUDENT;

#define DEF1(A,B) (A<B?A:B)
#define DEF2(A,B,C) DEF1(DEF1(A,B),C)
#define DEF3(A,B) (A-B*A)

int main(){
    // STUDENT stud[20];
    // strcpy(stud[4].name, "HongGilDong");
    // printf("%s\n", stud[4].name);

    // printf("%d\n", DEF3(30, DEF2(1>2, 3<4, 5>6)));


    int n = 3;
    int arr[3][3] = {
                      {0, 1, 1},
                      {1, 0, 1},
                      {1, 1, 0}          
                    };

    int m = 0;

    for(int i = 0; i < n; i++){
        int c = 0;
        for(int j = 0; j < n; j++) {
            if(i == j) continue;
            if(arr[i][j]){
                c++;
                continue;
            }

            for(int k = 0; k < n; k++){
                if(i == k || j == k) continue;
                if(arr[i][k] && arr[j][k]){
                    c++;
                    break;
                }
            }
        }
        m = m > c ? m : c;
    }

    printf("%d\n", m);

    return 0;
}