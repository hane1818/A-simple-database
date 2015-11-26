#ifndef STUDENT__
#define STUDENT__
#include <iostream>
#include <fstream>
#include <string>

class Student
{
friend std::ostream & operator << (std::ostream & os, const Student & s);
public:
    static constexpr int MAX_SCORES=3;
    Student() = default;
    Student(std::string name, char gender, int age, const int* scores);
    bool isSameName(std::string name) const;
    bool operator == (std::string rhs) const;
    bool operator < (const Student & rhs) const;
    explicit operator std::string() const { return name_; }
private:
    static constexpr unsigned int MAX_NAME_LEN_=30;
    std::string name_;
    char gender_='\0';
    int age_=0;
    int scores_[MAX_SCORES]={0};
};

std::ostream & operator << (std::ostream & os, const Student & s);

#endif // STUDENT__
