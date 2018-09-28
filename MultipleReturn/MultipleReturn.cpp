// C++17 structured bindings
// In Makefile use -std=c++1z

#include <iostream>
#include <set>
#include <tuple>

std::pair<int, double> createPair()
{
   return std::make_pair(1, 2.2);
}

std::tuple<int, double, std::string> createTuple()
{
   return std::make_tuple(1, 2.2, "Hello tuple");
}

int main()
{
   // Binding a pair
   auto [i1, d1] = createPair();
   std::cout << i1 << " " << d1 << std::endl;

   // Binding a tuple
   auto [i2, d2, str] = createTuple();
   std::cout << i2 << " " << d2 << " " << str << std::endl;

   // Binding an array
   int data[3] = {1, 2, 3};
   auto &[data0, data1, data2] = data;
   data1 += 20;
   std::cout << data0 << " " << data1 << " " << data2 << std::endl;
   std::cout << data[0] << " " << data[1] << " " << data[2] << std::endl;

   return 0;
}
