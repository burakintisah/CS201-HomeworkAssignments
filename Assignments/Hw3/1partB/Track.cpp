#include <iostream>
#include <string>
#include "Track.h"
using namespace std;



Track::Track(const string tname)
{
	trackName = tname;
	head = NULL;
}

Track::~Track()
{
	PaperNode * rest;
	while (head != NULL) {
		rest = head;
		head = head->next;
		rest->next = NULL;
		delete rest;
	}
}

Track::Track(const Track & trackToCopy)
{
	if (trackToCopy.head == NULL) {
		head = NULL;  // original list is empty
		trackName = trackToCopy.trackName;
	}
	else {
		// copy first node
		head = new PaperNode;
		head->a = trackToCopy.head->a;
		// copy rest of list
		PaperNode *newPtr = head;  // new list ptr

		for (PaperNode *origPtr = trackToCopy.head->next; origPtr != NULL; origPtr = origPtr->next) {
			newPtr->next = new PaperNode;
			newPtr = newPtr->next;
			newPtr->a = origPtr->a;
		}
		newPtr->next = NULL;
		trackName = trackToCopy.trackName;
	}
}

void Track::operator=(const Track & right)
{
	PaperNode * rest;
	while (head != NULL) {
		rest = head;
		head = head->next;
		rest->next = NULL;
		delete rest;
	}

	if (right.head == NULL) {
		head = NULL;  // original list is empty
		trackName = right.trackName;
	}
	else {
		// copy first node
		head = new PaperNode;
		head->a = right.head->a;
		// copy rest of list
		PaperNode *newPtr = head;  // new list ptr

		for (PaperNode *origPtr = right.head->next; origPtr != NULL; origPtr = origPtr->next) {
			newPtr->next = new PaperNode;
			newPtr = newPtr->next;
			newPtr->a = origPtr->a;
		}
		newPtr->next = NULL;
		trackName = right.trackName;
	}
}

bool Track::addAuthor(const int AuthorId, const string AuthorName, const string paperName)
{
	PaperNode * paper = findPaper(paperName);
	if (paper != NULL) {
		if((paper->a).addAuthor(AuthorId, AuthorName))
			return true;
	}
		
	else
		if (paper == NULL)
			cout << "There is not any paper with the given name !!" << endl;
		return false;

}

bool Track::removeAuthor(const int id,const string paperName)
{
	PaperNode * paper = findPaper(paperName);
	if ((paper->a).removeAuthor(id))
		return true;
	else
		if (paper == NULL)
			cout << "There is not any paper with the given name !!" << endl;
		return false;
}

bool Track::addPaper(const string name)
{
	bool exist = false;
	if (findPaper(name) != NULL)
		exist = true;

	if (exist) {
		cout << "There is a paper with the same name in this track. Not valid !!" << endl;
		return false;
	}

	else {
		Paper newPaper (name);
		PaperNode * newPtr = new PaperNode;
		newPtr->a = newPaper;
		newPtr->next = NULL;
		if (head == NULL) {
			head = newPtr;
		}
		else {
			for (PaperNode * i = head; i != NULL; i = i->next) {
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

bool Track::removePaper(const string name)
{
	bool exist = false;
	if (findPaper(name) != NULL)
		exist = true;

	if (exist) {
		PaperNode * found = findPaper(name);
		PaperNode * after = NULL;
		if (found->next != NULL)
			after = found->next;
		PaperNode * prev = NULL;
		for (PaperNode * i = head; i != NULL; i = i->next) { // to find prev node
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
		cout << "There is not any paper with the given name in this track !! " << endl;
		return false;
	}
}

string Track::getTrackName()
{
	return trackName;
}

void Track::displayPapers()
{
	if (head == NULL )
		cout << "--EMPTY--" << endl;
	else {
		for (PaperNode * i = head; i != NULL; i = i->next) {

			cout << "Paper " << i->a.getName() << endl;
			i->a.displayAuthors() ;
		}
	}
}

string Track::changeWord(string first)
{
	string result = first;
	for (int i = 0; i < first.length(); i++) {
		result[i] = toupper(first[i]);
	}
	return result;

}

bool Track::existPaper(const int id, string & name,  string & paperNames)
{
	bool exist = false;
	for (PaperNode * i = head; i != NULL; i = i->next) {
		bool check = (i->a).authorExist(id,name);
		if (check) {
			exist = true;
			paperNames = paperNames + "	Paper " + (i->a).getName() + "\n";
		}
	}
	return exist;
}

Track::PaperNode * Track::findPaper(string name)
{
	PaperNode * result = NULL;
	string check1 = changeWord(name);
	for (PaperNode * i = head; i != NULL; i = i->next) {
		string as = changeWord(i->a.getName());
		if (as == check1) {
			result = i;
			break;
		}
	}
	return result;
}

