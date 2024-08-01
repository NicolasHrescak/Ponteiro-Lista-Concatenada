#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da lista
struct Node {
    int data;
    struct Node* next;
};

// Função para criar um novo nó
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Função para imprimir a lista
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Função para concatenar duas listas
struct Node* concatenateLists(struct Node* list1, struct Node* list2) {
    if (list1 == NULL) {
        return list2;
    }

    struct Node* current = list1;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = list2;

    return list1;
}

int main() {
    // Criando a primeira lista: 1 -> 2 -> 3
    struct Node* list1 = createNode(1);
    list1->next = createNode(2);
    list1->next->next = createNode(3);

    // Criando a segunda lista: 4 -> 5 -> 6
    struct Node* list2 = createNode(4);
    list2->next = createNode(5);
    list2->next->next = createNode(6);

    // Imprimindo as listas originais
    printf("Lista 1: ");
    printList(list1);

    printf("Lista 2: ");
    printList(list2);

    // Concatenando as listas
    list1 = concatenateLists(list1, list2);

    // Imprimindo a lista concatenada
    printf("Lista Concatenada: ");
    printList(list1);

    return 0;
}
