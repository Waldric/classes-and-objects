#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

class Books {

private:

    string title;
    string author;
    int year = 0;

public:

  Books(const string& add_title, const string& add_author, int add_year)
    {
        title = add_title;
        author = add_author;
        year = add_year;
              
    }

   ~Books() {

       cout << "Destroying book: " << title << endl;
      
   }

  void DisplayBook()
  const{

       cout << endl;
       cout << left << setw(30) << "Title" << left << setw(30) << "Author" << left << setw(30) << "Year" << endl;
       cout << left << setw(30) << title << left << setw(30) << author << left << setw(30) << year << endl;
  }

  string getTitle() const{
    return title;
  }

  string getAuthor() const{
    return author;
  }

};
class Library {

private:
    vector<Books> books;


public:
  
  ~Library() {
       
        cout << "Closing library with " << books.size() << " books." << endl;
  }
  void AddBook(const string& title, const string& author, int year) {
        books.emplace_back(title, author, year);
    }

  void DisplayBooks() {

     if (books.empty()) {
            cout << "No books in the library." << endl;
            return;
        }

     for (const auto& book : books) {
            book.DisplayBook();
            cout << "-----------------------------------------------------------------------------------------" << endl;
        }   
    
    }
    
  void SearchBook(const string& title) const {
        bool found = false;
        for (const auto& book : books) {
            if (book.getTitle() == title) {
              cout << "Book Found! " << endl;
                book.DisplayBook();
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Book not found! " << endl;
        }
    }  
};

int main () {
    
    Library data;
    int choice;
    string exit;
    bool lastchoice = true;

    do {

         cout << "\nMENU " << endl;
         cout << "1 - Add Book " << endl;
         cout << "2 - Display Book " << endl;
         cout << "3 - Search Book " << endl;
         cout << "4 - Exit " << endl; 
         cout << "Enter your option: ";
         cin >> choice;

         switch (choice) {
             case 1: {
              string title, author;
              int year;
                cout << "Enter title: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter author: ";
                getline(cin, author);
                cout << "Enter year: ";
                cin >> year;
                data.AddBook(title, author, year);
                break;
          
             }
             case 2: {
              cout << "Displaying Books: \n" << endl;
              data.DisplayBooks();
              break;
             }
             case 3: {
              string title;
              cout << "Enter the title to search: ";
              cin.ignore();
              getline(cin, title);
              data.SearchBook(title);
              break;
             }
             case 4:
                  cout << "Are you sure you want to Exit? (Yes or No): ";
                  cin >> exit;
                  if (exit == "Yes" ||exit== "yes"  ){
                    lastchoice = false;
                  }
             break;
             default:
                  cout << "Invalid Input! Please Try Again. " << endl;
             break;
}
} while (lastchoice); 

  cout << "Exiting program... ";
  return 0;
  
}