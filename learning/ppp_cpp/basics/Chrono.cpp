#include "std_lib_facilities.h"
#include "Chrono.h"

namespace Chrono
{
    Month operator++(Month &m) // prefix increment operator
    {
        m = (m == Month::Dec) ? Month::Jan : Month(int(m) + 1); // “wrap around”
        return m;
    }

    ostream &operator<<(ostream &os, Month m)
    {
        return os << int(m);
    }

    const Date &default_date()
    {
        static Date dd{2001, Month::Jan, 1};
        return dd;
    }

    Date::Date()
        : y{default_date().year()},
          m{default_date().month()},
          d{default_date().day()}
    {
    }

    Date::Date(int yy, Month mm, int dd)
        : y{yy}, m{mm}, d{dd} // initialize data members
    {
        if (!is_valid())
            throw Invalid{}; // check for validity
    }

    bool Date::is_valid() // return true if date is valid
    {
        if (m < Month::Jan || m > Month::Dec)
            return false;
        else
            return true;
    }

    void Date::add_day(int dd)
    {
        d += dd; // more logics needed...
    }

    void Date::add_month(int n)
    {
        m = Month(int(m) + n); // more logics needed...
    }

    void Date::add_year(int n)
    {
        y += n;
    }

    bool Date::operator==(const Date &b)
    {
        return y == b.year() && m == b.month() && d == b.day();
    }

    bool Date::operator!=(const Date &b)
    {
        return !(*this == b);
    }

    ostream &operator<<(ostream &os, const Date &d)
    {
        return os << '(' << d.year()
                  << ',' << d.month()
                  << ',' << d.day() << ')';
    }

    istream &operator>>(istream &is, Date &dd)
    {
        int y, m, d;
        char ch1, ch2, ch3, ch4;
        is >> ch1 >> y >> ch2 >> m >> ch3 >> d >> ch4;
        if (!is)
            return is;
        if (ch1 != '(' || ch2 != ',' || ch3 != ',' || ch4 != ')')
        {                                // oops: format error
            is.clear(ios_base::failbit); // set the fail bit
            return is;
        }
        dd = Date(y, Month(m), d); // update dd
        return is;
    }

    enum class Day
    {
        sunday,
        monday,
        tuesday,
        wednesday,
        thursday,
        friday,
        saturday
    };

    Day day_of_week(const Date &d)
    {
        // . . .
        return Day::sunday;
    }
    Date next_Sunday(const Date &d)
    {
        // ...
        return Date();
    }
    Date next_weekday(const Date &d)
    {
        // . . .
        return Date();
    }
}

using namespace Chrono;

int main()
try
{
    Date dxy{2004, Month::Apr, 3};
    cout << dxy << '\n'; // see §9.8 for a declaration of <<

    Date dxy2;
    cout << dxy2 << '\n'; // see §9.8 for a declaration of <<

    vector<Date> birthdays(10); // ten elements with the default Date value,

    // for (Date x : birthdays)
    // {
    //     cout << x << endl;
    // }
    cout << (birthdays[0] == birthdays[1]) << endl;

    Date today{1978, Month::Jun, 25};

    Date tomorrow = today;
    tomorrow.add_day(1);

    cout << "today = " << today << endl;
    cout << "tommorrow = " << tomorrow << endl;

    // keep_window_open();
}
catch (Date::Invalid)
{
    error("invalid date"); // error() defined in §5.6.3
}