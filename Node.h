//
// Created by gabri on 15-10-2025.
//

#pragma once
#include <iterator>
#include <bits/ranges_base.h>

class Node {
    public:
    int x;
    int y;
    int value;
    Node* next;

    Node(int val, int xPos, int yPos) {
        value = val;
        x = xPos;
        y = yPos;
        next = nullptr;
    }
};

