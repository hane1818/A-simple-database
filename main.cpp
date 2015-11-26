#include <iostream>
#include <cstdlib>
#include <string>
#include "database.h"

using namespace std;

int main()
{
    Database db;
    while(true)
    {
        cout << "A simple database program\n" << endl;
        cout << "(1) Add a record" << endl;
        cout << "(2) Show all record" << endl;
        cout << "(3) Search student(s) by name" << endl;
        cout << "(4) Output records to a text file" << endl;
        cout << "(5) Input records from a text file" << endl;
        cout << "(6) Exit the program" << endl << endl;
        cout << "Please select a function...>";
        int opt=0;
        cin >> opt;
        cin.get();
        system("cls");
        switch(opt)
        {
        case 1: //add record
            {
                if(!db.isFull())
                {
                    cout << "Please input the required values:" << endl << endl;
                    string name;
                    cout << "Name (no space): ";
                    cin >> name;
                    char gender;
                    cout << "Gender(M/F): ";
                    cin >> gender;
                    int age;
                    cout << "Age: ";
                    cin >> age;
                    int scores[Student::MAX_SCORES]={0};
                    cout << Student::MAX_SCORES << " Scores: ";
                    for(int i=0;i<Student::MAX_SCORES;++i)
                        cin >> scores[i];
                    Student s(name, gender, age, scores);
                    db.Insert(s);
                    cout << endl << "Successfully add a record!" << endl << endl;
                    cin.get();
                }
                else
                    cout << "Database is full." << endl;
                break;
            }
        case 2: //show record
            {
                cout << "There are " << db.size() << " records." << endl << endl;
                cout << db << endl;
                break;
            }
        case 3: //search name
            {
                string name;
                cout << "Please input the name of the student...>";
                cin >> name;
                cin.get();
                cout << endl;
                cout << "If the length of name is too long, it may ignore part sequence to fit the name field when searching.";
                Database result = db.Select(name);
                cout << "There is/are " << result.size() << " \"" << name << "\":" << endl << endl;
                cout << result << endl;
                break;
            }
        case 4: //output file
            {
                cout << "Out all records to a text file." << endl << endl;
                cout << "Note that the original data in the file will be lost after writing to the file. Are you sure that you want to continue? (Y/N)...>";
                char ch;
                cin >> ch;
                cin.get();
                if(ch=='Y'||ch=='y')
                {
                    cout << "Please input the name of the file...>";
                    string filename;
                    cin >> filename;
                    db.Export(filename);
                    cout << endl << "Successfully export data to \"" << filename << "\"." << endl << endl;
                }
                else
                    cout << endl << "Failed to export data." << endl << endl;
                break;
            }
        case 5: //input file
            {
                cout << "Read in records from a text file." << endl << endl;
                cout << "Note that current data in the program will be lost after reading. Are you sure that you want to continue? (Y/N)...>";
                char ch;
                cin >> ch;
                cin.get();
                if(ch=='Y'||ch=='y')
                {
                    cout << "Please input the name of the file...>";
                    string filename;
                    cin >> filename;
                    cout << endl;
                    if(db.Import(filename))
                        cout << "Successfully import data from \"";
                    else
                        cout << "Failed to open \"";
                    cout << filename << "\"." << endl << endl;
                }
                else
                    cout << endl << "Failed to import data." << endl << endl;
                break;
            }
        case 6:
            cout << "Bye bye." << endl;
            return 0;
        default:
            cout << "Invalid choice." << endl;
            break;
        }
        cout << endl << "Press ENTER to continue.";
        cin.get();
        system("cls");
    }

    return 0;
}
