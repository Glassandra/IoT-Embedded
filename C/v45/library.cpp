#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>

class Item {
    protected:
        std::string title;
        std::string author;
        int year;

    public:
        Item(std::string title, std::string author, int year) : title(title), author(author), year(year) {}
        virtual void display_info() const {};
        virtual ~Item() {};
        bool operator==(const Item& other) const {
            return title == other.title && author == other.author && year == other.year;        
        }
        std::string get_title() const {
            return title;
        }
};

class Book : public Item {
    protected:
        int pages;
    
    public:
        Book(std::string title, std::string author, int year, int pages)
             : Item(title, author, year), pages(pages) {}
        void display_info() const override {
            std::cout << title << ", " << author << ", " << year << ", " << pages << std::endl; 
        }
};

class Magazine : public Item {
    protected:
        int issue;

    public:
        Magazine(std::string title, std::string author, int year, int issue)
             : Item(title, author, year), issue(issue) {}
        void display_info() const override {
                std::cout << title << ", " << author << ", " << year << ", " << issue << std::endl; 
        }
};

class LibraryUser {
    protected:
        std::string name;
        std::vector<Item*> borrowed_items;

    public:
        LibraryUser(std::string name) : name(name) {}
        void borrow(Item& item) {
            borrowed_items.push_back(&item);            
        }
        void return_item(const Item& item) {
            auto it = std::remove_if(borrowed_items.begin(), borrowed_items.end(),
                [&item](Item* i) {
                    return i->get_title() == item.get_title();
                });
            if (it != borrowed_items.end()) {
                borrowed_items.erase(it, borrowed_items.end());
            }
        }
        void list_borrowed_items() const {
            for (const Item* item : borrowed_items) {
                item->display_info();
            }
        }
        std::string get_name() const {
            return name;
        }
};

class Library {
    protected:
        std::vector<Item*> items;
        std::vector<LibraryUser*> users;

    public:
        void add_item(Item& item) {
            items.push_back(&item);
        }
        void remove_item(const Item& item) {
            auto it = std::remove_if(items.begin(), items.end(),
                [&item](Item* i) {
                    return i->get_title() == item.get_title();
                });
            if (it != items.end()) {
                items.erase(it, items.end());
            }
        }
        void register_user(LibraryUser& user) {
            users.push_back(&user);
        }
        void borrow_item(LibraryUser& user, Item& item) {
            user.borrow(item);
            remove_item(item);
        }
        void return_item(LibraryUser& user, Item& item) {
            user.return_item(item);
            add_item(item);
        }
        void list_items() const {            
            std::cout << "In library: " << std::endl;
            list_available_items();
            std::cout << "Borrowed by users: " << std::endl;
            for (const LibraryUser* user : users) {
                user->list_borrowed_items();
            }
        }
        void list_available_items() const {
            for(const Item* item : items) {
                item->display_info();
            }
        }
        void list_borrowed_items() const {
            for(const LibraryUser* user: users) {
                std::cout << "------------------" << std::endl;
                std::cout << "Books borrowed by " << user->get_name() << std::endl;
                user->list_borrowed_items();
            }
        }
};


int main() {
    Library library;
    
    LibraryUser pelle = LibraryUser("Pelle");
    LibraryUser lisa = LibraryUser("Lisa");
    library.register_user(pelle);
    library.register_user(lisa);
    

    Magazine mag = Magazine("Magazine", "Anna", 2020, 5);
    Book book = Book("Book", "Carl", 1990, 500);

    library.add_item(mag);
    library.add_item(book);

    std::cout << "Test list_available_items()\n";
    library.list_available_items();

    std::cout << "Test all items\n";
    library.borrow_item(pelle, mag);
    library.list_items();

    std::cout << "Test give back item\n";
    library.return_item(pelle, mag);
    library.list_items();

    std::cout << "Test list of borrowed books\n";
    library.borrow_item(pelle, book);
    library.borrow_item(lisa, mag);
    library.list_borrowed_items();

    return 0;
}