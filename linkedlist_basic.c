#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

// Insert at beginning
struct node* createNodeAtBeginning(struct node* head, int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (!newNode) {
        printf("Memory allocation error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = head;
    return newNode;
}

// Insert after a node with value = pos
struct node* createNodeAtMiddle(struct node* head, int data, int pos) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (!newNode) {
        printf("Memory allocation error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;

    struct node* temp = head;
    while (temp) {
        if (temp->data == pos) {
            newNode->next = temp->next;
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }
    return head;
}

// Insert at end
struct node* createNodeAtEnd(struct node* head, int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (!newNode) {
        printf("Memory allocation error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;

    if (!head) return newNode;

    struct node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Delete first node
struct node* deleteFirstNode(struct node* head) {
    if (head == NULL) return NULL;
    struct node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

// Delete a specific node by value
struct node* deleteSpecificNode(struct node* head, int pos) {
    struct node* temp = head;
    while (temp != NULL && temp->next != NULL) {
        if (temp->next->data == pos) {
            struct node* toDelete = temp->next;
            temp->next = temp->next->next;
            free(toDelete);
            break;
        }
        temp = temp->next;
    }
    return head;
}

// ✅ Delete last node
struct node* deleteLastNode(struct node* head) {
    if (head == NULL) {
        return NULL;
    }

    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    struct node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
    return head;
}

// Display the list
void Display(struct node* head) {
    struct node* temp = head;
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Driver code
int main() {
    struct node* head = NULL;

    head = createNodeAtBeginning(head, 5);
    head = createNodeAtBeginning(head, 2);
    head = createNodeAtBeginning(head, 1);
    Display(head);  // 1 -> 2 -> 5 -> NULL
    printf("##########\n");

    head = createNodeAtMiddle(head, 3, 2);
    head = createNodeAtMiddle(head, 4, 3);
    Display(head);  // 1 -> 2 -> 3 -> 4 -> 5
    printf("##########\n");

    head = createNodeAtEnd(head, 6);
    head = createNodeAtEnd(head, 7);
    Display(head);  // 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7
    printf("##########\n");

    head = deleteFirstNode(head);
    Display(head);  // 2 -> 3 -> 4 -> 5 -> 6 -> 7
    printf("##########\n");

    head = deleteSpecificNode(head, 7);
    Display(head);  // 2 -> 3 -> 4 -> 5 -> 6
    printf("##########\n");

    head = deleteLastNode(head);
    Display(head);  // 2 -> 3 -> 4 -> 5 -> NULL

    return 0;
}
