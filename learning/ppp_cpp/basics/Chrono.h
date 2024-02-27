namespace Chrono
{
    enum class Month
    {
        Jan = 1,
        Feb,
        Mar,
        Apr,
        May,
        Jun,
        Jul,
        Aug,
        Sep,
        Oct,
        Nov,
        Dec
    };

    // simple Date (use Month type)
    class Date
    {
    public:
        class Invalid // to be used as exception
        {
        };

        Date();                      // Default constructor
        Date(int y, Month m, int d); // check for valid date and initialize
        Date(int y);

        // nonmodifying operations:
        int year() const { return y; }
        Month month() const { return m; }
        int day() const { return d; }

        // modifying operations:
        void add_day(int n);
        void add_month(int n);
        void add_year(int n);

        bool operator==(const Date &b);
        bool operator!=(const Date &b);

    private:
        int y; // year
        Month m;
        int d; // day

        bool is_valid(); // return true if date is valid
    };

    const Date &default_date();

}
