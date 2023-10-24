#ifndef STYLE_H
#define STYLE_H

#include <string>
#include "Reference.h"


using namespace std;

class Style {
  public:
    virtual string styleCitation(Reference*) = 0;
    virtual string styleBibliography(Reference*) = 0;
    virtual ~Style();
};

class Harvard : public Style {
  public:
    virtual string styleCitation(Reference*);
    virtual string styleBibliography(Reference*);
};

class Weird : public Style {
  public:
    virtual string styleCitation(Reference*);
    virtual string styleBibliography(Reference*);
};


#endif


