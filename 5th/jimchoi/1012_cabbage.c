
#include <stdio.h>

typedef struct	__node {
	int            x;
	int            y;
	struct __node    *next; // 두ㅣ
	struct __node    *prev; //앞
	int					idx;
}	node;

typedef struct	{
	node        *front;
	node        *rear;
	int        size;
	char		name;
}	Qlist;

void add_front(Qlist *list, int x, int y)
{
	node	*new_node;

	new_node = (node *)malloc(sizeof(node));
	new_node->x = x;
	new_node->y = y;
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

void add_rear(Qlist *list, int x, int y)
{
	node	*new_node;

	new_node = (node *)malloc(sizeof(node));
	new_node->x = x;
	new_node->y = y;
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

void del_front(Qlist *list)
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



int arr[50][50] = {0,};
int vis[50][50] = {0,};

int T, M, N, K;
int main()
{
	Qlist *Q = malloc(sizeof(Qlist)); 
	int x; 
	int y;
	int i = 0;
	scanf("%d", &T);

	while(T--)
	{
		scanf("%d %d %d", &M, &N, &K);

        while(i < K)
		{
			scanf("%d %d", &x, &y);
			arr[x][y] = 1;
			i++;
		}
		i = 0;
		// while(i < M * N)
		// {

		// }
		add_front(Q, x, y);
		while(Q->front != 0)
		{
			vis[Q->front->x][Q->front->y] = 1;
		}
	}

}

void plantCabbage(int x, int y)
{

}

