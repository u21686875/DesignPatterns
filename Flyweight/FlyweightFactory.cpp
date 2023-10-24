#include <iostream>
#include <map>

#include "FlyweightFactory.h"
#include "Reference.h"

using namespace std;

Reference* FlyweightFactory::getFlyweight(int id){
  map<int,Reference*>::iterator it;

  it = referenceDatabase.find(id);
  if (it != referenceDatabase.end()) {
    return it->second;
  } else {
    cout<<"Must create a flyweight with a dialogue"<<endl;
    return 0;
  }
}

void FlyweightFactory::addReference(int i, Reference* r){
  referenceDatabase.insert(pair<int,Reference*>(i,r));
}

void FlyweightFactory::citationList() {
}

void FlyweightFactory::bibliographyList(){
}

FlyweightFactory::~FlyweightFactory(){
  // Must release Flyweights (References)
  map<int,Reference*>::iterator it;
  for (it = referenceDatabase.begin(); it != referenceDatabase.end(); ++it) {
    delete (*it).second;
  }
}

