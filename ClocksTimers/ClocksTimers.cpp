#include "ClocksTimers.h"

#include <ctime>

std::string timepointAsString(const std::chrono::system_clock::time_point &tp)
{
   // convert to system time (C-lib and POSIX)
   time_t t{std::chrono::system_clock::to_time_t(tp)};
   std::string ts{ctime(&t)}; // convert to calendar time
   ts.resize(ts.size() - 1);  // skip trailing newline

   return ts;
}
