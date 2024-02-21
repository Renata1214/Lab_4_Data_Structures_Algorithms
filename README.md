# Lab_4_Data_Structures_Algorithms

## Objectives
Objective: Gain practical experience on how iterators work and the effect of using them.
In the previous work, we have created containers Vector and List and tested the performance
of some operations. You must have noticed that “modify” operations take linear time O(n) for
Vector and quadratic time for List O(n2). The reason that the iteration over the List is worse
than linear time is the effect of the access operator “[]” being linear for each element. This is
not desirable, and we would like to fix it.

1. Implement an iterator class for List (let’s call it ListIterator), so that the user’s code for
“modify” function would run in O(n). To achieve this, the iterator’s operation “next” must
be of O(1) complexity. Create a new “modify_it” function that uses the iterator class. Verify
that this new function is indeed of O(n) and not of O(n2) algorithmic complexity.

3. Implement an iterator class VectorIterator for Vector, so that the same “modify_it” works
for Vector.

5. Modify Iterator classes so that they work with “range-based for loop”. 
