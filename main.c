/**
 * Demo program for ADT exercise.
 *
 * Author: Evgeny Hershkovitch Neiterman
 * Since : 2023-02
 */

#include "AdptArray.h"
#include "book.h"
#include "Person.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

int main()
{
	printf("\nBooks:\n");

	pbook b1 = creat_book("harry Potter", 12345);
	pbook b2 = creat_book("C intro", 45678);
	pbook b3 = creat_book("CPP intro", 4560);
	pbook b4 = creat_book("The Hunger Games", 5678);
	pbook b5 = creat_book("Python intro", 7509);
	PAdptArray mybooks = CreateAdptArray(copy_book, delete_book, print_book);
	SetAdptArrayAt(mybooks, 3, b1);
	SetAdptArrayAt(mybooks, 5, b2);
	printf("the size is %d\n", GetAdptArraySize(mybooks)); // prints 6
	SetAdptArrayAt(mybooks, 15, b3);
	SetAdptArrayAt(mybooks, 8, b4);
	printf("the size is %d\n", GetAdptArraySize(mybooks)); // should print 16
	pbook b = GetAdptArrayAt(mybooks, 4);				   // should return null;
	assert(b == NULL);									   // doesn't fail
	b = GetAdptArrayAt(mybooks, 3);
	printf("the book is %s\n", b->name); // should print "Harry Potter"
	PrintDB(mybooks);

	// prints:
	//  name: harry Potter serial number: 12345
	//  name: C intro serial number: 45678
	//  name: The Hunger Games serial number: 5678
	//  name: CPP intro serial number: 4560

	SetAdptArrayAt(mybooks, 8, b5);
	printf("\n");
	PrintDB(mybooks);

	// prints:
	//  name: harry Potter serial number: 12345
	//  name: C intro serial number: 45678
	//  name: Python intro serial number: 7509
	//  name: CPP intro serial number: 4560

	printf("\nCharacters:\n");
	pperson p1 = creat_person("Harry", "Potter", 934);
	pperson p2 = creat_person("Ron", "Weasley", 789);
	pperson p3 = creat_person("Hermione", "Granger", 456);
	pperson p4 = creat_person("Draco", "Malfoy", 300);
	pperson p5 = creat_person("Lucius", "Malfoy", 350);
	PAdptArray HP_caracters = CreateAdptArray(copy_person, delete_person, print_person);
	SetAdptArrayAt(HP_caracters, 2, p1);
	SetAdptArrayAt(HP_caracters, 8, p2);
	printf("the size is %d\n", GetAdptArraySize(HP_caracters)); // prints 9
	SetAdptArrayAt(HP_caracters, 20, p3);
	SetAdptArrayAt(HP_caracters, 10, p4);
	printf("the size is %d\n", GetAdptArraySize(HP_caracters)); // prints 21
	PrintDB(HP_caracters);
	// prints:
	// first name: Harry last name: Potter id: 934
	// first name: Ron last name: Weasley id: 789
	// first name: Draco last name: Malfoy id: 300
	// first name: Hermione last name: Granger id: 456

	SetAdptArrayAt(HP_caracters, 10, p5);
	printf("\n");
	PrintDB(HP_caracters);

	// prints :
	// first name: Harry last name: Potter id: 934
	// first name: Ron last name: Weasley id: 789
	// first name: Lucius last name: Malfoy id: 300
	// first name: Hermione last name: Granger id: 456

	pperson p = GetAdptArrayAt(HP_caracters, 7); // should return null;
	assert(p == NULL);							 // doesn't fail
	p = GetAdptArrayAt(HP_caracters, 8);
	printf("the person name is %s %s\n", p->first_name, p->last_name); // should print "the person name is Ron Weasley"

	// Delete
	DeleteAdptArray(mybooks);
	DeleteAdptArray(HP_caracters);

	delete_person(p1);
	delete_person(p2);
	delete_person(p3);
	delete_person(p4);
	delete_person(p5);
	delete_person(p);

	delete_book(b1);
	delete_book(b2);
	delete_book(b3);
	delete_book(b4);
	delete_book(b5);
	delete_book(b);
	return 0;
}
