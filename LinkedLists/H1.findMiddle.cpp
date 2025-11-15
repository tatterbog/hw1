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


ListNode* findMiddle(ListNode* head){
    ListNode* p1 = head;
    ListNode* p2 = head;
    
    while(p2 && p2->next){
        p1 = p1->next;
        p2 = p2->next->next;
    }

    return p1;
}

int main() {
    ListNode* head = createList(1, 2, 3, 4, 5);
    ListNode* head2 = createList(1, 2, 3, 4, 5, 6);

    std::cout << findMiddle(head)->data << '\n';
    std::cout << findMiddle(head2)->data << '\n';

    deleteList(head);
}