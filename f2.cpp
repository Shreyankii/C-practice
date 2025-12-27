#include <iostream>
using namespace std;

class Employee {
private:
    string name;
    int empid;

protected:
    float salary;

public:
    Employee(string name, int empid) {
        this->name = name;
        this->empid = empid;
        this->salary = 0.0f;
    }

    void displayBasic() {
        cout << "Name: " << name << endl;
        cout << "ID: " << empid << endl;
    }

    float getSalary() {
        return salary;
    }

    virtual void displayDetails() = 0; // Pure virtual

    virtual ~Employee() {
        cout << "Base class destructor" << endl;
    }

    int getempid() {
        return empid;
    }
};

class FullTimeEmployee : public Employee {
public:
    float basicPay;
    float bonus;

    FullTimeEmployee(string name, int empid, float basicPay, float bonus)
        : Employee(name, empid) {
        this->basicPay = basicPay;
        this->bonus = bonus;
        CalcSalary(); // Call it here
    }

    void CalcSalary() {
        salary = basicPay + bonus;
    }

    void displayDetails() override {
        displayBasic();
        cout << "Full Time Employee" << endl;
        cout << "Basic Pay: " << basicPay << endl;
        cout << "Bonus: " << bonus << endl;
        cout << "Total Salary: " << salary << endl;
    }

    ~FullTimeEmployee() {
        cout << "Destroyed FullTimeEmployee" << endl;
    }
};

class PartTimeEmployee : public Employee {
public:
    int hoursWorked;
    float hourlyRate;

    PartTimeEmployee(string name, int empid, int hoursWorked, float hourlyRate)
        : Employee(name, empid) {
        this->hoursWorked = hoursWorked;
        this->hourlyRate = hourlyRate;
        calculateSalary(); // Call it here
    }

    void calculateSalary() {
        salary = hoursWorked * hourlyRate;
    }

    void displayDetails() override {
        displayBasic();
        cout << "Part Time Employee" << endl;
        cout << "Hours Worked: " << hoursWorked << endl;
        cout << "Hourly Rate: " << hourlyRate << endl;
        cout << "Total Salary: " << salary << endl;
    }

    ~PartTimeEmployee() {
        cout << "Destroyed PartTimeEmployee" << endl;
    }
};

int main() {
    int n;
    cout << "Enter size of employee array: ";
    cin >> n;

    int count = 0;
    Employee* Emp[n];

    while (true) {
        int choice;
        cout << "\nMenu:\n1. Add Full-Time Employee\n2. Add Part-Time Employee\n3. Display All\n4. Search by ID\n5. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            if (count < n) {
                string name;
                int empid;
                float basicPay, bonus;

                cout << "Enter Name: ";
                cin >> name;
                cout << "Enter ID: ";
                cin >> empid;
                cout << "Enter Basic Pay: ";
                cin >> basicPay;
                cout << "Enter Bonus: ";
                cin >> bonus;

                Emp[count++] = new FullTimeEmployee(name, empid, basicPay, bonus);
            } else {
                cout << "Employee array is full!\n";
            }
            break;
        }
        case 2: {
            if (count < n) {
                string name;
                int empid, hoursWorked;
                float hourlyRate;

                cout << "Enter Name: ";
                cin >> name;
                cout << "Enter ID: ";
                cin >> empid;
                cout << "Enter Hours Worked: ";
                cin >> hoursWorked;
                cout << "Enter Hourly Rate: ";
                cin >> hourlyRate;

                Emp[count++] = new PartTimeEmployee(name, empid, hoursWorked, hourlyRate);
            } else {
                cout << "Employee array is full!\n";
            }
            break;
        }
        case 3: {
            for (int i = 0; i < count; i++) {
                cout << "\nEmployee " << (i + 1) << " details:\n";
                Emp[i]->displayDetails();
            }
            break;
        }
        case 4: {
            int searchID;
            cout << "Enter Employee ID to search: ";
            cin >> searchID;
            bool found = false;
            for (int i = 0; i < count; i++) {
                if (Emp[i]->getempid() == searchID) {
                    Emp[i]->displayDetails();
                    found = true;
                    break;
                }
            }
            if (!found)
                cout << "Employee with ID " << searchID << " not found.\n";
            break;
        }
        case 5: {
      
            for (int i = 0; i < count; i++) {
                delete Emp[i];
            }
            cout << "Exiting...\n";
            return 0;
        }
        default:
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}
