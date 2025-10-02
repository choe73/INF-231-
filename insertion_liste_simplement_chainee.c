nclude <stdio.h>
#include <stdlib.h>
typedef struct Node
{    int data;   
struct Node* next;
} 
Node;
void inserer_trie(Node** head, int val) 
{    Node* new = malloc(sizeof(Node));    new->data = val;    new->next = NULL;  
if (!*head || val < (*head)->data) 
{        new->next = *head;        *head = new;        return;    }   
Node* current = *head;   
while (current->next && current->next->data < val)     
current = current->next;    new->next = current->next;    current->next = new;}
void afficher(Node* head) {    while (head) {        printf("%d -> ", head->data);     
head = head->next;    }  
printf("NULL\n");}
//petit exemple iciint main() {    Node* liste = NULL;    
inserer_trie(&liste, 2);   
inserer_trie(&liste, 3);   
inserer_trie(&liste, 7);   
inserer_trie(&liste, 4); 
afficher(liste);
return 0;
}
