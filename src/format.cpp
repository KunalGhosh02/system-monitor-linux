#include "format.h"

#include <string>

using std::string;

//  helper function
// INPUT: Long int measuring seconds
string Format::ElapsedTime(long secs) {
  long mins = secs / 60;
  long hrs = mins / 60;
  long lsecs = int(secs % 60);
  mins = int(mins % 60);
  string pretty_time = std::to_string(hrs) + ":" + std::to_string(mins) + ":" +
                       std::to_string(lsecs);
  return pretty_time;
}