#include <iostream>
#include <map>
#include <string>
#include <algorithm>

class Phonebook  {
    private:
        std::map<std::string, std::string> phonebook;

    public:
        void addContact(std::string& name, std::string& phone) {
            std::transform(name.begin(), name.end(), name.begin(), ::tolower);
            phonebook[name] = phone;
        }

        void removeContact(std::string& name) {
            std::transform(name.begin(), name.end(), name.begin(), ::tolower);
            phonebook.erase(name);
        }

        void changeContact(std::string& name, std::string& phone) {
            std::transform(name.begin(), name.end(), name.begin(), ::tolower);
            phonebook[name] = phone;
        }

        bool searchContact(std::string name) {            
            std::transform(name.begin(), name.end(), name.begin(), ::tolower);
            auto it = phonebook.find(name);
            if (it != phonebook.end()) {
                std::string name = it->first;
                std::transform(name.begin(), name.begin()+1, name.begin(), ::toupper);
                std::cout << "Found " << name << " -> " << it->second << std::endl;
                return 1;
            }
            else {
                std:: cout << "Not found" << std::endl;
                return 0;
            }
        }

        void displayContacts() {
            for (const auto& contact: phonebook) {                
                std::string name = contact.first;
                std::transform(name.begin(), name.begin()+1, name.begin(), ::toupper);
                std::cout << name << " -> " << contact.second << std::endl;
            }

        }
};

int main() {
    Phonebook book;
    std::string name = "Test";
    std::string number = "04213";
    book.addContact(name, number);
    std::string name2 = "Lisa";
    std::string number2 = "1555";
    book.addContact(name2, number2);
    std::string name3 = "Örlig";
    std::string number3 = "200";
    book.addContact(name3, number3);

    book.searchContact("Test");
    book.searchContact("lisa");
    book.displayContacts();

}
