// Uses native_handle to enable realtime scheduling of C++ threads on a
// POSIX system. Must be executed by root.
// Source: ccpreference.com

#include <chrono>
#include <cstring>
#include <iostream>
#include <mutex>
#include <pthread.h>
#include <thread>

// global mutex
std::mutex iomutex;

void f(int num)
{
   std::this_thread::sleep_for(std::chrono::seconds(1));

   sched_param sch;
   int policy;

   pthread_getschedparam(pthread_self(), &policy, &sch);
   std::lock_guard<std::mutex> lk(iomutex); // RAII
   std::cout << "Thread " << num << " is executing at priority "
             << sch.sched_priority << '\n';
   // RAII: implicit call of destructor of std::lock_guard for unlocking
}

int main()
{
   std::thread t1(f, 1);
   std::thread t2(f, 2);

   sched_param sch;
   int policy;
   pthread_getschedparam(t1.native_handle(), &policy, &sch);
   sch.sched_priority = 20;

   if (pthread_setschedparam(t1.native_handle(), SCHED_FIFO, &sch)) {
      std::cout << "Failed to setschedparam: " << std::strerror(errno) << '\n';
   }

   t1.join();
   t2.join();

   return 0;
}
