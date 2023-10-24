#include <string>

#include "Style.h"
#include "Reference.h"


using namespace std;

Style::~Style() {

}

string Harvard::styleCitation(Reference* r) {
  string citation("(");

  citation += r->getFirstAuthor();
  if (r->getAuthorCount() > 1) {
    citation += " et al.";
  }
  citation += (","+r->getYear() + ")");

  return citation;

}

string Harvard::styleBibliography(Reference* r) {
  string bibliography;

  bibliography += r->getAuthors()+",";
  bibliography += r->getTitle() + ",";
  bibliography += r->getData() + ",";
  bibliography += r->getYear() + ".";

  return bibliography;
}

string Weird::styleCitation(Reference* r) {
  string citation("([");

  citation += r->getYear() + "]";

  citation += r->getFirstAuthor();
  if (r->getAuthorCount() > 1) {
    citation += " et al.";
  }
  citation += ")";

  return citation;

}

string Weird::styleBibliography(Reference* r) {
  string bibliography;

  bibliography += "["+ r->getYear() + "] ";
  bibliography += r->getAuthors()+",";
  bibliography += r->getTitle() + ",";
  bibliography += r->getData() + ".";


  return bibliography;
}

