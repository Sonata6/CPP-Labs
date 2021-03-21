#include "PersonalFileIO.h"
#include "Personal.h"
using namespace std;

template<typename T>
ostream& operator<< (ostream& out, const T& personal)
{
    out << personal.getSalary() << ", " << personal.getWorkingHours() << ", " << personal.pointgetWorkExp() << personal.getPosition() << personal.getPersonInf();
    return out;
}

template<typename T>
void save(T person)
{
    std::ofstream fout;
    fout.open("Personal.txt", std::ofstream::app);
    if (!fout.is_open())
    {
        //cout << "Error with file open" << endl;
    }
    else
    {
        //cout << "File is open!" << endl;
        fout << person;
    }
    fout.close();
}