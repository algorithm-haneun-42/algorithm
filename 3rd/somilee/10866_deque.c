#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;
int *deque;
int f = 0;
int r = 0;
int size;

int  push_front(void)
{
	int num;
	scanf("%d", &num);

	f = (f - 1 + size) % size;
	deque[f] = num;
	return (0);
}

int push_back(void)
{
	int num;
	scanf("%d", &num);

	deque[r] = num;
	r = (r + 1) % size;
	return (0);
}

int pop_front(void)
{
	if ((r - f + size) % size == 0)
		return (-1);
	f = (f + 1) % size;
	return (deque[(f - 1 + size) % size]);
}

int  pop_back(void)
{
	if ((r - f + size) % size == 0)
		return (-1);
	r = (r - 1 + size) % size;
	return (deque[r]);
}

int empty(void)
{
	if ((r - f + size) % size == 0)
		return (1);
	return (0);
}

int front(void)
{
	if ((r - f + size) % size == 0)
		return (-1);
	return (deque[f]);
}

int back(void)
{
	if((r - f + size) % size == 0)
		return (-1);
	return (deque[(r - 1 + size) % size]);
}

int main(void)
{
	scanf("%d", &n);
	size = n;
	deque = (int *)malloc(sizeof(int) * n);

	char cmd[11];
	for(int i = 0; i < n; i ++)
	{
		scanf("%s", cmd);
		if (strcmp(cmd, "push_front") == 0)
			push_front();
		else if (strcmp(cmd, "push_back") == 0)
			push_back();
		else if (strcmp(cmd, "pop_front") == 0)
			printf("%d\n", pop_front());
		else if (strcmp(cmd, "pop_back") == 0)
			printf("%d\n", pop_back());
		else if (strcmp(cmd, "size") == 0)
			printf("%d\n", (r - f + size) % size);
        else if (strcmp(cmd, "empty") == 0)
            printf("%d\n", empty());
        else if (strcmp(cmd, "front") == 0)
            printf("%d\n", front());
        else
			printf("%d\n", back());
	}
	free(deque);
	return (0);
}
