#include <chrono>
#include <iostream>
#include <memory>

using namespace std;

const long long NUMBER_OF_CREATIONS{10000000ll};

int main()
{
   cout << "--- Performance test: allocating deallocating memory" << endl;
   auto t1 = chrono::system_clock::now();
   for (long long i = 0ll; i < NUMBER_OF_CREATIONS; ++i) {
      // naked pointer
      int *pi{new int(123)}; // using heap memory
      delete pi;             // necessary to avoid memory leakage
   }
   chrono::duration<double> t2 = chrono::system_clock::now() - t1;
   cout << "naked       " << NUMBER_OF_CREATIONS << "x: " << t2.count()
        << " sec" << endl;

   t1 = chrono::system_clock::now();
   for (long long i = 0ll; i < NUMBER_OF_CREATIONS; ++i) {
      // class uses RAII
      unique_ptr<int> pi{new int(123)}; // using heap memory

      // pi++;  compile time error!

      // pi = new int(456);  compile time error

      // unique_ptr<int> pi2 {move(pi)};
      // ok: pi2 gets value of pi, pi becomes nulptr

      // object pi goes out of scope: dtor of unique_ptr<int> deallocates memory
   }
   t2 = chrono::system_clock::now() - t1;
   cout << "unique_ptr  " << NUMBER_OF_CREATIONS << "x: " << t2.count()
        << " sec" << endl;
   //---------------------------------------------------------------------------
   t1 = chrono::system_clock::now();
   for (long long i = 0ll; i < NUMBER_OF_CREATIONS; ++i) {
      shared_ptr<int> pi{new int(123)}; // using heap memory
      // pi++;  compile time error!
   }
   t2 = chrono::system_clock::now() - t1;
   cout << "shared_ptr  " << NUMBER_OF_CREATIONS << "x: " << t2.count()
        << " sec" << endl;
   //---------------------------------------------------------------------------
   t1 = chrono::system_clock::now();
   for (long long i = 0ll; i < NUMBER_OF_CREATIONS; ++i) {
      auto pi{make_shared<int>(123)}; // using heap memory
   }
   t2 = chrono::system_clock::now() - t1;
   cout << "make_shared " << NUMBER_OF_CREATIONS << "x: " << t2.count()
        << " sec" << endl;

   return 0;
}
