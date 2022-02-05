#include <stdlib.h>
#include <stdio.h>

typedef struct s_garbage
{
	void *ptr;
	struct s_garbage *next;
}   t_garbage;


t_garbage *create_garbage_list(void *ptr, t_garbage *head)
{
	t_garbage *garbage;

	garbage = malloc(sizeof(t_garbage));
	garbage->ptr = ptr;
	garbage->next = NULL;
	while(head && head->next)
		head = head->next;
	if (head)
		head->next = garbage;
	return(garbage);
}

void free_garbage_list(t_garbage * head)
{
	t_garbage *tmp;
	while(head)
	{
		free(head->ptr);
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

int main(void)
{
	t_garbage *garbage;

	garbage = create_garbage_list(NULL, NULL);

	char *ptr = malloc(1000);
	create_garbage_list(ptr, garbage);
	ptr = malloc(1500);
	create_garbage_list(ptr, garbage);
	ptr = malloc(3000);
	create_garbage_list(ptr, garbage);
	ptr = malloc(4500);
	create_garbage_list(ptr, garbage);
	ptr = malloc(6000);
	create_garbage_list(ptr, garbage);

	free_garbage_list(garbage);
}
