#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct	__node {
	int            data;
	struct __node    *next; // 두ㅣ
	struct __node    *prev; //앞
	int					idx;
}	node;

typedef struct	{
	node        *front;
	node        *back;
	int        size;
	char		name;
}	dlist;




void push_front(dlist *list, int data)
{
	node	*new_node;

	new_node = (node *)malloc(sizeof(node));
	new_node->data = data;
	new_node->next = NULL;
	new_node->prev = NULL;
	if (list->size == 0) {
		list->front = new_node;
		list->back = new_node;
	} else {
		new_node->next = list->front;
		list->front->prev = new_node;
		list->front = new_node;
	}
	list->size++;
	new_node->idx = list->size;
}

void push_back(dlist *list, int data)
{
	node	*new_node;

	new_node = (node *)malloc(sizeof(node));
	new_node->data = data;
	new_node->next = NULL;
	new_node->prev = NULL;
	if (list->size == 0) {
		list->front = new_node;
		list->back = new_node;
	} else {
		list->back->next = new_node;
		new_node->prev = list->back;
		list->back = new_node;
	}
	list->size++;
}

void pop_front(dlist *list)
{
	node	*tmp;

	if (list->size > 0)
	{
		tmp = list->front;
		list->front = list->front->next;
		list->front->prev = NULL;
		printf("%d\n", tmp->data);
		free(tmp);
	}
	else
	{
		printf("-1\n");
		free(list->front);
	}
	list->size--;
}

void pop_back(dlist *list)
{
	node    *tmp;

	if (list->size > 0)
	{
		tmp = list->back;
		list->back = list->back->prev;
		list->back->next = NULL;
		printf("%d\n", tmp->data);

		free(tmp);
	}
	else
	{
		printf("-1\n");
		free(list->back);
	}
	list->size--;
}
void size(dlist *list)
{
	printf("%d\n", list->size);
}

void empty(dlist *list)
{
	if (list->size == 0)
        printf("1\n");
    else
        printf("0\n");
}

void front(dlist *list)
{
	if (list->size == 0)
		printf("-1\n");
	else
		printf("%d\n", list->front->data);
}

void back(dlist *list)
{
	if (list->size == 0)
		printf("-1\n");
	else
	printf("%d\n", list->back->data);
}

int main()
{
	dlist    *list = malloc(sizeof(dlist));
	list->size = 0;
	int n;
	scanf("%d", &n);
	int i =0;
	char str[20];
	// char *str;
	int num = 0;
	while(i < n)
	{
		scanf("%s", str);

		if (strcmp(str, "push_front") == 0)
		{
			scanf("%d", &num);
			push_front(list, num);
		}
		else if (strcmp(str, "push_back") == 0)
			{
			scanf("%d", &num);
			push_back(list, num);
		}
		else if (strcmp(str, "pop_front") == 0)
			pop_front(list);
		else if (strcmp(str, "pop_back") == 0)
			pop_back(list);
		else if (strcmp(str, "size") == 0)
			size(list);
		else if (strcmp(str, "empty") == 0)
			empty(list);
		else if (strcmp(str, "front") == 0)
			front(list);
		else if (strcmp(str, "back") == 0)
			back(list);
		i++;
		strcpy(str, "");
	}
}

