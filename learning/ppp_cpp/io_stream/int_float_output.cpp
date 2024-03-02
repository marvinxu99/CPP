#include "std_lib_facilities.h"

int main()
{
     cout << 1234 << "\t(decimal)\n"
          << hex << 1234 << "\t(hexadecimal)\n"
          << oct << 1234 << "\t(octal)\n"
          << dec << 1234 << "\t(decimal)\n";

     cout << 1234 << '\t' << hex << 1234 << '\t' << oct << 1234 << '\n';

     // input format
     // int a;
     // int b;
     // int c;
     // int d;
     // cin >> a >> hex >> b >> oct >> c >> d;
     // cout << a << '\t' << b << '\t' << c << '\t' << d << '\n';

     // Floating-point output
     cout << 1234.56789 << "\t\t(defaultfloat)\n" // \t\t to line up columns
          << fixed << 1234.56789 << "\t(fixed)\n"
          << scientific << 1234.56789 << "\t(scientific)\n";

     cout << 1234.56789 << '\t'
          << fixed << 1234.56789 << '\t'
          << scientific << 1234.56789 << '\n';
     cout << 1234.56789 << '\n';                // floating format “sticks”
     cout << defaultfloat << 1234.56789 << '\t' // the default format for
                                                // floating-point output
          << fixed << 1234.56789 << '\t'
          << scientific << 1234.56789 << '\n';

     // By default, a floating-point value is printed using six total digits using the defaultfloat format

     cout << 1234.56789 << '\t'
          << fixed << 1234.56789 << '\t'
          << scientific << 1234.56789 << '\n';
     cout << defaultfloat << setprecision(5)
          << 1234.56789 << '\t'
          << fixed << 1234.56789 << '\t'
          << scientific << 1234.56789 << '\n';
     cout << defaultfloat << setprecision(8)
          << 1234.56789 << '\t'
          << fixed << 1234.56789 << '\t'
          << scientific << 1234.56789 << '\n';

     // Fields
     cout << 123456                          // no field used
          << '|' << setw(4) << 123456 << '|' // 123456 doesn’t fit in a 4-char field
          << setw(8) << 123456 << '|'        // set field width to 8
          << 123456 << "|\n";                // field sizes don’t stick

     cout << 12345 << '|' << setw(4) << 12345 << '|'
          << setw(8) << 12345 << '|' << 12345 << "|\n";
     cout << 1234.5 << '|' << setw(4) << 1234.5 << '|'
          << setw(8) << 1234.5 << '|' << 1234.5 << "|\n";
     cout << "asdfg" << '|' << setw(4) << "asdfg" << '|'
          << setw(8) << "asdfg" << '|' << "asdfg"
          << "|\n";
}