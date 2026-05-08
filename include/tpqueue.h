// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
 public:
    TPQueue() :head(nullptr) {}
    ~TPQueue() {
        while (head) {
            Node* next = head->next;
            delete head;
            head = next;
        }
    }

    T pop() {
        if (head) {
            T temp = head->data;
            Node* next = head->next;
            delete head;
            head = next;
            return temp;
        } else {
            return T();
        }
    }

    void push(T data) {
        if (head) {
            Node* temp = head;
            if (head->data.prior < data.prior) {
                head = create(data);
                head->next = temp;
            } else {
                while ((temp->next != nullptr)
                    &&data.prior <= temp->next->data.prior)
                    temp = temp->next;
                Node* newNode = create(data);
                newNode->next = temp->next;
                temp->next = newNode;
            }
        } else {
            head = create(data);
        }
    }

 private:
    struct Node {
        T data;
        Node* next;
    };

    Node* create(const T data) {
        Node* item = new Node;
        item->data = data;
        item->next = nullptr;
        return item;
    }

    Node* head;
};

struct SYM {
    char ch;
    int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
