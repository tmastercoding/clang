#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * @date ??.??.??
 * @author Tay Oh
 * @details Splits text according to sep
*/

char** split(char* text, const char sep, int* recivSize);

int main() {
    char text[] = "  a      Hello    world   )_)    ";
    int recivSize = 0;
    char** output = split(text, ' ', &recivSize);

    printf("recivSize: %d\n", recivSize);
    for(int idx = 0; idx < recivSize; idx++){
        free(output[idx]);
    }

    free(output);
    return 0;
}

char** split(char* text, const char sep, int* recivSize){
    int pos = 0;
    char buffer[1024];
    int buffer_idx = 0;
    int size = 0; 
    int word_count = 0;
    char** output;

    // get word_count of output array
    while(*(text+pos) != '\0'){
        if((*(text+pos) == sep) && ((*(text+pos+1) != sep) && (*(text+pos+1) != '\0'))){
            word_count++;
        }
        pos++;
    }

    // allocate memory for output
    output = (char**)malloc(sizeof(char*) * word_count);
    *recivSize = word_count;
    pos = 0;
    word_count = 0;

    // split array
    while(*(text+pos) != '\0'){
        
        // not space character, push character to temporary character buffer
        if(*(text+pos) != sep){
            buffer[buffer_idx] = *(text+pos);
            buffer_idx++;

        // space character, push temp char buffer to secodary char array
        } else{
            buffer[buffer_idx] = '\0';
            size = buffer_idx;
            buffer_idx = 0;
            
            // check if buffer contains sep
            if(size>0 && (buffer[0]!=sep)){
                // printf("buffer: %s\n", buffer);
                output[word_count] = (char* )malloc(sizeof(char) * size);
                strcpy(output[word_count], buffer);
                word_count++;
            }
        }
        pos++;
    }
    

    // print result for debug
    for(int idx = 0; idx < word_count; idx++){
        printf("%s\n", output[idx]);
    }


    return output;
}