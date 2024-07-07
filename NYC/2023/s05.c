#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int binToInt(char* binary, int size);
void getPossible(int* possible, char* data, int order, char segments[10][8], int segments_size, char mask[2][9]);

int main(){
    const int segment_size = 10;
    char segments[segment_size][8] = {"1111110", "0110000", "1101101", "1111001", "0110011", \
                            "1011011", "1011111", "1110000", "1111111", "1111011"};
    char mask[2][9];
    int cases_size = 0;
    int** temp_post;

    char cur_pre[9];
    char cur_post[9];
    int pre_arr[segment_size] = {-1, };
    int post_arr[segment_size] = {-1, };
    int intersect[segment_size] = {-1, };

    char* buffer = NULL;
    size_t size = 0;
    char* sep = " ";
    int length = 0;
    int count = 0;
    int pre_size = 0;
    int isMatch = 0;
    int postVal = 0;

    // get mask
    getline(&buffer, &size, stdin);
    length = strlen(buffer);
    buffer[length-1] = '\0';

    strcpy(mask[0], strtok(buffer, sep));
    strcpy(mask[1], strtok(NULL, sep));    

    // get cases_size
    getline(&buffer, &size, stdin);
    cases_size = atoi(buffer);

    // malloc
    temp_post = (int**)malloc(cases_size * sizeof(int*));

    // get each case
    for(int idx = 0; idx < cases_size; idx++){
        getline(&buffer, &size, stdin);
        length = strlen(buffer);
        buffer[length-1] = '\0';

        strcpy(cur_pre, strtok(buffer, sep));
        strcpy(cur_post, strtok(NULL, sep));    

        // get possible numbers
        getPossible(pre_arr, cur_pre, 0, segments, segment_size, mask);
        getPossible(post_arr, cur_post, 1, segments, segment_size, mask);

        // add post_arr to temp_post
        temp_post[count] = (int*)malloc(segment_size * sizeof(int));
        for(int jdx = 0; jdx < segment_size; jdx++){
            temp_post[count][jdx] = post_arr[jdx];
            // printf("%d\n", post_arr[jdx]);
        }

        count++;
    }

    // intersection
    for(int idx = 0; idx < segment_size; idx++){
        if(pre_arr[idx] != -1){
            pre_size++;
        }
        printf("%d\n", pre_arr[idx]);
    }

    if(pre_size > 0){
        count = 0;
        for(int idx = 0; idx < segment_size; idx++){
            if(temp_post[0][idx] != -1){
                intersect[count++] = temp_post[0][idx];
            }
        }
        for(int idx = 1; idx < cases_size; idx++){
            for(int jdx = 0; jdx < segment_size; jdx++){
                if(intersect[jdx] == -1){
                    continue;
                }
                isMatch = 0;
                for(int kdx = 0; kdx < segment_size; kdx++){
                    if(temp_post[idx][kdx] == -1){
                        continue;
                    }
                    if(temp_post[idx][kdx] == intersect[jdx]){
                        isMatch = 1;
                        break;
                    }
                }
                if(!isMatch){
                    intersect[jdx] = -1;
                }
            }
        }
        postVal = intersect[0];
        for(int idx = 1; idx < segment_size; idx++){
            if(intersect[idx] > postVal){
                postVal = intersect[idx];
            }
        }
    }


    printf("%d\n", pre_size);
    for(int idx = 0; idx < segment_size; idx++){
        if(pre_arr[idx] != -1){
            printf("%d ", pre_arr[idx]*10 + postVal);
        }
    }
    printf("\n");

    // free memory
    for(int idx = 0; idx < cases_size; idx++){
        free(temp_post[idx]);
    }

    free(temp_post);
    return 0;
}

// binary char arr to decimal int
int binToInt(char* binary, int size){
    int num = 0;
    int pow = 1;
    for(int idx = size-1; idx > -1; idx--){
        num += pow * (binary[idx] -'0');
        pow *= 2;
    }
    
    return num;
}


void getPossible(int* possible, char* data, int order, char segments[10][8], int segments_size, char mask[2][9]){
    int isWorking = 0;
    int count = 0;
    int maskVal;
    int dec_cur_segment;
    int dec_data;
    int dec_mask;

    if(!strcmp(mask[order], "1111111")){
        isWorking = 1;
    }
    
    for(int idx = 0; idx < segments_size; idx++){

        dec_cur_segment = binToInt(segments[idx], strlen(segments[idx]));
        dec_data = binToInt(data, strlen(data));
        dec_mask = binToInt(mask[order], strlen(mask[order]));

        if(!isWorking){
            maskVal = dec_cur_segment & dec_data;
            if(maskVal == dec_data){
                possible[count++] = idx;
            } else{
                possible[count++] = -1;
            }
        } else{

            maskVal = dec_mask & dec_data;
            if(maskVal == dec_cur_segment){
                possible[count++] = idx;
            } else{
                possible[count++] = -1;
            }
        }
    }
}