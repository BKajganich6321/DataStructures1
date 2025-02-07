#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

typedef struct Book
{
	int id;
	char title[100];
	char author[100];
	int publication_year;
	struct Book* next;
} Book;



void addBook(Book** head, int id, const char* title, const char* author, int
	publication_year);

void viewBooks(Book* head);

void updateBook(Book* head, int id);

void deleteBook(Book** head, int id);

void searchBooks(Book* head, const char* title);

double getNum(void);


void main()
{
	int choice = 0;
	int chosenID;
	int exit = 0;
	Book **currentBook;
    Book *firstBook;
	while (exit == 0)
	{
		printf("Please select one of the following options:\n");
		printf("1. Add a Book to the Library\n");
		printf("2. Delete a Book from the Library\n");
		printf("3. Search for a Book in the Library\n");
		printf("4. Update a Book currently in the Library\n");
		printf("5. View All the Books in the Library\n");
		printf("6. Exit\n");
		printf("Enter Your Choice: ");
		choice = (int)(getNum());
		switch (choice)
		{
			case 1:
				printf("Please enter the new Book ID number: ");

				break;
			case 2:
				printf("Please Enter ID Number of Book to be Deleted: ");
				chosenID = getNum();
				updateBook(&currentBook, chosenID);
				break;
			case 3:
				break;
			case 4:
				printf("Please Enter ID Number of Updating Book: ");
				chosenID = getNum();
				updateBook(currentBook, chosenID);
				break;
			case 5:
				viewBooks(firstBook);
				break;
			case 6:
				exit = 1;
				break;
			default:
				printf("That input is not a valid choice. Please try again");
				break;
		}
	}
	

}

/* FUNCTION: deleteBook
 PARAMETERS: Book** head: Pointer to first book
			 int id: it will check the book that needs to be removed
	 ACTION: This function will delete the book from the linked
			 list and free the memory
	RETURNS: Void */
void deleteBook(Book** head, int id)
{
	// check if the list is empty
	if (*&head == NULL)
	{
		return;
	}
	Book* currentBook = *head; // the pointer will  to the first book
	Book* previousBook = NULL; // this will track the previous book

	// a loop to get across the linked list
	while (currentBook != NULL)
	{
		// this will check if the book will match the id
		if (currentBook->id == id)
		{
			// if want to remove is the first one in the list
			if (previousBook == NULL)
			{
				*head = currentBook->next; //move the head to the next book so it won't be lost

			}

			// incase the book is somewhere in the linked list
			else
			{
				previousBook->next = currentBook->next; // link the previous book to the next

			}
			free(currentBook); // this will free the memorty of the deleted book
			return;

		}
		previousBook = currentBook; // this will update the previous book
		currentBook = currentBook->next; // this will move the current book to the next one
	}
}

/* FUNCTION: ViewBooks
 PARAMETERS: Book* head (Pointer to first book in list)
	 ACTION: Accept a pointer to the first Book in the list and print it followed by all other
			 books in the library including their details.
	 RETURN: void */
void viewBooks(Book* head)
{
	if (head == NULL)
	{
		printf("There are no books in the library");
	}
	else
	{
		printf("Current Library Database:\n\n");
		while (head != NULL)
		{
			printf("Book ID Number: %d\n", head->id);
			printf("Title: %s\n", head->title);
			printf("Author: %s\n", head->author);
			printf("Publication Year: %d\n\n", head->publication_year);
			head = head->next;
		}
	}	
}

/* FUNCTION: GetNum
 PARAMETERS: void
	 ACTION: Scans a user input for a number, returns  a double of that number
			 if a valid input is not given, returns -1
	***This function was explicitly provided to all students last semester***
	 RETURN: double: value of user input, -1 if invalid */
double getNum(void)
{
	char record[121] = { 0 }; // Buffer to store input string
	double number = 0.0; // Variable to store the converted number
	// Prompt the user for input and read the input string
	fgets(record, 121, stdin);
	// Attempt to convert the string to a double
	if (sscanf(record, "%lf", &number) != 1) {
		// If conversion fails, set the number to -1
		number = -1.0;
	}
	return number; // Return the double (or -1 if conversion failed)
}
