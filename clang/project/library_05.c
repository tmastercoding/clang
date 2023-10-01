#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
* -----------------------------
* 
* @ author : Tay Oh
* @ date : 30th July 2023
* @ description : A project allowing the user to do library related tasks
*                 using a book structures, pointers, functions,
                  files and memory allocation on clang.
* 
* ------------------------------
*
* function list:
* - main : allows the user to select the choices on the menu
* - register_book : register a book by inputting name, author
*              and publisher to a book structure that 
*              goes inside the library
* - search_book : search a book by searching with a name, 
*                 an author or a publisher and comparing
*                 this with books in library
*                 outputs book info
* - toggle_lent_status : toggle the lent status of a book, 
*                        from the library by providing a book_num
* - export_book_list : export the entire book library to a file
*                     called book_list.txt that is a backup of the library
* - import_book_list : import a book_library from a file called
*                      book_list.txt and replace existing library
*                      with the file
* - get_info : print the information of all books in the library
* - compare : compare two strings, 
*             returns 0 if unequal and 1 if equal
*/

// book structure
struct BOOK {
    char book_name[30];
    char auth_name[30];
    char publ_name[30];
    int borrowed;
};

typedef struct BOOK BOOK;

// register a book
int register_book(
    BOOK *book_list, 
    int *nth);

// search for a book in book_list
int search_book(
    BOOK *book_list, 
    int total_num_book);

// toggle a book's borrowed status
int toggle_lent_status(
    BOOK* book_list,
    int book_num);

// ouput the book list to book_list.txt
int export_book_list(
    BOOK *book_list, 
    int total_num_book);

// get info of a book from book_list.txt
int import_book_list(
    BOOK **book_list, 
    int *total_num_book,         
    int capacity);

// get info of books and print
int get_info(
    BOOK *book_list,
    int total_num_book);

// compare two strings
int compare(
    char *str1, 
    char *str2);

// select main menu
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
    // flag for program
    int flag = 1;
    // the book number given from the user
    int book_num;

    while (flag){
        printf("Library managing system\n");
        printf("Select your menu: \n");
        printf("1. Add a book\n");
        printf("2. Search for a book\n");
        printf("3. Borrow a book \n");
        printf("4. Return a book\n");
        printf("5. Output the information of the books to book_list.txt\n");
        printf("6. Get the information of the books from book_list.txt to replace book list\n");
        printf("7. Print the list of books\n");
        printf("8. Quit the program\n");

        // get user choice for menu
        scanf("%d", &user_choice);
        fflush(stdin);

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
                // get user input
                printf("Please input the number of the book\nyou wish to borrow: ");
                scanf("%d", &book_num);
                fflush(stdin);
                book_num-=1;
                
                // check if book is borrowed
                if(book_list[book_num].borrowed){
                    printf("The book has already been borrowed!");
                } else{
                    // set the book status to borrowed
                    toggle_lent_status(book_list, book_num);
                    printf("The book has been successfully borrowed!");
                }

                break;

            case 4:
                // return a book

                // get user input
                printf("Please input the number of the book\nyou wish to return: ");
                scanf("%d", &book_num);
                fflush(stdin);

                book_num-=1;
                // check if book is returned
                if(!(book_list[book_num].borrowed)){
                    printf("The book has already been returned!");
                } else{
                    // set the book status to returned
                    toggle_lent_status(book_list, book_num);
                    printf("The book has been successfully returned!");
                }                
                break;

            case 5:
                // Output the information of the books
                // to book_list.txt
                export_book_list(book_list, num_total_book);
                break;

            case 6:
                // Get the information of the books from
                // book_list.txt to replace book list
                import_book_list(&book_list, &num_total_book, capacity);
                break;

            case 7:
                // print all the book info
                get_info(book_list, num_total_book);
                break;

            case 8:
                // quit program
                flag = 0;
                break;

            default:
                // if input is not 1-8, output error message
                printf("Please only input options from 1-8!\n");
        }
    }

    // free memory of book_list when ended
    free(book_list);   
   
    return 0;
}

