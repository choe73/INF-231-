#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void inserer_tete(Node** last, int val) {
    Node* new = malloc(sizeof(Node));
    new->data = val;
    if (!*last) {
        new->next = new;
        *last = new;
    } else {
        new->next = (*last)->next;
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
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != last->next);
    printf("(circulaire)\n");
}
//petit exemple
int main() {
    Node* liste = NULL;
    inserer_tete(&liste, 3);
    inserer_queue(&liste, 5);
    inserer_tete(&liste, 1);
    inserer_queue(&liste, 7);
    afficher(liste);
    return 0;
}
