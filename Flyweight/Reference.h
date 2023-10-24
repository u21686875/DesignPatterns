#ifndef REFERENCE_H
#define REFERENCE_H

#include <string>
#include <vector>



using namespace std;

// Flyweight
//  Intrinsic state - authors, title, publication etc
//  Extrinsic state - style, Harvard etc.

class Style;

class Reference {
  public:
    Reference();
    Reference(string, string, string);
    Reference(vector<string>, string, string);
    string citation(Style*);     // gets extrinsic state in and returns in correct form
    string bibliography(Style*); // gets extrinsic state in and returns in correct form
    string getFirstAuthor();
    string getAuthors();
    string getTitle();
    string getYear();
    int getAuthorCount();
    virtual string getData() = 0;
    virtual ~Reference();
  protected:
    vector<string> author;         // attributes - intrinsic state  
    string         title;
    string         year;
};

class Book : public Reference {
  public:
    Book(); 
    Book(string, string, string, string);
    Book(vector<string>, string, string, string);
    virtual string getData();
  protected:
    string publisher;
};

class Conference : public Reference {
  public:
    Conference();
    Conference(string, string, string, string);
    Conference(vector<string>, string, string, string);
    virtual string getData();
  protected:
    string conference;
};

class Journal : public Reference {
  public:
    Journal();
    Journal(string, string, string, string);
    Journal(vector<string>, string, string, string);
    virtual string getData();

  protected: 
    string journal;
};


#endif
