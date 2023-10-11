#include <stdio.h>
#include <stdlib.h>
#include "book.h"
#include "linked_list.h"

int main()
{
    const struct book* book1 = book_initialize("Harry Potter and the Philosopher's Stone", 10.0f, 309, "English", 0.635f, 1997);
    const struct book* book2 = book_initialize("Harry Potter and the Chamber of Secrets", 10.0f, 341, "German", 0.635f, 1998);
    const struct book* book3 = book_initialize("Harry Potter and the Prisoner of Azkaban", 10.0f, 435, "Spanish", 0.726f, 1999);
    const struct book* book4 = book_initialize("Harry Potter and the Goblet of Fire", 15.0f, 734, "Ukrainian", 0.953f, 2000);
    const struct book* book5 = book_initialize("Harry Potter and the Order of the Phoenix", 15.0f, 870, "Italian", 0.954f, 2003);
    const struct book* book6 = book_initialize("Harry Potter and the Half - Blood Prince", 15.0f, 652, "French", 0.853f, 2005);
    const struct book* book7 = book_initialize("Harry Potter and the Deathly Hallows", 15.0f, 759, "Portuguese", 0.955f, 2007);

    struct linked_list* const books = linked_list_initialize();
    
    linked_list_free(books);

    return 0;
}
