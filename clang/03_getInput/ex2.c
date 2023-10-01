#include <stdio.h>

int main(){
    double celsius;

    printf("섭씨 온도를 화씨 온도로 바꿔주는 프로그램 입니다. \n");

    printf("input temp : ");

    scanf("%lf", &celsius); //get input &

    printf("celisus %f is %f in farenheit \n", 
            celsius, 9 *celsius/ 5 + 32);

    return 0;
}