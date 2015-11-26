#include "database.h"

bool Database::Insert(const Student & s)
{
    record_[num_record_++]=s;
    std::sort(record_, record_+num_record_);
}

const Database Database::Select(std::string name) const
{
    Database tmp;
    for(int i=0;i<num_record_;++i)
    {
        if(record_[i].isSameName(name))
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
        Drop();
        while(!fin.eof())
        {
            std::string name;
            char gender='\0';
            int age=0;
            int scores[Student::MAX_SCORES]={0};
            fin >> name >> gender >> age;
            for(int i=0;i<Student::MAX_SCORES;++i)
            {
                fin >> scores[i];
            }
            if(!(fin.eof()||isFull()))
            {
                Student s(name,gender,age,scores);
                Insert(s);
            }
        }
        fin.close();
        return true;
    }
    else return false;

}

std::ostream & operator << (std::ostream & os, const Database & db)
{
    for(int i=0;i<db.num_record_;++i)
    {
        os << db.record_[i] << std::endl;
    }

    return os;
}
