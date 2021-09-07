/*
** EPITECH PROJECT, 2021
** list lib adapted
** File description:
** liblist
*/

#include "my.h"
#include "shell.h"

void list_push(list_t **head, var_t *data)
{
    list_t *node = malloc(sizeof(list_t));

    if (node == NULL)
        return;
    node->data = data;
    node->next = (*head);
    (*head) = node;
}

void list_stack(list_t **head, var_t *data)
{
    list_t *node = malloc(sizeof(list_t));
    list_t *temp = (*head);

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

void list_destroy(list_t *head)
{
    list_t *temp;

    if (head == NULL)
        return;
    while (head != NULL) {
        temp = head;
        clear_node(temp);
        head = head->next;
        free(temp);
    }
}

void list_remove(list_t **head, int index)
{
    list_t *temp = (*head);
    list_t *next = NULL;

    if ((*head) == NULL)
        return;
    if (index == 0) {
        (*head) = temp->next;
        clear_node(temp);
        free(temp);
        return;
    }
    for (int i = 0; (temp != NULL) && (i < index - 1); i++)
        temp = temp->next;
    if (temp == NULL || temp->next == NULL)
        return;
    next = temp->next->next;
    clear_node(temp->next);
    free(temp->next);
    temp->next = next;
}

void list_remove_from_key(list_t **head, char *key)
{
    int index = -1;
    list_t *temp = (*head);
    list_t *next = NULL;

    if ((*head) == NULL) return;
    for (int i = 0; temp != NULL; temp = temp->next, i++) {
        if (temp->next == NULL) break;
        if (my_strcmp(temp->next->data->key, key) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) return;
    if (index == 0) {
        (*head) = temp->next;
        clear_node(temp), free(temp);
        return;
    }
    if (temp == NULL || temp->next == NULL) return;
    next = temp->next->next;
    clear_node(temp->next), free(temp->next), temp->next = next;
}