#include "mainmenu.h"
#include "bookType.h"
/**********************************************************
* AUTHOR : Ngoc Dang Tran;
* STUDENT ID : 1197865;
* ASSIGNMENT : Serendipity
* CLASS : CS1B;
* SECTION : MW: 9:30am-11:50am;
* DUE DATE : 01/27/2021;
***********************************************************/

//--------------------------------------------------------------------------------------------------------------------------------------------
//                         INVENTORY MODULE
//*****************************************************************
//*                     Serendipity Booksellers                   *
//*                        Inventory Database                     *
//*                      1. Look Up a Book                        *
//*                      2. Add a Book                            *
//*                      3. Edit a Book’s Record                  *
//*                      4. Delete a Book                         *
//*                      5. Return to the Main Menu               *
//*****************************************************************
//*                      Enter Your Choice(1-5):                  *
//--------------------------------------------------------------------------------------------------------------------------------------------
//Function to prompts to the Inventory
//The Inventory Module are set according to the parameters
//Precondition: the choice range from 1 to 4
//Postcondition: The function will receive the number '2' then display the contents
//               The function prompt the user to activate another modules
void invMenu(orderedLinkedList<bookType*> &onlyList)
{
char choice, discard, view;
string search, upSearch;        //A string object hold the name of the book that user want to search
int index;
bool exit = false;
bool quit = false;
cout << setprecision(2) << fixed;			//Set up number formatting
linkedListIterator<bookType*> find;
orderedLinkedList<bookType*> it;

do
    {
        system("clear");
        cout << "*****************************************************************" << endl;
        cout << "*                    Serendipity Booksellers                    *" << endl;
        cout << "*                      Inventory Database                       *" << endl;
        cout << "*                  1. Look Up a Book                            *" << endl;
        cout << "*                  2. Add a Book                                *" << endl;
        cout << "*                  3. Edit a Book's Record                      *" << endl;
        cout << "*                  4. Delete a Book                             *" << endl;
        cout << "*                  5. Return to the Main Menu                   *" << endl;
        cout << "*****************************************************************" << endl;
        cout << "*                  Enter your choice (1-5): ";
        cin >> choice;
        cin.ignore(1000, '\n');

        switch (choice)
            {

            case '1':
                if(bookType::getBookCount() >= 0)
                    {
                        index = 0;
                        //Display the Look Up Book MODULE
                        cout << "\n*                         Book Look Up                          *" << endl;
                        cout << "*Search (by Title): ";
                        getline(cin, search);
                        upSearch = search;
                        upSearch = upper(upSearch);

						for(find = onlyList.begin(); find != onlyList.end(); ++find)
							{
								find = it.lookUpBook(onlyList, find, upSearch);
								if(find == NULL)
					                break;
								else
									{
										system("clear");
										cout << "Search: " << search;
										cout << "\nRESULT: " << endl;
										(*find)->bookInfo();
										cout << "\n\nIs this the correct result? (Y/N): ";
										cin.get(view);
										cin.ignore();

										//If the user enters an invalid choice
										while (view != 'Y' && view != 'y' && view != 'N' && view != 'n')
										{
											cout << "\nYou entered an invalid choice! Please enter Y/N or y/n!";
											cin >> view;
											cin.ignore(1000, '\n');
										}

										//-------------------------------------------------------------------------------
										//The user decide whether to view the book record
										//-------------------------------------------------------------------------------
										if (view == 'Y' || view == 'y')
										{
											quit = true;
											break;
										}
										else if (view == 'N' || view == 'n')
											continue;
										else if (view != 'N' || view != 'n' || view != 'Y' || view != 'y')
											cout << "You entered an invalid choice! Please enter Y/N or y/n!" << endl;
									}
							}
						if(quit == false)					//If the book isn't found
							{
								cout << "Sorry. The book you searched for is not in the inventory!" << endl;
								cout << "Press any key to continue..";
								cin >> choice;
								cin.ignore();
							}
					}//End if
				else
					{
						cout << "The data is empty! Can not process the Look Up Book module!\n";
						cout << "\nPress any key to continue.." << endl;
						cin.get(discard);
						cin.ignore(1000 , '\n');
					}
                break;

            case '2':
                addBook(onlyList);
                break;

            case '3':
                if(bookType::getBookCount() < 0)
                    {
                        cout << "Sorry the database is empty! Can not find book to edit! Press any key to continue.." << endl;
                        cin.get(discard);
                        cin.ignore(1000 , '\n');
                    }
                else
                editBook(onlyList);
                break;

            case '4':
                if(bookType::getBookCount() < 0)
                    {
                        cout << "Sorry the database is empty! Can not find book to delete! Press any key to continue.." << endl;
                        cin.get(discard);
                        cin.ignore(1000 , '\n');
                    }
                else
                    deleteBook(onlyList);
                break;

            case '5':
                exit = true;
                break;

            default:
                system("clear");
                cout << "You have entered an invalid choice. Please enter a number in the range 1-5." << endl << endl;
                cout << "Press any key to continue..";
                cin.get(discard);
                cin.ignore();
        }
    } while (!exit);
return;
}


