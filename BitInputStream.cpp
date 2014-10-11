/*
 * Name: Anish Narsian
 * Date: 11/18/2013
 * This is the bitoutputstream.cpp file
 * It does bitwise operations
 */

#include "BitInputStream.hpp"
 
//using std namespace;

/** Fill the buffer from the input */ 
     void BitInputStream::fill() { 
        buf = in.get(); 
        nbits = 0; 
     }

 
     int BitInputStream::readBit() { 
	if(nbits == 8) {
          fill();
	}
	
	  int a=  getBit(buf, nbits);
          nbits++;
          //std::cout<< a << " buf: " << buf << std::endl;
          return a;
          
        
     }
    /*
     *Helper method to get bits
     *@return: int
     *@param: char b, int a
     */
     int BitInputStream::getBit(char b ,int n) {
        if(b & (1 <<n))
          return 1;
        else
          return 0;
    }
