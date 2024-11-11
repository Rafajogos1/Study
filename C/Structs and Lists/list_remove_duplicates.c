#include <stdio.h>
#include <stdlib.h>

typedef struct	Node {
	int 			data;
	struct Node*	next;
} Node;

/* This function recives the value to be stored and dynamically allocates memory, creating a new "node". */
/* @param value The value to be stored into the node. */
/* @return A node with "value" stored in it.*/
Node	*create_node(int value)
{
	Node	*new_node;

	new_node = malloc(sizeof(Node));
	if (!new_node)
		return NULL;
	new_node->data = value;
	new_node->next = NULL;
	return (new_node);
}

/* This function can both start a new list and attack new values. */
/* @param **head The first member of the list.*/
/* @param value The value to be stored into the node. */
void	append_node(Node **head, int value)
{
	Node	*new_node;
	Node	*current;

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
void	print_list(Node *head)
{
	while (head)
	{
		printf("Value: %i\n", head->data);
		head = head->next;
	}
}

/* This function frees the memory allocated for each node of the linked list. */
void	free_list(Node **head)
{
	Node	*next;

	while (*head)
	{
		next = (*head)->next;
		free(*head);
		*head = next;
	}
}

int	check_duplicates(Node *head, int num)
{
	head = head->next;
	while (head)
	{
		if (head->data == num)	
			return (1);
		else
			head = head->next;
	}
	return (0);
}

void	list_remove_duplicates(Node **head)
{
	Node	*list = *head;
	Node	*temp;
	int		current;

	if (*head == NULL || (*head)->next == NULL)
		return;
	while ((*head)->next)
	{
		current = (*head)->data;
		if (check_duplicates(*head, current))
		{
			if ((*head)->data == current)
			{	
				temp = (*head)->next->next;
				free((*head)->next);
				(*head)->next = temp;
				*head = list;
			}
			*head = list;
			list_remove_duplicates(head);
		}
		else
			*head = (*head)->next;
	}
	*head = list;
}

int	main()
{
	Node *list;

	list = NULL;
	append_node(&list, 1);
	append_node(&list, 2);
	append_node(&list, 2);
	append_node(&list, 2);
	append_node(&list, 3);
	append_node(&list, 4);
	append_node(&list, 4);
	append_node(&list, 4);
	append_node(&list, 4);
	append_node(&list, 4);
	append_node(&list, 5);
	append_node(&list, 5);
	append_node(&list, 6);
	append_node(&list, 7);
	append_node(&list, 8);
	append_node(&list, 8);
	append_node(&list, 8);
	append_node(&list, 8);
	append_node(&list, 8);
	append_node(&list, 8);
	append_node(&list, 8);
	append_node(&list, 8);
	append_node(&list, 8);
	append_node(&list, 8);
	append_node(&list, 8);
	print_list(list);
	printf("\n");
	list_remove_duplicates(&list);
	print_list(list);
	free_list(&list);
}