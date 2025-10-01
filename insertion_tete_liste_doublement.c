#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

void inserer_tete(Node** last, int val) {
    Node* new = malloc(sizeof(Node));
    new->data = val;
    if (!*last) {
        new->next = new->prev = new;
        *last = new;
    } else {
        Node* first = (*last)->next;
        new->next = first;
        new->prev = *last;
        first->prev = new;
        (*last)->next = new;
    }
}

void inserer_queue(Node** last, int val) {
    inserer_tete(last, val);
    *last = (*last)->next;
}

void afficher(Node* last) {
    if (!last) return;
    Node* temp = last->next;
    do {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while (temp != last->next);
    printf("(circulaire)\n");
}

int main() {
    Node* liste = NULL;
    inserer_tete(&liste, 3);
    inserer_queue(&liste, 5);
    inserer_tete(&liste, 1);
    inserer_queue(&liste, 7);
    afficher(liste);
    return 0;
}
