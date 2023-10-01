#include <stdio.h>

#define TRUE 1
#define FALSE 0

/**
* -----------------------------
* 
* @ author : Tay Oh
* @ date : 17th April 2023
* @ description : A project allowing the user to do library related tasks
*                 using array, pointer, function on clang.
*                 Tasks include borrowing and returning a book,
*                 Registering a book, searching for a book and more.
* 
* ------------------------------
*
* function list:
* - main : allows the user to select the main choices
* - add_book : adds a book 
*              with the name, author and publisher 
*              into the library
* - search_book : searches for a book 
* - toggle_lent_status : toggles the book's borrowed status
*                 with the given book number
* - view_book_list : displays all books
*                    and its book number, name, publisher and author
* - view_book : returns a book
*                 with the given book number
* - str_search : searches for a keyword in a given source
* - str_len : finds the length of a string
* - lowerCase : turns all the letters lowercase
*               and adds them to a second string
*/

struct Book{
    char name[100];
    char auth[100];
    char publ[100];
    int borrowed;
    int book_num;
};

int add_book(int *numTotalBook, struct Book *bookArr);

int search_book(struct Book *bookArr, int *numTotalBook);

int toggle_lent_status(struct Book *book);

int view_book_list(struct Book *bookArr, int num_total_book);

int view_book(int book_num, struct Book book);

int str_search(char *source, char *keyword);

int str_len(char *str);

int lowerCase(char *str, char *returnStr);

int main(){
    int user_choice;
    int num_total_book = 0;
    int exit_flag = TRUE;
    int book_num = -1;
    struct Book bookArr[100];

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
                // add a book function
                add_book(&num_total_book, bookArr);
                break;

            case 2:
                // search a book function
                search_book(bookArr, &num_total_book);

                break;

            case 3:
                // borrow a book
                printf("input: ");

                scanf("%d", &book_num);
                fflush(stdin);
                if ((book_num-1) >= 0 && (book_num-1) <= num_total_book){
                    toggle_lent_status( &( bookArr[book_num-1] ) );
                } else {
                    printf("number has to be over 0 and below %d\n", num_total_book);
                }


                break;

            case 4:
                // return a book 
                printf("input: ");

                scanf("%d", &book_num);
                fflush(stdin);
                if ((book_num-1) >= 0 && (book_num-1) <= num_total_book){
                    toggle_lent_status( &( bookArr[book_num-1] ) );
                } else {
                    printf("number has to be over 0 and below %d\n", num_total_book);
                }

                break;

            case 5:
                // view list
                view_book_list(bookArr, num_total_book);
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

int add_book(int *numTotalBook, struct Book *bookArr){
    struct Book book;

    // *** BUG: when inputting things in scanf
    // after space is pressed
    // input is terminated

    // inputs the book's name
    printf("Please enter the book\'s name: ");
    scanf("%s", book.name);
    fflush(stdin);

    // inputs the book's author    
    printf("Please enter the book\'s author: ");
    scanf("%s", book.auth);
    fflush(stdin);

    // inputs the book's publisher    
    printf("Please enter the book\'s publisher: ");
    scanf("%s", book.publ);
    fflush(stdin);

    book.borrowed = 0;
    book.book_num = *numTotalBook;

    bookArr[*numTotalBook] = book;

    (*numTotalBook)++;

    printf("adding succesful!\n");

    return TRUE;
}

int view_book(int book_num, struct Book book){

    printf(" ================================ \n" );
    printf(" Book number: %d\n", book_num+1);
    printf(" Book name: %s\n", book.name);
    printf(" Author name: %s\n", book.auth);
    printf(" Publisher name: %s\n", book.publ);
    printf(" Borrowed Status: %s\n", (book.borrowed)? "Borrowed": "Available");
    printf(" ˜================================ \n" );

    return TRUE;
}

int view_book_list(struct Book *bookArr, int num_total_book ){
    
    printf(" book list \n" );
    printf(" total %d ea \n", num_total_book );

    for(int book_num=0; book_num < num_total_book; book_num++){
        view_book(book_num, bookArr[book_num]);
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
    char lSource[source_len];
    char lKeyword[keyword_len];

    // printf("Source: %s\n", source);
    // printf("Keyword: %s\n", keyword);

    // turns variables case in sensitive
    lowerCase(source, lSource);
    lowerCase(keyword, lKeyword);

    // printf("lSource: %s\n", lSource);
    // printf("lKeyword: %s\n", lKeyword);
    
    for(int s_char = 0; s_char < source_len; s_char++){
        // printf("== outer : s_char: %c, char num: %d\n", source[s_char], s_char);
        
        flag = 1;
        for(int k_char = 0; k_char < keyword_len; k_char++){
            // printf("== inner :k_char: %c, char num: %d\n", keyword[k_char], k_char);
            if( lSource[s_char+k_char]!= lKeyword[k_char]){
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

int search_book(struct Book *bookArr, int *numTotalBook){
    int user_input;
    char user_search[100];

    int is_find = 0;
    int count_of_find = 0;

    printf("How do you want to search for a book?\n");
    printf("1: By book name\n");
    printf("2: By author name\n");
    printf("3: By publisher name\n");
    scanf("%d", &user_input);

    switch(user_input){
        case 1:
            // book name
            printf("input: ");
            scanf("%s", user_search);
            fflush(stdin);

            for(int book_num = 0; book_num < *numTotalBook; book_num++){
                is_find = str_search(bookArr[book_num].name, user_search);

                if(is_find){
                    count_of_find++;
                    view_book(book_num, bookArr[book_num]);
                }

            }

            break;

        case 2:
            // author name

            printf("input: ");
            scanf("%s", user_search);
            fflush(stdin);

            for(int book_num = 0; book_num < *numTotalBook; book_num++){
                is_find = str_search(bookArr[book_num].auth, user_search);

                if(is_find){
                    count_of_find++;
                    view_book(book_num, bookArr[book_num]);
                }

            }

            break;

        case 3:
            // publisher name
            printf("input: ");
            scanf("%s", user_search);
            fflush(stdin);

            for(int book_num = 0; book_num < *numTotalBook; book_num++){
                is_find = str_search(bookArr[book_num].publ, user_search);

                if(is_find){
                    count_of_find++;
                    view_book(book_num, bookArr[book_num]);
                }

            }

            break;

        default:
            printf("input numbers from 1-3\n");
            break;
    }

    return TRUE;
}

int toggle_lent_status(struct Book *book){
    book -> borrowed = !(book -> borrowed);

    return TRUE;
}

int lowerCase(char *str, char *returnStr){
    int len = str_len(str);

    // printf("len: %d\n", str_len(str));
    for(int pos = 0; pos < len; pos++){
        // printf("str[pos]: %c %d\n", str[pos], str[pos]);

        if( ( 64 < str[pos] ) && ( 91 > str[pos] ) ){
            // printf("%c -> ", str[pos]);
            returnStr[pos] = str[pos]+32;
            // printf("%c\n", returnStr[pos]);
        } else{
            returnStr[pos] = str[pos];
        }

    }

    return TRUE;
}