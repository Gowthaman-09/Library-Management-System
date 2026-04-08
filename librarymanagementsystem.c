#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 10000
#define MAX_LETTERS 50

void showMenu(int arrBookId[][2],char arrBookTitle[][MAX_LETTERS],char arrBookAuthor[][MAX_LETTERS],int *size);
int addBook(int arrBookId[][2],char arrBookTitle[][MAX_LETTERS],char arrBookAuthor[][MAX_LETTERS],int *size);
int searchBook(int arrBookId[][2],char arrBookTitle[][MAX_LETTERS], char arrBookAuthor[][MAX_LETTERS], int *size);
int returnBook(int arrBookId[][2],char arrBookTitle[][MAX_LETTERS],char arrBookAuthor[][MAX_LETTERS],int *size);
int isuueBook(int arrBookId[][2],char arrBookTitle[][MAX_LETTERS],char arrBookAuthor[][MAX_LETTERS],int *size);
int viewAllBook(int arrBookId[][2],char arrBookTitle[][MAX_LETTERS],char arrBookAuthor[][MAX_LETTERS],int *size);

int main()
{
    int count = 0;
    int arrBookId[MAX_BOOKS][2];

    char arrBookAuthor[MAX_BOOKS][MAX_LETTERS];
    char arrBookTitle[MAX_BOOKS][MAX_LETTERS];

    showMenu(arrBookId,arrBookTitle,arrBookAuthor,&count);

    return 0;
}


void showMenu(int arrBookId[][2],char arrBookTitle[][MAX_LETTERS],char arrBookAuthor[][MAX_LETTERS],int *size)
{

    printf("\n===== Library Management System =====\n\n");
    printf("1. Add new book\n");
    printf("2. View all books\n");
    printf("3. Issue a book\n");
    printf("4. Return a book\n");
    printf("5. Search for a book\n");
    printf("0. Exit\n\n");

    int ddChoice;
    printf("Enter the choice:  ");
    scanf("%d",&ddChoice);

    switch(ddChoice)
    {

    case 0:
        printf("Exiting...\n\n");
        printf("Thank you !!!\n");
        exit(EXIT_SUCCESS);
        break;

    case 1:
        addBook(arrBookId,arrBookTitle,arrBookAuthor,size);
        break;

    case 2:
        viewAllBook(arrBookId, arrBookTitle, arrBookAuthor, size);
        break;

    case 3:
        isuueBook(arrBookId,arrBookTitle,arrBookAuthor,size);
        break;

    case 4:
        returnBook(arrBookId,arrBookTitle,arrBookAuthor,size);
        break;


    case 5:
        searchBook(arrBookId,arrBookTitle,arrBookAuthor,size);
        break;


    default:
        printf("Invalid choice... Enter choice again...\n");
        showMenu(arrBookId,arrBookTitle,arrBookAuthor,size);

    }
}
//1.Add new books to a library (title and author)  -  sathira AS20240401
int addBook(int arrBookId[][2], char arrBookTitle[][MAX_LETTERS], char arrBookAuthor[][MAX_LETTERS], int *size)
{
    printf("\n----Book Adding Section----\n");
    char choiceYN = 'Y' ;
    int bookid;

    if(*size<MAX_BOOKS)
    {
        printf("\nEnter Book ID    : ");
        scanf("%d",&bookid);
        while (getchar() != '\n');

        if(bookid==00000)
        {
            printf("Bookid can't be 0... Add bookid again...\n");
            addBook(arrBookId,arrBookTitle,arrBookAuthor,size);
        }

        else
        {
        // search availability of entered book
        for(int i=0; i<*size; i++)
        {
            if(bookid==arrBookId[i][0])
            {
                printf("\n\tBook ID already exists...\n\n");
                showMenu(arrBookId,arrBookTitle,arrBookAuthor,size);
            }
        }
        arrBookId[*size][0]=bookid;

//if book is not available then add it in to library

        printf("Enter Book Title : ");
        fgets(arrBookTitle[*size], sizeof(arrBookTitle[*size]), stdin);
        arrBookTitle[*size][strcspn(arrBookTitle[*size], "\n")] = 0;

        printf("Enter Author Name: ");
        fgets(arrBookAuthor[*size], sizeof(arrBookAuthor[*size]), stdin);
        arrBookAuthor[*size][strcspn(arrBookAuthor[*size], "\n")] = 0;


        arrBookId[*size][1]=1;

        printf("(Successfully added...)\n\n");
        (*size)++;// size +1 to increase array size
       }
    }
    else
    {
        printf("\n\tBook Array Is Full...So you can't store books... \n");
        showMenu(arrBookId,arrBookTitle,arrBookAuthor,size);
    }

    printf("Do you want to add an another book(Y or N): ");
    scanf("%c", &choiceYN);

    if(choiceYN=='N')
    {
        showMenu(arrBookId,arrBookTitle,arrBookAuthor,size);
    }

    //if user want add a book again
    else if(choiceYN=='Y')
    {
        addBook(arrBookId,arrBookTitle,arrBookAuthor,size);
    }
    else
    {
        printf("Invalid input... \n");
        showMenu(arrBookId,arrBookTitle,arrBookAuthor,size);
    }
}