//This function used to capitalize a c-string
//The function will be done according to the parameters
//Postcondition:
//Precondition: The function will read in the string and capitalize all each character of a string
//              then return the module
string upper(string search)
{
    for(int i = 0; search[i] != '\0'; i++)
    {
    if (search[i] >= 'a' && search[i] <= 'z')
        search[i] = search[i] - 32;        //transforming lowercase to uppercase
    }
return search;
}



//--------------------------------------------------------------------------------------------------------------------------------------------
//                                                               ADD BOOK
//--------------------------------------------------------------------------------------------------------------------------------------------
//**************************************************************************************************
//*                                    Serendipity Booksellers                                     *
//*                                            Add Book                                            *
//*                                        Pending Values                                          *
//*                                                                                                *
//* Database Size: DATASIZE         Current Book Count: index                                      *
//* <1> Enter Book Tile             >> title                                                       *
//* <2> Enter ISBN                  >> numIsbn                                                     *
//* <3> Enter AUTHOR                >> author                                                      *
//* <4> Enter Publisher             >> publisher                                                   *
//* <5> Enter Date Added(mm/dd/yyyy)>> date                                                        *
//* <6> Enter Quantity on Hand      >> numQty                                                      *
//* <7> Enter Wholesale Cost        >> wholeSale                                                   *  -- This variable should be displayed as $0.00
//* <8> Enter Retail Price          >> retail                                                      *  -- This variable should be displayed as $0.00
//* <9> Save Book to Database                                                                      *
//* <0> Return to Inventory Menu                                                                   *
//**************************************************************************************************
//        Enter your choice(0-9):
//--------------------------------------------------------------------------------------------------------------------------------------------
//Function prompts the user to add book by selecting the choice and do the tasks.
//Precondition:
//Postcondition:
void addBook(orderedLinkedList<bookType*> &onlyList)
{
cout << setprecision(2) << fixed;			//Set up number formatting

char choice, discard;
//Data table
bool exit = false;
string tempDate;
string tempAuthor;
string tempPublisher;
string tempIbsn;
string tempTitle;
int tempQty;
double tempWholeSale;
double tempRetail;
double total = 0;
double sum = 0;
linkedListIterator<bookType*> find;

//CLEAN all the characters in temp varibles
bookType *book = NULL;
tempDate = "EMPTY";
tempAuthor = "EMPTY";
tempPublisher = "EMPTY";
tempIbsn = "EMPTY";
tempTitle = "EMPTY";
tempQty = 0;
tempWholeSale = 0.00;
tempRetail = 0.00;

do
    {
        system("clear");
        cout << "**************************************************************************************************" << endl;
        cout << "*                                    Serendipity Booksellers                                     *" << endl;
        cout << "*                                            Add Book                                            *" << endl;
        cout << "*                                        Pending Values                                          *" << endl;
        cout << "*                                                                                                *" << endl;
        cout << "* Current Book Count: " << left << setw(3) << bookType::getBookCount() << "                                                                        *" << endl;
		cout << "*                                                                                                *" << endl;
        cout << "* <1> Enter Book Title            >> " << left << setw(60) << tempTitle.substr(0, 60) << "*" << endl;
        cout << "* <2> Enter ISBN                  >> " << left << setw(60) << tempIbsn << "*" << endl;
        cout << "* <3> Enter Author                >> " << left << setw(60) << tempAuthor << "*" << endl;
        cout << "* <4> Enter Publisher             >> " << left << setw(60) << tempPublisher << "*" << endl;
        cout << "* <5> Enter Date Added(mm/dd/yyyy)>> " << left << setw(60) << tempDate << "*" << endl;
        cout << "* <6> Enter Quantity on Hand      >> " << left << setw(60) << tempQty << "*" << endl;
        cout << "* <7> Enter Wholesale Cost        >> $" << left << setw(59) << tempWholeSale << "*" << endl;
        cout << "* <8> Enter Retail Price          >> $" << left << setw(59) << tempRetail << "*" << endl;
        cout << "* <9> Save Book to Database                                                                      *" << endl;
        cout << "* <0> Return to Inventory Menu                                                                   *" << endl;
        cout << "**************************************************************************************************" << endl;
        cout << "        Enter your choice(0-9): ";
        cin >> choice;
        cin.ignore();

        switch(choice)
        {
            case '0':
                exit = true;
                break;

            case '1':
                cout << "Enter Book Title: ";
                getline(cin, tempTitle);
                break;

            case '2':
                cout << "Enter ISBN: ";
                getline(cin, tempIbsn);
                break;

            case '3':
                cout << "Enter Author: ";
                getline(cin, tempAuthor);
                break;

            case '4':
                cout << "Enter Publisher: ";
                getline(cin, tempPublisher);
                break;

            case '5':
                cout << "Enter Date Added(mm/dd/yyyy): ";
                getline(cin, tempDate);
                break;

            case '6':
                cout << "Enter Quantity on Hand: ";
                cin >> tempQty;
                cin.ignore(1000, '\n');
                break;

            case '7':
                cout << "Enter Wholesale Cost: ";
                cin >> tempWholeSale;
                cin.ignore(1000, '\n');
                break;

            case '8':
                cout << "Enter Retail Price: ";
                cin >> tempRetail;
                cin.ignore(1000, '\n');
                break;

            case '9':
                book = new bookType(tempAuthor, tempPublisher, tempDate, tempQty, tempIbsn, tempTitle, tempWholeSale, tempRetail);
				bookType::sCode = 0;
                onlyList.insert(book);
                bookType::incBookCount();   //increase book count

                //RESET all the characters in temp varibles
                tempDate = "EMPTY";
                tempAuthor = "EMPTY";
                tempPublisher = "EMPTY";
                tempIbsn = "EMPTY";
                tempTitle = "EMPTY";
                tempQty = 0;
                tempWholeSale = 0.00;
                tempRetail = 0.00;
                break;

            case '\n':
                break;

            default:
                cout << choice << endl;
                cout << "You have entered an invalid choice. Please enter a number in the range 0-9." << endl;
                cout << "Press any key to continue..";
                cin.get(discard);
                cin.ignore(1000, '\n');
                break;
        }		//End switch statement
    } while (!exit);	//End do while loop

/*for(find = onlyList.begin(); find != onlyList.end(); ++find)
		{
            total = (*find)->getWholeSale() * (*find)->getqty();
            sum += total;
        }
        cout << "\nTotal : " << sum << endl;*/
return;
}


