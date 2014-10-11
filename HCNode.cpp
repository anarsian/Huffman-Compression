/*
 * Name: Anish Narsian
 * email id: anarsian@ucsd.edu
 * Date: 11/18/2013
 * This is the HCNode.cpp file, 
 * it implements the methods from hpp
 * */
#include "HCNode.hpp"

/*
 * This overloads the > operator
 * */

bool HCNode::operator<(const HCNode &other) {
 /* if(this->count == other.count)
    return this->count<other.count;
  else if(this->count < other.count)
    return this->count > other.count;*/
  if(count != other.count) return count >other.count;

  return symbol > other.symbol;
};

/*bool comp(HCNode* one, HCNode* other) {
  return one < other;
}*/
