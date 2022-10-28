#include "mainmenu.h"

/**********************************************************
* AUTHOR : Ngoc Dang Tran;
* STUDENT ID : 1197865;
* ASSIGNMENT : Serendipity
* CLASS : CS1B;
* SECTION : MW: 9:30am-11:50am;
* DUE DATE : 01/27/2021;
**********************************************************/

//--------------------------------------------------------------------------------------------------------------------------------------------
//                            REPORT MODULE
//*****************************************************************
//*                     Serendipity Booksellers                   *
//*                             Reports                           *
//*                  1. Inventory Listing                         *
//*                  2. Inventory Wholesale Value                 *
//*                  3. Inventory Retail Value                    *
//*                  4. Listing by Quanity                        *
//*                  5. Listing by Cost                           *
//*                  6. Listing by Age                            *
//*                  7. Return to Main Menu                       *
//*****************************************************************
//*                  Enter Your Choice(1-5):                      *
//--------------------------------------------------------------------------------------------------------------------------------------------
//Function to prompts to the Reports
//The Reports Module are set according to the parameters
//Precondition: the choice range from 1 to 4
//Postcondition: The function will receive the number '3' then display the contents
//               The function prompt the user to activate another modules
void reports(orderedLinkedList<bookType*> &onlyList)
{
char choice;
bool exit = false;
bookType::setSCode(0);

do
    {
        system("clear");
        cout << "*****************************************************************" << endl;
        cout << "*                    Serendipity Booksellers                    *" << endl;
        cout << "*                           Reports                             *" << endl;
        cout << "*                  1. Inventory Listing                         *" << endl;
        cout << "*                  2. Inventory Wholesale Value                 *" << endl;
        cout << "*                  3. Inventory Retail Value                    *" << endl;
        cout << "*                  4. Listing by Quanity                        *" << endl;
        cout << "*                  5. Listing by Cost                           *" << endl;
        cout << "*                  6. Listing by Age                            *" << endl;
        cout << "*                  7. Return to Main Menu                       *" << endl;
        cout << "*****************************************************************" << endl;
        cout << "*                  Enter your choice (1-7): ";
        cin >> choice;
        cin.ignore();
        cin.clear();

        switch (choice)
            {

                case '1':
                    repListing(onlyList);
                    break;

                case '2':
                    repWholesale(onlyList);
                    break;

                case '3':
                    repRetail(onlyList);
                    break;

                case '4':
                    repQty(onlyList);
                    break;

                case '5':
                    repCost(onlyList);
                    break;

                case '6':
                    repAge(onlyList);
                    break;

                case '7':
                    system("clear");
                    exit = true;
                    break;

                default:
                    system("clear");
                    cout << "You have entered an invalid choice. Please enter a number in the range 1-7." << endl << endl;
                    break;
            }
    } while (!exit);

system("clear");

return;
}


