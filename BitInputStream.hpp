/*
 * Name: Anish Narsian
 * Date: 11/18/2013
 * Email: anarsian@ucsd.edu
 * This is the bitinputstream.hpp file
 */
#include <iostream> 
class BitInputStream  {
  private: 
    char buf; // one byte buffer of bits 
    int nbits; // how many bits have been read from buf 


    std::istream & in; 
    /*
     *helper method to getBit
     *@return: int
     */  
    int getBit(char b, int n) ;
  public: 
  // the input stream to use 
  /** Initialize a BitInputStream that will use 
    * the given istream for input. 
    */ 
     BitInputStream(std::istream & is) : in(is) { 
	buf = 0; // clear buffer 
        nbits = 0; // initialize bit index 
     }

     /*
      *This readsbits
      *@return: int
      */
     int readBit();
    
     void fill();

  };
