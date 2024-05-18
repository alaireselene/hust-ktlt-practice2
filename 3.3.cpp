/*
 Tạo class biểu diễn danh sách liên kết đôi của các số nguyên. Viết hàm tạo danh sách, hàm in danh sách, hàm đảo ngược danh sách, hàm thêm một phần tử vào cuối danh sách, hàm xóa một phần tử ở cuối danh sách, hàm xóa một phần tử ở đầu danh sách, hàm xóa một phần tử ở vị trí bất kỳ trong danh sách, hàm tìm một phần tử trong danh sách, hàm sửa một phần tử ở vị trí bất kỳ trong danh sách.
 */

#include <iostream>

class Node {
private:
    int data;
public:
    Node* next;
    Node* prev;
    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
    int getData() {
        return this->data;
    }
    void setData(int data) {
        this->data = data;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
    int size;
public:
    DoublyLinkedList() {
        this->head = NULL;
        this->tail = NULL;
        this->size = 0;
    }

    void addNode(int data) {
        Node* newNode = new Node(data);
        if (this->head == NULL) {
            this->head = newNode;
            this->tail = newNode;
        } else {
            this->tail->next = newNode;
            newNode->prev = this->tail;
            this->tail = newNode;
        }
        this->size++;
    }

    void printList() {
        Node* temp = this->head;
        while (temp != NULL) {
            std::cout << temp->getData() << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    void reverseList() {
        std::cout << "Reversed: " << std::endl;
        Node* temp = this->head;
        while (temp != NULL) {
            Node* tempNext = temp->next;
            temp->next = temp->prev;
            temp->prev = tempNext;
            temp = tempNext;
        }
        Node* tempHead = this->head;
        this->head = this->tail;
        this->tail = tempHead;
    }

    void addNodeAtEnd(int data) {
        std::cout << "Added " << data << " at the end" << std::endl;
        Node* newNode = new Node(data);
        if (this->head == NULL) {
            this->head = newNode;
            this->tail = newNode;
        } else {
            this->tail->next = newNode;
            newNode->prev = this->tail;
            this->tail = newNode;
        }
        this->size++;
    }

    void deleteNodeAtEnd() {
        std::cout << "Deleted at the end" << std::endl;
        if (this->head == NULL) {
            return;
        }
        if (this->head == this->tail) {
            delete this->head;
            this->head = NULL;
            this->tail = NULL;
        } else {
            Node* temp = this->tail;
            this->tail = this->tail->prev;
            this->tail->next = NULL;
            delete temp;
        }
        this->size--;
    }

    void deleteNodeAtBegin() {
        std::cout << "Deleted at the beginning" << std::endl;
        if (this->head == NULL) {
            return;
        }
        if (this->head == this->tail) {
            delete this->head;
            this->head = NULL;
            this->tail = NULL;
        } else {
            Node* temp = this->head;
            this->head = this->head->next;
            this->head->prev = NULL;
            delete temp;
        }
        this->size--;
    }

    void deleteNodeAtPosition(int position) {
        std::cout << "Deleted at position " << position << std::endl;
        if (position < 0 || position >= this->size) {
            return;
        }
        if (position == 0) {
            deleteNodeAtBegin();
        } else if (position == this->size - 1) {
            deleteNodeAtEnd();
        } else {
            Node* temp = this->head;
            for (int i = 0; i < position; i++) {
                temp = temp->next;
            }
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
            this->size--;
        }
    }

    Node* findNode(int data) {
        Node* temp = this->head;
        while (temp != NULL) {
            if (temp->getData() == data) {
                return temp;
            }
            temp = temp->next;
        }
        return NULL;
    }

    void editNodeAtPosition(int position, int data) {
        if (position < 0 || position >= this->size) {
            return;
        }
        Node* temp = this->head;
        for (int i = 0; i < position; i++) {
            temp = temp->next;
        }
        temp->setData(data);
        std::cout << "Edited at position " << position << " to " << data << std::endl;
    }

    int getSize() {
        return this->size;
    }

    void findNodeAnnounce(int data) {
        Node* temp = this->head;
        while (temp != NULL) {
            if (temp->getData() == data) {
                std::cout << "Found: " << temp->getData() << std::endl;
                return;
            }
            temp = temp->next;
        }
        std::cout << "Not found node with value " << data << std::endl;
    }
};

int main() {
    DoublyLinkedList* list = new DoublyLinkedList();
    list->addNode(1);
    list->addNode(2);
    list->addNode(3);
    list->addNode(4);
    list->addNode(5);
    list->printList();
    list->reverseList();
    list->printList();
    list->addNodeAtEnd(6);
    list->printList();
    list->deleteNodeAtEnd();
    list->printList();
    list->deleteNodeAtBegin();
    list->printList();
    list->deleteNodeAtPosition(1);
    list->printList();
    list->findNodeAnnounce(3);
    list->editNodeAtPosition(1, 7);
    list->printList();
    return 0;
}