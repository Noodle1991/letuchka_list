#include <iostream>

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *create_list(std::string input) {
    ListNode *dummy = new ListNode();
    ListNode *current = dummy;
    for (int i = 0; i < input.length(); i++) {
        current->next = new ListNode(input[i] - '0');
        current = current->next;
    }

    return dummy->next;
}

void print_list(ListNode *head) {
    ListNode *current = head;
    std::cout << "[";
    while (current != nullptr) {
        std::cout << current->val;
        if (current->next != nullptr) {
            std::cout << ",";
        } else std::cout << "]";
        current = current->next;
    }
}

ListNode *add_two_linked_numbers(ListNode *l1, ListNode *l2) {
    ListNode *dummy = new ListNode();
    ListNode *current = dummy;

    int pit = 0;
    while (l1 != nullptr || l2 != nullptr) {
        int sum = pit;

        if (l1 != nullptr) {
            sum = sum + l1->val;
            l1 = l1->next;
        }

        if (l2 != nullptr) {
            sum = sum + l2->val;
            l2 = l2->next;
        }

        pit = sum / 10;
        current->next = new ListNode(sum % 10);
        current = current->next;
    }

    if (pit > 0) {
        current->next = new ListNode(pit);
    }

    return dummy->next;
}

void delete_list(ListNode *l1) {
    ListNode *current = l1;
    while (current != nullptr) {
        ListNode *data = current;
        current = current->next;
        delete data;
    }
}

int main() {
    std::string num1;
    std::string num2;
    std::cin >> num1;
    std::cin >> num2;

    ListNode *l1 = create_list(num1);
    ListNode *l2 = create_list(num2);
    ListNode *result = add_two_linked_numbers(l1, l2);

    std::cout << "Ввод: l1 = ";
    print_list(l1);
    std::cout << ", l2 = ";
    print_list(l2);
    std::cout << '\n' << "Вывод: ";
    print_list(result);

    delete_list(l1);

    delete_list(l2);

    delete_list(result);

    return 0;
}