//2. view all book function by J.M Hasintha Dilshan AS20240579
int viewAllBook(int arrBookId[][2],char arrBookTitle[][MAX_LETTERS],char arrBookAuthor[][MAX_LETTERS],int *size)
{
     if(*size==0)
    {
        printf("\nThere is no books in the library!\n");
    }
    else
    {
    printf("\n-----View All Books-----\n");
    int i;
    for(i=0; i<*size; i++)
    {

        printf("\nBook Id number%c %04d\n",':',arrBookId[i][0]);
        printf("Title of the book: %s\n",arrBookTitle[i]);
        printf("Author of the book: %s\n",arrBookAuthor[i]);

        if(arrBookId[i][1]==1)
        {

            printf("Availability:Yes\n\n");
        }
        else
        {
            printf("Availability:No\n\n");
        }
    }
    }
    showMenu(arrBookId,arrBookTitle,arrBookAuthor,size);

}

//3.issue book function by D.V.Sayuri AS20240480
int isuueBook(int arrBookId[][2],char arrBookTitle[][MAX_LETTERS],char arrBookAuthor[][MAX_LETTERS],int *size)
{
    printf("\n----Issue Book Section---\n");
    int available = 0;
    for(int i = 0; i < *size; i++) {
        if(arrBookId[i][1] == 1) {
            available = 1;
            break;
    }
}
    if(*size==0||available ==0){
        printf("There are no books available in the system.\n");
        showMenu(arrBookId,arrBookTitle,arrBookAuthor,size);
    }else{
    int i;
    while (getchar() != '\n');

    int issueBookId;
    printf("Enter the ID number of the book - ");
    scanf("%d",&issueBookId);
    for(i=0; i<*size; i++)
    {
        if(arrBookId[i][0]==issueBookId)
        {

            if(arrBookId[i][1]==0){
                printf("This book is already issued.\n");
            }else{
            arrBookId[i][1]=0;
            printf("Book Issued Successfully.\n");

            }
            break;
        }
    }
    if(i==*size)
    {
        printf("Book ID does not match.\n");
    }

    showMenu(arrBookId,arrBookTitle,arrBookAuthor,size);
    }


}

