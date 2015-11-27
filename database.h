#ifndef DATABASE__
#define DATABASE__
#include "student.h"
#include <iostream>
#include <fstream>
#include <algorithm>

class Database
{
friend std::ostream & operator << (std::ostream & os, const Database & db);

public:
    bool isFull() const { return (num_record_==MAX_RECORD_); }
    size_t size() const { return num_record_; }
    void Show() const { std::cout << (*this); }
    bool Insert(const Student & s);
    bool Import(std::string filename);
    const Database Select(std::string name) const;
    void Export(std::string filename) const;
    Database & operator << (const Student & s);
private:
    static constexpr std::size_t MAX_RECORD_=100;
    Student record_[MAX_RECORD_];
    std::size_t num_record_=0;
    void Reset_() { num_record_=0; }
};

std::ostream & operator << (std::ostream & os, const Database & db);

#endif // DATABASE__
