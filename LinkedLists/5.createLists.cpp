#include <iostream>

struct ListNode {
    int data;
    ListNode* next;
    
    explicit ListNode(int val = 0) : data(val), next(nullptr) {}
};


ListNode* createList(){
    return nullptr;
}


template<typename T, typename... Rest>
ListNode* createList(const T& first, const Rest&... rest){
    ListNode* head = new ListNode(first);
    head->next = createList(rest...);
    return head;
}



void printList(ListNode* head) {
    while(head != nullptr) {
        std::cout << head->data <<' ';
        head = head->next;
    }
}

void deleteList(ListNode* head) {
    while(head != nullptr) {
        ListNode* tmp = head;
        head = head->next;
        delete tmp;
    }
}


int main() {
    ListNode* head = createList(1, 2, 3, 4, 5);
    printList(head);

    deleteList(head);
}