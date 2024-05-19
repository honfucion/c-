#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Lớp cơ bản
class Person {
protected:
    string name;
    int age;
public:
    Person() : name(""), age(0) {}
    Person(string n, int a) : name(n), age(a) {}

    // Setters và Getters
    void setName(string n) { name = n; }
    string getName() const { return name; }

    void setAge(int a) { age = a; }
    int getAge() const { return age; }

    // Phương thức ảo
    virtual void display() const {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

// Lớp dẫn xuất từ Person
class Student : public Person {
private:
    string school;
public:
    Student() : Person(), school("") {}
    Student(string n, int a, string s) : Person(n, a), school(s) {}

    void setSchool(string s) { school = s; }
    string getSchool() const { return school; }

    // Ghi đè phương thức display
    void display() const override {
        cout << "Name: " << name << ", Age: " << age << ", School: " << school << endl;
    }

    // Nạp chồng phương thức
    void display(string prefix) const {
        cout << prefix << "Name: " << name << ", Age: " << age << ", School: " << school << endl;
    }
};

// Template class
template <typename T>
class DataManager {
private:
    vector<T> data;
public:
    void addData(const T& d) {
        data.push_back(d);
    }

    void displayData() const {
        for (const auto& item : data) {
            item.display();
        }
    }
};

// Biến static
class Counter {
public:
    static int count;
    Counter() { count++; }
};

int Counter::count = 0;

// Hàm đọc file
void readFile(const string& filename) {
    ifstream infile(filename);
    if (!infile) {
        cerr << "Cannot open file!" << endl;
        return;
    }

    string line;
    while (getline(infile, line)) {
        cout << line << endl;
    }

    infile.close();
}

// Hàm ghi file
void writeFile(const string& filename, const string& data) {
    ofstream outfile(filename, ios::app);
    if (!outfile) {
        cerr << "Cannot open file!" << endl;
        return;
    }

    outfile << data << endl;
    outfile.close();
}

// Kiểm tra logic
void logicTest() {
    if (Person().getAge() == 0) {
        cout << "Default constructor works correctly." << endl;
    }
}

void menu() {
    int choice;
    DataManager<Student> studentManager;
    string name;
    int age;
    string school;

    do {
        cout << "Menu:" << endl;
        cout << "1. Add student" << endl;
        cout << "2. Display students" << endl;
        cout << "3. Read from file" << endl;
        cout << "4. Write to file" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter age: ";
            cin >> age;
            cout << "Enter school: ";
            cin >> school;
            studentManager.addData(Student(name, age, school));
            break;
        case 2:
            studentManager.displayData();
            break;
        case 3:
            readFile("students.txt");
            break;
        case 4:
            cout << "Enter data to write to file: ";
            cin.ignore(); // clear the input buffer
            getline(cin, name);
            writeFile("students.txt", name);
            break;
        case 5:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice, please try again." << endl;
            break;
        }
    } while (choice != 5);
}

int main() {
    logicTest();
    menu();
    return 0;
}
