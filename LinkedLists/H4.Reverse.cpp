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


ListNode* reverseList(ListNode* head) {
    if(head == nullptr){
        return head;
    }

    ListNode* prev = head,*curr = head->next,*ptr = head->next;
    prev->next = nullptr;
    while(ptr!=nullptr){
        ptr = curr->next;
        curr->next = prev;
        prev = curr;
        curr = ptr;
    }

    head = prev;
    return head;
}

int main() {
    ListNode* head = createList(1, 2, 3, 4, 5, 6);
    printList(head);
    head = reverseList(head);
    printList(head);

    deleteList(head);
}