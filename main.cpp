#include "mainmenu.h"

//Stylesheet:
//**************************************************************************************************************************************************
// * PROGRAMMED BY : Ngoc Dang Tran
// * CLASS : CS1B
// * SECTION : MW: 9:30 - 11:50
// * FILE NAME : main.cpp
// * ASSIGNMENT : Serendipity
//**************************************************************************************************************************************************
//  PURPOSE : Develop a point-of-sale  (POS)  software  package  that  will  make  the  computer  function  as  a  cash  register and keep an inventory file.
//            The inventory file will be a database of all the books in the bookstore. In general, the software is to perform the following tasks:
//              •Calculate the total of a sale, including sales tax
//              •When a book is purchased, subtract it from the inventory file
//              •Add, change, delete, and look up books in the inventory file
//              •Display various sales reports
//**************************************************************************************************************************************************
//* The program below displays a menu on the screen, which allows the user to activate any of the modules
//**********************************************************
//*               Serendipity Booksellers                  *
//*                      Main Menu                         *
//*                 1. Cashier Module                      *
//*                 2. Inventory Database Module           *
//*                 3. Report Module                       *
//*                 4. Exit                                *
//**********************************************************
//*                 Enter Your Choice(1-4):                *
//**************************************************************************************************************************************************
// ALGORITHM :
// Step 1: Display menu screen
// Step 2: Ask the user to input a number (1 - 4) which represents the module that wanted to go
//        If the number is out of range (choice < 1 || choice > 4), the program displays the message:
//            "You have entered an invalid choice. Please enter a number in the range 1-4.""
// Step 3: Prompts the user to the wanted modules
//**************************************************************************************************************************************************
//Main program
int main()
{
//Data table
char choice, discard;
string search, upSearch;        //A string object hold the name of the book that user want to search
bool exit = false;
cout << setprecision(2) << fixed;			//Set up number formatting

orderedLinkedList<bookType*> onlyList;
onlyList.initializeList();
linkedListIterator<bookType*> it;

//Display Main Menu
do
    {
        system("clear");    //Clear screen
        cout << "*****************************************************************" << endl;
        cout << "*                    Serendipity Booksellers                    *" << endl;
        cout << "*                           Main Menu                           *" << endl;
        cout << "*                  1. Cashier Module                            *" << endl;
        cout << "*                  2. Inventory Database Module                 *" << endl;
        cout << "*                  3. Report Module                             *" << endl;
        cout << "*                  4. Exit                                      *" << endl;
        cout << "*****************************************************************" << endl;
        cout << "*                  Enter your choice (1-4): ";
        cin >> choice;
        cin.ignore(1000, '\n');
        //Prompts the user to the desired Module
        switch (choice)
        {

        case '1':
            //Output message if the book database is empty
            if(bookType::getBookCount() <= 0)
                {
                    cout << "Sorry the database is empty! Can not find book! Press any key to continue.." << endl;
                    cin >> discard;
                }
            else
                cashier(onlyList);
            break;

        case '2':
            invMenu(onlyList);
            break;

        case '3':
            if(bookType::getBookCount() <= 0)
                {
                    cout << "Sorry, there is no book to report! Press any key to continue.." << endl;
                    cin >> discard;
                }
            else
                reports(onlyList);
            break;
                                                   
        case '4': //exit the while loop
            exit = true;
            break;

        default:
            cout << "You have entered an invalid choice. Please enter a number in the range 1-4." << endl << endl;
            }
}while (!exit);

system("clear");
return 0;
}
