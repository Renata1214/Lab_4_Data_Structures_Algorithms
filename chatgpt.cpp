#include <iostream>
#include "myvectorcopy.h"
#include "mylistcopy.h"


using std::cout;



//modify function
template <class C> void modify(C & v)
{
   
   for ( auto & i : v )
   {
    
    i.name += '!';
   
   }
    
}


template <class C> void print(C & v)
{
cout << "print:";
for ( auto & i : v )
cout << ' ' << i.name;
cout << '\n';
}


int main()
{
Vector v;
for(int i=0; i<10; i++)
v.push_back(std::to_string(i));
modify(v);
print(v);
List s;
for(int i=0; i<10; i++)
s.push_front(std::to_string(i));
modify(s);
print(s);
}
