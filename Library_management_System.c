#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_LENGTH 100
#define AUTHOR_LENGTH 50

typedef struct {
    int id;
    char title[TITLE_LENGTH];
    char author[AUTHOR_LENGTH];
} Book;

Book library[MAX_BOOKS];
int bookCount = 0;

void addBook() {
    if (bookCount >= MAX_BOOKS) {
        printf("Library is full. Cannot add more books.\n");
        return;
    }

    Book newBook;
    newBook.id = bookCount + 1;

    printf("Enter book title: ");
    getchar(); // Clear the newline character from the input buffer
    fgets(newBook.title, TITLE_LENGTH, stdin);
    newBook.title[strcspn(newBook.title, "\n")] = '\0'; // Remove the newline character

    printf("Enter book author: ");
    fgets(newBook.author, AUTHOR_LENGTH, stdin);
    newBook.author[strcspn(newBook.author, "\n")] = '\0'; // Remove the newline character

    library[bookCount] = newBook;
    bookCount++;
    printf("Book added successfully!\n");
}

void viewBooks() {
    if (bookCount == 0) {
        printf("No books in the library.\n");
        return;
    }

    printf("Library Books:\n");
    for (int i = 0; i < bookCount; i++) {
        printf("ID: %d, Title: %s, Author: %s\n", library[i].id, library[i].title, library[i].author);
    }
}

void searchBook() {
    char searchTitle[TITLE_LENGTH];
    printf("Enter the title of the book to search: ");
    getchar(); // Clear the newline character from the input buffer
    fgets(searchTitle, TITLE_LENGTH, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = '\0'; // Remove the newline character

    for (int i = 0; i < bookCount; i++) {
        if (strcmp(library[i].title, searchTitle) == 0) {
            printf("Book found: ID: %d, Title: %s, Author: %s\n", library[i].id, library[i].title, library[i].author);
            return;
        }
    }
    printf("Book not found.\n");
}

void deleteBook() {
    int bookId;
    printf("Enter the ID of the book to delete: ");
    scanf("%d", &bookId);

    int index = -1;
    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == bookId) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Book not found.\n");
        return;
    }

    for (int i = index; i < bookCount - 1; i++) {
        library[i] = library[i + 1];
    }
    bookCount--;
    printf("Book deleted successfully!\n");
}

int main() {
    int choice;

    while (1) {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. View Books\n");
        printf("3. Search Book\n");
        printf("4. Delete Book\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                viewBooks();
                break;
            case 3:
                searchBook();
                break;
            case 4:
                deleteBook();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
