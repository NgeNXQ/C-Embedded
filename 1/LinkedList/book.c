#include <stdio.h>
#include <stdlib.h>
#include "book.h"

struct book* create_book(const char* const title, const float price, const int number_of_pages, const char* const language, const float weight, const int publication_year)
{
    struct book* new_book = (struct book*)malloc(sizeof(struct book));

    if (new_book == NULL) 
    {
        perror("Memory allocation failed.");
        return NULL;
    }

    new_book->title = (char*)malloc(strlen(title) + 1);
    new_book->language = (char*)malloc(strlen(language) + 1);

    if (new_book->title == NULL || new_book->language == NULL)
    {
        perror("Memory allocation failed.");
        free(new_book->title);
        free(new_book->language);
        free(new_book);
        return NULL;
    }

    strcpy(new_book->title, title);
    new_book->price = price;
    new_book->number_of_pages = number_of_pages;
    strcpy(new_book->language, language);
    new_book->weight = weight;
    new_book->publication_year = publication_year;

    return new_book;
}

void print_book(const struct book* const book)
{
    if (book == NULL)
    {
        printf("book is null.");
        return;
    }

    printf("Title: %s.\n", book->title);
    printf("Price: %4.2f$.\n", book->price);
    printf("Number of pages: %d.\n", book->number_of_pages);
    printf("Language: %s.\n", book->language);
    printf("Weight: %4.3f kg.\n", book->weight);
    printf("Publication year: %d.\n", book->publication_year);
}
