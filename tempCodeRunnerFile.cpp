#include #include

using namespace std;

int main() { string bookname[100]; string authorname[100]; bool bookStatus[100] = {false}; int numBooks = 0; int choice;

do {
    cout << "Welcome to the library system" << endl;
    cout << "Press 1 to add a new book and author name" << endl;
    cout << "Press 2 to print book list" << endl;
    cout << "Press 3 to remove a book" << endl;
    cout << "Press 4 to toggle book status" << endl;
    cout << "Press 5 to exit" << endl;
    cin >> choice;

    switch (choice)
    {
        case 1:
        {
            cin.ignore();
            cout << "Please type book name" << endl;
            getline(cin, bookname[numBooks]);
            

            cout << "Please enter the author name" << endl;
            getline(cin, authorname[numBooks]);
            numBooks++;

            cout << "The Book has been added!" << endl;
            break;
        }
        case 2:
        {
            cout << "Book List:" << endl;
            for (int j = 0; j < numBooks; j++) {
                cout << j + 1 << ". " << bookname[j] << " by " << authorname[j];
                if (bookStatus[j]) {
                    cout << " (Borrowed)" << endl;
                } else {
                    cout << " (Available)" << endl;
                }
            }
            break;
        }
        case 3:
        {
            if (numBooks > 0) {
                int bookIndex;
                cout << "Please enter the index of the book to remove (1-" << numBooks << "): ";
                cin >> bookIndex;
                if (bookIndex >= 1 && bookIndex <= numBooks) {
                    for (int k = bookIndex - 1; k < numBooks - 1; k++) {
                        bookname[k] = bookname[k + 1];
                        authorname[k] = authorname[k + 1];
                        bookStatus[k] = bookStatus[k + 1];
                    }
                    numBooks--;
                    cout << "Book removed successfully!" << endl;
                } else {
                    cout << "Invalid index!" << endl;
                }
            } else {
                cout << "No books to remove!" << endl;
            }
            break;
        }
        case 4:
        {
            cout << "Enter Book index to toggle status: ";
            int index;
            cin >> index;
            if (index >= 1 && index <= numBooks) {
                bookStatus[index - 1] = !bookStatus[index - 1]; 
                cout << "Status toggled successfully!" << endl;
            } else {
                cout << "Invalid index!" << endl;
            }
            break;
        }
        case 5:
        {
            cout << "Goodbye!" << endl;
            break;
        }
        default:
        {
            cout << "Invalid number, please choose from the menu!" << endl;
            break;
        }
    }
} while (choice != 5);
return 0;
}