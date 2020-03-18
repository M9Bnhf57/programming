// Dmitry Diordichuk
// cort@mail.ru
// Wed Mar 18 20:14:12 STD 2020

#include "dr_list.h"
#include "dr_print.h"

void	dr_push_tail(t_list *list, int number)
{
	t_list	*new_tail;

	new_tail = dr_create_node(number);
	if (new_tail)
	{
		while (list->next != NULL)
			list = list->next;
		list->next = new_tail;
	}
}

t_list	*dr_create_node(int number)
{
	t_list	*new_node;

	new_node = (t_list*)malloc(sizeof(t_list));
	if (new_node)
	{
		new_node->next = NULL;
		new_node->number = number;
	}
	return (new_node);
}

void	dr_print_list(t_list *list)
{
	t_list *temp;

	if (list)
	{
		temp = list;
		while (temp->next != NULL)
		{
			dr_putnbr(temp->number);
			dr_putstr(", ");
			temp = temp->next;
		}
		dr_putnbr(temp->number);
		dr_putstr(".\n");
	}
}

void	dr_push_head(t_list **list, int number)
{
	t_list *new_head;

	new_head = dr_create_node(number);
	if (new_head && list)
	{
		new_head->next = *list;
		*list = new_head;
	}
}

int	dr_list_size(t_list *list)
{
	int size;

	if (list)
	{
		size = 0;
		while (list->next != NULL)
		{
			list = list->next;
			size++;
		}
		return (++size);
	}
	return (-1);
}

t_list	*dr_list_last(t_list *list)
{
	if (list)
	{
		while (list->next != NULL)
			list = list->next;
	}
	return (list);
}

void	dr_list_clear(t_list **list)
{
	if (*list)
	{
		while ((*list)->next != NULL)
		{
			while ((*list)->next->next != NULL)
				(*list) = (*list)->next;
			free((*list)->next);
			(*list)->next = NULL;
		}
		free(*list);
		*list = NULL;
	}
}

t_list	*dr_list_at(t_list *list, unsigned int nbr)
{
	unsigned int i;

	i = 0;
	while (list->next != NULL)
	{
		if (i == nbr - 1)
			return (list);
		list = list->next;
		i++;
	}
	if (i == nbr - 1)
		return (list);
	return (list = NULL);
}

