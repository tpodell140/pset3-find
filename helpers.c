/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    
    if (value > values[n - 1]) // Returns false if value is larger than largest value in array
    {
        return false;
    }
    
    int i=(n - 1) / 2;
    int count = 0;
   do
   {
      if (count > (n - 1)) // Prevents infinite searching <---- Is this necessary?
      {
          return false;
      }
      
      if (values[i] == value) // Actual searching loop
      {
          return true;
      }
      else if (values[i] > value)
      {
          
          i = i / 2;
          count ++;
          
      }
      else if (values[i] < value)
      {
           
          i = i + ((n- i) / 2);
          count ++;
      }
   } while (i>=0 && i<n);
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
   int count = 0; 
     do
    {
       count = 0; // Resets count variable for each trip through list.
        for (int i=0; i < n - 1; i++) // Iterates through array from beginning through the next-to-last variable
        {
            if (values[i] > values[i + 1]) // Compares to see if each position in the list is greater than next entry
            {
                int swap = values[i];
                values[i] = values[i + 1];
                values[i + 1] = swap;
                count ++;
            }
        }
    } while (count != 0);
    
    return;
}
