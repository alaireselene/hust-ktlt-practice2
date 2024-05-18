#include <iostream>
#include <cstring>
#include <cmath>

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

    Polynomial operator+(const Polynomial& other) {
        Polynomial result;
        Node* temp = this->head;
        while (temp != NULL) {
            result.addNode(temp->getData(), temp->getPower());
            temp = temp->next;
        }
        temp = other.head;
        while (temp != NULL) {
            result.addNode(temp->getData(), temp->getPower());
            temp = temp->next;
        }
        return result;
    }
    int evaluate(int x) {
        Node* temp = this->head;
        int result = 0;
        while (temp != NULL) {
            result += temp->getData() * std::pow(x, temp->getPower());
            temp = temp->next;
        }
        return result;
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
    Polynomial q;
    for (int i = 0; i < n; i++) {
        int data;
        std::cin >> data;
        q.addNode(data, n - i - 1);
    }
    int x_0;
    std::cin >> x_0;

    std::cout << "Polynomial 1: " << std::endl;
    p.printPolynomial();
    p.derivative();
    std::cout << "Derivative of Polynomial 1: " << std::endl;
    p.printPolynomial();

    std::cout << "Polynomial 2: " << std::endl;
    q.printPolynomial();
    q.derivative();
    std::cout << "Derivative of Polynomial 2: " << std::endl;
    q.printPolynomial();

    Polynomial r = p + q;
    std::cout << "Sum of Polynomials 1 and 2 after derivative: " << std::endl;
    r.printPolynomial();

    std::cout << "Value of Polynomial 1 at x = " << x_0 << ": " << p.evaluate(x_0) << std::endl;
    std::cout << "Value of Polynomial 2 at x = " << x_0 << ": " << q.evaluate(x_0) << std::endl;

    return 0;
}