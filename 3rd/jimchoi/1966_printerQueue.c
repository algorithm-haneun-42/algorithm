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
void print_num(dlist *list, int size, int print, int *result);
void clear(dlist *list);

int num[10] = {0, };
int count;
int list_size;
int main ()
{

	int n, i, size, print;
	i = 0;
	// scanf("%d", &n);
	n = 3;
	size = 1;
	print = 0;

	dlist *list = (dlist *)malloc(sizeof(dlist));
	int result[n];
	while(i<n)
	{
		// dlist    *list=malloc(sizeof(dlist));
		// list = (dlist *)malloc(sizeof(dlist));
		// printf("문서개수 : ");
		// scanf("%d %d", &size ,&print);
		print_num(list,size, print, result);
		if(list)
			free(list);
		i++;

	}
	for(i=0; i<n; i++)
        printf("%d\n", result[i]);
    return 0;

}


void clear(dlist *list)
{
	node *tmp = list->front;
	node *del;
	while (tmp!= NULL)
	{
		del = tmp->next;
		if (tmp)
			free(tmp);	
		tmp = del;
	}
}

void print_num(dlist *list, int size, int print, int *result)
{
		list->size = 0;

	int i= 0;
	int tmp = 1;
	while(i < size)
	{
		// printf(" 중요도 : ");
		// scanf("%d", &tmp);
		add_rear(list, tmp);
		if (i == print)
			list->rear->idx = 100;
		num[tmp] += 1;
		i++;
		tmp++;
	}
	i = 9;
	int printCount = 1;
	node *temp = list->front;
	while(i > -1)
	{
		if (num[i] == 0)
		{
			i--;
			continue;
		}	
		if(temp->data == i)
		{
			if(temp->idx == 100)
				{
					result[count] = printCount;
					// printf("%d\n", result[count]);
					count++; 
					clear(list);
					return ;
				}
			del_front(list);
			temp = list->front;
			printCount++;
			num[i] --;
		}
		else
		{
			add_rear(list, temp->data);
			if(temp->idx == 100)
				list->rear->idx = 100;
			del_front(list);
			temp = list->front;
		}
		
	}
}
