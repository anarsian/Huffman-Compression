/*
 * Name: Anish Narsian
 * PID: anarsian@ucsd.edu
 * Date: 11/18/2013
 * This is the compress.cpp file this intends
 * to compress a file using following;
 * 1. Build a huffman tree
 * 2. do the encoding
 * 3. store as characters in the compressed outfile
 */
#include "HCTree.hpp"
#include <vector>
#include <iostream>

int main(int argc, char *argv[]) {
  //Check no. of args
  if(argc != 3) {
    std::cerr<"Enter correct no. of args";
    return -1;
  }


  ifstream file;
  vector<int> freqs(256, 0);
  long long numFreqs = 0;
  file.open(argv[1], ios::binary); //open file
  byte readCh;
        ofstream of;

  if(file.is_open()) {

    while(!file.eof()) {
      readCh = file.get();
      if(readCh<0) continue; //Check for case with useless chars
      if(readCh == -1) break; //Check for case with end
      freqs[(int)readCh]++;
      numFreqs++;  //to be stored in header
       
      }
    }
  
  else {
    std::cerr<< "Error opening file";
    return -1;
  }
   file.close();
    
    //Now build the tree
    HCTree *a = new HCTree();
    a->build(freqs);
 
    of.open(argv[2],ios::binary);
    //Printing out file header:
  BitOutputStream out =  BitOutputStream( of); 
    for(int i = 0; i<freqs.size();i++) {
      of << " " << freqs[i];
    }
    of <<" " << numFreqs;
    of << "\n";
    file.open(argv[1],ios::binary); //open

    while(!file.eof()) {
      readCh = file.get();
      if(readCh<0) continue; //check for cases
      if(readCh == -1) break;
      a->encode(readCh, out);
    }
        out.flush(); //flush for left over vals
    delete a;
    of.close();
    file.close();
}

