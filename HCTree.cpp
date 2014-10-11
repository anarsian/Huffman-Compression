/*
 * Name: Anish Narsian
 * PID: anarsian@ucsd.edu
 * Date: 11/18/2013
 * This is the HCTree.cpp file it has the 
 * encode and decode methods as well as a
 * recursive helper method
 */

#include "HCTree.hpp"
#include <iostream>
#include <stdlib.h>

using namespace std;

  HCTree::~HCTree() {
    deleteAll(root);
  }
  /*
   *This is the deconstructor
   *This prevents memory leaks
   */
  void HCTree::deleteAll(HCNode *node) {
    if(node == 0)
      return;

    deleteAll(node->c0);
    deleteAll(node->c1);

    delete node;
 }


/** Use the Huffman algorithm to build a Huffman coding trie.
  *  PRECONDITION: freqs is a vector of ints, such that freqs[i] is 
  *  the frequency of occurrence of byte i in the message.
  *  POSTCONDITION:  root points to the root of the trie,
  *  and leaves[i] points to the leaf node containing byte i.
  */
  void HCTree::build(const vector<int>& freqs) {
    //define pqueue
    std::priority_queue<HCNode*,std::vector<HCNode*>,HCNodePtrComp> pq;
    for(int i = 0; i<freqs.size(); i++) {
      

      if(freqs[i] != 0) {

        leaves[i] = new HCNode (freqs[i], (byte)i);        
	pq.push(leaves[i]);      //push onto pqueue
      }
    }

     while(pq.size() > 1) {
       HCNode* a = pq.top(); //take top value
       pq.pop(); //remove it from pqueue
       HCNode* b = pq.top(); //take top val again
       pq.pop();
       HCNode* head = new HCNode(a->count + b->count, a->symbol, a, b, 0); 
       b->p = head; //set parent equal to head
       a->p = head;
       pq.push(head); //push the head into pqueue
     }
     if(pq.size() == 1) {
       root = pq.top();
     }
  }


 /** Write to the given ofstream
   *  the sequence of bits (as ASCII) coding the given symbol.
   *  PRECONDITION: build() has been called, to create the coding
   *  tree, and initialize root pointer and leaves vector.
   *  THIS METHOD IS USEFUL FOR THE CHECKPOINT BUT SHOULD NOT 
   *  BE USED IN THE FINAL SUBMISSION.
   */
  void HCTree::encode(byte symbol, ofstream& out) {
    HCNode* cur = leaves[(int)symbol];
    helpMe(cur, out);


  }
  /*
   *recursive Helper method
   */
  void HCTree::helpMe(HCNode* curr, ofstream& out) { 

    if(curr == root) //Base case
      return;
    if(curr->p == root) { //Base case two
      if(curr->p->c0 == curr) {
      
      out << 0;  //write
   
      return;
      }
      else {
        
        out << 1; //write
        
	return;
      }
    }

    helpMe(curr->p,out); //recursive call
    if(curr->p->c0 == curr) {
      
      out << 0;
      
    }
    else {
      out << 1;
    }
  }
      
      
  /* Return the symbol coded in the next sequence of bits (represented as 
     *  ASCII text) from the ifstream.
     *  PRECONDITION: build() has been called, to create the coding
     *  tree, and initialize root pointer and leaves vector.
     *  THIS METHOD IS USEFUL FOR THE CHECKPOINT BUT SHOULD NOT BE USED
     *  IN THE FINAL SUBMISSION.
     */
  int HCTree::decode(ifstream& in) {
      HCNode* curr = root;
      while(curr->c0 != 0 ) {  
	
        char dCh = in.get();
	if(in.eof()) return -1;

	if(dCh == '0') //if reads 0
          curr = curr->c0;
	else  //if reads 1
          curr = curr->c1;
    
      }
      return (int) curr->symbol; //return
    }


/** Return symbol coded in the next sequence of bits from the stream.
     *  PRECONDITION: build() has been called, to create the coding
     *  tree, and initialize root pointer and leaves vector.
     */
  int HCTree::decode(BitInputStream& in) {
      HCNode* curr = root;
      while(curr->c0 != 0 ) {  
	
        int dCh = in.readBit(); //readbit

	if(dCh == 0)
          curr = curr->c0; //write 0
	else
          curr = curr->c1;
    
      }
      return (int) curr->symbol;
    }



    /** Write to the given BitOutputStream
     *  the sequence of bits coding the given symbol.
     *  PRECONDITION: build() has been called, to create the coding
     *  tree, and initialize root pointer and leaves vector.
     */



  void HCTree::encode(byte symbol, BitOutputStream& out) {
    HCNode* cur = leaves[(int)symbol]; //make new node
    helpMeNew(cur, out);
  }


  /*
   *recursive helper method
   */ 

  void HCTree::helpMeNew(HCNode* curr, BitOutputStream& out) { 
//return type vector<char>
    
    if(curr == root) 
      return;
    if(curr->p == root) {
      if(curr->p->c0 == curr) {
      out.writeBit(0);  //write 0
      return;
      }
      else {
	out.writeBit(1); //write 1
	return;
      }
    }

    helpMeNew(curr->p,out); //recursive call
    if(curr->p->c0 == curr) {
      out.writeBit(0); //write bit
    }
    else {
      out.writeBit(1);
    }
  }
        
    
    
 




    