//Function prompts users to edit book
//Call the function look up book then edit
void editBook(orderedLinkedList<bookType*> &onlyList)
{
system("clear");
string search, upSearch;
int result = 0;
char view, choice, store;
bool stop = false;
bool pause = false;
string tempDate;
string tempAuthor;
string tempPublisher;
string tempIbsn;
string tempTitle;
int tempQty;
double tempWholeSale;
double tempRetail;
linkedListIterator<bookType*> find;
orderedLinkedList<bookType*> tem;

    //CALL/DISPLAY look up book first
    cout << "************************************************************************" << endl;
    cout << "*                            Book Look Up                              *" << endl;
    cout << "* Search (by Title): ";
	getline(cin, search);
	upSearch = search;
	upSearch = upper(upSearch);

	for(find = onlyList.begin(); find != onlyList.end(); ++find)
		{
			find = tem.lookUpBook(onlyList, find, upSearch);
			if(find == NULL)
					break;
			else
				{
					system("clear");
					cout << "Search: " << search;
					cout << "\nRESULT: " << endl;
					(*find)->bookInfo();
					cout << "\n\nIs this the correct result? (Y/N): ";
					cin.get(view);
					cin.ignore();

					//If the user enters an invalid choice
					while (view != 'Y' && view != 'y' && view != 'N' && view != 'n')
						{
							cout << "\nYou entered an invalid choice! Please enter Y/N or y/n!";
							cin >> view;
							cin.ignore(1000, '\n');
						}
					//-------------------------------------------------------------------------------
					//The user decide whether to view the book record
					//-------------------------------------------------------------------------------
					if (view == 'Y' || view == 'y')
					{
						stop = true;
						break;
					}
					else if (view == 'N' || view == 'n')
						continue;
				}
		}
	if(stop == false)					//If the book isn't found
		{
			cout << "Sorry. The book you searched for is not in the inventory!" << endl;
			cout << "Press any key to continue..";
			cin >> choice;
			cin.ignore();
		}

	//--------------------------------------------------------------------------------------------------------------------------------------------------------------
	//The desired book is found
	//Prompt the user to edit the book
	//--------------------------------------------------------------------------------------------------------------------------------------------------------------
	if (stop)
	{
		//Print the temporary data before editing and save to the database
		tempDate = (*find)->getDatedAdded();
		tempAuthor = (*find)->getAuthor();
		tempPublisher = (*find)->getPub();
		tempIbsn = (*find)->getISBN();
		tempTitle = (*find)->getTitle();
		tempQty = (*find)->getqty();
		tempWholeSale = (*find)->getWholeSale();
		tempRetail = (*find)->getRetail();

	do
		{
			system("clear");
			cout << "**************************************************************************************************" << endl;
			cout << "*                                    Serendipity Booksellers                                     *" << endl;
			cout << "*                                           Edit Book                                            *" << endl;
			cout << "*                                        Pending Values                                          *" << endl;
			cout << "*                                                                                                *" << endl;
			cout << "* Database Size: " << setw(3) << onlyList.length() << "         Current Book Count: " << left << setw(48) << result << "*" << endl;
			cout << "* <1> Edit Book Title             >> " << left << setw(60) << tempTitle.substr(0, 60) << "*" << endl;
			cout << "* <2> Edit ISBN                   >> " << left << setw(60) << tempIbsn << "*" << endl;
			cout << "* <3> Edit Author                 >> " << left << setw(60) << tempAuthor << "*" << endl;
			cout << "* <4> Edit Publisher              >> " << left << setw(60) << tempPublisher << "*" << endl;
			cout << "* <5> Edit Date Added(mm/dd/yyyy) >> " << left << setw(60) << tempDate << "*" << endl;
			cout << "* <6> Edit Quantity on Hand       >> " << left << setw(60) << tempQty << "*" << endl;
			cout << "* <7> Edit Wholesale Cost         >> $" << left << setw(59) << tempWholeSale << "*" << endl;
			cout << "* <8> Edit Retail Price           >> $" << left << setw(59) << tempRetail << "*" << endl;
			cout << "* <9> Save Book to Database and Return to Inventory Menu                                         *" << endl;
			cout << "**************************************************************************************************" << endl;
			cout << "        Enter your choice(0-9): ";
			cin >> choice;
			cin.ignore();

		switch(choice)
			{
				case '9':
					cout << "*WARNING* Are you sure to save all the changes and leave? (Y/N)\n";
					cin.get(store);
					cin.ignore(1000, '\n');
					if(store == 'Y' || store == 'y')
						{
							(*find)->setTitle(tempTitle);
							(*find)->setISBN(tempIbsn);
							(*find)->setAuthor(tempAuthor);
							(*find)->setPub(tempPublisher);
							(*find)->setDatedAdded(tempDate);
							(*find)->setqty(tempQty);
							(*find)->setWholeSale(tempWholeSale);
							(*find)->setRetail(tempRetail);
						}

					pause = true;
					break;

				case '1':
					cout << "Edit Book Title: ";
					getline(cin, tempTitle);
					break;

				case '2':
					cout << "Edit ISBN: ";
					getline(cin, tempIbsn);
					break;

				case '3':
					cout << "Edit Author: ";
					getline(cin, tempAuthor);
					break;

				case '4':
					cout << "Edit Publisher: ";
					getline(cin, tempPublisher);
					break;

				case '5':
					cout << "Edit Date Added(mm/dd/yyyy): ";
					getline(cin, tempDate);
					break;

				case '6':
					cout << "Edit Quantity on Hand: ";
					cin >> tempQty;
					cin.ignore(1000, '\n');
					break;

				case '7':
					cout << "Edit Wholesale Cost: ";
					cin >> tempWholeSale;
					cin.ignore(1000, '\n');
					break;

				case '8':
					cout << "Edit Retail Price: ";
					cin >> tempRetail;
					cin.ignore(1000, '\n');
					break;

				case '\n':
					break;

				default:
					cout << choice << endl;
					cout << "You have entered an invalid choice. Please enter a number in the range 0-9." << endl << endl;
					break;
			}//End switch statement

	} while (!pause);//End do while loop
    }     
return;
}


