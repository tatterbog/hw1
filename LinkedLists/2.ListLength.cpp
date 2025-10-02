#include <iostream>

struct ListNode {
    int data;
    ListNode* next;
    
    explicit ListNode(int val = 0) : data(val), next(nullptr) {}
};


void deleteList(ListNode* head) {
    while(head != nullptr) {
        ListNode* tmp = head;
        head = head->next;
        delete tmp;
    }
}

size_t listLength(ListNode* head){
    size_t size = 0;
    while(head != nullptr){
        size++;
        head = head->next;
    }
    return size;
}

int main() {

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);

    std::cout << listLength(head) << '\n'; 

    deleteList(head);
    head = nullptr;
}