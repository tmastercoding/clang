#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct SplitObject{
    char** outputArr;
    int recivSize;
} SplitObject;

SplitObject split(char* text, const char sep);

int main() {
    char text[] = "  a      Hello    world   )_)    ";
    SplitObject split_object;
    split_object = split(text, ' ');

    printf("recivSize: %d\n", split_object.recivSize);
    for(int idx = 0; idx < split_object.recivSize; idx++){
        free(split_object.outputArr[idx]);
    }

    free(split_object.outputArr);
    return 0;
}

SplitObject split(char* text, const char sep){
    int pos = 0;
    char buffer[1024];
    int buffer_idx = 0;
    int size = 0; 
    int word_count = 0;
    char** output;
    SplitObject split_object;

    // get word_count of output array
    while(*(text+pos) != '\0'){
        if((*(text+pos) == sep) && ((*(text+pos+1) != sep) && (*(text+pos+1) != '\0'))){
            word_count++;
        }
        pos++;
    }

    // allocate memory for output
    output = (char**)malloc(sizeof(char*) * word_count);
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
    split_object.outputArr = output;
    split_object.recivSize = word_count;

    return split_object;
}