//Function prompts users to the Inventory Listing Module
//The Reports Listing Module are set according to the parameters
//The program will display the content as in setting up below
void repListing(orderedLinkedList<bookType*> &onlyList)
{
int x = 0;
int page = 1;
char choice;
char key;
linkedListIterator<bookType*> it;

//**************************************************************************************************************************************************
//Display the information
//**************************************************************************************************************************************************

		system("clear");
		cout << left;
		cout << "*******************************************************************************************************************************" << endl;
		cout << "*                                                  SERENDIPITY BOOKSELLERS                                                    *" << endl;
		cout << "*                                                       REPORT LISTING                                                        *" << endl;
		cout << "*                                                                                                                             *" << endl;
		time();
		date();
		cout << "        \tPAGE: " << page << " of 7" << "\tDETAILING " << bookType::getBookCount() << " BOOK RECORDS" << "                            *\n";
		cout << "*                                                                                                                             *" << endl;
		cout << left << setw(30) << "* TITLE" << setw(12) << "ISBN" << setw(17) << "AUTHOR" << setw(17) << "PUBLISHER" << setw(13) << "DATE ADDED" << setw(8) << "QTY O/H" << setw(16) << "WHOLESALE COST" << setw(11) << "RETAIL PRICE" << " *\n";
		cout << "* -------------------------- " << " " << "---------- " << " " << "--------------- " << " " << "---------------  " << "----------   " << "------- " << "--------------- "<< "------------ *" << endl;

		for(it = onlyList.begin(); it != onlyList.end(); ++it)
			{
				if(it == NULL)
					break;
				else
				{
				cout << left << "* " << setw(27) << (*it)->getTitle().substr(0 ,26) << " " << setw(11) << (*it)->getISBN().substr(0,10)
					<< " " << setw(16) << (*it)->getAuthor().substr(0, 15) << " " << setw(16) << (*it)->getPub().substr(0, 15)
					<< " " << setw(12) << (*it)->getDatedAdded() << " " << right << setw(7) << (*it)->getqty() << "     $"
					<< right << setw(9) << (*it)->getWholeSale() << left << "     $" << right << setw(8) << (*it)->getRetail()  << " *\n";
				cout << "*                                                                                                                             *" << endl;
				if (x == BOOKPERSCREEN || x == 2*BOOKPERSCREEN || x == 3*BOOKPERSCREEN || x == 4*BOOKPERSCREEN || x == 5*BOOKPERSCREEN || x == 6*BOOKPERSCREEN)
					{
						cout << "Press a key to continue..";
						cin.get(key);
						cin.ignore();
						system("clear");
						cout << left;
						cout << "*******************************************************************************************************************************" << endl;
						cout << "*                                                  SERENDIPITY BOOKSELLERS                                                    *" << endl;
						cout << "*                                                       REPORT LISTING                                                        *" << endl;
						cout << "*                                                                                                                             *" << endl;
						time();
						date();
						cout << "        \tPAGE: " << ++page << " of 7" << "\tDETAILING " << bookType::getBookCount() << " BOOK RECORDS" << "                            *\n";
						cout << "*                                                                                                                             *" << endl;
						cout << left << setw(30) << "* TITLE" << setw(12) << "ISBN" << setw(17) << "AUTHOR" << setw(17) << "PUBLISHER" << setw(13) << "DATE ADDED" << setw(8) << "QTY O/H" << setw(16) << "WHOLESALE COST" << setw(11) << "RETAIL PRICE" << " *\n";
						cout << "* -------------------------- " << " " << "---------- " << " " << "--------------- " << " " << "---------------  " << "----------   " << "------- " << "--------------- "<< "------------ *" << endl;
					} //end if
                    x++;
				}
			}// end for

		cout << "*******************************************************************************************************************************" << endl;
		cout << "Press a key to continue..";
		cin.get(key);
		cin.ignore();

return;
}

//Function prompts users to the Inventory Whole Sale Module
//The Reports Whole Sale Module are set according to the parameters
//The program will display the content as in setting up below
void repWholesale(orderedLinkedList<bookType*> &onlyList)
{
cout << fixed << showpoint << right << setprecision(2); //set up number format
system("clear");
char choice, key;
double total = 0;
int page = 1;
double sum = 0;
int x = 0;
linkedListIterator<bookType*> it;

//**************************************************************************************************************************************************
//Display the information
//**************************************************************************************************************************************************
    system("clear");
    cout << left;
    cout << "******************************************************************************************************************************" << endl;
    cout << "*                                                  SERENDIPITY BOOKSELLERS                                                   *" << endl;
    cout << "*                                                  REPORT WHOLESALE LISTING                                                  *" << endl;
    cout << "*                                                                                                                            *" << endl;
    time();
    date();
    cout << "        \tPAGE: " << page << " of 7" << "\tDETAILING " << bookType::getBookCount() << " BOOK RECORDS" << "                           *\n";
    cout << "*                                                                                                                            *" << endl;
    cout << left << setw(70) << "* TITLE" << setw(20) << "ISBN" << setw(15) << "QTY O/H" << setw(14) << "WHOLESALE COST" << "      *" << endl;
    cout << "* ----------------------------------------------------------" << "          " << "----------  " << "        " << "-------" << "        " << "--------------"<< "      *" << endl;

    for(it = onlyList.begin(); it != onlyList.end(); ++it)
        {
            if(it == NULL)
                break;
            else
                {
                    cout << left << "* " << setw(58) << (*it)->getTitle().substr(0, 58) << "          " << setw(12) << (*it)->getISBN().substr(0,12) << "        " << right << setw(6) << (*it)->getqty()
                        << left << "              $" << right << setw(8) << (*it)->getWholeSale() << "      *\n";
                    cout << "*                                                                                                                            *" << endl;
                    if (x == BOOKPERSCREEN || x == 2*BOOKPERSCREEN || x == 3*BOOKPERSCREEN || x == 4*BOOKPERSCREEN || x == 5*BOOKPERSCREEN || x == 6*BOOKPERSCREEN)
                        {
                            cout << "Press a key to continue..";
                            cin.get(key);
                            cin.ignore();
                            system("clear");
                            cout << left;
                            cout << "******************************************************************************************************************************" << endl;
                            cout << "*                                                  SERENDIPITY BOOKSELLERS                                                   *" << endl;
                            cout << "*                                                  REPORT WHOLESALE LISTING                                                  *" << endl;
                            cout << "*                                                                                                                            *" << endl;
                            time();
                            date();
                            cout << "        \tPAGE: " << ++page << " of 7" << "\tDETAILING " << bookType::getBookCount() << " BOOK RECORDS" << "                           *\n";
                            cout << "*                                                                                                                            *" << endl;
                            cout << left << setw(70) << "* TITLE" << setw(20) << "ISBN" << setw(15) << "QTY O/H" << setw(14) << "WHOLESALE COST" << "      *" << endl;
                            cout << "* ----------------------------------------------------------" << "          " << "----------  " << "        " << "-------" << "        " << "--------------"<< "      *" << endl;
                        } //end if
                        x++;
                }
        }//end for

     //CALCULATE THE TOTAL WHOLESALE OF THE INVENTORY
     for(it = onlyList.begin(); it != onlyList.end(); ++it)
        {
            if(it == NULL)
                break;
            else 
            {
                total = (*it)->getWholeSale() * (*it)->getqty();
                sum = sum + total;
            }
        }
    cout << left << "* Total WholeSale:      $ " << setw(99) << sum << "*\n";
    cout << "******************************************************************************************************************************" << endl;
    cout << "Press a key to continue..";
    cin.get(key);
    cin.ignore();

return;
}