//4.return book function by W.H.D Wickramasinghe AS20240514
int returnBook(int arrBookId[][2], char arrBookTitle[][MAX_LETTERS], char arrBookAuthor[][MAX_LETTERS], int *size)
{
    printf("\n----Book Return Section----\n");

    if (*size == 0)
    {
        printf("\nNo books available in the library!\n");

        char oppChoice[20];
        printf("Do you want to add a new book? Enter Yes (otherwise No): ");
        scanf("%s", oppChoice);

        if (strcmp(oppChoice, "Yes") == 0)
        {
            addBook(arrBookId, arrBookTitle, arrBookAuthor, size);
        }

        showMenu(arrBookId, arrBookTitle, arrBookAuthor, size);
        return 0;
    }

    while (getchar() != '\n');
    int returnBookId;
    int checker = 0;

    printf("Enter the ID number of the book - ");
    scanf("%d", &returnBookId);

    for (int i = 0; i < *size; i++)
    {
        if (arrBookId[i][0] == returnBookId)
        {
            if(arrBookId[i][1] == 1)
            {
                printf("\n Book is already in the Library!\n");
                checker = 1;
            }
            else
            {
            arrBookId[i][1] = 1;
            printf("\nBOOK RETURNED SUCCESSFULLY\n");
            checker = 1;
            }

        }
    }

    if (!checker)
    {
        char oppChoice[20];
        while (getchar() != '\n');
        printf("Book is not found! Do you want to add it as a new book? Enter Yes (otherwise No): ");
        scanf("%s", oppChoice);

        if (strcmp(oppChoice, "Yes") == 0)
        {
            addBook(arrBookId, arrBookTitle, arrBookAuthor, size);
        }
    }

    showMenu(arrBookId, arrBookTitle, arrBookAuthor, size);
    return 0;
}

//5.Search for a book by title or author - Gowthaman AS20240539
int searchBook(int arrBookId[][2],char arrBookTitle[][MAX_LETTERS], char arrBookAuthor[][MAX_LETTERS], int *size)
{

    int choice;
    char userentered[50];
    int i;
    int j ;



    printf("\n 1.Search for a book by title\n");
    printf(" 2.Search for a book by author\n");
    printf("\n Enter your choice: ");
    scanf("%d",&choice);
    while (getchar() != '\n');

    if(choice == 1)
    {
        printf("\n Enter the title of the book: ");
        fgets(userentered, sizeof(userentered), stdin);
        userentered[strcspn(userentered, "\n")] = 0;

        for(i=0; i<*size; i++)
        {
            if(strcmp(arrBookTitle[i], userentered)==0)
            {
                printf("\n\tBook Id%8c %04d\n",':',arrBookId[i][0]);
                printf("\tBook Title%5c %s \n",':',arrBookTitle[i]);
                printf("\tBook Author%4c %s ",':',arrBookAuthor[i]);

                if(arrBookId[i][1]==1)
                {
                    printf("\n\tBook Availabe%2c Yes\n\n",':');
                }
                else
                {
                    printf("\n\tBook Availabe%2c No\n\n",':');
                }
                showMenu(arrBookId,arrBookTitle,arrBookAuthor,size);

            }
        }

    }
    else if(choice == 2)
    {
        printf("\n Enter the author of the book: ");
        fgets(userentered, sizeof(userentered), stdin);
        userentered[strcspn(userentered, "\n")] = 0;
        for(i=0; i<*size; i++)
        {

            if(strcmp(arrBookAuthor[i], userentered)==0)
            {

                printf("\n\tBook Id%8c %04d\n",':',arrBookId[i][0]);
                printf("\tBook Title%5c %s \n",':',arrBookTitle[i]);
                printf("\tBook Author%4c %s ",':',arrBookAuthor[i]);

                if(arrBookId[i][1]==1)
                {
                    printf("\n\tBook Availabe%2c Yes\n\n",':');
                }
                else
                {
                    printf("\n\tBook Availabe%2c No\n\n",':');
                }

                showMenu(arrBookId,arrBookTitle,arrBookAuthor,size);

            }

        }

    }
    printf("\n\tBook Not Found\n\n");
    showMenu(arrBookId,arrBookTitle,arrBookAuthor,size);
}












