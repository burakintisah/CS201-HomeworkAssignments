#include <iostream>
#include <string>
#include "SimpleACS.h"
using namespace std;


ACS::ACS()
{
	head = NULL;
	name = "";
	topic = "";
	trackCount = 0;
}

ACS::~ACS()
{
	TrackNode * temp;
	while (head != NULL) {
		temp = head;
		head = head->next;
		temp->next = NULL;
		trackCount--;
		delete temp;
	}
}

ACS::ACS(const ACS & acsToCopy)
{
	if (acsToCopy.head == NULL) {
		head = NULL;  // original list is empty
		name = acsToCopy.name;
		topic = acsToCopy.topic;
		trackCount = acsToCopy.trackCount;
	}
	else {
		// copy first node
		head = new TrackNode;
		head->t = acsToCopy.head->t;
		// copy rest of list
		TrackNode *newPtr = head;  // new list ptr

		for (TrackNode *origPtr = acsToCopy.head->next; origPtr != NULL; origPtr = origPtr->next) {
			newPtr->next = new TrackNode;
			newPtr = newPtr->next;
			newPtr->t = origPtr->t;
		}
		newPtr->next = NULL;
		name = acsToCopy.name;
		topic = acsToCopy.topic;
		trackCount = acsToCopy.trackCount;
	}
}

void ACS::operator=(const ACS & right)
{
	TrackNode * temp;
	while (head != NULL) {
		temp = head;
		head = head->next;
		temp->next = NULL;
		trackCount--;
		delete temp;
	}
	if (right.head == NULL) {
		head = NULL;  // original list is empty
		name = right.name;
		topic = right.topic;
		trackCount = right.trackCount;
	}
	else {
		// copy first node
		head = new TrackNode;
		head->t = right.head->t;
		// copy rest of list
		TrackNode *newPtr = head;  // new list ptr

		for (TrackNode *origPtr = right.head->next; origPtr != NULL; origPtr = origPtr->next) {
			newPtr->next = new TrackNode;
			newPtr = newPtr->next;
			newPtr->t = origPtr->t;
		}
		newPtr->next = NULL;
		name = right.name;
		topic = right.topic;
		trackCount = right.trackCount;
	}
}

bool ACS::addTrack(const string trackName)
{
	bool exist = false;
	if (findTrack(trackName) != NULL)
		exist = true;
	
	if ( exist )
		return false;
	else {
		Track newTrack (trackName);
		trackCount = trackCount + 1;
		TrackNode *newPtr = new TrackNode;
		newPtr->t = newTrack;
		newPtr->next = NULL;
		if (trackCount == 1) // if trackCount becomes 1
			head = newPtr;
		else {
			for (TrackNode * i = head; i != NULL; i = i->next) {		
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

bool ACS::removeTrack(const string trackName)
{
	bool exist = false;
	if (findTrack(trackName) != NULL)
		exist = true;
	
	if (exist) {
		TrackNode * found = findTrack(trackName);
		TrackNode * after = NULL;
		if (found->next != NULL)
			after = found->next;
		TrackNode * prev = NULL;
		for (TrackNode * i = head; i != NULL; i = i->next) { // to find prev node
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
	else
		return false;
}

void ACS::displayTracks()
{
	if (trackCount == 0)
		cout << "--EMPTY--" << endl;
	else {
		for (TrackNode * i = head; i != NULL; i = i->next) {

			cout << "Track " <<  i->t.getTrackName() << endl;
		}
	}
}

ACS::TrackNode * ACS::findTrack(string trackName)
{
	TrackNode * result = NULL;
	string check1 = trackName;

	for (int k = 0; k < trackName.length(); k++) {
		check1[k] = toupper(trackName[k]);
	}
	for (TrackNode * i = head; i != NULL; i = i->next) {
		string check2 = i->t.getTrackName();
		for (int a = 0; a < check2.length(); a++) {
			check2[a] = toupper(check2[a]);
		}
		if (check1 == check2) {
			result = i;
			break;			
		}
	}
	return result;
}



