#include <string.h>
#include <stdlib.h>
#include "lists.h"

/**
 * add_dnodeint_end - Add a node at the end of a list
 *
 * @head: The address of the pointer to the first element of the list
 * @n: The number to store in the new element
 *
 * Return: A pointer to the new element
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new;
	dlistint_t *l;

	/* Vérifie si le pointeur head est valide */
	if (head == NULL)
		return (NULL);

	/* Allocation de mémoire pour le nouveau nœud */
	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
	{
		return (NULL);
	}

	/* Initialisation complète du nœud */
	new->n = n;
	new->next = NULL;
	new->prev = NULL;  /* Sécurisation */

	/* Si la liste est vide, le nouveau nœud devient le head */
	if (*head == NULL)
	{
		*head = new;
		return (new);
	}

	/* Sinon, parcourir la liste jusqu'au dernier nœud */
	l = *head;
	while (l->next != NULL)
	{
		l = l->next;
	}

	/* Relier le nouveau nœud */
	l->next = new;
	new->prev = l;

	return (new);
}
