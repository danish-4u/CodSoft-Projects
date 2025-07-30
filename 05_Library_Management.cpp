#include <iostream>
#include <vector>
using namespace std;

struct Book {
    string title, author;
    int id;
    bool available;
};

int main() {
    vector<Book> library;
    int choice;
    do {
        cout << "\n1. Add Book\n2. View Books\n3. Issue Book\n4. Return Book\n5. Exit\nChoice: ";
        cin >> choice;
        if (choice == 1) {
            Book b;
            cout << "Enter ID, Title, Author: ";
            cin >> b.id >> ws;
            getline(cin, b.title);
            getline(cin, b.author);
            b.available = true;
            library.push_back(b);
        } else if (choice == 2) {
            for (auto &b : library)
                cout << b.id << " - " << b.title << " by " << b.author << (b.available ? " [Available]" : " [Issued]") << endl;
        } else if (choice == 3 || choice == 4) {
            int id;
            cout << "Enter Book ID: ";
            cin >> id;
            for (auto &b : library) {
                if (b.id == id) {
                    b.available = (choice == 4);
                    cout << (choice == 3 ? "Book Issued" : "Book Returned") << endl;
                    break;
                }
            }
        }
    } while (choice != 5);
    return 0;
}
