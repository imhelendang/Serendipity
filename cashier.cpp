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
//                                                  FUNCTION DEFINITION FOR PROTOTYPES
//--------------------------------------------------------------------------------------------------------------------------------------------
//                         CASHIER MODULE
//                      Serendipity Book Sellers
//Date:
//Qty    ISBN         Title                    Price         Total
//____________________________________________________________________
//
//
//              Subtotal
//              Tax
//              Total
//
//            Thank You for Shopping at Serendipity!
//--------------------------------------------------------------------------------------------------------------------------------------------
//Function to prompts to the Cashier
//The Cashier Module are set according to the parameters
//Precondition: The choice range from 1 to 4
//Postcondition: The function will receive the number '1' then display the contents
//              In cashier module: the program will prompt the user
//              to input the required information date, quanity, ISBN, title, price
//              then calculate and output the total price, and the sum at the end
void cashier(orderedLinkedList<bookType*> &onlyList)
{

//Process the program only when the data contains books
//Data table
int *cart = new int[onlyList.length()];		//creat based off the length
bookType *book[onlyList.length()];
string search, upSearch;
int numQty, index;
int result = 0;
char another, discard, yes, view, choice;
bool found;		//to check whether the book is found
bool again = false;		//to control the loop if the customer want to buy another book
bool case1 = false;		//to check whether one of the books the customer want to buy isn't in the inventory
linkedListIterator<bookType*> find, copy;
orderedLinkedList<bookType*> it;


	for(copy = onlyList.begin(); copy != onlyList.end(); ++copy)
	{
		book[result] = (*copy);	//Copy address of all books to the array
		cart[result] = 0;	//initialize the array to 0
		result++;
	}
		
	do
		{
		system("clear");
		//Display the Look Up Book MODULE
		cout << "*                         Book Look Up                          *" << endl;
		cout << "*Search (by Title): ";
		getline(cin, search);
		upSearch = search;
		upSearch = upper(upSearch);

		for(find = onlyList.begin(); find != onlyList.end(); ++find)
			{
				found = false;		//set to default

				//Call look up book function
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

				//If the customer enters an invalid choice
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
								found = true;		//the book is found

								//Check whether the book is available to purchase (qty > 0)
								if((*find)->getqty() == 0)	
									cout << "\nCurrent book is not available to be purchased!" << endl;
								//The book is available to purchase
								else						
								{
									//Traverse the result
									for(int i = 0; i < onlyList.length(); i++)
										{
											if(book[i] == *find)
												{
													//Ask for the desired quanity to make purchase
													cout << "\nCurrently have " << (*find)->getqty() << " in inventory. And have " << cart[i] << " in shopping cart!";
													cout << "\nEnter the quantity of books that you want: ";
													cin >> numQty;
													cin.ignore();
													//Make sure the user input valid integer
													while(numQty < 0)
														{
															cout << "\nYou have entered an invalid input! Please enter the quanity of books that you want: ";
															cin >> numQty;
															cin.ignore();
															cin.ignore();
														}

													//Check the quanity number
													if(numQty > (*find)->getqty())
														{
															cout << "\nThe current quantity is lower than the desired quantity!\n";
															cout << "Will use all the books currently have. Press any key to continue..";
															cin >> discard;
															cin.ignore();
															cart[result] = (*find)->getqty();
															numQty = 0;
														}
													else if((*find)->getqty() == cart[result])
														{
															cout << "\nCurrently have all available books in shopping cart. Can not add more books!" << endl;
															cout << "Press any key to continue..";
															cin >> discard;
															cin.ignore();
															numQty = 0;
														}
												//Store the quanity to the shopping cart
												cart[i] += numQty;

												//The book is found and able to purchase
												case1 = true;
												}//end if
										}//end for
								}//End else
							break;
						}
						else if (view == 'N' || view == 'n')
						{
							continue;
							result += 1;
						}
					}
			}
			if(found == false && case1 == false)		//If the book isn't found and the customer hasn't added any books to the cart
				{
					cout << "Sorry. The book you searched for is not in the inventory!" << endl;
					cout << "Press any key to continue..";
					cin >> choice;
					cin.ignore();
					again = true;
				}
			else
			{
				if(found == false)		//If the book isn't found and the customer has added some books to the cart
					cout << "\nSorry, couldn't find a match..\n";

				//Ask for another run
				cout << "\nDo you want to buy another book? (Y/N): ";
				cin >> another;
				cin.ignore(1000, '\n');

				while (another != 'Y' && another != 'y' && another != 'N' && another != 'n')
					{
						cout << "\nYou entered an invalid choice! Please enter Y/N or y/n!";
						cin >> another;
						cin.ignore(1000, '\n');
					}

				if(another == 'N' || another == 'n')
					{
						cout << "\nView the final receipt? (Y/N)";
						cin >> yes;
						if(yes == 'Y' || yes == 'y')
						{
							receipt(onlyList, cart);
							again = true;
						}
					}//End if
			}
	}while(!again);

	//Delete shopping cart
	delete [] cart;

return;
}

//Function to print the final receipt for the user
//Postcondition:
void receipt(orderedLinkedList<bookType*> &onlyList, int cart[])
{
	system("clear");
	cout << fixed << showpoint << right << setprecision(2); //set up number format
	const float TAX_RATE = 0.06;  //tax for calculating the product's price
	float grandTotal = 0;
	float sum = 0;
	char discard, confirm;
	linkedListIterator<bookType*> it;
	it = onlyList.begin();

		//Display the Receipt to prompt the user to confirm the final purchase
		cout << left;
		cout << "****************************************************************";
		cout << "\n*                              Receipt                         *" << endl;
		time();
		date();
		cout << "                    *" << endl;
		cout << "Qty\tISBN\t\tTitle\t\t\t\tPrice\t\t" << endl;
		cout << "________________________________________________________________" << endl;


		for(int index = 0; index < onlyList.length(); index++)
		{
			if(cart[index] != 0 && it != onlyList.end())
			{
				sum = (*it)->getRetail() * cart[index];
				cout << cart[index] << "\t";
				cout << left << setw(14) << (*it)->getISBN() << "\t";
				cout << left << setw(26) << (*it)->getTitle().substr(0,25) << "\t$ ";
				cout << right << setw(6) << (*it)->getRetail() << endl << endl;
				cout << left << "\t\t Total    \t\t\t\t$ " << right << setw(6) << sum << endl << endl << endl;
				grandTotal += sum;
			}
			++it;
		}

		cout << left << "\t\t Grand Total    \t\t\t$ " << setw(10) << right << setw(6) << grandTotal << endl;
		cout << left << "\t\t Tax            \t\t\t$ " << setw(10) << right << setw(6) << grandTotal*TAX_RATE << endl;
		cout << left << "\t\t Grand Total with Tax \t\t\t$ " << setw(10) << right << setw(6) << grandTotal+(grandTotal*TAX_RATE) << endl;
		cout << "\nConfirm purchase? (Y/N) ";
		cin >> discard;
		if (discard == 'Y' || discard == 'y')
		{
			it = onlyList.begin();
			for(int index = 0; index < onlyList.length(); index++)
				{
					if(cart[index] != 0 && it != onlyList.end())
						(*it)->setqty((*it)->getqty() - cart[index]);
						
					++it;
				}
		}
		cout << "\nThanks for selecting Serendipity!\n";
		cout << "\nPress any key to continue..";
		cin >> discard;
		cin.ignore(1000, '\n');

		return;
}
