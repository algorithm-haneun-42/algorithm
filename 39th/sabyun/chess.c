#include <stdio.h>
#include <stdlib.h>
#define IFN 0x3FFFFF
typedef struct point{
	int x;
	int y;
	struct point *next;
}t_point;

int q_empty(t_point *q)
{
	if(!q)
		return 1;
	return 0;
}
void q_add(t_point **q, t_point *add)
{
	t_point *temp = *q;
	if(!add)
		return;
	if(!temp)
	{
		*q = add;
		return;
	}
	while(temp && temp->next != 0)
		temp = temp->next;
	temp->next = add;
}
t_point* q_pop(t_point **q)
{
	t_point *temp = *q;
	if(!temp)
		return NULL;
	if(temp && temp->next == 0)
	{
		*q = NULL;
		return (temp);
	}
	else{
		t_point *temp1 = *q;
		*q = temp1->next;
		return temp1;
	}
}

t_point* check_arr(int arr[201][201], t_point *a, int num)
{
	if((a->x > 200 || a->y > 200) || (a->x < 0 || a->y < 0))
		return NULL;
	if(arr[a->x][a->y] == IFN)
	{
		arr[a->x][a->y] = num;
		return a;
	}
	else if (arr[a->x][a->y] > num)
	{
		arr[a->x][a->y] = num;
		return a;
	}
	return NULL;
}

int main()
{
	int n;
	t_point st;
	t_point ed;
	st.next =0;
	ed.next = 0;
	scanf ("%d %d %d %d %d", &n, &st.x, &st.y , &ed.x, &ed.y);
	t_point *que = 0;
	int arr[201][201];
	for(int i = 0; i < 201; i++)
	{
		for(int j= 0; j < 201; j++)
		{
			arr[i][j] = IFN;
		}
	}
	q_add(&que,&st);
	check_arr(arr,&st,0);
	while(!q_empty(que))
	{
		t_point *temp = q_pop(&que);
		int x = temp->x;
		int y = temp->y;
		temp->next = 0;
		int num = arr[x][y];
		int dx[6] = {-2,-2,0,0,+2,+2};
		int dy[6] = {-1,+1,-2,+2,-1,+1};
		for(int i = 0; i < 6; i++)
		{
			t_point *ttemp = calloc(sizeof(t_point),1);
			ttemp->x = x+dx[i];
			ttemp->y = y+dy[i];
			t_point *add = check_arr(arr,ttemp,num +1);
			q_add(&que,add);
		}
	}
	if(arr[ed.x][ed.y] == IFN)
		printf("-1\n");
	else
		printf("%d\n",arr[ed.x][ed.y]);
}