#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
	Book** p = (Book**)malloc(3 * sizeof(Book*));
	for (int i = 0; i<3; i++)
		p[i] = (Book*)malloc(sizeof(Book));
	strcpy(p[0]->title, "Don Quixote");
	p[0]->pages = 1000;
	p[0]->price = 750.0;
	strcpy(p[1]->title, "Oblomov");
	p[1]->pages = 400;
	p[1]->price = 250.0;
	strcpy(p[2]->title, "The Odyssey");
	p[2]->pages = 500;
	p[2]->price = 500.0;
	for (int i = 0; i<3; i++)
		print_book(*(p[i]));
	free(p);
}