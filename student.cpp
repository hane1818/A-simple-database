#include "student.h"

Student::Student(std::string name, char gender, int age, const int* scores)
{
    name_=name;
    if(name_.size() > MAX_NAME_LEN_)
    {
        std::cout << "Warning: length of student name is too long to save.\nIt will reset length to fit the field." << std::endl;
        name_.resize(MAX_NAME_LEN_);
    }
    gender_=gender;
    age_=age;
    for(int i=0;i<MAX_SCORES;++i)
        scores_[i]=scores[i];
}

bool Student::isSameName(std::string name) const
{
    if(name.size() > MAX_NAME_LEN_)
        name.resize(MAX_NAME_LEN_);
    return name==name_;
}

bool Student::operator == (std::string rhs) const
{
    return isSameName(rhs);
}

bool Student::operator < (const Student & rhs) const
{
    return name_ < rhs.name_;
}

std::ostream & operator << (std::ostream & os, const Student & s)
{
    os << s.name_ << " ";
    os << s.gender_ << " ";
    if(os == std::cout) os << "(" << s.age_ << ") ";
    else os << s.age_ << " ";
    for(int i=0;i<s.MAX_SCORES;++i)
        os << s.scores_[i] << " ";

    return os;
}

std::istream & operator >> (std::istream & is, Student & s)
{
    is >> s.name_ >> s.gender_ >> s.age_;
    for(int i=0;i<s.MAX_SCORES;++i)
        is >> s.scores_[i];

    return is;
}
