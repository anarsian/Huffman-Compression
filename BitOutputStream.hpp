/*
 * This is the bitoutputstream.hpp file,
 * it defines the class and the methods to
 * implement in the cpp file
 * */
#include <iostream> 
class BitOutputStream { 
  private: 
    char buf;   // one byte buffer of bits
    int nbits;   // how many bits have been written to buf 
 

    std::ostream & out; // reference to the output stream to use 
   /*
    *Helper method to setBit
    *@return: void
    *@params: char b, int bit, int n
    */
    void setBit(char & b, int bit, int n);
  public: 
/** Initialize a BitOutputStream that will use 
* the given ostream for output. 
*/ 
     BitOutputStream(std::ostream & os) : out(os), buf(0), nbits(0) { 
 // clear buffer and bit counter 
     }
     /*
      *This is the method that writes the bit
      *@return void
      *@param: int i
      */
     void writeBit(int i);
      /*
       *This is the flush method
       *it sets buf to 0 and does some otherstuff
      */
     void flush();
};
