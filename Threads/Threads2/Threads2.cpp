#include <algorithm>
#include <cassert>
#include <iostream>
#include <thread>
#include <vector>

const int NUMBER_OF_THREADS{15};

// Call by reference for parameter i
void thFunc(int &i)
{
   std::cout << "Hi from thread " << i << " !\n";
}

void test(std::vector<std::thread> &workers)
{
   for (int i = 0; i < NUMBER_OF_THREADS; ++i) {
      // Passing local var i by refrence to thread function is dangerous!
      auto th = std::thread(&thFunc, std::ref(i));
      workers.push_back(std::move(th));
      assert(!th.joinable());
   }
   // Local var i removed from stack, threads are still using var i
}

int main()
{
   std::vector<std::thread> workers;

   test(workers);
   std::cout << "Hi from main\n";
   std::for_each(begin(workers), end(workers), [](std::thread &th) {
      assert(th.joinable());
      th.join();
   });

   return 0;
}
