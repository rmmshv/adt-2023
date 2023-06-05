// Implementation file for the Hash class
// Written By: A. Student
// Changed by: Rimma Esheva

#include <string>

#include "HashTable.h"

using namespace std;

/*~*~*~*
  A simple hash function 
 *~**/
int HashTable::_hash(string key) const
{
    int sum = 0;
    for (int i = 0; key[i]; i++)
        sum += key[i];
    return sum % hashSize;
};

/*~*~*~*
  hash insert - linear probe
*~**/

bool HashTable::insert(const Student &itemIn)
{
    if ( count == hashSize)
        return false;
   /* write your code here */
   int noCol = 0;
   int i = _hash(itemIn.getName());
   while (hashAry[i].getOccupied() == 1) {
       noCol++;
       i = (i+1) % hashSize;
   }
   hashAry[i].setItem(itemIn);
   hashAry[i].setOccupied(1);
   hashAry[i].setNoCollisions(noCol);
   count++;
   
   return true;
}

/*~*~*~*
   hash delete - linear probe
*~**/

bool HashTable::remove(Student &itemOut)
{
    return false;
}

/*~*~*~*
   hash search - linear probe
   search for key
   if found: 
      - copy data to itemOut
      - copy number of collisions for this key to noCol
      - returns true
   if not found, returns false
*~**/
bool HashTable::search(Student &itemOut, int &noCol, string key)
{
   int i = _hash(key);
   int start = i;

   do {
      if (hashAry[i].getItem().getName() == key) {
         itemOut = hashAry[i].getItem();
         noCol = hashAry[i].getNoCollisions();

         return true;
      }
      i = (i+1) % hashSize;
   
   } while(i != start);

     
    return false;
}
