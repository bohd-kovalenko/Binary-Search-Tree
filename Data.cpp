#include "Data.h"

Data::Data() {
    string names[] = {"Alice", "Bob", "Charlie", "Dave", "Emma", "Frank", "Grace", "Henry", "Isabella", "Jack", "Katie",
                      "Luke", "Megan", "Nate", "Olivia", "Peter", "Quinn", "Rachel", "Sarah", "Tom", "Ursula", "Victor",
                      "Wendy", "Xander", "Yvonne", "Zack"};
    name = names[rand() % 26];
    GPA = rand() % 1000;
    studyingDesireRate = rand() % 11;
    writtenOfWorksCount = rand() % 11;
}

bool Data::operator==(const Data &rhs) const {
    return GPA == rhs.GPA &&
           studyingDesireRate == rhs.studyingDesireRate;
}

bool Data::operator!=(const Data &rhs) const {
    return !(rhs == *this);
}

bool Data::operator<(const Data &rhs) const {
    if (GPA < rhs.GPA)
        return true;
    if (rhs.GPA < GPA)
        return false;
    return studyingDesireRate < rhs.studyingDesireRate;
}

bool Data::operator>(const Data &rhs) const {
    return rhs < *this;
}

bool Data::operator<=(const Data &rhs) const {
    return !(rhs < *this);
}

bool Data::operator>=(const Data &rhs) const {
    return !(*this < rhs);
}

Data::~Data() {

}

ostream &operator<<(ostream &os, const Data &data) {
    os << "name: " << data.name << " GPA: " << data.GPA << " studyingDesireRate: " << data.studyingDesireRate
       << " writtenOfWorksCount: " << data.writtenOfWorksCount;
    return os;
}