//Function prompts users to the Inventory Retail Module
//The Reports Retails Module are set according to the parameters
//The program will display the content as in setting up below
void repRetail(orderedLinkedList<bookType*> &onlyList)
{
cout << fixed << showpoint << right << setprecision(2); //set up number format
system("clear");
char choice, key;
double total = 0;
double sum;
int x = 0;
int page = 1;
linkedListIterator<bookType*> it;

//**************************************************************************************************************************************************
//Display the information
//**************************************************************************************************************************************************
    sum = 0;
    system("clear");
    cout << left;
    cout << "******************************************************************************************************************************" << endl;
    cout << "*                                                  SERENDIPITY BOOKSELLERS                                                   *" << endl;
    cout << "*                                                   REPORT RETAIL LISTING                                                    *" << endl;
    cout << "*                                                                                                                            *" << endl;
    time();
    date();
    cout << "        \tPAGE: " << page << " of 7" << "\tDETAILING " << bookType::getBookCount() << " BOOK RECORDS" << "                           *\n";
    cout << "*                                                                                                                            *" << endl;
    cout << left << setw(70) << "* TITLE" << setw(20) << "ISBN" << setw(20) << "QTY O/H" << setw(11) << "RETAIL COST" << "    *\n";
    cout << "* ----------------------------------------------------------" << "          " << "----------  " << "        " << "-------" << "             " << "-----------"<< "    *" << endl;

    for(it = onlyList.begin(); it != onlyList.end(); ++it)
        {
            if(it == NULL)
                break;
            else
                {
                cout << left << "* " << setw(58) << (*it)->getTitle().substr(0, 58) << "          " << setw(11) << (*it)->getISBN().substr(0,11) << "         " << right << setw(6) << (*it)->getqty()
                    << left << "                $" << right << setw(8) << (*it)->getRetail() << "    *\n";
                cout << "*                                                                                                                            *" << endl;
                if (x == BOOKPERSCREEN || x == 2*BOOKPERSCREEN || x == 3*BOOKPERSCREEN || x == 4*BOOKPERSCREEN || x == 5*BOOKPERSCREEN || x == 6*BOOKPERSCREEN)
                    {
                        cout << "Press a key to continue..";
                        cin.get(key);
                        cin.ignore();
                        system("clear");
                        cout << left;
                        cout << "******************************************************************************************************************************" << endl;
                        cout << "*                                                  SERENDIPITY BOOKSELLERS                                                   *" << endl;
                        cout << "*                                                   REPORT RETAIL LISTING                                                    *" << endl;
                        cout << "*                                                                                                                            *" << endl;
                        time();
                        date();
                        cout << "        \tPAGE: " << ++page << " of 7" << "\tDETAILING " << bookType::getBookCount() << " BOOK RECORDS" << "                           *\n";
                        cout << "*                                                                                                                            *" << endl;
                        cout << left << setw(70) << "* TITLE" << setw(20) << "ISBN" << setw(20) << "QTY O/H" << setw(11) << "RETAIL COST" << "    *\n";
                        cout << "* ----------------------------------------------------------" << "          " << "----------  " << "        " << "-------" << "             " << "-----------"<< "    *" << endl;
                    } //end if
                    x++;
                }
        }// end for

    //CALCULATE RETAIL OF THE INVENTORY
     for(it = onlyList.begin(); it != onlyList.end(); ++it)
        {
            if(it == NULL)
                break;
            else 
            {
                total = (*it)->getRetail() * (*it)->getqty();
                sum += total;
            }
        }
    cout << left << "* Total Retail:         $ " << setw(99) << sum << "*\n";
    cout << "******************************************************************************************************************************" << endl;
    cout << "Press a key to continue..";
    cin.get(key);
    cin.ignore();
return;
}

