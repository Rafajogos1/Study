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

int	check_sort(Node *head)
{
	while(head->next)
	{
		if (head->data > head->next->data)
			return(0);
		else
			head = head->next;
	}
	return (1);
}

void	list_sort(Node **head)
{
	Node	*list = *head;
	int		current;

	current = 0;
	while (!check_sort(*head))
	{
		while ((*head)->next)
		{
			if ((*head)->data > (*head)->next->data)
			{
				current = (*head)->data;
				(*head)->data = ((*head)->next)->data;
				((*head)->next)->data = current;
			}
			*head = (*head)->next;
		}
		*head = list;
	}
}

int	main()
{
	Node *list;
	int	nodes;

	list = NULL;
	append_node(&list, 1);
	append_node(&list, 2);
	append_node(&list, 50);
	append_node(&list, -2234);
	append_node(&list, 32634);
	append_node(&list, 0);
	print_list(list);
	printf("\n");
	list_sort(&list);
	print_list(list);
	free_list(&list);
}