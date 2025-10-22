//
// Created by gabri on 22-10-2025.
//

#pragma once
class Node {
public:
    int value;
    int x;
    int y;
    Node* next;

    Node(int value, int x, int y) {
        this->value = value;
        this->x = x;
        this->y = y;
        this->next = nullptr;
    }
};
