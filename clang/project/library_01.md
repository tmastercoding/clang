```c
#include <stdio.h>

#define TRUE 1
#define FALSE 0

/**
* -----------------------------
* 
* @ author : Tay Oh
* @ date : 26th March 2023
* @ description : A project allowing the user to do library related tasks
*                 using array, pointer, function on clang.
* 
* ------------------------------
*
* function list:
* - main : allows the user to select the main choices
* - add_book : adds a book 
*              with the name, author and publisher 
*              into the library
* - search_book : searches for a book 
*                 with the inputted the name, author or publisher
* - borrow_book : borrows a book
*                 with the given book number
* - return_book : returns a book
*                 with the given book number
* - view_book_list : displays all books
*                    and its book number, name, publisher and author
* - a_book_info : returns a book
*                 with the given book number
*/


int add_book( 
    char (*book_name)[100], 
    char (*auth_name)[100], 
    char (*publ_name)[100], 
    int *borrowed, 
    int *num_total_book );

int search_book( 
    char (*book_name)[100], 
    char (*auth_name)[100], 
    char (*publ_name)[100], 
    int *borrowed,
    int *num_total_book );

int borrow_book( 
    int *borrowed,
    int num_book );

int return_book( 
    int *borrowed,
    int num_book);

int view_book_list( 
    char (*book_name)[100], 
    char (*auth_name)[100], 
    char (*publ_name)[100], 
    int *borrowed, 
    int *num_total_book );

int a_book_info(    
    int book_num,
    char (*book_name)[100], 
    char (*auth_name)[100], 
    char (*publ_name)[100], 
    int *borrowed);

int str_search(char *source, char *keyword);
int str_len(char *str);
    
int main(){
    int user_choice;
    int num_total_book=0;

    int *p_num_total_book=&num_total_book;
    
    char book_name[100][100];
    char auth_name[100][100];
    char publ_name[100][100];

    int borrowed[100] = {0,};

    int exit_flag = TRUE;
    int book_num = -1;

    while( exit_flag  ){
        printf("library organising program\n");
        printf("select a menu\n");
        printf("1. add a book\n");
        printf("2. search a book\n");
        printf("3. borrow a book\n");
        printf("4. return a book\n");
        printf("5. view book list \n");
        printf("6. program exit\n");

        printf("your selection: ");
        scanf("%d", &user_choice);

        switch( user_choice ){
            case 1:
                add_book(book_name, auth_name, publ_name, borrowed, &num_total_book);
                // add a book function
                break;

            case 2:
                // search a book function
                search_book(book_name, auth_name, publ_name, borrowed, &num_total_book);
                break;

            case 3:
                // borrow a book function
                scanf("%d", &book_num);
                fflush(stdin);
    
                borrow_book(borrowed, book_num);

                break;

            case 4:
                // return a book function
                scanf("%d", &book_num);
                fflush(stdin);

                return_book(borrowed, book_num);

                break;

            case 5:
                view_book_list(book_name, auth_name, publ_name, borrowed, &num_total_book);
                // view list
                break;

            case 6:
                // exit program
                exit_flag = FALSE;
                printf("Thank you for using this program!~~");

                break;

            default:
                printf("input only numbers from 1-6.\n");                
                break;

        }
    }

    return 0;
}

int add_book( 
    char (*book_name)[100], 
    char (*auth_name)[100], 
    char (*publ_name)[100], 
    int *borrowed, 
    int *num_total_book ){
    
    printf("Please input the book name: ");
    scanf("%s", book_name[*num_total_book]);
    fflush(stdin);

    printf("Please input the author\'s name: ");
    scanf("%s", auth_name[*num_total_book]);
    fflush(stdin);

    printf("Please input the book publisher: ");
    scanf("%s", publ_name[*num_total_book]);
    fflush(stdin);
    borrowed[*num_total_book] = 0;

    printf("adding succesful!\n");

    (*num_total_book)++;

    return 1;
}

int view_book_list( 
    char (*book_name)[100], 
    char (*auth_name)[100], 
    char (*publ_name)[100], 
    int *borrowed, 
    int *num_total_book ){
    
    printf(" book list \n" );
    printf(" total %d ea \n", *num_total_book );

    for(int book_num=0; book_num< *num_total_book; book_num++){
        a_book_info(book_num, book_name, auth_name, publ_name, borrowed);

        // if(borrowed[book_num]){
        //     printf("Borrowed\n");
        // } else{
        //     printf("Available\n");
        // }

    }
    return 1;
}

int borrow_book( 
    int *borrowed,
    int num_book ){
    
    borrowed[num_book-1] = 1;
    printf("borrow succesful!\n");

    return num_book;
}

int return_book( 
    int *borrowed,
    int num_book ){
    
    borrowed[num_book-1] = 0;
    printf("returned succesful!\n");
    
    return num_book;
}

int toggle_lent_status( 
    int *borrowed,
    int num_book ){
    
    borrowed[num_book] = !borrowed[num_book];
    
    return 1;
}

int search_book( 
    char (*book_name)[100], 
    char (*auth_name)[100], 
    char (*publ_name)[100], 
    int *borrowed,
    int *num_total_book ){

    int user_input;

    // char buffer[100] = { '\0', };
    char search[100];

    int is_find = 0;
    int count_of_find=0;

    printf("How do you want to search for a book?\n");
    printf("1: By book name\n");
    printf("2: By author name\n");
    printf("3: By publisher name\n");
    scanf("%d", &user_input);

    switch(user_input){
        case 1:
            // book name
            printf("input: ");
            scanf("%s", search);
            fflush(stdin);

            for( int book_num = 0; book_num < *num_total_book; book_num++){
                is_find = str_search(book_name[book_num], search);
                if( is_find ) {
                    count_of_find++;
                    a_book_info(book_num, book_name, auth_name, publ_name, borrowed);
                }
                
            }
            // book name

            break;
            
        case 2:
            // author name
            printf("input: ");
            scanf("%s", search);
            fflush(stdin);

            for( int book_num = 0; book_num < *num_total_book; book_num++){
                is_find = str_search(auth_name[book_num], search);
                if( is_find ) {
                    count_of_find++;
                    a_book_info(book_num, book_name, auth_name, publ_name, borrowed);
                }
            }
            break;
            
        case 3:
            // publisher name
            printf("input: ");
            scanf("%s", search);
            fflush(stdin);

            for( int book_num = 0; book_num < *num_total_book; book_num++){
                is_find = str_search(publ_name[book_num], search);

                if( is_find ) {
                    count_of_find++;
                    a_book_info(book_num, book_name, auth_name, publ_name, borrowed);
                }
            }

            break;
            
        default:
            printf("input numbers from 1-3 only\n");
            break;
           
    }

    if(!count_of_find){
        printf("Sorry! This book is not in our library!\n");
    }

    return TRUE;
}

int str_search(char *source, char *keyword){
    // compare length
    int source_len = str_len(source);
    int keyword_len = str_len(keyword);
    int flag = 0;

    if(source_len < keyword_len){
        return flag;
    }
    for(int s_char = 0; s_char < source_len; s_char++){
        // printf("== outer : s_char: %c, char num: %d\n", source[s_char], s_char);
        
        flag = 1;
        for(int k_char = 0; k_char < keyword_len; k_char++){
            // printf("== inner :k_char: %c, char num: %d\n", keyword[k_char], k_char);
            if( source[s_char+k_char]!= keyword[k_char]){
                // printf("========= breaking ==========\n");
                flag = 0;
                break;
            }
        }
        if (flag){
            return flag;
        }

    }
    return flag;
}

int str_len(char *str){
    int len = 0;

    while(*str!='\0'){
        str++;
        len++;
    }

    return len;
}

int a_book_info(    
    int book_num,
    char (*book_name)[100], 
    char (*auth_name)[100], 
    char (*publ_name)[100], 
    int *borrowed){

    printf(" ================================ \n" );
    printf(" Book number: %d\n", book_num+1);
    printf(" Book name: %s\n", book_name[book_num]);
    printf(" Author name: %s\n", auth_name[book_num]);
    printf(" Publisher name: %s\n", publ_name[book_num]);
    printf(" Borrowed Status: %s\n", (borrowed[book_num])? "Borrowed": "Available");
    printf(" ˜================================ \n" );

    return TRUE;
}
```