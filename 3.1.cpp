#include <iostream>
#include <cstring>
#include <iomanip>

int listSize = 0;
int totalSalary = 0;
int highestSalary = 0;

class Employer {
private:
    std::string id;
    std::string fullName;
    int salary;
public:
    Employer* next;
    Employer(std::string id, std::string fullName, int salary) {
        this->id = id;
        this->fullName = fullName;
        this->salary = salary;
        this->next = NULL;
        listSize++;
        totalSalary += salary;
        if (salary > highestSalary) {
            highestSalary = salary;
        }
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
    void editId(std::string id) {
        this->id = id;
    }
    void editFullName(std::string fullName) {
        this->fullName = fullName;
    }
    void editSalary(int salary) {
        totalSalary -= this->salary;
        this->salary = salary;
        totalSalary += salary;
        if (salary > highestSalary) {
            highestSalary = salary;
        }
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
        std::cout << "Employer " << fullName << " added successfully." << std::endl;
    }

    void removeEmployer(std::string id) {
        if (head == NULL) {
            std::cout << "Employer list is empty. Action cancelled." << std::endl;
            return;
        }
        Employer* temp = head;
        if (temp->getId() == id) {
            std::cout << "Employer " << temp->getFullName() << " removed successfully. Here is the result:" << std::endl;
            totalSalary -= temp->getSalary();
            if (temp->getSalary() == highestSalary) {
                int purgedHighestSalary = highestSalary;
                highestSalary = 0;
                Employer* temp2 = head;
                while (temp2 != NULL) {
                    if (temp2->getSalary() > highestSalary && temp2->getSalary() != purgedHighestSalary) {
                        highestSalary = temp2->getSalary();
                    }
                    temp2 = temp2->next;
                }
            }
            head = temp->next;
            delete temp;
            --listSize;
            return;
        }
        while (temp->next != NULL) {
            if (temp->next->getId() == id) {
                std::cout << "Employer " << temp->next->getFullName() << " removed successfully. Here is the result:" << std::endl;
                totalSalary -= temp->next->getSalary();
                Employer* temp2 = temp->next;
                temp->next = temp2->next;
                delete temp2;
                --listSize;
                while (temp->next != NULL) {
                    temp = temp->next;
                }
                return;
            }
            temp = temp->next;
        }
        std::cout << "Employer not found. Action cancelled." << std::endl;
    }
    void editEmployerSalary(std::string id, int newSalary) {
        if (head == NULL) {
            std::cout << "Employer list is empty. Action cancelled." << std::endl;
            return;
        }
        Employer* temp = head;
        while (temp != NULL) {
            if (temp->getId() == id) {
                temp->editSalary(newSalary);
                std::cout << "Employer " << temp->getFullName() << " salary edited successfully. Here is the result:" << std::endl;
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
        std::cout << std::left << std::setfill('=') << std::setw(70) << "[EMPLOYERS TABLE]"<< std::endl;
        std::cout << std::setfill(' ') << std::setw(10) << std::left << "Index" 
                  << std::setw(10) << std::left << "ID" 
                  << std::setw(30) << std::left << "Full Name" 
                  << std::setw(20) << std::left << "Salary" << std::endl;
        std::cout << std::setfill('-') << std::setw(70) << "" << std::endl;
        int index = 1;
        while (temp != NULL) {
            std::cout << std::setfill(' ') << std::setw(10) << std::left << index++ 
                      << std::setw(10) << std::left << temp->getId() 
                      << std::setw(30) << std::left << temp->getFullName() 
                      << std::setw(20) << std::left << temp->getSalary() << std::endl;
            temp = temp->next;
        }
        std::cout << std::setfill('-') << std::setw(70) << "" << std::endl;
        std::cout << "Avg. salary: " << float(totalSalary)/listSize <<", Highest: " << highestSalary << std::endl;
        std::cout << std::setfill('=') << std::setw(70) << "" << std::endl;
        std::cout << std::endl;
    }
};

int main() {
    EmployerList employerList;
    employerList.addEmployer("20227148", "Nguyen Truong Son", 1000);
    employerList.addEmployer("20227149", "Tran Trung Long", 2000);
    employerList.addEmployer("20227150", "Hoang Bao An", 3000);
    employerList.printList();
    employerList.removeEmployer("20227149");
    employerList.printList();
    employerList.editEmployerSalary("20227148", 5000);
    employerList.printList();
    employerList.removeEmployer("20227148");
    employerList.printList();
    employerList.removeEmployer("20227150");
    employerList.printList();
    return 0;
}