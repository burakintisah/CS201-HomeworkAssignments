#include "Paper.h"
#include <iostream>

Paper::Paper()
{
	name = "";
	head = NULL;
}

Paper::Paper(const string name)
{
	this->name = name;
	head = NULL;
}

Paper::~Paper()
{
	AuthorNode * temp;
	while (head != NULL ) {
		temp = head;
		head = head->next;
		temp->next = NULL;
		delete temp;
	}
}

Paper::Paper(const Paper & paperToCopy)
{
	if (paperToCopy.head == NULL) {
		head = NULL;  // original list is empty
		name = paperToCopy.name;
	}
	else {
		// copy first node
		head = new AuthorNode;
		head->a = paperToCopy.head->a;
		// copy rest of list
		AuthorNode *newPtr = head;  // new list ptr

		for (AuthorNode *origPtr = paperToCopy.head->next; origPtr != NULL; origPtr = origPtr->next) {
			newPtr->next = new AuthorNode;
			newPtr = newPtr->next;
			newPtr->a = origPtr->a;
		}
		newPtr->next = NULL;
		this->name = paperToCopy.name;
	}
}

void Paper::operator=(const Paper & right)
{
	AuthorNode * temp;
	while (head != NULL) {
		temp = head;
		head = head->next;
		temp->next = NULL;
		delete temp;
	}
	if (right.head == NULL) {
		head = NULL;  // original list is empty
		name = right.name;
	}
	else {
		// copy first node
		head = new AuthorNode;
		head->a = right.head->a;
		// copy rest of list
		AuthorNode *newPtr = head;  // new list ptr

		for (AuthorNode *origPtr = right.head->next; origPtr != NULL; origPtr = origPtr->next) {
			newPtr->next = new AuthorNode;
			newPtr = newPtr->next;
			newPtr->a = origPtr->a;
		}
		newPtr->next = NULL;
		this->name = right.name;
	}
}

string Paper::getName()
{
	return this->name;
}

bool Paper::addAuthor(const int id, const string name)
{
	bool exist = false;
	if (findAuthor(id) != NULL)
		exist = true;

	if (exist) {
		cout << "There is an author with the same id. The author cannot be added !!" << endl;
		return false;
	}
		
	else {
		Author newAuthor (id,name);
		AuthorNode * newPtr = new AuthorNode;
		newPtr->a = newAuthor;
		newPtr->next = NULL;
		if (head == NULL) {
			head = newPtr;
		}
		else {
			for (AuthorNode * i = head; i != NULL; i = i->next) {
				// for finding the last node
				if (i->next == NULL) {
					i->next = newPtr;
					break;
				}
			}
		}
		return true;
	}
}

bool Paper::removeAuthor(const int id)
{
	bool exist = false;
	if (findAuthor(id) != NULL)
		exist = true;

	if (exist) {
		AuthorNode * found = findAuthor(id);
		AuthorNode * after = NULL;
		if (found->next != NULL)
			after = found->next;
		AuthorNode * prev = NULL;
		for (AuthorNode * i = head; i != NULL; i = i->next) { // to find prev node
			if (i->next == found) {
				prev = i;
			}
		}
		if (prev != NULL)
			prev->next = after;
		else
			head = after;
		found->next = NULL;
		delete found;
		return true;
	}
	else {
		cout << "There is not any author with the given id !! " << endl;
		return false;
	}
		
}

void Paper::displayAuthors()
{
	if (head == NULL)
		cout << "	--EMPTY--" << endl;
	else {
		for (AuthorNode * i = head; i != NULL; i = i->next) {
			cout << "	Author " << i->a.getID() << ", Author " << i->a.getName() << endl;
		}
	}
}

bool Paper::authorExist(const int id, string & name)
{
	bool result = false;
	for (AuthorNode * i = head; i != NULL; i = i->next) {
		if ((i->a).getID() == id) {
			result = true;
			name = (i->a).getName();
			break;
		}
	}
	return result;
}

Paper:: AuthorNode * Paper::findAuthor(int id)
{
	AuthorNode * result = NULL;
	for (AuthorNode * i = this->head; i != NULL; i = i->next) {
		if (i->a.getID() == id) {
			result = i;
			break;
		}
	}
	return result;
}
