class Item:    

    def __init__(self, title, author, year):
        self._title = title
        self._author = author
        self._year = year
        self._status = ""

    def display_info(self):
        pass

    def set_status(self, status):
        self._status = status

class Book(Item):

    def __init__(self, title, author, year, pages):
        self._pages = pages
        super().__init__(title, author, year)

    def display_info(self):
        print(f"Title: {self._title}\nAuthor: {self._author}\nYear: {self._year}\nPages: {self._pages}")

class Magazine(Item):

    def __init__(self, title, author, year, publication):
        self._publication = publication
        super().__init__(title, author, year)

    def display_info(self):
        print(f"Title: {self._title}\nAuthor: {self._author}\nYear: {self._year}\nPublication: {self._publication}")


class LibraryUser:
    def __init__(self, name):
        self._name = name
        self._borrowed_items = []
    
    def borrow(self, Item):
        self._borrowed_items.append(Item)
    
    def return_item(self, Item):
        self._borrowed_items.remove(Item)

class Library:
    def __init__(self):
        self._items = []
        self._users = []

    def add_item(self, Item):
        self._items.append(Item)

    def remove_item(self, Item):
        self._items.remove(Item)

    def register_user(self, LibraryUser):
        self._users.append(LibraryUser)

    def borrow_item(self, LibraryUser, Item):
        if Item in self._items:
            if Item._status == "":
                Item.set_status(LibraryUser._name)
                LibraryUser.borrow(Item)
            else:
                print(f"Not possible, {Item._title} is borrowed by {Item._status}") 
        else:
            print(f"Not possible, {Item._title} does not exist.")

    def return_item(self, LibraryUser, Item):
        Item.set_status("")
        LibraryUser.return_item(Item)
    
    def list_items(self):        
        for item in self._items:
            item.display_info()            
            print("---------")

    def list_available_items(self):
        for item in self._items:
            if item._status == "":
                item.display_info()            
                print("---------")

    def summary(self):
        for item in self._items:
            if item._status != "":
                print(f"{item._title} is borrowed by {item._status}")
            else:
                print(f"{item._title} is available")


""" library = Library()
user1 = LibraryUser("Pelle")
user2 = LibraryUser("Emma")

library.register_user(user1)
library.register_user(user2)

book1 = Magazine("News", "Pelle", 2005, "Street")
book2 = Book("Swan Lake", "Emma", 1999, 500)
book3 = Book("404", "null", 000, 0)

library.add_item(book1)
library.add_item(book2)

print("---------")
library.list_available_items()

library.remove_item(book1)
print("---------")
library.list_available_items()

library.add_item(book1)

library.borrow_item(user1, book2)
print("---------")
print("Available items")
library.list_available_items()
print("All items")
library.list_items()

library.borrow_item(user2, book2)
library.borrow_item(user2, book3)
library.summary() """