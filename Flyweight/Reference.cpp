#include <iostream>
#include <string>
#include <vector>

#include "Reference.h"
#include "Style.h"

using namespace std;

Reference::Reference(){
  title="";
  year = "";
}

Reference::Reference(string a, string t, string y) {
  author.push_back(a);
  title = t;
  year = y;
}
    
Reference::Reference(vector<string> a, string t, string y) {
  author = a;
  title = t;
  year = y;
}

string Reference::citation(Style* style) {
  return style->styleCitation(this);
}
    

string Reference::bibliography(Style* style) {
  return style->styleBibliography(this);
}

string Reference::getFirstAuthor() {
  return author[0];
}

string Reference::getAuthors() {
  vector<string>::iterator it = author.begin();
  string tmp;
  tmp += *it;
  it++;
  
  for (; it != author.end(); it++) {
    tmp += " and "+(*it);
  }
  return tmp;
}

string Reference::getTitle() {
  return title;
}

string Reference::getYear() {
  return year;
}

int Reference::getAuthorCount(){
  return author.size();
}

Reference::~Reference() {
    //Nothing to do
}



Book::Book() :Reference() {
  publisher = "";
}

Book::Book(string a, string t, string p, string y) : Reference(a,t,y) {
  publisher = p;
}
    
Book::Book(vector<string> a, string t, string p, string y) : Reference(a,t,y) {
  publisher = p;
}

string Book::getData(){
  return publisher;
}



Conference::Conference(){
  conference = "";
}

Conference::Conference(string a, string t, string c, string y) : Reference(a,t,y) {
  conference = c;
}
    
Conference::Conference(vector<string> a, string t, string c, string y) : Reference(a,t,y) {
  conference = c;
}

string Conference::getData(){
  return conference;
}





Journal::Journal(){
  journal = "";
}

Journal::Journal(string a, string t, string j, string y) : Reference(a,t,y) {
  journal = j;
}
    
Journal::Journal(vector<string> a, string t, string j, string y) : Reference(a,t,y) {
  journal = j;
}

string Journal::getData(){
  return journal;
}
