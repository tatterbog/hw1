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


void deleteList(ListNode* head) {
    while(head != nullptr) {
        ListNode* tmp = head;
        head = head->next;
        delete tmp;
    }
}

size_t DecimalConverter(ListNode* head) {
    size_t result = 0;
    while (head != nullptr) {
        result = result * 2 + head->data;
        head = head->next;
    }
    return result;
}


int main() {
    ListNode* head = createList(1, 0, 1, 0);
    std::cout << DecimalConverter(head) << '\n';

    deleteList(head);
}