//Function prompts users to the Listing by Quanity Module
//Postcondition:
//Precondition:
void repQty(orderedLinkedList<bookType*> &onlyList)
{
system("clear");
char key;
int page = 1;
int x = 0;
linkedListIterator<bookType*> it;
orderedLinkedList<bookType*> copy;

//**************************************************************************************************************************************************
//Display the information
//**************************************************************************************************************************************************
    bookType::setSCode(5);
    for(it = onlyList.begin(); it != onlyList.end(); ++it)
        {
            //book = new bookType (it);
            copy.insert(*it);
        }
    system("clear");
    cout << left;
    cout << "******************************************************************************************************************************" << endl;
    cout << "*                                                  SERENDIPITY BOOKSELLERS                                                   *" << endl;
    cout << "*                                                  REPORT QUANTITY LISTING                                                   *" << endl;
    cout << "*                                                                                                                            *" << endl;
    time();
    date();
    cout << "        \tPAGE: " << page << " of 7" << "\tDETAILING " << bookType::getBookCount() << " BOOK RECORDS" << "                           *\n";
    cout << "*                                                                                                                            *" << endl;
    cout << setw(65) << "* TITLE" << "          " << setw(13) << "  ISBN" << "              " << setw(7) << "QTY O/H" << "                *" << endl;
    cout << "* -----------------------------------------------------------------" << "          " << "-------------" << "            " << "-------" << "                *" << endl;


    for(it = copy.begin(); it != copy.end(); ++it)
        {
            if(it == NULL)
                break;
            else
                {
                    cout << left << "* " << setw(65) << (*it)->getTitle().substr(0, 65) << "          " << setw(13) << (*it)->getISBN().substr(0,13) << "          " << right << setw(7) << (*it)->getqty()
                        << left << "                  *\n";
                    cout << "*                                                                                                                            *" << endl;
                    if (x == BOOKPERSCREEN || x == 2*BOOKPERSCREEN || x == 3*BOOKPERSCREEN || x == 4*BOOKPERSCREEN || x == 5*BOOKPERSCREEN || x == 6*BOOKPERSCREEN)
                        {
                            cout << "Press a key to continue..";
                            cin.get(key);
                            cin.ignore();
                            system("clear");
                            cout << left;
                            cout << "******************************************************************************************************************************" << endl;
                            cout << "*                                                  SERENDIPITY BOOKSELLERS                                                   *" << endl;
                            cout << "*                                                  REPORT QUANTITY LISTING                                                   *" << endl;
                            cout << "*                                                                                                                            *" << endl;
                            time();
                            date();
                            cout << "        \tPAGE: " << ++page << " of 7" << "\tDETAILING " << bookType::getBookCount() << " BOOK RECORDS" << "                           *\n";
                            cout << "*                                                                                                                            *" << endl;
                            cout << setw(65) << "* TITLE" << "          " << setw(13) << "  ISBN" << "            " << setw(7) << "  QTY O/H" << "                *" << endl;
                            cout << "* -----------------------------------------------------------------" << "          " << "-------------" << "            " << "-------" << "                *" << endl;
                        } //end if
                        x++;
                }
        }
    cout << "******************************************************************************************************************************" << endl;
    cout << "Press a key to continue..";
    cin.get(key);
    cin.ignore();

return;
}

