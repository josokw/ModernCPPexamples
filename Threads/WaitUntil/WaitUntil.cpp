// waituntil causes the current thread to block until the condition variable
// is notified, a specific time is reached, or a spurious wakeup occurs,
// optionally looping until some predicate is satisfied.
// Source: cppreference.com

#include <atomic>
#include <chrono>
#include <condition_variable>
#include <iostream>
#include <thread>

// global vars
std::condition_variable cv;
std::mutex mtx;
std::atomic<int> i = ATOMIC_VAR_INIT(0);

void waits(int idx)
{
   // std::unique_lock has additional functionalities, more advanced but lower
   // performance than std::lock_guard: for example, can be unlocked by the
   // unlock() function and can be moved().
   std::unique_lock<std::mutex> lock(mtx); // RAII, lock in ctor.
   // std::unique_lock() can defer the lock: lock(mtx, std::defer_lock)
   auto now = std::chrono::system_clock::now();

   if (cv.wait_until(lock, now + std::chrono::milliseconds(idx),
                     // Predicate function, returns a bool (true or false).
                     []() { return i == 100; })) {
      std::cerr << "Thread " << idx << "ms finished waiting, because "
                << "condition i == " << i << '\n';
   } else {
      std::cerr << "Thread " << idx << " timed out, i == " << i << '\n';
   }
   // RAII: implicit call of destructor of std::unique_lock for unlocking.
}

void signals()
{
   std::this_thread::sleep_for(std::chrono::milliseconds(120));
   std::cerr << "**Notifying...\n";
   cv.notify_all();
   std::this_thread::sleep_for(std::chrono::milliseconds(100));
   // Change value global var for stop condition thread.
   i = 100;
   std::cerr << "**Notifying again...\n";
   cv.notify_all();
}

int main()
{
   std::cout << "---- WaitUntil started\n";
   std::thread t1(waits, 100);
   std::thread t2(waits, 200);

   std::thread t3(waits, 300); // This thread will be stopped by true value
                               // predicate function (i == 100).
   std::thread t4(signals);

   t1.join();
   t2.join();
   t3.join();
   t4.join();

   return 0;
}
