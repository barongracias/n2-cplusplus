#include <string>
#include <iostream>
#include <memory>
using namespace std;

class Researcher {
protected:
    string name;
    string title;

public:
    Researcher(const string& name, const string& title): name(name), title(title) {}

    virtual ~Researcher() = default;

    string getName() const {return name;}
    string getTitle() const {return title;}

    virtual void printInfo() const = 0;
};