//Function prompts users to the Listing by Cost Module
void repCost(orderedLinkedList<bookType*> &onlyList)
{
cout << fixed << showpoint << right << setprecision(2); //set up number format
system("clear");
char choice, key;
int x = 0;
int page = 1;

linkedListIterator<bookType*> it;
orderedLinkedList<bookType*> copy;

//**************************************************************************************************************************************************
//Display the information
//**************************************************************************************************************************************************
    bookType::sCode = 6;    //set comparation according to whole sale cost
    for(it = onlyList.begin(); it != onlyList.end(); ++it)
            copy.insert(*it);
            
    system("clear");
    cout << left;
    cout << "******************************************************************************************************************************" << endl;
    cout << "*                                                  SERENDIPITY BOOKSELLERS                                                   *" << endl;
    cout << "*                                              REPORT WHOLESALE LISTING HI - LO                                              *" << endl;
    cout << "*                                                                                                                            *" << endl;
    time();
    date();
    cout << "        \tPAGE: " << page << " of 7" << "\tDETAILING " << bookType::getBookCount() << " BOOK RECORDS" << "                           *\n";
    cout << "*                                                                                                                            *" << endl;
    cout << setw(65) << "* TITLE" << "            " << setw(13) << "ISBN " << "          " << setw(14) << "WHOLESALE COST" << "           *" << endl;
    cout << "* -----------------------------------------------------------------" << "          " << "-------------" << "          " << "--------------" << "           *" << endl;


    for(it = copy.begin(); it != copy.end(); ++it)
        {
            cout << left << "* " << setw(65) << (*it)->getTitle().substr(0, 65) << "          " << setw(13) << (*it)->getISBN().substr(0,13)
                    << "             $" << right << setw(10) << (*it)->getWholeSale() << "           *" << endl;
            cout << "*                                                                                                                            *" << endl;

            if (x == BOOKPERSCREEN || x == 2*BOOKPERSCREEN || x == 3*BOOKPERSCREEN || x == 4*BOOKPERSCREEN || x == 5*BOOKPERSCREEN || x == 6*BOOKPERSCREEN)
                {
                    cout << "Press a key to continue..";
                    cin.get(key);
                    cin.ignore();
                    system("clear");
                    cout << left;
                    cout << "******************************************************************************************************************************" << endl;
                    cout << "*                                                  SERENDIPITY BOOKSELLERS                                                   *" << endl;
                    cout << "*                                              REPORT WHOLESALE LISTING HI - LO                                              *" << endl;
                    cout << "*                                                                                                                            *" << endl;
                    time();
                    date();
                    cout << "        \tPAGE: " << ++page << " of 7" << "\tDETAILING " << bookType::getBookCount() << " BOOK RECORDS" << "                           *\n";
                    cout << "*                                                                                                                            *" << endl;
                    cout << setw(65) << "* TITLE" << "            " << setw(13) << "ISBN " << "          " << setw(14) << "WHOLESALE COST" << "           *" << endl;
                    cout << "* -----------------------------------------------------------------" << "          " << "-------------" << "          " << "--------------" << "           *" << endl;
                } //end if
            x++;
        }

    cout << "******************************************************************************************************************************" << endl;
    cout << "Press a key to continue..";
    cin.get(key);
    cin.ignore();
return;
}


