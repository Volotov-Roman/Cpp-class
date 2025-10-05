#include <stdio.h>

struct node
{
	int value;
	struct node* ptr;
};
typedef struct node Node;

int main()
{
	Node a;
	Node b;
	Node c;
	a.value = 100;
	b.value = 200;
	c.value = 300;
	a.ptr = &b;
	b.ptr = &c;
	c.ptr = &a;
	Node* p = &a;
	while (1)
	{
		printf("%i\n", p->value);
		p = p->ptr;
	}
}