//Function prompts users to delete book
//Call the function look up
//Give the warning "Warning! You about to delete the book: book[index],title"
//Take the last book and overwrite on the book selected to delete
void deleteBook(orderedLinkedList<bookType*> &onlyList)
{

system("clear");
char deleteBook, view, discard;
bool found = false;
string search, upSearch;        //A string object hold the name of the book that user want to search
linkedListIterator<bookType*> find;
orderedLinkedList<bookType*> tem;


    //CALL/DISPLAY look up book first 
    cout << "************************************************************************" << endl;
    cout << "*                           Delete Book                                *" << endl;
	cout << "* Search (by Title): ";
	getline(cin, search);
	upSearch = search;
	upSearch = upper(upSearch);

	for(find = onlyList.begin(); find != onlyList.end(); ++find)
		{
			find = tem.lookUpBook(onlyList, find, upSearch);
			if(find == NULL)
					break;
			else
                {
					system("clear");
					cout << "Search: " << search;
					cout << "\nRESULT: " << endl;
					(*find)->bookInfo();
					cout << "\n\nIs this the correct result? (Y/N): ";
					cin.get(view);
					cin.ignore();

					while (view != 'Y' && view != 'y' && view != 'N' && view != 'n')
						{
							cout << "\nYou entered an invalid choice! Please enter Y/N or y/n!";
							cin >> view;
							cin.ignore(1000, '\n');
						}
			//-------------------------------------------------------------------------------
			//The user decide whether to view the book record
			//-------------------------------------------------------------------------------
					if (view == 'Y' || view == 'y')
					{
						found = true;
						cout << "*WARNING* Do you wish to delete this book? (Y/N) ";
						cin >> deleteBook;

						while (deleteBook != 'Y' && deleteBook != 'y' && deleteBook != 'N' && deleteBook != 'n')
						{
							cout << "\nYou entered an invalid choice! Please enter Y/N or y/n!";
							cin >> deleteBook;
							cin.ignore(1000, '\n');
						}

						if(deleteBook == 'Y' || deleteBook == 'y')
						{

							//--------------------------------------------------------------------------------------------------------------------------------------------------------------
							//The desired book is found
							//Prompt the user to delete the book
							//--------------------------------------------------------------------------------------------------------------------------------------------------------------
							onlyList.deleteNode(*find);
							cout << "Delete the book successfully! Press any key to continue..";
							cin >> discard;
							cin.ignore();
						}
						break;
					}//End if
					else if (view == 'N' || view == 'n')
						continue;
					else if (view != 'N' || view != 'n' || view != 'Y' || view != 'y')
						cout << "You entered an invalid choice! Please enter Y/N or y/n!" << endl;
				}
		}
	if(found == false)					//If the book isn't found
		{
			cout << "Sorry. The book you searched for is not in the inventory!" << endl;
			cout << "Press any key to continue..";
			cin >> discard;
			cin.ignore();
		}
return;
}

