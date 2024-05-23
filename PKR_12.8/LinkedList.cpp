#include "LinkedList.h"
#include <cstddef>
#include <iostream>

void push(Node** head_ref, int new_data) {
    Node* new_node = new Node;
    new_node->data = new_data;
    new_node->next = (*head_ref);
    new_node->prev = NULL;
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;
    (*head_ref) = new_node;
}

void printList(Node* node) {
    while (node != NULL) {
        std::cout << node->data << " ";
        node = node->next;
    }
    std::cout << std::endl;
}

Node* rearrangeList(Node* head) {
    int sum = 0, count = 0;
    Node* temp = head;
    while (temp) {
        sum += temp->data;
        count++;
        temp = temp->next;
    }
    double avg = static_cast<double>(sum) / count;
    Node* less = NULL, * greater = NULL;
    temp = head;
    while (temp) {
        if (temp->data < avg)
            push(&less, temp->data);
        else
            push(&greater, temp->data);
        temp = temp->next;
    }
    if (less == NULL)
        return greater;
    Node* last = less;
    while (last->next)
        last = last->next;
    last->next = greater;
    if (greater != NULL)
        greater->prev = last;
    return less;
}
