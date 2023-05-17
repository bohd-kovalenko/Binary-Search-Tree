#include <string>
#include <ostream>

#ifndef LAB2_4_DATA_H
#define LAB2_4_DATA_H

#endif //LAB2_4_DATA_H
using namespace std;

struct Data {
    string name;
    double GPA;
    int studyingDesireRate;
    int writtenOfWorksCount;

    virtual ~Data();

    Data();

    bool operator==(const Data &rhs) const;

    bool operator!=(const Data &rhs) const;

    bool operator<(const Data &rhs) const;

    bool operator>(const Data &rhs) const;

    bool operator<=(const Data &rhs) const;

    bool operator>=(const Data &rhs) const;

    friend ostream &operator<<(ostream &os, const Data &data);
};