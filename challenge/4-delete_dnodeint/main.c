#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * main - point d'entrée pour tester la liste doublement chaînée
 *
 * Return: Toujours EXIT_SUCCESS
 */
int main(void)
{
    dlistint_t *head;

    head = NULL;
    add_dnodeint_end(&head, 0);
    add_dnodeint_end(&head, 1);
    add_dnodeint_end(&head, 2);
    add_dnodeint_end(&head, 3);
    add_dnodeint_end(&head, 4);
    add_dnodeint_end(&head, 98);
    add_dnodeint_end(&head, 402);
    add_dnodeint_end(&head, 1024);

    /* Affiche la liste au départ */
    print_dlistint(head);
    printf("-----------------\n");

    /*
     * On supprime l'élément à l'index 5
     * Si la suppression réussit (retour = 1), on réaffiche la liste
     */
    if (delete_dnodeint_at_index(&head, 5) == 1)
    {
        print_dlistint(head);
        printf("-----------------\n");
    }

    /*
     * À partir d'ici, on supprime plusieurs fois l'index 0 (toujours la tête),
     * en ne réaffichant qu'en cas de succès.
     */
    if (delete_dnodeint_at_index(&head, 0) == 1)
    {
        print_dlistint(head);
        printf("-----------------\n");
    }

    if (delete_dnodeint_at_index(&head, 0) == 1)
    {
        print_dlistint(head);
        printf("-----------------\n");
    }

    if (delete_dnodeint_at_index(&head, 0) == 1)
    {
        print_dlistint(head);
        printf("-----------------\n");
    }

    if (delete_dnodeint_at_index(&head, 0) == 1)
    {
        print_dlistint(head);
        printf("-----------------\n");
    }

    if (delete_dnodeint_at_index(&head, 0) == 1)
    {
        print_dlistint(head);
        printf("-----------------\n");
    }

    if (delete_dnodeint_at_index(&head, 0) == 1)
    {
        print_dlistint(head);
        printf("-----------------\n");
    }

    /*
     * Les suppressions suivantes vont probablement échouer si la liste est déjà vide,
     * donc on NE réaffiche pas systématiquement la liste
     */
    delete_dnodeint_at_index(&head, 0);
    delete_dnodeint_at_index(&head, 0);
    delete_dnodeint_at_index(&head, 0);
    delete_dnodeint_at_index(&head, 0);
    delete_dnodeint_at_index(&head, 0);
    delete_dnodeint_at_index(&head, 0);
    delete_dnodeint_at_index(&head, 0);
    delete_dnodeint_at_index(&head, 0);
    delete_dnodeint_at_index(&head, 0);

    /* Affiche l'état final (liste vide ou contenant encore quelques éléments) */
    print_dlistint(head);

    /* Libère la mémoire */
    free_dlistint(head);

    return (0);
}
