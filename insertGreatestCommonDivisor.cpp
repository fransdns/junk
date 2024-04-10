

#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {

        ListNode* tmp = head;
        int menor = 1;
        int mcd = 1;
        while (tmp->next != nullptr) {

            int a = tmp->val;
            int b = tmp->next->val;
            //obteniendo el MCD
            if (a == b) {
                mcd = a;
            }
            if (a < b) {
                menor = a;
                for (int div = 2; div <= a; div++) {
                    if (a % div == 0) {
                        if (b % div == 0) {
                            mcd = div;
                        }
                    }

                }
            }
            if (b < a) {
                menor = b;
                for (int div = 2; div <= b; div++) {
                    if (b % div == 0) {
                        if (a % div == 0) {
                            mcd = div;
                        }
                    }

                }
            }

            //para este punto ya tengo el MCD
            ListNode* newNode = new ListNode(mcd);
            newNode->next = tmp->next;
            tmp->next = newNode;

            //avanzo
            tmp = tmp->next->next;

        }
        return head;
    }
};

void append(ListNode** head_ref, int new_val) {
    ListNode* new_node = new ListNode(new_val);
    if (*head_ref == nullptr) {
        *head_ref = new_node;
        return;
    }
    ListNode* last = *head_ref;
    while (last->next != nullptr) {
        last = last->next;
    }
    last->next = new_node;
}

void printList(ListNode* node) {
    while (node != nullptr) {
        std::cout << node->val << " -> ";
        node = node->next;
    }
    std::cout << "null" << std::endl;
}

int main() {

    // Crear las listas para el ejemplo
    ListNode* lista1 = nullptr;

    Solution s;



    append(&lista1, 34);
    append(&lista1, 2);
    append(&lista1, 4);
    append(&lista1, 10);
    append(&lista1, 18);

    printList(s.insertGreatestCommonDivisors(lista1));



    return 0;
}
