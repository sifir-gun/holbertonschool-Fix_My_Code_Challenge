#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Function to delete a node at a specific index
 *
 *
 * @head: Pointer to the head of the list
 * @index: Index of the node to delete
 *
 * Return: 1 if successful, -1 if it fails
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current;
	unsigned int i;

	if (head == NULL || *head == NULL)
		return (-1);

	current = *head;

	/* Suppression du premier nœud */
	if (index == 0)
	{
		*head = current->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(current);
		return (1);
	}

	/* Parcours jusqu'à l'index */
	for (i = 0; current != NULL && i < index; i++)
		current = current->next;

	/* Si l'index est hors limites */
	if (current == NULL)
		return (-1);

	/* Suppression du dernier nœud */
	if (current->next == NULL)
		current->prev->next = NULL;
	else
	{
		/* Mise à jour des liens pour un nœud intermédiaire */
		current->prev->next = current->next;
		current->next->prev = current->prev;
	}

	free(current);
	return (1);
}
