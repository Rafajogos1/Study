#include <stdlib.h>
#include <stdio.h>

/* Lists can be doubly-linked, meaning that each node has a pointer to the previous node as well as the next one. */
/* While they consume more memory, they're useful for when traversal through nodes is needed to be done both ways. */
/* They're also more complex to handle, but also have their own advantages over single-linked lists. */

typedef struct lst
{
	int			data;
	struct lst	*previous;
	struct lst	*next;
}lst;

/* This function prints a "new line" character. */
/* Its purpose is just to make it quicker to write. */
void	print_nl(void)
{
	printf("\n");
}

/* This function recives the value to be stored and dynamically allocates memory, creating a new "node". */
/* @param value The value to be stored into the node. */
/* @return A node with "value" stored in it.*/
lst	*create_node(int value)
{
	lst	*new_node;

	new_node = malloc(sizeof(lst));
	if (!new_node)
		return NULL;
	new_node->data = value;
	new_node->previous = NULL;
	new_node->next = NULL;
	return (new_node);
}

/* This function can both start a new list and attack new values. */
/* @param **head The first member of the list.*/
/* @param value The value to be stored into the node. */
void	append_node(lst **head, int value)
{
	lst	*new_node;
	lst	*current;

	new_node = create_node(value);
	if (!new_node)
		return;
	if (*head == NULL)
	{
		*head = new_node;
		return;
	}
	current = *head;
	while (current->next != NULL)
		current = current->next;
	current->next = new_node;
	new_node->previous = current;
}

/* This function prints the contents of each node and the previous one of the linked list. */
/* @param *head The head of the linked list to be printed. */
void	print_list(lst *head)
{
	while (head)
	{
		if (head->previous)
			printf("Value: %i Previous: %i\n", head->data, head->previous->data);
		else
			printf("Value: %i Previous: NULL\n", head->data);
		head = head->next;
	}
}

/* This function acts simillarly to "print_list", but in reverse. */
/* This function exists to show case how doubly-linked lists can be traversed both ways. */
/* @param *head The head of the linked list to be printed. */
void	print_reverse(lst *head)
{
	printf("Printing in reverse...\n");
	while (head->next)
		head = head->next;
	while (head->previous)
	{
		if (head->next)
			printf("Value: %i Next: %i\n", head->data, head->next->data);
		else
			printf("Value: %i Next: NULL\n", head->data);
		head = head->previous;
	}
	printf("Value: %i Next: %i\n", head->data, head->next->data); /* Since the function is printing in reverse, once it reaches the beginning, */
																/* another call needs to be made for the first node, as it doesn't have a "previous" pointer. */
}

/* This function frees the memory allocated for each node of the linked list. */
/* Since the freeing already works one.way, there's no need to adapt for doubly-linked lists. */
void	free_list(lst **head)
{
	lst	*next;

	while (*head)
	{
		next = (*head)->next;
		free(*head);
		*head = next;
	}
}

int	main()
{
	lst	*list;

	list = NULL;
	append_node(&list, 1);
	append_node(&list, 2);
	append_node(&list, 50);
	append_node(&list, -2234);
	append_node(&list, 32634);
	append_node(&list, 0);
	print_list(list);
	print_nl();
	print_reverse(list);
	free_list(&list);
}