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

bool findNode(ListNode* head, int value){
    while(head != nullptr){
        if(head->data == value){
            return true;
        }
        head = head->next;
    }

    return false;
}


int main() {

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);

    std::cout << std::boolalpha << findNode(head, 2) << '\n'; 
    std::cout << std::boolalpha << findNode(head, 7) << '\n'; 

    deleteList(head);
    head = nullptr;
}