#include<stdio.h>
typedef struct {
    t_node *head;
    t_node *tail;
    int size;
} t_list;
typedef struct _node {
    int item;
    struct _node* next;
} t_node;

//complexidade O(n²)
void sort(t_list* list) {
    if (list->head == NULL || (list->head)->next == NULL) {
        return;
    }
    t_node* ordenados = NULL;
    t_node* current = list->head;
    while (current != NULL) {
        t_node* next = current->next; 
        if (ordenados == NULL || ordenados->item >= current->item) {
            current->next = ordenados;
            ordenados = current;
        } else {
            t_node* temp = ordenados;
            while (temp->next != NULL && temp->next->item < current->item) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = next; 
    }
    list->head = ordenados; 
}
