#include <iostream>
#include <cstring>
#include <iomanip>

int listSize = 0;
int totalSalary = 0;
int highestSalary = 0;

class Employer {
private:
    int index;
    std::string id;
    std::string fullName;
    int salary;
public:
    Employer* next;
    Employer(std::string id, std::string fullName, int salary) {
        this->index = ++listSize;
        this->id = id;
        this->fullName = fullName;
        this->salary = salary;
        this->next = NULL;
        totalSalary += salary;
        if (salary > highestSalary) {
            highestSalary = salary;
        }
    }
    int getIndex() {
        return this->index;
    }
    std::string getId() {
        return this->id;
    }
    std::string getFullName() {
        return this->fullName;
    }
    int getSalary() {
        return this->salary;
    }
};

class EmployerList {
private:
    Employer* head;
public:
    EmployerList() {
        this->head = NULL;
    }

    void addEmployer(std::string id, std::string fullName, int salary) {
        Employer* newEmployer = new Employer(id, fullName, salary);
        if (head == NULL) {
            head = newEmployer;
        } else {
            Employer* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newEmployer;
        }
    }

    void removeEmployer(int index) {
        if (head == NULL) {
            std::cout << "Employer list is empty. Action cancelled." << std::endl;
            return;
        }
        Employer* temp = head;
        if (temp->getIndex() == index) {
            totalSalary -= temp->getSalary();
            head = temp->next;
            delete temp;
            --listSize;
            return;
        }
        while (temp->next != NULL) {
            if (temp->next->getIndex() == index) {
                totalSalary -= temp->next->getSalary();
                Employer* temp2 = temp->next;
                temp->next = temp2->next;
                delete temp2;
                --listSize;
                return;
            }
            temp = temp->next;
        }
        std::cout << "Employer not found. Action cancelled." << std::endl;
    }

    void printList() {
    if (head == NULL) {
        std::cout << "Employer list is empty. Action cancelled." << std::endl;
        return;
    }
    Employer* temp = head;
    std::cout << std::left << std::setfill('=') << std::setw(70) << "EMPLOYERS TABLE" << std::endl;
    std::cout << std::setfill(' ') << std::setw(10) << std::left << "Index" 
              << std::setw(10) << std::left << "ID" 
              << std::setw(30) << std::left << "Full Name" 
              << std::setw(20) << std::left << "Salary" << std::endl;
    std::cout << std::setfill('-') << std::setw(70) << "" << std::endl;
    while (temp != NULL) {
        std::cout << std::setfill(' ') << std::setw(10) << std::left << temp->getIndex() 
                  << std::setw(10) << std::left << temp->getId() 
                  << std::setw(30) << std::left << temp->getFullName() 
                  << std::setw(20) << std::left << temp->getSalary() << std::endl;
        temp = temp->next;
    }
    std::cout << std::setfill('=') << std::setw(70) << "" << std::endl;
}
};

int main() {
    EmployerList employerList;
    employerList.addEmployer("1", "John Doe", 1000);
    employerList.addEmployer("2", "Jane Doe", 2000);
    employerList.addEmployer("3", "Jack Doe", 3000);
    employerList.printList();
    employerList.removeEmployer(2);
    employerList.printList();
    employerList.removeEmployer(1);
    employerList.printList();
    employerList.removeEmployer(3);
    employerList.printList();
    employerList.removeEmployer(3);
    employerList.printList();
    return 0;
}