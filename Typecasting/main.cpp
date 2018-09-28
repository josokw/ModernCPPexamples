#include <iostream>
#include <string>
#include <vector>

// Abstract base class
class Base
{
public:
   virtual void fBase1() = 0;
   virtual void fBase2()
   {
      fBase1();
      fBase1();
      fBase1();
   }
};

class Derived1 : public Base
{
public:
   // Use base class interface
   virtual void fBase1() override
   {
      std::cerr << "Derived1::fBase1() " << std::endl;
   }
   // Inheritance used and extension
   void fDerived1() { std::cerr << "--- Derived1::fDerived1() " << std::endl; }
};

class Derived2 : public Base
{
public:
   // Use base class interface
   virtual void fBase1() override
   {
      std::cerr << "Derived2::fBase1() " << std::endl;
   }
   // Inheritance used and extension
   void fDerived2() { std::cerr << "--- Derived2::fDerived2() " << std::endl; }
};

// Avoid C typecasting, always use C++ typecasting.

int main()
{
   int x{2};
   double d{static_cast<double>(x)};

   x = static_cast<int>(d);
   std::cout << x << " " << d << std::endl;

   Derived1 derived1;
   Derived2 derived2;

   derived1.fBase2();
   derived2.fBase2();

   std::cout << "\n********** polymorficVector: " << std::endl;
   std::vector<Base *> polymorficVector{&derived1, &derived2};

   for (auto &p : polymorficVector) {
      p->fBase1();
      // p->fDerived1() ==> compiler error, not in de scope of Base
      //
      // Run time typecasting: dynamic_cast<T>
      // Converts pointers and references to classes up, down, and sideways
      // along the inheritance hierarchy.
      if (auto pd = dynamic_cast<Derived1 *>(p)) {
         pd->fDerived1();
      } else {
         std::cerr << "*** fDerived1() not available" << std::endl;
      }

      // Compile time cast: static_cast, compiler checks if cast is possible.
      // Correct?
      std::cerr << "######## ";
      static_cast<Derived1 *>(p)->fDerived1();
      std::cerr << std::endl;

      // Invalid static_cast ==> compiler error
      // static_cast<int*>(p)->fDerived1();
   }

   return 0;
}
