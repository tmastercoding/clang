#include <stdio.h>
#include <stdlib.h>

// book structure
struct BOOK {
    char book_name[30];
    char auth_name[30];
    char publ_name[30];
    int borrowed;
};

typedef struct BOOK BOOK;

// get the length of a string
int str_len(char *str);

// compare two strings
int compare(char *str1, char *str2);

// register a book
int register_book(BOOK *book_list, int *nth);

// search for a book in book_list
int search_book(BOOK *book_list, int total_num_book);

// borrow a book
int borrow_book(BOOK* book_list);

// return a book
int return_book(BOOK *book_list);

int main(){
    // the capacity of library
    int capacity;

    // number of books
    int num_total_book = 0;

    // create book_list
    BOOK *book_list;

    // assign memory to the list
    printf("Please tell me the maximum storage of your library: ");
    scanf("%d", &capacity);
    book_list = (BOOK *)malloc(sizeof(BOOK) * capacity);

    // the menu user selected
    int user_choice;
    
    int flag = 1;

    while (flag){
        printf("Library managing system\n");
        printf("Select your menu: \n");
        printf("1. add a book\n");
        printf("2. search for a book\n");
        printf("3. borrow a book \n");
        printf("4. return a book\n");
        printf("5. quit the program\n");
        scanf("%d", &user_choice);

        switch(user_choice){
            case 1: 
                // add a book
                register_book(book_list, &num_total_book);
                break;

            case 2:
                // search for a book
                search_book(book_list, num_total_book);
                break;

            case 3:
                // borrow a book
                borrow_book(book_list);
                break;

            case 4:
                // return a book
                return_book(book_list);
                break;

            case 5:
                // quit program
                flag = 0;
                break;
        }
    }

    free(book_list);   
   
    return 0;
}

int str_len(char *str){
    int size = 0;

    // while str is not null
    while(*str != '\0'){
        str++;
        // add 1 to size
        size++;
    }

    return size;
}

int compare(char *str1, char *str2) {
    // if sizes do not match
    if(str_len(str1) != str_len(str2)){
        return 0;
    }
    
    // go through str1
    while (*str1){
        // if char of str1 is not the
        // same as str 2, return false
        if(*str1 != *str2){
            return 0;
        }

        str1++;
        str2++;
    }

    // if while loop reached the end 
    // return true
    if(*str2 == '\0') return 1;

    // else return false
    return 0;
}

int register_book(BOOK *book_list, int *nth) {
    // input book name
    printf("Book name: ");
    scanf("%s", book_list[*nth].book_name);
    
    // input book author
    printf("Book author: ");
    scanf("%s", book_list[*nth].auth_name);

    // input book publisher
    printf("Book publisher: ");
    scanf("%s", book_list[*nth].publ_name);

    // set the book to unborrowed
    book_list[*nth].borrowed = 0;

    // move the cursor
    (*nth)++;

    return 0;
}

int search_book(BOOK *book_list, int total_num_book){
    // input for the mode
    int user_input;
    // index
    int i;
    // keyword
    char user_search[30];
    // flag found match 
    int flag = 0;

    // which mode to use
    printf("How do you want to search?\n");
    printf("1. book title search\n");
    printf("2. author search\n");
    printf("3. publisher search\n");
    scanf("%d", &user_input);

    // what is the keyword?
    printf("Please input the keyword you want to search for: ");
    scanf("%s", user_search);
    
    printf("search results: \n");

    // case 1

    if(user_input == 1){
        // i goes through num_total book
        // comparing each book with the
        // user_search

        for (i = 0; i < total_num_book; i++){
            // if comparison is true
            if (compare(book_list[i].book_name, user_search)){
                // print information
                printf("number: %d // book title: %s // author: %s // publisher: %s \n",
                       i+1, book_list[i].book_name, 
                            book_list[i].auth_name, 
                            book_list[i].publ_name);
                
                // switch flag on
                flag++;
            }
        }
    // case 2
    } else if(user_input == 2){
        // i goes through num_total book
        // comparing each book with the
        // user_search

        for (i = 0; i < total_num_book; i++){
            // if comparison is true
            if (compare(book_list[i].auth_name, user_search)){
                // print information
                printf("number: %d // book title: %s // author: %s // publisher: %s \n",
                       i+1, book_list[i].book_name, 
                            book_list[i].auth_name, 
                            book_list[i].publ_name);
                
                // switch flag on
                flag++;
            }
        }    
    // case 3    
    } else if(user_input == 3){
        // i goes through num_total book
        // comparing each book with the
        // user_search

        for (i = 0; i < total_num_book; i++){
            // if comparison is true
            if (compare(book_list[i].publ_name, user_search)){
                // print information
                printf("number: %d // book title: %s // author: %s // publisher: %s \n",
                       i+1, book_list[i].book_name, 
                            book_list[i].auth_name, 
                            book_list[i].publ_name);
                
                // switch flag on
                flag++;
            }
        }
    }

    // if there was no match
    if(!flag){
        printf("Sorry! We couldn\'t find a match!\n");
    }

    return 0;
}

int borrow_book(BOOK* book_list){ 
    // the book number given from the user
    int book_num;

    // get user input
    printf("Please input the number of the book\nyou wish to borrow: ");
    scanf("%d", &book_num);

    // check if book is borrowed
    if(book_list[book_num].borrowed){
        printf("The book has already been borrowed!");
    } else{
        // set the book status to borrowed
        book_list[book_num].borrowed = 1;
        printf("The book has been successfully borrowed!");
    }

    return 0;
}

int return_book(BOOK* book_list){ 
    // the book number given from the user
    int book_num;

    // get user input
    printf("Please input the number of the book\nyou wish to return: ");
    scanf("%d", &book_num);

    // check if book is returned
    if(!(book_list[book_num].borrowed)){
        printf("The book has already been returned!");
    } else{
        // set the book status to returned
        book_list[book_num].borrowed = 0;
        printf("The book has been successfully returned!");
    }

    return 0;
}