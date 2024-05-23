#pragma once

struct Node {
    int data;
    Node* next;
    Node* prev;
};

void push(Node** head_ref, int new_data);
void printList(Node* node);
Node* rearrangeList(Node* head);