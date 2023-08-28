/*
Long Pham
Implementation of Linked List class
Date created: April 19, 2023
Date updated: April 24, 2023
*/


#include "List.h"
#include <iostream>
#include <iomanip>

/*
DEFAULT CONSTRUCTOR
Create an empty linked list by setting head pointer to null
*/
template <class T>
List<T>::List(void){
    head = nullptr;
}

/*
METHOD: append
Add an item to end of list
PARAMETERS: reference of item being added
RETURN VALUE: none
*/
template <class T>
void List<T>::append(const T &item){
    if (head == nullptr){                 //append to empty list
        head = new Node;
        head->item = item;
        head->next = nullptr;
	}
    
    else{                                //append to non-empty list
	Node* ptr{head};
      while(ptr->next != nullptr){
		ptr = ptr->next;
	  }
	ptr->next = new Node;
	ptr = ptr->next;
	ptr->item = item;
	ptr->next = nullptr;

    ptr = nullptr;
    }

}


/*
COPY CONSTRUCTOR
Copy the parameter object to constructed object
*/
template<class T>
List<T>::List( const List<T> &mylist ){
	if(mylist.head == nullptr){               //if list being copied is empty
		head = nullptr;
	}
	
	else{
		head = new Node;
		head->item = (mylist.head) -> item;
		head->next = nullptr;

		Node* fromPtr = mylist.head;
		Node* toPtr = head;

		while(fromPtr->next != nullptr){
			fromPtr = fromPtr->next;
			toPtr->next = new Node;
			toPtr = toPtr->next;
			toPtr->item = fromPtr->item;
			toPtr->next = nullptr;
		}
        fromPtr = nullptr;
        toPtr = nullptr;
	}

   

}


/*
METHOD: insert
Insert an item to list in specified index
PARAMETERS: reference of item being added, index to be added - type int
RETURN VALUE: none
*/
template<class T>
void	List<T>::	insert		( const T &item, int index ){
	int itemCount{};
	Node* ptr{head};

	if(index == 0){                      //inserting to start of list
		head = new Node;
		head->item = item;
		head->next = ptr;

        ptr = nullptr;
		return;
	}

    
	while(itemCount != index){           //inserting to other positions
		itemCount++;
		if (itemCount == index){
			Node* ptr1{ptr->next};
			ptr->next = new Node;
			ptr = ptr->next;
			ptr->item = item;
			ptr->next = ptr1;

            ptr1 = nullptr;
			break;
		}
		ptr = ptr->next;
	}

    ptr = nullptr;
    
}


/*

METHOD: remove
Remove an item from list using item's index
PARAMETERS: index of item to be removed - type int
RETURN VALUE: none
*/
template<class T>
void		List<T>::remove		( int index ){
	if(head == nullptr){                       //when removing from empty list, do nothing
		return;
	}
	
	if (index == 0){                          //remove first item
		Node* secondItemPtr = head->next;
		delete head;
		head = secondItemPtr;
		return;
	}

	int itemCount{};                          //remove other items
	Node* ptr1{head};
	Node* ptr2;
	while(itemCount != index){
		itemCount++;
		if (itemCount == index){
			ptr2 = ptr1->next->next;
			delete ptr1->next;
			ptr1 -> next = ptr2;
			return;
		}
		ptr1 = ptr1->next;
	}

    ptr1 = nullptr;
    ptr2 = nullptr;


}


/*
OVERLOADED [] OPERATOR
Return item at position INDEX
PARAMETERS: INDEX, type int
RETURN VALUE: item at position INDEX
*/
template <class T>
T &	List<T>::		operator[]	( int index ){
	if (head == nullptr && index == 0){                //if user tries to assign first item of an empty list
		head = new Node;
		head->next = nullptr;
		return head->item;
	}

	int itemCount{};                                  //return the item in the specified index
	Node* ptr = head;
	while(itemCount != index){
		itemCount++;
		if (itemCount == index){
			ptr = ptr->next;
			return ptr->item;
		}
		ptr = ptr->next;
	}
	return ptr->item;
}


/*
METHOD: length
Return the list's length
PARAMETERS: none
RETURN VALUE: length of list, type int
*/
template <class T>
int		List<T>::	length		( void ) const{
	int itemCount{};
	Node* ptr{head};
	if (ptr == nullptr){                      //if list empty, length = 0
		return itemCount;
	}
	
	while (ptr != nullptr){                  //traverse through list and count the items
		itemCount++;
		ptr = ptr->next;
	}
	return itemCount;
}


/*
METHOD: isEmpty
Check if list is empty
PARAMETERS: none
RETURN VALUE: boolean indicating if list is empty
*/
template <class T>
bool	List<T>::	isEmpty		( void ) const{
	return head == nullptr;
}

/*
OVERLOADED = OPERATOR
Assign another list to this list
PARAMETERS: another list, type List<T>
RETURN VALUE: this list after assignment, type List<T>
*/
template<class T>
List<T>	List<T>::	operator=	( const List<T> &mylist ){
	
	if(mylist.head == nullptr){                                   //if an empty list is assigned to this list, clear this list
		(*this).clear();
		return *this;
	}
	
	Node* ptr{head};                                              //delete this list's items before copying other list over
	while(ptr != nullptr){
		ptr = head->next;
		delete head;
		head = ptr;
	}

	

	head = new Node;                                            //copying
	head->item = (mylist.head) -> item;
	head->next = nullptr;

	Node* ptr1 = mylist.head;
	Node* ptr2 = head;

	while(ptr1->next != nullptr){
		ptr1 = ptr1->next;
		ptr2->next = new Node;
		ptr2 = ptr2->next;
		ptr2->item = ptr1->item;
		ptr2->next = nullptr;
	}

    ptr1 = nullptr;
    ptr2 = nullptr;
	return *this;
}


/*
OVERLOADED + OPERATOR
Concatenate another list to the end of this list
PARAMETERS: another list, type List<T>
RETURN VALUE: this list after concatenation, type List<T>
*/
template <class T>
List<T>		List<T>::operator+	( const List<T> &mylist ) const{
	List<T> thisCopy(*this);                    //create copies of this list and other list
	List<T> mylistCopy(mylist);


	Node* ptr1{thisCopy.head};
	Node* ptr2{thisCopy.head};
	
	while (ptr1 != nullptr){                     //concatenate other list to this list
		ptr1 = ptr1->next;
		if (ptr1 == nullptr){
			ptr2->next = mylistCopy.head;

			mylistCopy.head = nullptr;

			ptr2 = nullptr;
			return thisCopy;
		}
		ptr2 = ptr2->next;
	}


	return mylistCopy;                          //if this list is empty, return other list
}

/*
METHOD: to_string
Print out list
PARAMETERS: none
RETURN VALUE: list in string form
*/
template <class T>
string	List<T>::	to_string	( void ) const{
	stringstream list;
	Node* ptr{head};
	while(ptr != nullptr){
		list << (ptr->item) << " ";
		ptr = ptr->next;
	}
	return list.str();
}

/*
METHOD: clear
Clear the list
PARAMETERS: none
RETURN VALUE: none
*/
template <class T>
void	List<T>::	clear		( void ){
	Node* ptr{head};
	while(ptr != nullptr){
		ptr = head->next;
		delete head;
		head = ptr;
	}
}

/*
DESTRUCTOR
Traverse through the list and delete every item
*/
template <class T>
List<T>::~List		( void ){
	Node* ptr{head};
	while(ptr != nullptr){
		ptr = head->next;
		delete head;
		head = ptr;
	}
}