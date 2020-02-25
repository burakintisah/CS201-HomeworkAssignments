#include <iostream>
#include "SimpleTrack.h"
#include "SimpleACS.h"
using namespace std;


int main() {
	ACS trye;
	trye.addTrack("Osman");
	trye.addTrack("Burak");
	trye.addTrack("asdf");

	ACS trye2;
	trye2 = trye;
	
	trye2.displayTracks();
	trye.displayTracks();

	trye2.removeTrack("Osman");
	trye2.displayTracks();
	trye.displayTracks();

	ACS try3 = trye;
	try3.displayTracks();

	trye.addTrack("Osman");
	trye.addTrack("OSMAN");
	trye.addTrack("ASDF");
	trye.displayTracks();
	
}