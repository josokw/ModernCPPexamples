#include <exception>
#include <future>
#include <iostream>
#include <vector>

// Thread function returns a result (int) or throws an excpetion.
int twice(int m)
{
   if (m == 10)
      throw std::runtime_error("I don't like 'm'");
   return 2 * m;
}

int main()
{
   std::vector<std::future<int>> futures;

   for (int i = 0; i < 100; ++i) {
      futures.push_back(std::async(std::launch::async, twice, i));
   }

   try {
      // Retrieve and print the value stored in the future.
      for (auto &ftr : futures) {
         std::cerr << " twice() result = " << ftr.get() << std::endl;
      }
   }
   catch (std::exception &e) {
      std::cerr << "ERROR: " << e.what() << std::endl;
   }

   // No need to join the created threads explicitly.
   // RAII: futures will call its dtor,
   // calling the dtor of every contained async object.
   return 0;
}
