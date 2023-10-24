#include <iostream>
#include <string>

#include "FlyweightFactory.h"
#include "Style.h"
#include "Reference.h"

using namespace std;

int main() {

  FlyweightFactory* f = new FlyweightFactory();
  Reference* r;

  vector<string> authors;
  authors.push_back("Gamma, E.");
  authors.push_back("Helm, R.");
  authors.push_back("Johnson, R.");
  authors.push_back("Vlissides, J.");
  r = new Book(authors,"Design Patterns - Elements of Resuable Object Oriented Software","Addison Wesley","1995");
  f->addReference(0,r);

  authors.clear();
  
  authors.push_back("Rohse, S.");
  authors.push_back("Anderson, T.");
  r = new Journal(authors,"Design Patterns for Complex Learning","Journal of Learning Design","2006");
  f->addReference(100,r);


	Style* s = new Harvard();
	//Style* s = new Weird();

  cout << "Design patterns " << f->getFlyweight(0)->citation(s) << " have become an integral part of our programming curriculum.  Teaching patterns requires complex systems which in turn is requiring students to apply different learning techniques " << f->getFlyweight(100)->citation(s) << "." << endl;
  cout << endl;
  cout << "Bibliography" <<  endl;
  cout << f->getFlyweight(0)->bibliography(s) << endl;
  cout << f->getFlyweight(100)->bibliography(s) << endl;
    // cout << f->getFlyweight(1000)->bibliography(s) << endl; // This will segfault as is, should create the flyweight with a dialogue
  delete s;
  delete f;

  
  return 0;
}

