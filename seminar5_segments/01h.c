#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct book
	{
		char* title;
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
	char* q = (char*)malloc(50 * sizeof(char));
	Book* p = (Book*)malloc(sizeof(Book));
	p->title = q;
	p->pages = 1000;
	p->price = 750.0;
	strcpy(q, "Don Quixote");
	print_book(*p);
	free(p);
}