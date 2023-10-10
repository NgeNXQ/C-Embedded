#include <stdio.h>
#include <stdlib.h>
#include "book.h"
#include "linked_list.h"

int main()
{
    const struct book* book1 = create_book("Harry Potter and the Philosopher's Stone", 10.0f, 309, "English", 0.635f, 1997);
    const struct book* book2 = create_book("Harry Potter and the Chamber of Secrets", 10.0f, 341, "German", 0.635f, 1998);
    const struct book* book3 = create_book("Harry Potter and the Prisoner of Azkaban", 10.0f, 435, "Spanish", 0.726f, 1999);
    const struct book* book4 = create_book("Harry Potter and the Goblet of Fire", 15.0f, 734, "Ukrainian", 0.953f, 2000);
    const struct book* book5 = create_book("Harry Potter and the Order of the Phoenix", 15.0f, 870, "Italian", 0.954f, 2003);
    const struct book* book6 = create_book("Harry Potter and the Half - Blood Prince", 15.0f, 652, "French", 0.853f, 2005);
    const struct book* book7 = create_book("Harry Potter and the Deathly Hallows", 15.0f, 759, "Portuguese", 0.955f, 2007);

    struct linked_list* const books = initialize_linked_list();
    
    //add_last(books, book1);
    //add_last(books, book2);
    //add_last(books, book3);
    //add_last(books, book4);
    //add_last(books, book5);
    //add_last(books, book6);
    //add_last(books, book7);

    const struct book* const book2_node = add_first(books, book2);

    print_linked_list(books);

    add_first(books, book1);

    print_linked_list(books);

    const struct book* const book4_node =  add_last(books, &book4);

    print_linked_list(books);

    add_before(books, book4_node, book3);

    print_linked_list(books);

    add_after(books, book4_node, book5);

    print_linked_list(books);

    remove_first(books);

    print_linked_list(books);

    add_before(books, book2_node, book1);

    print_linked_list(books);

    add_last(books, &book6);

    print_linked_list(books);

    remove_last(books);

    print_linked_list(books);

    const struct book* const book6_node = add_last(books, &book6);

    print_linked_list(books);

    add_after(books, book6_node, &book7);

    print_linked_list(books);

    //print_linked_list(books);

    free_linked_list(books);

    return 0;
}
