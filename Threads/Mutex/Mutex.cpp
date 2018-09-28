// C++11 example, mutex and lock_guard
#include <algorithm>
#include <atomic>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

using namespace std;

// shared var
volatile int counter{0};
// mutex: mutual exclusion
mutex mtx;

// Always check if a function is 'thread safe'.

void increment_count1()
{
   // Scoped lock pattern
   // RAII: Resource Acquisition in Initialization idiom for locking (in ctor)
   // and unlocking (in dtor) a mutex.
   lock_guard<mutex> lock(mtx);
   cout << "1 counter = " << (++counter) << endl;
   // Unlocking mutex in dtor
}

void increment_count2()
{
   cout << "2 counter = " << (++counter) << endl;
}

void increment_count3(int data)
{
   // Scoped lock pattern
   lock_guard<mutex> lock(mtx);
   cout << "3 counter = " << (++counter) << " " << data << endl;
}

int main()
{
   vector<std::thread> workers;

   cout << "--- Executing thread function using mutex: " << endl;
   for (int i = 0; i < 20; ++i) {
      workers.push_back(std::thread(increment_count1));
   }
   for (auto &th : workers) {
      th.join();
   }
   workers.clear();

   cout << "--- Executing thread function not using mutex: " << endl;
   for (int i = 0; i < 20; ++i) {
      workers.push_back(std::thread(increment_count2));
   }
   for (auto &th : workers) {
      th.join();
   }
   workers.clear();

   cout << "--- Executing thread function using mutex and communicating "
           "a parameter: "
        << endl;
   for (int i = 0; i < 20; ++i) {
      workers.push_back(thread(increment_count3, i * 1000));
   }
   std::for_each(begin(workers), end(workers), [](thread &th) { th.join(); });

   return 0;
}
