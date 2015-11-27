#include "database.h"

bool Database::Insert(const Student & s)
{
    if(isFull()) return false;
    (*this) << s;
    return true;
}

const Database Database::Select(std::string name) const
{
    Database tmp;
    for(int i=0;i<num_record_;++i)
    {
        if(record_[i] == name)
        {
            tmp.Insert(record_[i]);
        }
    }

    return tmp;
}

void Database::Export(std::string filename) const
{
    std::ofstream fout(filename);
    if(fout)
    {
        fout << (*this);
    }
    fout.close();
}

bool Database::Import(std::string filename)
{
    std::ifstream fin(filename);
    if(fin)
    {
        Reset_();
        while(!fin.eof())
        {
            Student s;
            fin >> s;
            if(!(fin.eof()||isFull()))
                (*this) << s;
        }
        fin.close();
        return true;
    }
    else return false;

}

Database & Database::operator << (const Student & s)
{
    if(!isFull())
    {
        record_[num_record_++]=s;
        std::sort(record_, record_+num_record_);
    }
    return (*this);
}

std::ostream & operator << (std::ostream & os, const Database & db)
{
    for(int i=0;i<db.num_record_;++i)
    {
        os << db.record_[i] << std::endl;
    }

    return os;
}
