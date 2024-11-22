#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Review Class
class Review {
private:
    string reviewerName;
    string content;

public:
    Review(string name, string reviewContent) : reviewerName(name), content(reviewContent) {}

    string getReviewerName() const { return reviewerName; }
    string getContent() const { return content; }

    void display() const {
        cout << "Reviewer: " << reviewerName << endl;
        cout << "Review: " << content << endl;
    }

    bool containsText(const string& text) const {
        return reviewerName.find(text) != string::npos || content.find(text) != string::npos;
    }
};

// Book Class
class Book {
private:
    string title;
    string author;
    vector<Review> reviews;

public:
    Book(string t, string a) : title(t), author(a) {}

    string getTitle() const { return title; }
    string getAuthor() const { return author; }

    void addReview(const Review& review) {
        reviews.push_back(review);
    }

    void display() const {
        cout << "\nTitle: " << title << ", Author: " << author << endl;
        cout << "Reviews:" << endl;
        if (reviews.empty()) {
            cout << "No reviews yet." << endl;
        }
        else {
            for (const auto& review : reviews) {
                review.display();
                cout << "---------------------" << endl;
            }
        }
    }

    void searchReviews(const string& searchText) const {
        cout << "\nSearch Results in Book \"" << title << "\":" << endl;
        bool found = false;
        for (const auto& review : reviews) {
            if (review.containsText(searchText)) {
                review.display();
                cout << "---------------------" << endl;
                found = true;
            }
        }
        if (!found) {
            cout << "No matching reviews found." << endl;
        }
    }
};

// Library Class
class Library {
private:
    vector<Book> books;

public:
    void addBook(const Book& book) {
        books.push_back(book);
    }

    void displayAllBooks() const {
        for (const auto& book : books) {
            book.display();
        }
    }

    void searchReviewsInLibrary(const string& searchText) const {
        cout << "\nSearching for \"" << searchText << "\" in all reviews:" << endl;
        bool found = false;
        for (const auto& book : books) {
            book.searchReviews(searchText);
            found = true;
        }
        if (!found) {
            cout << "No matching reviews found in the library." << endl;
        }
    }
};

// Main Function
int main() {
    Library library;

    Book book1("1984", "George Orwell");
    book1.addReview(Review("Alice", "A chilling dystopian masterpiece."));
    book1.addReview(Review("Bob", "Thought-provoking and timeless."));

    Book book2("To Kill a Mockingbird", "Harper Lee");
    book2.addReview(Review("Charlie", "A powerful story about justice and morality."));
    book2.addReview(Review("Alice", "Deeply moving and beautifully written."));

    library.addBook(book1);
    library.addBook(book2);

    cout << "--- Library Books and Reviews ---" << endl;
    library.displayAllBooks();

    string searchText;
    cout << "\nEnter text to search in reviews: ";
    getline(cin, searchText);

    library.searchReviewsInLibrary(searchText);

    return 0;
}