//Function prompts users to the Listing by Age Module
void repAge(orderedLinkedList<bookType*> &onlyList)
{
system("clear");
char choice, key;
int x = 0;
int page = 1;

linkedListIterator<bookType*> it;
orderedLinkedList<bookType*> copy;
bookType *book = NULL;

//**************************************************************************************************************************************************
//Display the information
//**************************************************************************************************************************************************
    bookType::setSCode(4);  //set comparation according to date added
    for(it = onlyList.begin(); it != onlyList.end(); ++it)
            copy.insert(*it);

    system("clear");
    cout << left;
    cout << "******************************************************************************************************************************" << endl;
    cout << "*                                                  SERENDIPITY BOOKSELLERS                                                   *" << endl;
    cout << "*                                             REPORT BY AGE LISTING (BY OLDEST)                                              *" << endl;
    cout << "*                                                                                                                            *" << endl;
    time();
    date();
    cout << "        \tPAGE: " << page << " of 7" << "\tDETAILING " << bookType::getBookCount() << " BOOK RECORDS" << "                           *\n";
    cout << "*                                                                                                                            *" << endl;
    cout << setw(67) << "* TITLE" << "     " << setw(13) << "ISBN" << "      " << setw(7) << "QTY O/H" << "      " << setw(10) << "DATE ADDED" << "           *" << endl;
    cout << "* -----------------------------------------------------------------" << "     " << "-------------" << "      " << "-------" << "      " << "----------" << "           *" << endl;


    for(it = copy.begin(); it != copy.end(); ++it)
        {
            cout << left << "* " << setw(65) << (*it)->getTitle().substr(0, 65) << "     " << setw(13) << (*it)->getISBN().substr(0,13) << "       " << right << setw(4) << (*it)->getqty()
                << left << "        " << setw(10) << (*it)->getDatedAdded().substr(0,10) << "           *" << endl;
            cout << "*                                                                                                                            *" << endl;

            if (x == BOOKPERSCREEN || x == 2*BOOKPERSCREEN || x == 3*BOOKPERSCREEN || x == 4*BOOKPERSCREEN || x == 5*BOOKPERSCREEN || x == 6*BOOKPERSCREEN)
                {
                    cout << "Press a key to continue..";
                    cin.get(key);
                    cin.ignore();
                    system("clear");
                    cout << left;
                    cout << "******************************************************************************************************************************" << endl;
                    cout << "*                                                  SERENDIPITY BOOKSELLERS                                                   *" << endl;
                    cout << "*                                             REPORT BY AGE LISTING (BY OLDEST)                                              *" << endl;
                    cout << "*                                                                                                                            *" << endl;
                    time();
                    date();
                    cout << "        \tPAGE: " << ++page << " of 7" << "\tDETAILING " << bookType::getBookCount() << " BOOK RECORDS" << "                           *\n";
                    cout << "*                                                                                                                            *" << endl;
                    cout << setw(67) << "* TITLE" << "     " << setw(13) << "ISBN" << "      " << setw(7) << "QTY O/H" << "      " << setw(10) << "DATE ADDED" << "           *" << endl;
                    cout << "* -----------------------------------------------------------------" << "     " << "-------------" << "      " << "-------" << "      " << "----------" << "           *" << endl;
                } //end if
            x++;
        }

    cout << "******************************************************************************************************************************" << endl;
    cout << "Press a key to continue..";
    cin.get(key);
    cin.ignore();
return;
}

//Function to print out date on reports/reciept
void date()
{
    time_t tmNow;
    tmNow = time(NULL);
    struct tm t = *localtime(&tmNow);
    cout << left << "       DATE: " << setw(2) << right << t.tm_mon+1 << left << "/" << setw(2) << t.tm_mday << "/" << setw(4) << t.tm_year+1900;
    return;
}

void time()
{
    time_t tmNow;
    tmNow = time(NULL);
    struct tm t = *localtime(&tmNow);
    cout << "* TIME: ";
    if(t.tm_hour >= 12)
        {
            if(t.tm_hour==12)
                cout << right << setw(2) << "12";
            else if(t.tm_hour < 22)
                cout << right << setw(2) << "0" << t.tm_hour-12;
            else
                cout << right << setw(2) << t.tm_hour-12;

            cout << ":" << setw(2);
            if(t.tm_min < 10)
                cout << "0" << t.tm_min;
            else
                cout << t.tm_min;
            
            cout << ":" << setw(2);
            if(t.tm_sec < 10)
                cout << "0" << t.tm_sec;
            else
                cout << t.tm_sec;

            cout << " PM";

        }
    else
        {
            if(t.tm_hour < 10)
                 cout << setw(2) << "0" << t.tm_hour;
            else
                 cout << setw(2) << t.tm_hour;

            cout << ":" << setw(2);
            if(t.tm_min < 10)
                cout << "0" << t.tm_min;
            else
                cout << t.tm_min;
            
            cout << ":" << setw(2);
            if(t.tm_sec < 10)
                cout << "0" << t.tm_sec;
            else
                cout << t.tm_sec;

            cout << " AM";
        }
    return;
}

