#include <stdio.h>
#include "ohlibrary.h"

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

