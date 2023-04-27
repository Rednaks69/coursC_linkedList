#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int val;
    struct node *next;
} node_gen;

void print_list(node_gen *head)
{
    node_gen *current = head;
    while (current != NULL)
    {
        printf("%d\n", current->val);
        current = current->next;
    }
}

void push_last(node_gen *head, int valeur)
{
    node_gen *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = (node_gen *)malloc(sizeof(node_gen));
    current->next->val = valeur;
    current->next->next = NULL;
}
void push_first(node_gen **head, int valeur)
{
    node_gen *new_node;
    new_node = (node_gen *)malloc(sizeof(node_gen));

    new_node->next = (*head);
    new_node->val = valeur;
    (*head) = new_node;
}

int pop_last(node_gen *head)
{
    int valeur = -1;
    node_gen *current = head;
    if (head == NULL)
    {
        return -1;
    }
    while (current->next->next != NULL)
    {
        current = current->next;
    }

    valeur = current->next->val;
    current->next = NULL;
    return valeur;
}

int pop_first(node_gen **head)
{
    int valeur = 0;

    if (head == NULL)
    {
        return -1;
    }
    valeur = (*head)->val;
    (*head) = (*head)->next;
    // free(head);
    return valeur;
}

int pop_by_index(node_gen **head, int n)
{
    int i = 0;
    int valeur = 0;
    node_gen *current = *head;
    node_gen *tempsNode = NULL;
    if (n == 0)
    {
        return pop_first(head);
    }
    for (i = 0; i < n - 1; i++)
    {
        if (current->next == NULL)
        {
            return -1;
        }
        current = current->next;
    }

    tempsNode = current->next;
    valeur = tempsNode->val;
    current->next = tempsNode->next;
    free(tempsNode);
    // valeur = current->next->val;
    // current->next = current->next->next;
    // free(current->next);
    return valeur;
}
int main()
{

    node_gen *head = NULL;
    head = (node_gen *)malloc(sizeof(node_gen));
    head->val = 1;
    head->next = (node_gen *)malloc(sizeof(node_gen));
    head->next->val = 2;
    head->next->next = (node_gen *)malloc(sizeof(node_gen));
    head->next->next->val = 3;
    head->next->next->next = NULL;
    print_list(head);
    printf("-----------------\n");
    push_last(head, 12);
    print_list(head);
    printf("-----------------\n");
    push_first(&head, 22);
    print_list(head);
    printf("-----------------\n");
    pop_last(head);
    print_list(head);
    printf("-----------------\n");
    pop_first(&head);
    print_list(head);
    printf("-----------------\n");
    pop_by_index(&head, 1);
    print_list(head);
    return 0;
}