#ifndef FLYWEIGHTFACTORY_H
#define FLYWEIGHTFACTORY_H

#include <vector>
#include <map>
#include "Reference.h"

class FlyweightFactory {
  public:
    Reference* getFlyweight(int);
    void addReference(int,Reference*);
    void citationList();
    void bibliographyList();
    virtual ~FlyweightFactory();
  private:
    map<int, Reference*> referenceDatabase;
};

#endif

