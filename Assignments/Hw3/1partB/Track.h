#ifndef __TRACK_H
#define __TRACK_H
#include <iostream>
#include <string>
#include "Paper.h"
using namespace std;


class Track {
public:
	Track(const string tname = "");
	~Track();
	Track(const Track &trackToCopy);
	void operator=(const Track &right);
	bool addAuthor(const int AuthorId, const string AuthorName, const string paperName);
	bool removeAuthor(const int id, const string paperName);
	bool addPaper(const string name);
	bool removePaper(const string name);
	string getTrackName();
	void displayPapers();
	bool existPaper(const int id,string & name,string & paperNames);
	static string changeWord(string first);

private:
	struct PaperNode {
		Paper a;
		PaperNode* next;
	};
	PaperNode * head;
	string trackName;

	PaperNode *  findPaper(string name);
};
#endif