#include <functional>
#include <iostream>
#include <map>
#include <string>
#include <utility>

using namespace std;

using commandfunction = std::function<int()>;

int start()
{
   cout << "** exec start **" << endl;
   return 1000;
}

int stop()
{
   cout << "** exec stop **" << endl;
   return 2000;
}

int repeat()
{
   cout << "** exec repeat **" << endl;
   return 3000;
}

class Something // A functor is class which defines the operator().
                // That lets you create objects which "look like" a function.
{
public:
   Something(int smt)
      : smt_{smt}
   {
   }
   int operator()()
   {
      cout << "** exec something **" << endl;
      return smt_;
   }

private:
   int smt_;
};

int main()
{
   pair<string, int> si{"one", 1};
   cout << si.first << "=" << si.second << endl;

   int i{100};
   pair<int, int *> ipi{i, &i};
   cout << ipi.first << "=" << ipi.second << endl;

   pair<string, commandfunction> cf{"start", start};
   cout << cf.first << " " << cf.second() << endl;

   map<string, commandfunction> cfs{{"start", start}, {"stop", stop}};
   cfs["start"]();
   cfs["stop"]();

   cfs["repeat"] = repeat;
   cfs["repeat"]();

   Something smt{4000};
   cfs["something"] = smt;

   // Command processor
   string input;
   const string exitCommand("exit");
   cout << endl;
   do {
      cout << "\n+++ Enter command: ";
      cin >> input;
      if (input != exitCommand) {
         auto iter_command = cfs.find(input);
         if (iter_command != end(cfs)) {
            auto fnc = (*iter_command).second;
            int result = fnc();
            cout << "   result = " << result << endl;
         } else {
            cout << "+++ ERROR unkown command '" << input << "'";
         }
      }
   } while (input != exitCommand);
   cout << endl;

   return 0;
}
