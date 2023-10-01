# premitive type    
int, char, pointer, .....

# define datatype    
using struct 

# howto struct    
```c

struct book {
    int book_number,
    char name[30],
    char author[30],
    char publisher[30],
    int borrowed;
}

const int total_size = 100;
struct book books[ total_size ];
books[0].name
books[0].author
books[0].borrowed
.... etc

struct book* p_book;
```