int export_book_list(BOOK *book_list, 
                     int total_num_book ){

    // open the file book_list.txt to write
    FILE *fp = fopen("./book_list.txt", "w");
    // index
    int idx;

    // if file does not exist
    if(fp == NULL){
        // print error and quit function
        printf("Output error!\n");
        return -1;
    }

    // input the number of books into file
    fprintf(fp, "Number of books: %d\n", total_num_book);

    // go through book_list
    for(idx = 0; idx < total_num_book; idx++){
        // output book info
        fprintf(fp, "No. %d\nBook name: %s\nAuthor name: %s\nPublisher name: %s\n", 
                    idx + 1,
                    book_list[idx].book_name,
                    book_list[idx].auth_name,
                    book_list[idx].publ_name);

        // output borrowed status
        fprintf(fp, "Borrowed: ");
        if(book_list[idx].borrowed){
            fprintf(fp, "YES\n");
        } else{
            fprintf(fp, "NO\n");
        }

        // dashes to seperate
        fprintf(fp, "--------------------------------\n");
    }

    printf("output completed!\n");
    fclose(fp);

    return 0;
}

int import_book_list(BOOK **book_list, 
                     int *total_num_book, 
                     int capacity ){

    // open the file book_list.txt to read
    FILE *fp = fopen("book_list.txt", "r");
    // number of books
    int total_book;
    // index
    int idx;

    // check if file exists
    if(fp == NULL){ 
        // print error and quit program
        printf("Couldn\'t find the file! \n");
        return -1;
    }
    
    // STR LENGTHS
    int len_no_of_book = strlen("Number of books: ");
    int len_no = strlen("No. ");
    int len_book_name = strlen("Book name: ");
    int len_auth_name = strlen("Author name: ");
    int len_publ_name = strlen("Publisher name: ");
    int len_borrowed = strlen("Borrowed: ");
    int len_dashes = 33;

    // get the total book number
    fseek(fp, len_no_of_book, SEEK_CUR);
    fscanf(fp, "%d", &total_book);

    // replace total book num 
    (*total_num_book) = total_book;

    // delete existing book_list
    free(*book_list);

    // if capacity user selected is
    // less than total book number
    if(capacity < total_book){
        // print error and quit
        printf("ERROR\n\
                The capacity you selected is less than the\n\
                number of books in the file you selected.\n");
        return -1;
    }

    // allocate memory again
    (*book_list) = (BOOK *)malloc(sizeof(BOOK) * capacity);

    // buffer
    char buffer[100];

    // go through file and input information to book_list
    for(idx = 0; idx<total_book; idx++){
        // skip "No. "
        fseek(fp, len_no, SEEK_CUR);
        fgets(buffer, 10, fp);
        
        // skip "Book name: "
        fseek(fp, len_book_name, SEEK_CUR) ;
        // input book name
        fscanf(fp, "%[^\n]%*c", (*book_list)[idx].book_name);

        // skip "Author name: "
        fseek(fp, len_auth_name, SEEK_CUR);
        // input author name
        fscanf(fp, "%[^\n]%*c", (*book_list)[idx].auth_name);

        // skip "Publisher name: "
        fseek(fp, len_publ_name, SEEK_CUR);
        // input publisher name
        fscanf(fp, "%[^\n]%*c", (*book_list)[idx].publ_name);
        
        // skip "Borrowed: "
        fseek(fp, len_borrowed, SEEK_CUR);
        fgets(buffer, 100, fp);

        // input borrowed status
        if(compare(buffer, "YES")){
            (*book_list)[idx].borrowed = 1;
        } else{
            (*book_list)[idx].borrowed = 0;
        }

        // dashes
        fseek(fp, len_dashes, SEEK_CUR);
    }
    printf("successful import!");
    fclose(fp);

    return 0;
}

