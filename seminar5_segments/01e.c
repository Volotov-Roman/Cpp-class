#include <stdio.h>
#include <stdlib.h>
struct book
	{
		char title[50];
		int pages;
		float price;
	};
typedef struct book Book;
void print_book(struct book b)
{
	printf("Book info:\n");
	printf("Title: %s\nPages: %d\nPrice: %g\n\n", b.title, b.pages, b.price);
}
int main()
{
	Book** p = (Book**)malloc(sizeof(Book*));
	Book a = {"Don Quixote", 1000, 750.0};
	**p = a;
	print_book(**p);
	free(p);
}