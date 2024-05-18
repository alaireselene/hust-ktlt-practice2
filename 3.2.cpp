#include <iostream>
#include <cstring>

class Node {
private:
    int data;
    int power;
public:
    Node* next;
    Node(int data, int power) {
        this->data = data;
        this->power = power;
        this->next = NULL;
    }
    int getData() {
        return this->data;
    }
    int getPower() {
        return this->power;
    }
    void setData(int data) {
        this->data = data;
    }
    void setPower(int power) {
        this->power = power;
    }
};

class Polynomial {
private:
    Node* head;
    int size;
public:
    Polynomial() {
        this->head = NULL;
        this->size = 0;
    }

    void addNode(int data, int power) {
        Node* newNode = new Node(data, power);
        if (this->head == NULL) {
            this->head = newNode;
        } else {
            Node* temp = this->head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        this->size++;
    }

    void printPolynomial() {
        Node* temp = this->head;
        while (temp != NULL){
            if (temp->getPower() == 0) {
                std::cout << temp->getData();
                break;
            } else if (temp->getPower() == 1) {
                std::cout << temp->getData() << "x";
            } else {
                std::cout << temp->getData() << "x^" << temp->getPower();
            }
            if (temp->next != NULL) {
                std::cout << " + ";
            }
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    void derivative() {
        Node* temp = this->head;
        while (temp != NULL) {
            temp->setData(temp->getData() * temp->getPower());
            temp->setPower(temp->getPower() - 1);
            temp = temp->next;
        }
    }
};

int main() {
    Polynomial p;
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        int data;
        std::cin >> data;
        p.addNode(data, n - i - 1);
    }
    p.printPolynomial();
    p.derivative();
    p.printPolynomial();
    return 0;
}