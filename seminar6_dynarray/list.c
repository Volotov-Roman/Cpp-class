#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

Node* init_node(int n)
{
	Node* p = (Node*)malloc(sizeof(Node));
	p->value = n;
	p->prev = NULL;
	p->next = NULL;
	return p;
}

List init(size_t n)
{
	List res;

	if (n==0)
	{
		res.head = NULL;
		res.tail = NULL;
	}

	else
	{
		Node* current = init_node(0);
		res.head = current;
		for (int i = 1; i < n; ++i)
		{
			Node* new = init_node(0);
			current->next = new;
			new->prev = current;
			current = new;
		}
		res.tail = current;
	}

	res.size = n;
	return res;
}

void print(const List* pl)
{
    Node* current_node = pl->head;
    while (current_node != NULL) {
        printf("%i ", current_node->value);
        current_node = current_node->next;
    }
    printf("\n");
}

void push_back(List* pl, int value)
{
	Node* new = init_node(value);
	if (pl->size)
	{
		new->prev = pl->tail;
		pl->tail->next = new;
		pl->tail = new;
	}
	else
	{
		pl->head = new;
		pl->tail = new;
	}
	pl->size++;
}

int pop_back(List* pl)
{
	assert(pl->size > 0);
	int res = pl->tail->value;
	if (pl->size > 1)
	{
		pl->tail = pl->tail->prev;
		free(pl->tail->next);
		pl->tail->next = NULL;
	}
	else if (pl->size == 1)
	{
		free(pl->tail);
		pl->head = NULL;
		pl->tail = NULL;
	}
	pl->size--;
	return res;
}

void push_front(List* pl, int value)
{
	Node* new = init_node(value);
	if (pl->size)
	{
		new->next = pl->head;
		pl->head->prev = new;
		pl->head = new;
	}
	else
	{
		pl->head = new;
		pl->tail = new;
	}
	pl->size++;
}

int pop_front(List* pl)
{
	assert(pl->size > 0);
	int res = pl->head->value;
	if (pl->size > 1)
	{
		pl->head = pl->head->next;
		free(pl->head->prev);
		pl->head->prev = NULL;
	}
	else if (pl->size == 1)
	{
		free(pl->head);
		pl->head = NULL;
		pl->tail = NULL;
	}
	pl->size--;	
	return res;
}

Node* erase(List* pl, Node* p)
{
	if (p->next)
	{
		p->next->prev = p->prev;
		p->prev->next = p->next;
	}
	else
	{
		pl->tail = p->prev;
		p->prev->next = NULL;
	}

	Node* res = p->next;
	free(p);
	p = NULL;
	pl->size--;
	return res;
}

void splice(List* plist, Node* p, List* pother)
{
	if (p->prev)
	{
		pother->head->prev = p->prev;
		p->prev->next = pother->head;
		pother->tail->next = p;
		p->prev = pother->tail;
	}
	else   // p == plist->head
	{
		plist->head = pother->head;
		p->prev = pother->tail;
	}
	plist->size += pother->size;
	pother->size = 0;
	pother->head = NULL;
	pother->tail = NULL;
}

void destroy(List* pl)
{
	Node* current = pl->head;
	while (current->next != NULL)
	{
		current = current->next;
		free(current->prev);
	}
	free(current);
	pl->head = NULL;
	pl->tail = NULL;
	pl->size = 0;
}

void advance(Node** pp, size_t n)
{
	for (int i = 0; i < n; ++i)
	{
		if ((*pp)->next == NULL)
		{
			*pp = NULL;
			return;
		}
		*pp = (*pp)->next;
	}
}