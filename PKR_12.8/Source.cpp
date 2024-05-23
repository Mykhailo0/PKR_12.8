// main.cpp
#include <iostream>
#include <fstream>
#include "LinkedList.h"
#include "Windows.h"

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Node* lst = NULL;
    std::ifstream file("text.txt");
    int num;
    while (file >> num) {
        push(&lst, num);
    }
    std::cout << "������� ������:\n";
    printList(lst);
    Node* rearranged = rearrangeList(lst);
    std::cout << "�������� ������:\n";
    printList(rearranged);
    return 0;
}