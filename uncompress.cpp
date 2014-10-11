/*
 * Name: Anish Narsian
 * PID: anarsian@ucsd.edu
 * Date: 11/18/2013
 * This is the uncompress.cpp file this intends
 * to uncompress a file using following;
 * 1. Build a huffman tree
 * 2. do the decoding
 * 3. store as characters in the uncompressed outfile
 */


#include<iostream>
#include<vector>
#include "HCTree.hpp"

using namespace std;

int main(int argc,char* argv[])
{

    ifstream file;
    ofstream of;
    file.open(argv[1], ios::binary );

    of.open(argv[2], ios::binary);

    vector<int> freq (256,0); //make vector


    for (int i=0; i<256;i++)
    {
        file >>freq[i]; 

    }

    HCTree *obj= new HCTree();

    obj->build(freq); //build it
    long long size ;
        file >> size;  //size for limits in decoding

  while( file.get()!='\n')  {} //skip extra chars
   BitInputStream in = BitInputStream(file);
   in.fill(); //fill the first set of 8 bits
  for(int i =1; i<size; i++)   
  {
       int num = (obj->decode(in)); //decode
       if(num != -1)
         of << (byte)num;

    }
    delete obj; //delete to prevenet leaks
    of.close(); //close
    file.close();

}

