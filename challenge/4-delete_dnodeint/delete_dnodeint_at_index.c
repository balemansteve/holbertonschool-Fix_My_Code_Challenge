#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *current = *head;
    unsigned int i = 0;

    if (*head == NULL)
        return (-1);

    /* Find the node to delete */
    while (current != NULL && i < index)
    {
        current = current->next;
        i++;
    }

    /* If index is out of bounds */
    if (current == NULL)
        return (-1);

    /* Update previous node's next pointer */
    if (current->prev != NULL)
        current->prev->next = current->next;
    else
        *head = current->next;  /* Deleting the head node */

    /* Update next node's prev pointer */
    if (current->next != NULL)
        current->next->prev = current->prev;

    free(current);
    return (1);
}