/**********************************************************
* AUTHOR : Ngoc Dang Tran;
* FILE NAME : mainmenu.h
* ASSIGNMENT : Serendipity
* CLASS : CS1B;
* SECTION : MW: 9:30am-11:50am;
**********************************************************/

#ifndef MAINMENU_H_
#define MAINMENU_H_

#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bookType.h"
#include "orderedLinkedList.h"

using namespace std;

//Constant variable
//const int DATASIZE = 125;
const int BOOKPERSCREEN = 20;

//Function prototype
//--------------------------------------------------------------------------------------------------------------------------------------------
//                            CASHIER PROTOTYPES
//--------------------------------------------------------------------------------------------------------------------------------------------
void cashier(orderedLinkedList<bookType*> &);
//This function prompts the users to the Cashier Module

void receipt(orderedLinkedList<bookType*> &, int cart[]);
//This function prints the final receipt for the user

//--------------------------------------------------------------------------------------------------------------------------------------------
//                            					INVENTORY PROTOTYPES
//--------------------------------------------------------------------------------------------------------------------------------------------
void invMenu(orderedLinkedList<bookType*> &);
//This function prompts the users to the Inventory invModule

//int lookUpBook(orderedLinkedList<bookType*> &, orderedLinkedList<bookType*> &);
//This function prompts the users to look up book

string upper(string search);
//This function capitalize the c-string

void addBook(orderedLinkedList<bookType*> &);
//This function prompts the users to add book

void editBook(orderedLinkedList<bookType*> &);
//This function prompts the users to edit book

void deleteBook(orderedLinkedList<bookType*> &);
//This function prompts the users to delete book


//--------------------------------------------------------------------------------------------------------------------------------------------
//                            REPORT PROTOTYPES
//--------------------------------------------------------------------------------------------------------------------------------------------
void reports(orderedLinkedList<bookType*> &);
//This function prompts the users to the Report Module

void repListing(orderedLinkedList<bookType*> &);
//This function prompts the users to the Inventory Listing Module

void repWholesale(orderedLinkedList<bookType*> &);
//This function prompts the users to the Inventory Whole Sale Module

void repRetail(orderedLinkedList<bookType*> &);
//This function prompts the users to the Inventory Ratail Module

void repQty(orderedLinkedList<bookType*> &);
//This function prompts the users to the Listing by Quanity Module

void repCost(orderedLinkedList<bookType*> &);
//This function prompts the users to the Listing by Cost Module

void repAge(orderedLinkedList<bookType*> &);
//This function prompts the users to the Listing by Age Module

//--------------------------------------------------------------------------------------------------------------------------------------------
//                            ADDITIONAL FUNCTIONS
//--------------------------------------------------------------------------------------------------------------------------------------------
void date();
//Function to print out date on reports/reciept

void time();
//Function to print out time on reports/reciept
#endif /* MAINMENU_H_ */