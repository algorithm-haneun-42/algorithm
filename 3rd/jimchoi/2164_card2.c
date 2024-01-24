#include <stdlib.h>
#include <stdio.h>

typedef struct	__node {
	int            data;
	struct __node    *next; // 두ㅣ
	struct __node    *prev; //앞
	int					idx;
}	node;

typedef struct	{
	node        *front;
	node        *rear;
	int        size;
	char		name;
}	dlist;

void add_front(dlist *list, int data)
{
	node	*new_node;

	new_node = (node *)malloc(sizeof(node));
	new_node->data = data;
	new_node->next = NULL;
	new_node->prev = NULL;
	if (list->size == 0) {
		list->front = new_node;
		list->rear = new_node;
	} else {
		new_node->next = list->front;
		list->front->prev = new_node;
		list->front = new_node;
	}
	list->size++;
	new_node->idx = list->size;
}

void add_rear(dlist *list, int data)
{
	node	*new_node;

	new_node = (node *)malloc(sizeof(node));
	new_node->data = data;
	new_node->next = NULL;
	new_node->prev = NULL;
	if (list->size == 0) {
		list->front = new_node;
		list->rear = new_node;
	} else {
		list->rear->next = new_node;
		new_node->prev = list->rear;
		list->rear = new_node;
	}
	list->size++;
}

void del_front(dlist *list)
{
	node	*tmp;

	if (list->size > 1)
	{
		tmp = list->front;
		list->front = list->front->next;
		list->front->prev = NULL;
		free(tmp);
	}
	else
		free(list->front);
	list->size--;
}

void del_rear(dlist *list)
{
	node    *tmp;

	if (list->size > 1)
	{
		tmp = list->rear;
		list->rear = list->rear->prev;
		list->rear->next = NULL;
		free(tmp);
	}
	else
		free(list->rear);
	list->size--;
}

int main ()
{
	dlist    *list=malloc(sizeof(dlist));

	int n, i;
	scanf("%d", &n);
	while(i<n)
	{
		add_rear(list, i+1);
		i++;
	}
	node *tmp= list->front;
	while(tmp->next != NULL)
	{
		// printf("%d\n", tmp->data);
		tmp = tmp->next;
		del_front(list);
		add_rear(list, tmp->data);
		tmp = tmp->next;
		del_front(list);
	}
	tmp = list->front;
	while(tmp)
	{
		printf("%d\n", tmp->data);
		tmp = tmp->next;
	}
	free(list->front);
	free(list);
}