// C++11 threading

#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <thread>
#include <vector>

const int NUMBER_OF_THREADS{15};

void thFunc()
{
   std::cout << "--F1: Hi from thread function! no args\n";
}

void thFuncArg(char c)
{
   std::cout << "--F2: Hi from thread function! 1 arg = " << c << "\n";
}

class C
{
public:
   C(int i)
      : _i(i)
   {
   }
   void show1() const
   {
      std::cout << "--FC: Hi from thread function in object! no args: " << _i
                << " \n";
   }
   // Use call by value in thread function
   void show2(const std::string extra) const
   {
      std::cout << "--FC: Hi from thread function in object! extra = " << extra
                << "  " << _i << " \n";
   }

private:
   int _i;
};

int main()
{
   // Example using thread function with no arguments
   std::thread th1(&thFunc);
   std::cout << "A: Hi from main!\n";
   th1.join();

   // Example using thread function with 1 argument
   std::thread th2(&thFuncArg, 'X');
   std::cout << "B: Hi from main!\n";
   th2.join();

   // Example using thread function in an object
   // = raw thread or naked thread = thread is not in class/object
   // Active object RAII: create thread in ctor, stop and join thread in dtor
   C c(1234);
   std::thread th3a(&C::show1, &c);
   std::cout << "C: Hi from main!\n";
   th3a.join();
   std::thread th3b(&C::show2, &c, "HaHaHa");
   std::cout << "C: Hi from main!\n";
   th3b.join();

   // Example using lambda function
   std::thread th4([]() { std::cout << "--L1: Hi from thread!\n"; });
   std::cout << "D: Hi from main\n";
   th4.join();

   // Example using a vector of threads: workers
   std::vector<std::thread> workers;
   for (int i = 0; i < NUMBER_OF_THREADS; ++i) {
      workers.push_back(std::thread(
         [i]() { std::cout << "--L2: Hi from thread " << i + 1 << " !!\n"; }));
   }

   std::cout << "E: Hi from main!\n";
   // using for_each algorithm and iterators for joining
   std::for_each(begin(workers), end(workers),
                 [](std::thread &th) { th.join(); });

   return 0;
}
