#include <stdio.h>
#include <stdlib.h>

// Structure definition for linked list node
typedef struct s_list
{
    void *content;
    struct s_list *next;
} t_list;

// Function to create a new node
t_list *lstnew(void *content)
{
    t_list *new_node = (t_list *)malloc(sizeof(t_list));
    if (!new_node)
        return NULL;

    new_node->content = content;
    new_node->next = NULL;
    return new_node;
}

// Function to add a new node to the front of the list
void lstadd_front(t_list **head, t_list *new_node)
{
    if (!new_node)
        return;

    new_node->next = *head;
    *head = new_node;
}

// Function to print the content of the list (assuming content is of type int)
void print_list(t_list *head)
{
    t_list *current = head;
    while (current != NULL)
    {
        printf("%d -> ", *(int *)(current->content));
        current = current->next;
    }
    printf("NULL\n");
}

int main()
{
    t_list *head = NULL; // Initialize an empty list

    // Creating nodes with values 1, 2, 3, 4, 5
    for (int i = 5; i > 0; --i)
    {
        int *data = (int *)malloc(sizeof(int));
        *data = i;
        t_list *new_node = lstnew(data);
        lstadd_front(&head, new_node);
    }

    // Print the list
    printf("Linked List: ");
    print_list(head);

    // Cleanup: Free allocated memory
    t_list *current = head;
    while (current != NULL)
    {
        t_list *temp = current;
        current = current->next;
        free(temp->content); // Free the content (assuming it's dynamically allocated)
        free(temp); // Free the node itself
    }

    return 0;
}