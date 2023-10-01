#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// book structure
struct BOOK {
    char book_name[30];
    char auth_name[30];
    char publ_name[30];
    int borrowed;
};
typedef struct BOOK BOOK;

// register a book
int register_book(BOOK *book_list, int *nth);
// search for a book in book_list
int search_book(BOOK *book_list, int total_num_book);
// borrow a book
int borrow_book(BOOK* book_list);
// return a book
int return_book(BOOK *book_list);
// ouput the book list to book_list.txt
int print_book_list(BOOK *book_list, int total_num_book);
// get info of a book from book_list.txt
int retrieve_book_info(BOOK **book_list, int *total_num_book, int capacity);
// compare two strings
int compare(char *str1, char *str2);

int main(){

    // printf("Number of books: %lu\n", strlen("Number of books: "));
    // printf("No. %lu\n", strlen("No. "));
    // printf("Book name: %lu\n", strlen("Book name: "));
    // printf("Author name: %lu\n", strlen("Author name: "));
    // printf("Publisher name: %lu\n", strlen("Publisher name: "));
    // printf("Borrowed: %lu\n", strlen("Borrowed: "));
    // printf("--------------------------------%lu\n", strlen("--------------------------------"));

    // the capacity of library
    int capacity;
    // number of books
    int num_total_book = 0;

    // create book_list
    BOOK *book_list;
    // index
    int i;

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
        printf("1. Add a book\n");
        printf("2. Search for a book\n");
        printf("3. Borrow a book \n");
        printf("4. Return a book\n");
        printf("5. Output the information of the books to book_list.txt\n");
        printf("6. Get the information of the books from book_list.txt to replace book list\n");
        printf("7. Print the list of books\n");
        printf("8. Quit the program\n");

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
                // Output the information of the books
                // to book_list.txt
                print_book_list(book_list, num_total_book);
                break;

            case 6:
                // Get the information of the books from
                // book_list.txt to replace book list
                retrieve_book_info(&book_list, &num_total_book, capacity);
                break;

            case 7:
                // print all the book info
                for(i = 0; i < num_total_book; i++){
                    // output book info
                    printf("No. %d\nBook name: %s\nAuthor name: %s\nPublisher name: %s\n", 
                                i+1,
                                book_list[i].book_name,
                                book_list[i].auth_name,
                                book_list[i].publ_name);

                    // output borrowed status
                    printf("Borrowed: ");
                    if(book_list[i].borrowed){
                        printf("YES\n");
                    } else{
                        printf("NO\n");
                    }
                    printf("--------------------------------\n");
                }
                break;

            case 8:
                // quit program
                flag = 0;
                break;

            default:
                printf("Please only input options from 1-8!\n");
                        }
    }

    free(book_list);   
   
    return 0;
}

int print_book_list(BOOK *book_list, int total_num_book){
    // open the file book_list.txt to write
    FILE *fp = fopen("./book_list.txt", "w");
    int i;

    // if file does not exist
    if(fp == NULL){
        // print error and quit function
        printf("Output error!\n");
        return -1;
    }

    // input the number of books into file
    fprintf(fp, "Number of books: %d\n", total_num_book);

    // go through book_list
    for(i = 0; i < total_num_book; i++){
        // output book info
        fprintf(fp, "No. %d\nBook name: %s\nAuthor name: %s\nPublisher name: %s\n", 
                    i+1,
                    book_list[i].book_name,
                    book_list[i].auth_name,
                    book_list[i].publ_name);

        // output borrowed status
        fprintf(fp, "Borrowed: ");
        if(book_list[i].borrowed){
            fprintf(fp, "YES\n");
        } else{
            fprintf(fp, "NO\n");
        }

        fprintf(fp, "--------------------------------\n");
    }

    printf("output completed!\n");
    fclose(fp);

    return 0;
}

int retrieve_book_info(BOOK **book_list, int *total_num_book, int capacity){
    // open a file to read
    FILE *fp = fopen("book_list.txt", "r");
    int total_book;
    int i;
    char str[10];

    // check if file exists
    if(fp == NULL){ 
        // print error and quit program
        printf("Couldn\'t find the file! \n");
        return -1;
    }
    
    // STR LENGTH REFERENCE
    // "Number of books: " = 
    // "No. " = 417
    // "Book name: " = 11
    // "Author name: " = 13
    // "Publisher name: " = 16
    // "Borrowed: " = 10
    // dashes = 32

    // get the total book number
    fseek(fp, 17, SEEK_CUR);
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

    char test_str[100];

    for(i = 0; i<total_book; i++){
        // "No. "
        fseek(fp, 4, SEEK_CUR);
        fgets(test_str, 10, fp);

        // "Book name: "
        fseek(fp, 11, SEEK_CUR) ;
        fscanf(fp, "%s", (*book_list)[i].book_name);

        // "Author name: "
        fseek(fp, 13, SEEK_CUR);
        fscanf(fp, "%s", (*book_list)[i].auth_name);

        // "Publisher name: "
        fseek(fp, 16, SEEK_CUR);
        fscanf(fp, "%s", (*book_list)[i].publ_name);
        
        // "Borrowed"
        fseek(fp, 10, SEEK_CUR);
        fgets(test_str, 100, fp);
        if(compare(test_str, "YES")){
            (*book_list)[i].borrowed = 1;
        } else{
            (*book_list)[i].borrowed = 0;
        }

        // dashes
        fseek(fp, 33, SEEK_CUR);
    }
    printf("successful import!");

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
    book_num-=1;
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
    book_num-=1;
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

int compare(char *str1, char *str2) {
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