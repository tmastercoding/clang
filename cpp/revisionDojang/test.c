#include <stdio.h>
#include <float.h>

int main(){
    float num = 7.1f;
    // printf("%.3f", num);



    float num1 = FLT_MIN;    // float의 양수 최솟값
    float num2 = FLT_MAX;    // float의 양수 최댓값
    float num3 = -FLT_MAX;    // float의 양수 최댓값

    // float의 양수 최솟값을 100000000.0으로 나누면 아주 작은 수가 되면서 언더플로우 발생
    num1 = num1 / 100000000.0f;
    num3 = num3 / FLT_MAX;

    // float의 양수 최댓값에 1000.0을 곱하면 저장할 수 있는 범위를 넘어서므로 오버플로우 발생
    num2 = num2 * 1000.0f;

    printf("%e %e  %e\n", num1, num2, num3);    // 0.000000e+00 inf: 실수의 언더플로우는 0
                                      // 오버플로우는 무한대가 됨
    
    return 0;
}