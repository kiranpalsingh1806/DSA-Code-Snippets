#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
};

bool isCircular(struct Node *head) {
    if(head == NULL) {
        return true;
    }
    struct Node *node = head->next;

    while(node != NULL && node != head) {
        node = node->next;
    }

    return (node == head);
}

Node *newNode(int data) {
    struct Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}

int main() {
    struct Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);

    if(isCircular(head)) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }

    head->next->next->next->next = head;

    if(isCircular(head)) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}