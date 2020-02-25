#include <iostream>
#include "Author.h"
#include "Paper.h"
#include "Track.h"
#include "ACS.h"

using namespace std;

int main() {
	
	/* // for testing Author class
	Author auth1;
	Author auth2(123, "Ahmet");

	cout << auth1.getID() << " " << auth1.getName() << endl;
	cout << auth2.getID() << " " << auth2.getName() << endl;
	*/
	
	/*// for testing Paper class
	Paper pape1;
	Paper pape2("Paper2");
	Paper pape3 = pape2;
	Paper pape4;

	cout << pape3.getName() << endl;

	pape1.addAuthor(1, "Ahmet");
	pape1.addAuthor(2, "Murat");
	pape1.addAuthor(1, "Burak");

	pape1.displayAuthors();

	pape4 = pape1;
	pape4.displayAuthors();
	
	pape1.removeAuthor(1);

	cout << "" << endl;
	pape1.displayAuthors();
	*/

	/* // for testig track class
	Track track2("track2");
	Track track3;
	Track track4;

	track2.addPaper("paper1");
	track2.addPaper("paper2");
	track2.addPaper("paper3");
	track2.addPaper("paper3");
	track2.displayPapers();

	cout << track2.getTrackName() << "  " << track2.getPaperCount() << endl;

	track2.removePaper("paper3");
	track2.displayPapers();

	track2.addAuthor(1, "Osman", "paper2");
	track2.addAuthor(21, "Osman", "paper2");
	
	track2.displayPapers();

	cout <<  track2.getTrackName() << "  " << track2.getPaperCount() << endl;
	*/

	ACS acs1;
	ACS * acs2 = new ACS();
	(*acs2).addTrack("123");
	(*acs2).addTrack("1234");
	(*acs2).addTrack("12345");

	(*acs2).addPaper("123", "paper1");
	(*acs2).addPaper("123", "paper2");
	(*acs2).addPaper("123", "paper3");
	(*acs2).addPaper("12345", "paper4");
	(*acs2).addPaper("1234", "paper4");
	(*acs2).addPaper("12345", "paper5");

	(*acs2).removeTrack("12345");
	(*acs2).removePaper("123","paper1");

	(*acs2).displayEverything();

	(*acs2).addAuthor("123", "paper2", 11, "name1");
	(*acs2).addAuthor("123", "paper2", 12, "name2");
	(*acs2).addAuthor("123", "paper2", 13, "name3");
	(*acs2).addAuthor("123", "paper2", 11, "name4");
	(*acs2).addAuthor("1234", "paper4", 11, "name4");
	(*acs2).addAuthor("123", "paper4", 11, "name4");

	cout << Track::changeWord("ashasdhasjjsa") << endl;
	
	(*acs2).displayEverything();

	(*acs2).displayTrack("123");
	
	(*acs2).displayAuthor(11);

	ACS acs3;
	acs3 = *acs2;
	acs3.displayEverything();
	delete acs2;


	/*acs1.addTrack("track1");
	acs1.addTrack("track2");
	acs1.addTrack("track3");
	
	acs1.displayEverything();
	cout << "" << endl;

	acs1.addPaper("track1", "paper1");
	acs1.addPaper("track1", "paper2");
	acs1.addPaper("track1", "paper3");
	acs1.addPaper("track3", "paper4");
	acs1.addPaper("track3", "paper5");

	acs1.displayEverything();
	cout << "" << endl;

	acs1.removePaper("TRACK1", "PAPER2");
	acs1.displayEverything();
	cout << "" << endl;

	acs1.addAuthor("track1", "paper1", 1, "Osman");
	acs1.addAuthor("track1", "paper3", 1, "Osman");
	acs1.addAuthor("track1", "paper1", 2, "Burak");
	
	acs1.addAuthor("track1", "paper1", 2, "shjshjshj");
	cout << "" << endl;
	acs1.addAuthor("track3", "paper4", 2, "Burak");
	cout << "" << endl;
	acs1.addAuthor("track3", "paper5", 2, "Burak");

	acs1.displayEverything();
	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;

	acs1.displayTrack("track1");
	acs1.displayTrack("track3");
	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;
	
	acs1.displayAuthor(2);
*/
	return 0;
}




//#include "Paper.h"
//#include "Track.h"
//#include "ACS.h"
//#include <iostream>
//using namespace std;
//
//int main() {
//	
//	cout << "" << endl;
//	ACS* acs = new ACS;
//	acs->addAuthor("sample", "", 1, "author");
//	acs->addPaper("sample", "");
//	acs->displayAllTracks();
//	cout << "" << endl;
//	acs->displayTrack("sdasd");
//	//acs->displayAuthor(1);
//
//	cout << "" << endl;
//	acs->addTrack("new track");
//	acs->addTrack("new track");
//	acs->addTrack("sample track");
//	cout << "" << endl;
//
//	acs->displayAllTracks();
//	cout << "" << endl;
//
//	acs->addPaper("new track", "new paper");
//	acs->addPaper("new track", "new paper2");
//	acs->addPaper("new track", "new paper3");
//
//	cout << "" << endl;
//
//	acs->addAuthor("new track", "new paper", 1, "ahmet");
//	acs->addAuthor("new track", "new paper", 2, "serdar");
//	acs->addAuthor("new track", "new paper", 2, "gurbuz");
//	acs->addAuthor("new track", "new paper", 1, "serdar");
//	acs->addAuthor("new track", "new paper2", 2, "ahmet");
//
//	cout << "***********************************************************************" << endl;
//
//	acs->displayTrack("nEw TraCk");
//	acs->displayTrack("SAMPLE track");
//
//	cout << "**************************************************************************" << endl;
//
//	acs->addPaper("sample track", "sample paper");
//	acs->addPaper("sample track", "sample paper2");
//	acs->addPaper("sample track", "sample paper3");
//
//	cout << "" << endl;
//	cout << "** first acs **" << endl;
//	cout << "" << endl;
//
//	acs->displayAllTracks();
//	acs->displayTrack("new track");
//	acs->displayTrack("sample track");
//
//	cout << "" << endl;
//	ACS * acs2 = new ACS();
//	*acs2 = *acs;
//
//	acs2->displayAllTracks();
//	acs2->displayTrack("new track");
//	acs2->displayTrack("sample track");
//
//	// TO BE FIXED COPY CONSTRUCTOR
//
//	cout << "" << endl;
//	acs2->removeTrack("newtrack");
//	acs2->removeTrack("new track");
//
//
//	cout << "" << endl;
//	acs2->addTrack("fucking track");
//	acs2->addPaper("fucking track", "fucking paper");
//	cout << "" << endl;
//
//	cout << "** first acs **" << endl;
//	acs->displayAllTracks();
//	cout << "" << endl;
//
//	cout << "** second acs **" << endl;
//	acs2->displayAllTracks();
//	cout << "" << endl;
//
//	acs2->displayTrack("NEW TRACK");
//	acs2->displayTrack("sample track");
//	acs2->displayTrack("fucking track");
//
//	cout << "" << endl;
//	cout << "" << endl;
//	cout << "" << endl;
//
//	string b = "hello worlds";
//	ACS::changeWord(b);
//	cout << b << endl;
//
//	cout << "" << endl;
//	cout << "" << endl;
//	cout << "" << endl;
//	
//	acs->displayAuthor(2);
//
//	system("PAUSE");
//	return 0;
//}

