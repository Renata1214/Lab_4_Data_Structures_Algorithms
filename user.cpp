#include <iostream>
#include "myvector.h"
#include "mylist.h"
// #include "myvectorcopy.h"
// #include "mylistcopy.h"


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


//Output 
/*print: 0 1 2 3 4 5 6 7 8 9
print: 9 8 7 6 5 4 3 2 1 0*/


/*The reason that the iteration over the List is worse
than linear time is the effect of the access operator “[]” being linear for each element*/