import io
import sys
import unittest
from library import Item, Book, Magazine, LibraryUser, Library

class TestItem(unittest.TestCase):
    def setUp(self):
        self.item = Item("Generic Title", "Generic Author", 2020)

    def test_initialization(self):
        self.assertEqual(self.item._title, "Generic Title")
        self.assertEqual(self.item._author, "Generic Author")
        self.assertEqual(self.item._year, 2020)
        self.assertEqual(self.item._status, "")

    def test_set_status(self):
        self.item.set_status("Checked Out")
        self.assertEqual(self.item._status, "Checked Out")

class TestBook(unittest.TestCase):
    def setUp(self):
        self.book = Book("Swan Lake", "Emma", 1999, 500)

    def test_initialization(self):
        self.assertEqual(self.book._title, "Swan Lake")
        self.assertEqual(self.book._author, "Emma")
        self.assertEqual(self.book._year, 1999)
        self.assertEqual(self.book._pages, 500)

    def test_display_info(self):
        captured_output = io.StringIO()
        sys.stdout = captured_output
        self.book.display_info()
        sys.stdout = sys.__stdout__
        self.assertIn("Title: Swan Lake", captured_output.getvalue())
        self.assertIn("Author: Emma", captured_output.getvalue())
        self.assertIn("Year: 1999", captured_output.getvalue())
        self.assertIn("Pages: 500", captured_output.getvalue())

class TestMagazine(unittest.TestCase):
    def setUp(self):
        self.magazine = Magazine("News", "Pelle", 2005, "Street")

    def test_initialization(self):
        self.assertEqual(self.magazine._title, "News")
        self.assertEqual(self.magazine._author, "Pelle")
        self.assertEqual(self.magazine._year, 2005)
        self.assertEqual(self.magazine._publication, "Street")

    def test_display_info(self):
        captured_output = io.StringIO()
        sys.stdout = captured_output
        self.magazine.display_info()
        sys.stdout = sys.__stdout__
        self.assertIn("Title: News", captured_output.getvalue())
        self.assertIn("Author: Pelle", captured_output.getvalue())
        self.assertIn("Year: 2005", captured_output.getvalue())
        self.assertIn("Publication: Street", captured_output.getvalue())

class TestLibraryUser(unittest.TestCase):
    def setUp(self):
        self.user = LibraryUser("Pelle")
        self.book = Book("Swan Lake", "Emma", 1999, 500)

    def test_initialization(self):
        self.assertEqual(self.user._name, "Pelle")
        self.assertEqual(self.user._borrowed_items, [])

    def test_borrow(self):
        self.user.borrow(self.book)
        self.assertIn(self.book, self.user._borrowed_items)

    def test_return_item(self):
        self.user.borrow(self.book)
        self.user.return_item(self.book)
        self.assertNotIn(self.book, self.user._borrowed_items)

class TestLibrary(unittest.TestCase):
    def setUp(self):
        self.library = Library()
        self.book = Book("Swan Lake", "Emma", 1999, 500)
        self.user = LibraryUser("Pelle")

    def test_add_item(self):
        self.library.add_item(self.book)
        self.assertIn(self.book, self.library._items)

    def test_remove_item(self):
        self.library.add_item(self.book)
        self.library.remove_item(self.book)
        self.assertNotIn(self.book, self.library._items)

    def test_register_user(self):
        self.library.register_user(self.user)
        self.assertIn(self.user, self.library._users)

    def test_borrow_item(self):
        self.library.add_item(self.book)
        self.library.register_user(self.user)
        self.library.borrow_item(self.user, self.book)
        self.assertEqual(self.book._status, "Pelle")
        self.assertIn(self.book, self.user._borrowed_items)

    def test_borrow_item_already_borrowed(self):
        self.library.add_item(self.book)
        self.library.register_user(self.user)
        self.library.borrow_item(self.user, self.book)
        captured_output = io.StringIO()
        sys.stdout = captured_output
        self.library.borrow_item(self.user, self.book)
        sys.stdout = sys.__stdout__
        self.assertIn("Not possible, Swan Lake is borrowed by Pelle", captured_output.getvalue())

    def test_return_item(self):
        self.library.add_item(self.book)
        self.library.register_user(self.user)
        self.library.borrow_item(self.user, self.book)
        self.library.return_item(self.user, self.book)
        self.assertEqual(self.book._status, "")
        self.assertNotIn(self.book, self.user._borrowed_items)

    def test_list_items(self):
        self.library.add_item(self.book)
        captured_output = io.StringIO()
        sys.stdout = captured_output
        self.library.list_items()
        sys.stdout = sys.__stdout__
        self.assertIn("Title: Swan Lake", captured_output.getvalue())

    def test_list_available_items(self):
        self.library.add_item(self.book)
        captured_output = io.StringIO()
        sys.stdout = captured_output
        self.library.list_available_items()
        sys.stdout = sys.__stdout__
        self.assertIn("Title: Swan Lake", captured_output.getvalue())

if __name__ == '__main__':
    unittest.main()