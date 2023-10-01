#include <stdio.h>

int string_comp(char *pre, char *post);
int string_len(char *pre);

int main(){
    char str_a[] = "abdc";
    char str_b[] = "abbc";
    
    // Case 00.
    // int is_same = string_comp(str_a, str_b);

    // if (is_same){
    //     printf("same\n");
    // } else{
    //     printf("not same\n");
    // }
    
    // Case 01.
    printf( "%s\n", string_comp(str_a, str_b)? "same": "not same" );
    
    // char *pre = str_a;
    // char *post = str_b;

    // while(*pre != '\0' && *post != '\0'){
    //     if(*pre == *post){
    //         printf("equal\n");
    //     } else{
    //         break;
    //     }

    //     pre++;
    //     post++;
    // }

    return 0;
}

// int string_comp(char *pre, char *post){
//     while(*pre != '\0' && *post != '\0'){
//         if(*pre == *post){
//             printf("equal\n");
//         } else{
//             return 0;
//         }

//         pre++;
//         post++;
//     }
//     return 1;
// }

int string_comp(char *pre, char *post){
    if(string_len(pre) != string_len(post)) return 0;

    while(*pre != '\0'){
        if(*(pre++) != *(post++)){
            return 0;
        }
    }
    return 1;
}

int string_len(char *pre){
    int len = 0;
    // while(*(pre++) != '\0'){
    //     len++;
    // }
    while(*(pre + (len++) ) != '\0');

    return len;
}
