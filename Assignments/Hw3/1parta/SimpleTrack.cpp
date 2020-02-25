#include <iostream>
#include <string>
#include "SimpleTrack.h"
using namespace std;


Track::Track(const string tname)
{
	trackName = tname;
}

Track::~Track()
{
}

Track::Track(const Track & trackToCopy)
{
	trackName = trackToCopy.trackName;
}

void Track::operator=(const Track & right)
{
	trackName = right.trackName;
}

string Track::getTrackName()
{
	return trackName;
}
