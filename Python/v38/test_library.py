import library as testing_environment

library = testing_environment.Library()
user1 = testing_environment.LibraryUser("Pelle")
user2 = testing_environment.LibraryUser("Emma")

library.register_user(user1)
library.register_user(user2)

book1 = testing_environment.Magazine("News", "Pelle", 2005, "Street")
book2 = testing_environment.Book("Swan Lake", "Emma", 1999, 500)
book3 = testing_environment.Book("404", "null", 000, 0)

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
library.summary()