int register_book(BOOK *book_list, 
                  int *nth ){

    // input book name
    printf("Book name: ");

    // [^\n] tells to stop inputting if inputted 
    // char is \n and \n only
    // %*c makes the new line discarded
    scanf("%[^\n]%*c", book_list[*nth].book_name);
    fflush(stdin);

    // input book author
    printf("Book author: ");
    scanf("%[^\n]%*c", book_list[*nth].auth_name);
    fflush(stdin);

    // input book publisher
    printf("Book publisher: ");
    scanf("%[^\n]%*c", book_list[*nth].publ_name);
    fflush(stdin);

    // set the book to unborrowed
    book_list[*nth].borrowed = 0;

    // move the cursor
    (*nth)++;

    return 0;
}


int search_book(BOOK *book_list, 
                int total_num_book ){

    // input for the mode
    int user_input;
    // index
    int idx;
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
    fflush(stdin);

    // what is the keyword?
    printf("Please input the keyword you want to search for: ");
    scanf("%[^\n]%*c", user_search);
    fflush(stdin);

    printf("search results: \n");


    switch(user_input){
        case 1:
            // book name comparison
            // i goes through num_total book
            // comparing each book with the
            // user_search

            for (idx = 0; idx < total_num_book; idx++){
                // if comparison is true
                if (compare(book_list[idx].book_name, user_search)){
                    // print information
                    printf("number: %d // book title: %s // author: %s // publisher: %s \n",
                            idx+1, 
                            book_list[idx].book_name, 
                            book_list[idx].auth_name, 
                            book_list[idx].publ_name);
                    
                    // switch flag on
                    flag++;
                }
            }
            break;

        case 2:
            // book author comparison
            // i goes through num_total book
            // comparing each book with the
            // user_search

            for (idx = 0; idx < total_num_book; idx++){
                // if comparison is true
                if (compare(book_list[idx].auth_name, user_search)){
                    // print information
                    printf("number: %d // book title: %s // author: %s // publisher: %s \n",
                            idx+1, 
                            book_list[idx].book_name, 
                            book_list[idx].auth_name, 
                            book_list[idx].publ_name);
                    
                    // switch flag on
                    flag++;
                }
            }
            break;

        case 3:
            // publisher name comparison
            // i goes through num_total book
            // comparing each book with the
            // user_search

            for (idx = 0; idx < total_num_book; idx++){
                // if comparison is true
                if (compare(book_list[idx].publ_name, user_search)){
                    // print information
                    printf("number: %d // book title: %s // author: %s // publisher: %s \n",
                            idx+1, 
                            book_list[idx].book_name, 
                            book_list[idx].auth_name, 
                            book_list[idx].publ_name);
                    
                    // switch flag on
                    flag++;
                }
            }
            break;
        
        default:
            printf("Please only choose between options 1-3\n");
            printf("search results: \n");
    }

    // if there was no match
    if(!flag){
        printf("Sorry! We couldn\'t find a match!\n");
    }

    return 0;
}

int toggle_lent_status(BOOK* book_list, 
                       int book_num ){

    // make the borrowed status opposite of what it was
    book_list[book_num].borrowed = !(book_list[book_num].borrowed);
    return 0;
}

int compare(char *str1, 
            char *str2 ){

    // if sizes do not match
    if(strlen(str1) != strlen(str2)){
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

int get_info(BOOK *book_list, 
             int num_total_book ){
                
    for(int idx = 0; idx < num_total_book; idx++){
        // output book info
        printf("No. %d\nBook name: %s\nAuthor name: %s\nPublisher name: %s\n", 
                    idx+1,
                    book_list[idx].book_name,
                    book_list[idx].auth_name,
                    book_list[idx].publ_name);

        // output borrowed status
        printf("Borrowed: ");

        if(book_list[idx].borrowed){
            printf("YES\n");
        } else{
            printf("NO\n");
        }
        printf("--------------------------------\n");
    }

    return 0;
}