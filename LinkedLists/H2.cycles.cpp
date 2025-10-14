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

bool hasCycle(ListNode* head){
    ListNode* p1 = head;
    ListNode* p2 = head;

    while(p2 && p2->next){
        p1 = p1->next;
        p2 = p2->next->next;
        if(p1 == p2){
            return true;
        }
    }

    return false;
}

int main() {
    ListNode* head = createList(1, 2, 3, 4);
    std::cout << std::boolalpha << hasCycle(head) << '\n'; 

    deleteList(head);
    head = nullptr;

    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);
    head2->next->next = head2->next; 

    std::cout << hasCycle(head2) << '\n'; 

    delete head2->next;
    delete head2;
}