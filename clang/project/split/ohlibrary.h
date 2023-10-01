#define TRUE 1
#define FALSE 0

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