#ifndef BOOK_H
#define BOOK_H

struct book
{
    char* title;
    float price;
    int number_of_pages;
    char* language;
    float weight;
    int publication_year;
};

struct book* book_initialize(const char* const title, const float price, const int number_of_pages, const char* const language, const float weight, const int publication_year);
void book_print(const struct book* const book);

#endif // BOOK_H