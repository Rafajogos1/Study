#include <stdio.h>
#include <stdlib.h>

/* Structs can have a pointer to another of its kind, creating what is called a "linked list". */

typedef struct lst /* This struct has only 2 values. An integer variable and a pointer to another struct of the same type. */
{
	int			data;
	struct lst	*next;
}lst;

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
}

/* This function prints the contents of each node of the linked list. */
/* @param *head The head of the linked list to be printed. */
void	print_list(lst *head)
{
	while (head)
	{
		printf("Value: %i\n", head->data);
		head = head->next;
	}
}

/* This function frees the memory allocated for each node of the linked list. */
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
	lst *list;

	list = NULL;
	append_node(&list, 1);
	append_node(&list, 2);
	append_node(&list, 50);
	append_node(&list, -2234);
	append_node(&list, 32634);
	append_node(&list, 0);
	print_list(list);
	free_list(&list);
}