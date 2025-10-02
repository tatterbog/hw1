#include <iostream>

struct ListNode {
    int data;
    ListNode* next;
    
    explicit ListNode(int val = 0) : data(val), next(nullptr) {}
};


void printList(ListNode* head) {
    while(head != nullptr) {
        std::cout << head->data << ' ';
        head = head->next;
    }
    std::cout << '\n';
}

void deleteList(ListNode* head) {
    while(head != nullptr) {
        ListNode* tmp = head;
        head = head->next;
        delete tmp;
    }
}


int main() {

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    
    printList(head);

    deleteList(head);
    head = nullptr;
}