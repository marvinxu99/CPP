#include "std_lib_facilities.h"
#include "punc_stream.h"

bool Punct_stream::is_whitespace(char c)
{
    return white.contains(c);
}

Punct_stream &Punct_stream::operator>>(string &s)
{
    while (!(buffer >> s))
    { // try to read from buffer
        if (buffer.bad() || !source.good())
            return *this;

        buffer.clear();

        string line;
        getline(source, line); // get a line from source
        // do character replacement as needed:
        for (char &ch : line)
            if (is_whitespace(ch))
                ch = ' '; // to space
            else if (!sensitive)
                ch = tolower(ch); // to lower case

        buffer.str(line); // put string into stream
    }

    return *this;
}