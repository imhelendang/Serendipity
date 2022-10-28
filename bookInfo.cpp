#include "mainmenu.h"
#include "bookType.h"
/**********************************************************
* AUTHOR : Ngoc Dang Tran;
* STUDENT ID : 1197865;
* ASSIGNMENT : Serendipity
* CLASS : CS1B;
* SECTION : MW: 9:30am-11:50am;
* DUE DATE : 01/27/2021;
**********************************************************/

//--------------------------------------------------------------------------------------------------------------------------------------------
//                                 BOOK INFORMATION
//--------------------------------------------------------------------------------------------------------------------------------------------
//This function display the book's information for the users
void bookType::bookInfo()
{
	cout << left;

	cout << "**************************************************************************************************" << endl;
	cout << "*                                    Serendipity Booksellers                                      " << endl;
	cout << "*                                       Book Information                                          " << endl;
	//Display the information
	cout << "* ISBN:             " << getISBN() << endl;
	cout << "* Title:            " << getTitle() << endl;
	cout << "* Author:           " << getAuthor() << endl;
	cout << "* Publisher:        " << getPub() << endl;
	cout << "* Date Added:       " << getDatedAdded() << endl;
	cout << "* Quantity In Hand: " << getqty() << endl;
	cout << "* Wholesale Cost:  $" << getWholeSale() << endl;
	cout << "* Retail Price:    $" << getRetail() << endl;
	cout << "**************************************************************************************************" << endl;

	return;
}
