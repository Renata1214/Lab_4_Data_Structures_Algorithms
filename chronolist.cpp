#include <iostream>
#include <chrono>
#include <string>
#include "myvector.h"
#include "mylist.h"

using std::cout; 
using std:: string;

template <class C> void fill_back(C & v, int n)
{
    for (int i=0; i < n; i++)
    {
    v.push_back ("z"+ std::to_string(i));
    }
}


template <class C> void fill_front(C & v, int n)
{
    for (int i=0; i < n; i++)
    {
    v.push_front ("z"+ std::to_string (i));
    } 
}


template <class C> void remove_back(C & v)
{
    bool notempty= true;
    while (notempty){
        v.pop_back();
        if (v.size()==0){notempty=false;}
    }
}


template <class C> void remove_front(C & v)
{
    bool nempty= true;
    while (nempty){
        v.pop_front();
    if (v.size()==0){
        nempty=false;}
    }
}



template <class C> void modify(C & v)
{
   
   for ( auto & i : v )
   {
    
    i.name += '!';
   
   }
    
}


int main() {

    List trial1;
    int n=100000;

    // Measure execution time for function1
    auto start1 = std::chrono::steady_clock::now();
    modify(trial1);
    auto end1 = std::chrono::steady_clock::now();
    auto duration1 = std::chrono::duration_cast<std::chrono::microseconds>(end1 - start1);
    std::cout << "Execution time for fill back: " << duration1.count() << " microseconds" << std::endl;
    
    return 0;
}

