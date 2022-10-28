#include "mainmenu.h"
#ifndef SORTBOOK_H_
#define SORTBOOK_H_

//						Sorting method
//Fucntion to sorting the quanity books (in descending order)
//Precondition: Fucntion is excuted according to parameters
//Postcondition: The list sorted by quantity on hand in descending order (the books of the greatest quantity listed first)
template <typename H>
void sortBook(H *other[], const int length, bool order)
{
	int index, location;
	int smallest;
	H *temp;

	for(index = 0; index < length-1; index++)
	{
		smallest = index;	//Assume the first one is the smallest
		for(location = index+1; location < length; location++)
		{
			if(order)
			{
				if((*other[location]) < *other[index])
				smallest = location;
			}
			else
			{
				if((*other[location]) > *other[index])
				smallest = location;
			}
		}

		//Swap locations
		temp = other[smallest];
		other[smallest] = other[index];
		other[index] = temp;
	}

	return;
}



#endif /* SORTBOOK_H_ */

