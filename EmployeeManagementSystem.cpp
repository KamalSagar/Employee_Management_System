#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Employee {
private:
    int id;
    string name;
    string position;
    double salary;

public:
    Employee(int id, const string& name, const string& position, double salary)
        : id(id), name(name), position(position), salary(salary) {}

    int getId() const {
        return id;
    }

    string getName() const {
        return name;
    }

    string getPosition() const {
        return position;
    }

    double getSalary() const {
        return salary;
    }

    void setName(const string& newName) {
        name = newName;
    }

    void setPosition(const string& newPosition) {
        position = newPosition;
    }

    void setSalary(double newSalary) {
        salary = newSalary;
    }

    void display() const {
        cout << "ID: " << id << ", Name: " << name 
             << ", Position: " << position 
             << ", Salary: $" << salary << endl;
    }
};

class EmployeeManagementSystem {
private:
    vector<Employee> employees;
    int nextId;

public:
    EmployeeManagementSystem() : nextId(1) {}

    void addEmployee() {
        string name, position;
        double salary;
        cout << "Enter employee name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter employee position: ";
        getline(cin, position);
        cout << "Enter employee salary: ";
        cin >> salary;

        employees.push_back(Employee(nextId++, name, position, salary));
        cout << "Employee added successfully!" << endl;
    }

    void removeEmployee() {
        int id;
        cout << "Enter employee ID to remove: ";
        cin >> id;

        for (auto it = employees.begin(); it != employees.end(); ++it) {
            if (it->getId() == id) {
                employees.erase(it);
                cout << "Employee removed successfully!" << endl;
                return;
            }
        }
        cout << "Employee not found!" << endl;
    }

    void updateEmployee() {
        int id;
        cout << "Enter employee ID to update: ";
        cin >> id;

        for (auto& employee : employees) {
            if (employee.getId() == id) {
                string name, position;
                double salary;
                cout << "Enter new name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter new position: ";
                getline(cin, position);
                cout << "Enter new salary: ";
                cin >> salary;

                employee.setName(name);
                employee.setPosition(position);
                employee.setSalary(salary);
                cout << "Employee updated successfully!" << endl;
                return;
            }
        }
        cout << "Employee not found!" << endl;
    }

    void displayEmployees() const {
        if (employees.empty()) {
            cout << "No employees to display." << endl;
            return;
        }

        for (const auto& employee : employees) {
            employee.display();
        }
    }

    void searchEmployee() const {
        int id;
        cout << "Enter employee ID to search: ";
        cin >> id;

        for (const auto& employee : employees) {
            if (employee.getId() == id) {
                employee.display();
                return;
            }
        }
        cout << "Employee not found!" << endl;
    }
};

int main() {
    EmployeeManagementSystem system;
    int choice;

    while (true) {
        cout << "\nEmployee Management System" << endl;
        cout << "1. Add Employee" << endl;
        cout << "2. Remove Employee" << endl;
        cout << "3. Update Employee" << endl;
        cout << "4. Display All Employees" << endl;
        cout << "5. Search Employee" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                system.addEmployee();
                break;
            case 2:
                system.removeEmployee();
                break;
            case 3:
                system.updateEmployee();
                break;
            case 4:
                system.displayEmployees();
                break;
            case 5:
                system.searchEmployee();
                break;
            case 6:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    }
}
