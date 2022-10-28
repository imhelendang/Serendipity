#ifndef BOOKTYPE_H
#define BOOKTYPE_H
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


class bookType
{
private:
  string bookTitle;
  string isbn;
  string author;
  string publisher;
  string date;
  int qty;
  double wholeSale;
  double retail;

public:
  //                Friend functions
  friend ostream& operator<<(ostream&, const bookType&);
  friend istream& operator>>(istream&, bookType&);

  //                Static variables
  static int bookCount;
  static void incBookCount();
  static void decBookCount();
  static int sCode; //0 = compare by bookTitle
  	  	  	  	  	//1 = compare by isbn
  	  	  	  	  	//2 = compare by author
  	  				      //3 = compare by publisher
  	  	  	  	    //4 = compare by datedAdded
  	  	  	  	  	//5 = compare by qtyOnHand
  	  	  	  	  	//6 = compare by Wholesale price
  	  	  	  	  	//7 = compare by retail price



  bookType();		//Default constructor
  bookType(const bookType& other);		//Copy constructor
  bookType(string, string, string, int, string, string, double, double); 	//Constructor with parameters
  ~bookType();  //Destructor with empty body

  //								Setters
  void setTitle(string title);
  void setISBN(string isbnNum);
  void setAuthor(string bAuthor);
  void setPub(string pub);
  void setDatedAdded(string nDate);
  void setqty(int nty);
  void setWholeSale(double whole);
  void setRetail(double reTail);
  static void setSCode(int num);

  //								Getters
  string getTitle() const;
  string getISBN() const;
  string getAuthor() const;
  string getPub() const;
  string getDatedAdded() const;
  int getqty() const;
  double getWholeSale() const;
  double getRetail() const;
  static int getBookCount();
  static int getSCode();

  //								Print method
  void bookInfo();		//This function display the book information

  //								Equal method
  bool equals(int cart[], int);

  //                Overload operators
  const bookType& operator=(const bookType&);
  //Overload assignment operator.

  bool operator<(const bookType& otherBook) const;
  //Overload the less than operator.
  //Postcondition: Returns true if the quantity/retail of this book
  // is less than the quantity of
  // otherBook, otherwise it returns false.

  bool operator>(const bookType& otherBook) const;
  //Overload the greater than operator.
  //Postcondition: Returns true if the quantity/retail of this book
  // is less than the quantity of
  // otherBook, otherwise it returns false.

  bool operator<=(const bookType& otherBook) const;
  //Overload the less than or equal to operator.
  //Postcondition: Returns true if the quantity/retail of this book
  // is less than or equal to the quantity of
  // otherBook, otherwise it returns false.

  bool operator>=(const bookType& otherBook) const;
  //Overload the greater than or equal to operator.
  //Postcondition: Returns true if the quantity/retail of this book
  // is greater than or equal to the quantity of
  // otherBook, otherwise it returns false.

  bool operator==(const bookType& otherBook) const;
  //Overload the equality operator.
  //Postcondition: Returns true if the quantity/retail of this book
  // is  equal to the quantity of
  // otherBook, otherwise it returns false.

  bool operator!=(const bookType& otherBook) const;
  //Overload the equality operator.
  //Postcondition: Returns true if the quantity/retail of this book
  // is  not equal to the quantity of
  // otherBook, otherwise it returns false.
};
#endif /* BOOKTYPE_H_ */
