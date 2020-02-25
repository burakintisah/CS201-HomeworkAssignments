#include "ACS.h"
#include <iostream>

ACS::ACS()
{
	head = NULL;
	trackCount = 0;
}

ACS::~ACS()
{
	Node * rest;
	while (head != NULL) {
		rest = head;
		head = head->next;
		rest->next = NULL;
		delete rest;
	}
}

ACS::ACS(const ACS & systemToCopy)
{
	if (systemToCopy.head == NULL) {
		head = NULL;  // original list is empty
		trackCount = 0;
	}
	else {
		// copy first node
		head = new Node;
		head->t = systemToCopy.head->t;
		// copy rest of list
		Node *newPtr = head;  // new list ptr

		for (Node *origPtr = systemToCopy.head->next; origPtr != NULL; origPtr = origPtr->next) {
			newPtr->next = new Node;
			newPtr = newPtr->next;
			newPtr->t = origPtr->t;
		}
		newPtr->next = NULL;
		trackCount = systemToCopy.trackCount;
	}
}

void ACS::operator=(const ACS & right)
{
	Node * rest;
	while (head != NULL) {
		rest = head;
		head = head->next;
		rest->next = NULL;
		delete rest;
	}
	if (right.head == NULL) {
		head = NULL;  // original list is empty
		trackCount = 0;
	}
	else {
		// copy first node
		head = new Node;
		head->t = right.head->t;
		// copy rest of list
		Node *newPtr = head;  // new list ptr

		for (Node *origPtr = right.head->next; origPtr != NULL; origPtr = origPtr->next) {
			newPtr->next = new Node;
			newPtr = newPtr->next;
			newPtr->t = origPtr->t;
		}
		newPtr->next = NULL;
		trackCount = right.trackCount;
	}
}

void ACS::addTrack(string trackName)
{
	bool exist = false;
	if (findTrack(trackName) != NULL)
		exist = true;

	if (exist) {
		cout << "There is an track with the same name. Could not added !!" << endl;
	}

	else {
		Track newTrack(trackName);
		Node * newPtr = new Node;
		newPtr->t = newTrack;
		newPtr->next = NULL;
		if (head == NULL) {
			head = newPtr;
			trackCount++;
		}
		else {
			for (Node * i = head; i != NULL; i = i->next) {
				// for finding the last node
				if (i->next == NULL) {
					i->next = newPtr;
					trackCount++;
					break;
				}
			}
		}
	}
}

void ACS::removeTrack(string trackName)
{
	bool exist = false;
	if (findTrack(trackName) != NULL)
		exist = true;

	if (exist) {
		Node * found = findTrack(trackName);
		Node * after = found->next;
		Node * prev = NULL;
		for (Node * i = head; i != NULL; i = i->next) { // to find prev node
			if (i->next == found) {
				prev = i;
			}
		}
		if (prev != NULL)
			prev->next = after;
		else
			head = after;
		found->next = NULL;
		trackCount--;
		delete found;
	}
	else {
		cout << "There is not any track with the given name !! " << endl;
	}
}

void ACS::displayAllTracks()
{
	if (head == NULL)
		cout << "--EMPTY--" << endl;
	else {
		for (Node * i = head; i != NULL; i = i->next) {
			cout << "Track " << i->t.getTrackName() << endl;
		}
	}
}

void ACS::addPaper(string trackName, string paperName)
{
	Node * found = findTrack(trackName);
	if (found == NULL)
		cout << "There is not any track with the given name !!" << endl;
	else
		(found->t).addPaper(paperName);
}

void ACS::removePaper(string trackName, string paperName)
{
	Node * found = findTrack(trackName);
	if (found == NULL)
		cout << "There is not any track with the given name !!" << endl;
	else
		(found->t).removePaper(paperName);
}

void ACS::addAuthor(string trackName, string paperName, int authorID, string authorName)
{
	Node * found = findTrack(trackName);
	if (found == NULL)
		cout << "There is not any track with the given name !!" << endl;
	else
		(found->t).addAuthor(authorID, authorName, paperName);
}

void ACS::removeAuthor(string trackName, string paperName, int authorID)
{
	Node * found = findTrack(trackName);
	if (found == NULL)
		cout << "There is not any track with the given name !!" << endl;
	else
		(found->t).removeAuthor(authorID, paperName);
}

void ACS::displayTrack(string trackName)
{
	bool exist = false;
	if (findTrack(trackName) != NULL)
		exist = true;
	if (!exist)
		cout << "\n--EMPTY--" << endl;
	else {
		Node * found = findTrack(trackName);
		cout << "Track " << (found->t).getTrackName() << endl;
		(found->t).displayPapers();
	}
}

void ACS::displayAuthor(int authorID)
{
	string name = "";
	bool exist = false;
	bool autorName = false;
	for (Node * i = head; i != NULL; i = i->next) {
		string papers = "";
		exist = (i->t).existPaper(authorID, name,papers);
		if (exist ){
			if (!autorName) {
				cout << "Author " << authorID << ", Author " << name << endl;
				autorName = true;
			}
			cout << "Track " << (i->t).getTrackName() << endl;
			cout << papers << endl;
		}	
	}

}

void ACS::displayEverything()
{
	for (Node * i = head; i != NULL; i = i->next) {
		cout << "Track " << (i->t).getTrackName() << endl;
		(i->t).displayPapers();
		cout << "" << endl;
	}
}

ACS :: Node * ACS::findTrack(string trackName)
{
	Node * result = NULL;
	string check2 = Track:: changeWord(trackName);
	for (Node * i = head; i != NULL; i = i->next) {
		string as = Track::changeWord(i->t.getTrackName());
		if (as== check2) {
			result = i;
			break;
		}
	}
	return result;
}
