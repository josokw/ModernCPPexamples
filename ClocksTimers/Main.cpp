#include "ClocksTimers.h"

#include <chrono>
#include <iostream>
#include <thread>

int main()
{
   // time points, represent absolute time
   std::chrono::system_clock::time_point epoch; // default ctor
   std::chrono::system_clock::time_point systemStart{
      std::chrono::system_clock::now()};

   // durations
   const std::chrono::seconds twentySeconds{20};
   const std::chrono::hours aDay{24};
   const std::chrono::hours aYear{aDay * 365};
   const std::chrono::milliseconds oneMillisecond{1};
   std::chrono::milliseconds msecs{
      std::chrono::duration_cast<std::chrono::milliseconds>(aDay)};

   std::cout << std::endl;
   std::cout << "Epoch:            " << timepointAsString(epoch) << std::endl;
   std::cout << "System start:     " << timepointAsString(systemStart)
             << std::endl;

   std::cout << std::endl;
   std::cout << oneMillisecond.count() << " msec" << std::endl;
   std::cout << std::chrono::nanoseconds(oneMillisecond).count() << " nsec"
             << std::endl;
   std::cout << msecs.count() << " msec" << std::endl << std::endl;

   std::cout << "Passed time since epoch in msec = " << timeSinceEpoch_msec()
             << std::endl;
   std::cout << "Passed time since epoch in sec  = " << timeSinceEpoch_sec()
             << std::endl;
   std::cout << std::endl;

   const std::chrono::seconds fiveSeconds{5};
   std::chrono::system_clock::time_point t1{std::chrono::system_clock::now()};
   std::cout << "Sleeping ... " << timepointAsString(t1) << std::endl;
   // sleep_until absolute time (time point)
   std::this_thread::sleep_until(t1 + fiveSeconds);
   std::chrono::system_clock::time_point t2{std::chrono::system_clock::now()};
   std::cout << "Awake (absolute time): " << timepointAsString(t2) << std::endl;

   std::cout << std::endl << "Sleeping ..." << std::endl;
   // sleep_for duration
   std::this_thread::sleep_for(fiveSeconds);
   std::cout << "Awake (duration): " << fiveSeconds.count() << " sec"
             << std::endl
             << std::endl;

   return 0;
}
