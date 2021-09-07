/*
** EPITECH PROJECT, 2021
** list lib adapted
** File description:
** liblist
*/

#include "my.h"
#include "shell.h"

void clear_argnode(argslist_t *arg)
{
    free(arg->data->token);
    free(arg->data);
}

void listarg_stack(argslist_t **head, arg_t *data)
{
    argslist_t *node = malloc(sizeof(argslist_t));
    argslist_t *temp = (*head);

    if (node == NULL)
        return;
    node->data = data;
    node->next = NULL;
    if ((*head) == NULL)
        (*head) = node;
    else {
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = node;
    }
}

void listarg_destroy(argslist_t *head)
{
    argslist_t *temp;

    if (head == NULL)
        return;
    while (head != NULL) {
        temp = head;
        clear_argnode(temp);
        head = head->next;
        free(temp);
    }
}