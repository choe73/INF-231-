#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void supprimer_occurrences(Node** head, int val) {
    while (*head && (*head)->data == val) {
        Node* temp = *head;
        *head = (*head)->next;
        free(temp);
    }
    Node* current = *head;
    while (current && current->next) {
        if (current->next->data == val) {
            Node* temp = current->next;
            current->next = temp->next;
            free(temp);
        } else {
            current = current->next;
        }
    }
}

void afficher(Node* head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void inserer_fin(Node** head, int val) {
    Node* new = malloc(sizeof(Node));
    new->data = val;
    new->next = NULL;
    if (!*head) {
        *head = new;
        return;
    }
    Node* temp = *head;
    while (temp->next) temp = temp->next;
    temp->next = new;
}
//petit exemple
int main() {
    Node* liste = NULL;
    inserer_fin(&liste, 3);
    inserer_fin(&liste, 5);
    inserer_fin(&liste, 3);
    inserer_fin(&liste, 7);
    inserer_fin(&liste, 3);
    printf("Liste avant suppression : ");
    afficher(liste);
    supprimer_occurrences(&liste, 3);
    printf("Liste après suppression : ");
    afficher(liste);
    return 0;
}
