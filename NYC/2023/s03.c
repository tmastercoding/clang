#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){ 
    // declare variables
    char** lines;
    char* buffer = NULL;
    size_t size = 0;
    char* sep = " ";
    char* cur;
    char* prev;
    char* temp;

    char tags[4][10] = {"<CENTER>", "</CENTER>", "<RIGHT>", "</RIGHT>"};
    int input_size = 7;
    int width = 10;

    int state = 0;
    int idx = 0;
    int line_width = 0;
    int word_count = 0;
    int tag_flag = 0;
    int skip_flag = 0;

    // get input + output
    while(idx < input_size){
        // get line
        getline(&buffer, &size, stdin);
        
        // remove new line
        line_width = strlen(buffer);
        line_width--;
        buffer[line_width] = '\0';
        
        // select state
        for(int jdx = 0; jdx < 4; jdx++){
            if( !( strcmp( tags[jdx], buffer ) ) ){
                switch(jdx){
                    case 0:
                        state = 1;
                        break;

                    case 2:
                        state = 2;
                        break;

                    default:
                        state = 0;
                        break;
                }
                tag_flag = 1;
                break;
            }
        }

        if(tag_flag){
            tag_flag = 0;
            continue;
        }

        // split lines needed to print
        word_count = 1;
        for(int jdx = 0; jdx < line_width; jdx++){
            if(buffer[jdx] == ' '){
                word_count++;
            }
        }
        
        lines = (char**)malloc(sizeof(char*) * word_count);
        prev = strtok(buffer, sep);


        lines[0] = (char*)malloc(sizeof(char) * strlen(prev));
        strcpy(lines[0], prev);
        printf("lines[0]: %s\n", lines[0]);
        
        for(int jdx = 1; jdx < word_count; jdx++){
            printf("prev: %s\n", prev);
            temp = strtok(NULL, sep);
            cur = (char* )malloc(sizeof(char) * strlen(temp));
            strcpy(cur, temp);
            printf("cur: %s\n", cur);
            if(strcmp(prev, "!")){
                if(strlen(prev) + 1 + strlen(cur) <= width){
                    strcat(prev, "-");
                    printf("after prev: %s\n", prev);
                    strcat(prev, cur);
                    skip_flag = 1;
                }
            } else{
                strcpy(prev, cur);
            }
            printf("after prev: %s\n", prev);
            lines[jdx-1] = (char* )malloc(sizeof(char) * strlen(prev));
            
            strcpy(lines[jdx-1], prev);
            strcpy(prev, cur);

            if(skip_flag){
                skip_flag = 0;
                strcpy(prev, "!");
            }
            free(cur);
        }

        for(int jdx = 0; jdx < word_count; jdx++){
            switch(state){
                case 0:
                    if(strlen(lines[jdx]) > 0){
                        printf("%s", lines[jdx]);
                        for(int kdx = 0; kdx < width - strlen(lines[jdx]); kdx++){
                            printf("-");
                        }
                        printf("\n");
                    }
                    break;
                case 1:
                    break;
                case 2:
                    break;
            }
        }
        
        // free memory
        for(int jdx = 0; jdx < word_count; jdx++){
            free(lines[jdx]);
        }
        free(lines);
        idx++;
    }

    return 0;
}