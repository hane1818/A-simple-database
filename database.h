#ifndef DATABASE__
#define DATABASE__
#include "student.h"

class Database
{
friend std::ostream & operator << (std::ostream & os, const Database & db);

public:
    bool isFull(){ return (num_record_==MAX_RECORD_); }
    int size() { return num_record_; }
    void Drop() { num_record_=0; }
    void Insert(const Student & s);
    bool Import(const std::string filename);
    const Database Select(const std::string name) const;
    void Show() const;
    void Export(const std::string filename) const;
private:
    static constexpr int MAX_RECORD_=100;
    Student record_[MAX_RECORD_];
    int num_record_=1;
};

std::ostream & operator << (std::ostream & os, const Database & db);

#endif // DATABASE__
