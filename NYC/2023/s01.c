#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_dir(int** town, int x, int y, int size, int reach, int addToX, int addToY);
int get_x(int** town, int x, int y, int size, int reach);
int get_plus(int** town, int x, int y, int size, int reach);

int main(){
    int size = 0;
    int reach = 0;
    int** town;
    char* buffer = NULL;
    size_t buffer_size =  0;
    const char* sep = " ";
    int jdx = 0;
    int max = 0;

    getline(&buffer, &buffer_size, stdin);
    size = atoi(strtok(buffer, sep));
    reach = atoi(strtok(NULL, sep));

    // malloc town
    town = (int** )malloc(sizeof(int* ) * size);
    for(int idx = 0; idx < size; idx++){
        town[idx] = (int*)malloc(sizeof(int) * size);
    }

    // get input for town
    for(int idx = 0; idx < size; idx++){
        getline(&buffer, &buffer_size, stdin);
        jdx = 0;
        town[idx][jdx++] = atoi(strtok(buffer, sep));

        for(; jdx < size; jdx++){
            town[idx][jdx] = atoi(strtok(NULL, sep));
        }
    }

    // print town
    // for(int idx = 0; idx < size; idx++){
    //     for(jdx = 0; jdx < size; jdx++){
    //         printf("%d ", town[idx][jdx]);
    //     }
    //     printf("\n");
    // }

    for(int idx = 0; idx < size; idx++){
        for(jdx = 0; jdx < size; jdx++){
            if(max < get_x(town, idx, jdx, size, reach)){
                max = get_x(town, idx, jdx, size, reach);
            }
            if(max < get_plus(town, idx, jdx, size, reach)){
                max = get_plus(town, idx, jdx, size, reach);
            }
        }
    }

    printf("%d\n", max);

    // free town
    for(int idx = 0; idx < size; idx++){
        free(town[idx]);
    }
    free(town);

    return 0;
}


int get_dir(int** town, int x, int y, int size, int reach, int addToX, int addToY){
    int tot = 0;
    int count = 0;

    while(1){
        x += addToX;
        y += addToY;
        
        if (!((0 <= x) && (x < size))){
            break;
        }
        if (!((0 <= y) && (y < size))){
            break;
        }

        if (!(count < reach)){
            break;
        }
        // printf("%d %d\n", x, y);
        count++;

        tot += town[x][y];
    }

    return tot;
}

int get_x(int** town, int x, int y, int size, int reach){
    return get_dir(town, x, y, size, reach, 1, 1) \
    + get_dir(town, x, y, size, reach, 1, -1)     \
    + get_dir(town, x, y, size, reach, -1, -1)    \
    + get_dir(town, x, y, size, reach, -1, 1)  \
    + town[x][y];
}

int get_plus(int** town, int x, int y, int size, int reach){
    return get_dir(town, x, y, size, reach, 1, 0) \
    + get_dir(town, x, y, size, reach, -1, 0)     \
    + get_dir(town, x, y, size, reach, 0, -1)    \
    + get_dir(town, x, y, size, reach, 0, 1)  \
    + town[x][y];
}