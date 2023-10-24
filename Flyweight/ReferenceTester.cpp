#include <iostream>
#include <string>

#include "Style.h"
#include "Reference.h"

using namespace std;

int main() {

  vector<string> authors;
  authors.push_back("Gamma, E.");
  authors.push_back("Helm, R.");
  authors.push_back("Johnson, R.");
  authors.push_back("Vlissides, J.");

  Reference* r = new Book(authors,"Design Patterns - Elements of Resuable Object Oriented Software","Addison Wesley","1995");
  Style* s = new Harvard();
  
  cout << "Citation = " <<  r->citation(s) << endl;
  cout << "Bibliography = " <<  r->bibliography(s) << endl;

  delete s;

  s = new Weird();

  cout << "Citation = " <<  r->citation(s) << endl;
  cout << "Bibliography = " <<  r->bibliography(s) << endl;

  delete s;
  delete r;

  
  return 0;
}

