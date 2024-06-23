#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    // declare variables
    char** jobs_arr;

    char* buffer = NULL;
    size_t size = 0;

    int tot_jobs = 0;
    int user_size = 0;
    
    int idx = 0;
    int jdx = 0;
    int count = 0;
    
    // input tot_jobs
    while( 1 ){
        getline(&buffer, &size, stdin);
        tot_jobs = atoi(buffer);
        // restriction
        if( (0 < tot_jobs) && (tot_jobs < 151) ){
            break;
        }
        printf("Please input integer between 1 and 150\n");
    }

    // malloc jobs_arr
    jobs_arr = (char**)malloc(sizeof(char*) * tot_jobs);

    // get input for jobs_list
    while(idx < tot_jobs){
        getline(&buffer, &size, stdin);

        jobs_arr[idx] = (char *)malloc(sizeof(char) * strlen(buffer));
        strcpy(jobs_arr[idx], buffer);

        // printf("jobs_arr[%d]: %s", idx, jobs_arr[idx]);
        idx++;
    }

    // input user_size
    while( 1 ){
        getline(&buffer, &size, stdin);
        user_size = atoi(buffer);
        // restriction
        if( (0 < user_size) && (user_size < 151) ){
            break;
        }
        printf("Please input integer between 1 and 150\n");
    }

    idx = 0;
    count = tot_jobs;
    // get user_arr
    while(idx < user_size){
        getline(&buffer, &size, stdin);
        jdx = 0;

        while(jdx < tot_jobs){
            if(!strcmp(buffer, jobs_arr[jdx])){
                strcpy(jobs_arr[jdx], "");
                count--;
            }

            jdx++;
        }
        
        idx++;
    }

    // output
    idx = 0;
    printf("%d\n", count);
    while(idx < tot_jobs){
        printf("%s", jobs_arr[idx]);
        idx++;
    }

    // free malloc
    idx = 0;
    while(idx < tot_jobs){
        free(jobs_arr[idx]);
        idx++;
    }

    free(jobs_arr);

    return 0;
}