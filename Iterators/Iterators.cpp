// C++11 example ---------------------------------------------------------------

#include <array>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
   array<int, 4> arr = {10, 20, 30, 40};
   // C++03: array<int, 4>::iterator iter = begin(arr);
   auto iter1 = begin(arr);
   // iterator: pointer semantics, operators * ++ --
   cout << *iter1 << endl;
   ++iter1;
   cout << *iter1 << endl;

   iter1 = begin(arr);
   while (iter1 < end(arr)) {
      cout << *iter1 << " ";
      ++iter1;
   }
   cout << endl;
   // C++11 range-based for loop
   for (auto e : arr) {
      cout << e << " ";
   }
   cout << endl << endl;

   vector<int> vec = {100, 200, 300, 400, 500};
   // C++03: vector<int>::iterator iter2 = begin(vec);
   auto iter2 = begin(vec);
   // iterator: pointer semantics, operators * ++ --
   cout << *iter2 << endl;
   ++iter2;
   cout << *iter2 << endl;

   iter2 = begin(vec);
   while (iter2 < end(vec)) {
      cout << *iter2 << " ";
      ++iter2;
   }
   cout << endl;
   // C++11 range-based for loop
   for (auto e : vec) {
      cout << e << " ";
   }
   cout << endl;

   int idx{0};
   for (auto e : vec) {
      cout << idx << ": " << e << "   ";
      ++idx;
   }
   cout << endl;

   return 0;
}
