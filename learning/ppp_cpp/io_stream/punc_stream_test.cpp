#include "std_lib_facilities.h"
#include "punc_stream.h"

int main()
{
    Punct_stream ps{cin};     // ps reads from cin
    ps.whitespace(";:.");     // semicolon, colon, and dot are also whitespace
    ps.case_sensitive(false); // not case-sensitive

    return 0;
}