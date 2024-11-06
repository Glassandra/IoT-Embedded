#include <iostream>
#include <string>
#include <vector>

class Person {
    protected:
        std::string first;
        std::string last;
    
    public:
        Person(std::string first, std::string last) : first(first), last(last) {}
        Person() = default;
        void setFirstName(std::string first) { this->first = first;}
        void setLastName(std::string last) {this->last = last;}
        std::string getName() {return first + " " + last;}
        void printFullName() {std::cout << first << " " << last << std::endl; }
        virtual void printInfo() {
            std::cout << "name: " << getName() << std::endl;
        }
        static void printPeople(std::vector<Person*> people) {            
            for (auto person : people) {
            person->printInfo();
    }
        }
};

class Employee : public Person {
    std::string department;

    public:
        Employee(std::string firstName, std::string lastName, std::string department)
            : Person(firstName, lastName), department(department) {}
        std::string getDepartment() { return department;}
        void setDepartment(std::string department) {
            this->department = department;
        }
        void printInfo() override {
            std::cout << "name: " << getName() << std::endl;
            std::cout << "deparment: " << department << std::endl;
        }
};

int main() {
    std::vector<Person*> people;
    Person p("Caleb", "Curry");
    Employee e("first", "last", "sales");

    people.push_back(&p);
    people.push_back(&e);

    Person::printPeople(people);