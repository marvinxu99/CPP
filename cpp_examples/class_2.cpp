// 09-person2.cpp : model Person, Student and Employee as a class inheritance hierarchy
 
#include <iostream>
#include <string>
#include <string_view>
#include <vector>
using namespace std;
 
class Person 
{
public:
    struct Date;

    Person(Date dob) 
        : dob{ dob } {}

    Person(Date dob, string_view familyname, string_view firstname, bool familynamefirst = false)
        : dob{ dob }
        , familyname{ familyname }
        , firstname{ firstname }
        , familynamefirst{ familynamefirst } {}

    virtual ~Person() {}

    void setFamilyName(string_view familyname) 
    { 
        familyname = familyname; 
    }

    void setFirstName(string_view firstname) 
    { 
        firstname = firstname; 
    }
    
    void setFamilyNameFirst(bool familynamefirst) 
    { 
        familynamefirst = familynamefirst; 
    }
    
    string getName() 
    {
        if (familyname.empty() || firstname.empty()) {
            return familyname + firstname;
        }
        else if (familynamefirst) {
            return familyname + ' ' + firstname;
        }
        else {
            return firstname + ' ' + familyname;
        }
    }
    
    bool operator== (Person& rhs) 
    { 
        return (getName() == rhs.getName()) && (dob.year == rhs.dob.year) && (dob.month == rhs.dob.month) && (dob.day == rhs.dob.day); 
    }

    struct Date {
        unsigned short year{};
        unsigned char month{}, day{};
    };

protected:
    const Date dob;

private:
    string familyname, firstname;
    bool familynamefirst{};

public:
    // "default constructor"
    Person() = delete;                           //  Person p1{}, p2(), p3;
    // "copy constructor"
    Person(const Person&) = default;              //  Person p4{ p1 }, p5(p2);
    // "copy assignment operator"
    Person& operator= (const Person&) = delete;  //  Person p6; p6 = p1;
    // "move constructor"
    Person(Person&&) = delete;                   //  Person p7{ std::move(p2) };
    // "move assignment operator"
    Person& operator= (Person&&) = delete;       //  Person p8; p8 = std::move(p3);
    // "destructor"
    //~Person() = delete;                        //  Any Person object going out of scope

    /* Rule of five
    Because the presence of a user-defined (or = default or = delete declared) destructor, 
    copy-constructor, or copy-assignment operator prevents implicit definition of the move 
    constructor and the move assignment operator, any class for which move semantics are 
    desirable, has to declare all five special member functions: 
    */
}; 

//Alternatively, global operator== can be overloaded for Person, as demonstrated here:
//bool operator== (Person& lhs, Person& rhs) 
//{
//    return lhs.getName() == rhs.getName();
//}


class Student : public Person 
{
public:
    enum class Schooling;

    Student(const Person& person, 
            const vector<string>& attended_classes = {}, 
            Schooling school_type = Schooling::preschool)
        : Person{ person }
        , school_type{ school_type }
        , attended_classes{ attended_classes } {}

    const Date& getDOB() const 
    { 
        return dob; 
    }
    
    const vector<string>& getAttendedClasses() const 
    { 
        return attended_classes; 
    }

    enum class Schooling { preschool, elementary, juniorhigh, highschool, college, homeschool, other };

private:
    Schooling school_type;
    vector<string> attended_classes;
};
 
class Employee : public Person 
{
public:
    Employee(const Person& person, int employee_id, int salary = 0)
        : Person{ person }
        , employee_id{ employee_id }
        , salary{ salary } {}

    bool isBirthday(Date today) const 
    { 
        return dob.month == today.month && dob.day == today.day; 
    }
    
    void setSalary(int salary) { salary = salary; }
    
    auto getDetails() const 
    { 
        return pair{ employee_id, salary }; 
    }

private:
    const int employee_id;
    int salary;
};
 
int main() 
{
    Person genius{ { 1879, 3, 14 }, "Einstein", "Albert" };
    Student genius_student{ genius, { "math", "physics", "philosophy" }, Student::Schooling::other };
    Employee genius_employee{ genius, 1001, 15000 };
 
    cout << "Full name: " << genius_student.getName() << '\n';
 
    cout << "School classes: ";
    for (const auto& the_class : genius_student.getAttendedClasses()) {
        cout << the_class << ' ';
    }
    cout << '\n';
 
    auto [ id, salary ] = genius_employee.getDetails();
    cout << "ID: " << id << ", Salary: $" << salary << '\n';
    Person::Date next_bday{ 2020, 3, 14 };
    if (genius_employee.isBirthday(next_bday)) {
        cout << "Happy Birthday!\n";
    }

    Person person1 { { 2000, 1, 1 }, "John", "Smith" };
    auto person2{ person1 };
    if (person1 == person2) {
        cout << "Same!\n";
    }
    else {
        cout << "Different!\n";
    }
}