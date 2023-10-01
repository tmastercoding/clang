char compare(char *pre, char *post){
    
    while(*pre){
        if(*pre != *post){
            return 0;
        }

        pre++;
        post++;
    }

    if(*post == '\0') return 1;

    return 0;
}