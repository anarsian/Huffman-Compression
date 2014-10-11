/*
 * Name: Anish Narsian
 * Date: 11/18/2013
 * Email: anarsian@ucsd.edu
 *This is the bitoutputstream.cpp file,
 * it implements the methods defined in hpp
 * */
#include "BitOutputStream.hpp"


/** Send the buffer to the output, and clear */
     void BitOutputStream::flush() {
       out.put(buf); 
       out.flush(); 
       buf = nbits = 0; 
     }


/** Write the least significant bit of the argument to 
 * the bit buffer, and increment the bit buffer index. 
 * But flush the buffer first, if it is full. 
 */ 
void BitOutputStream::writeBit(int i) { 
// Is the bit buffer full? Then flush it 
// Increment the index 
  
  if(nbits == 8) {
    flush(); //flush
  }
  
    setBit(buf, i, nbits);
    nbits++;  
    
 
} 
   /*
    *Set bit helper method
    *@return: void
   *@params:char b, int bit, int n
   */

   void BitOutputStream::setBit(char & b, int bit, int n) {

	if(bit == 1)
         b = (b | (1 << n));
    else
        b = (b & ~(1 << n)); 
}






