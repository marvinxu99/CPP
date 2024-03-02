#include "std_lib_facilities.h"

/*
File streams:  ifstream, ofstream
    ios_base::app     Append
    ios_base::ate     "at end" - open and see to end
    ios_base::binary
    ios_base::in
    ios_base::out
    ios_base::trunc    truncate file to 0 length

    ofstream of1 {name1}; // defaults to ios_base::out
    ifstream if1 {name2}; // defaults to ios_base::in
    ofstream ofs {name, ios_base::app}; // ofstreams by default include io_base::out
    fstream fs {"myfile", ios_base::in|ios_base::out}; // both in and out

    if an operating system cannot honor a request to open a file in a certain way,
    the result will be a stream that is not in the good() state:

        if (!fs) // oops: we couldn’t open that file that way
*/

int main()
try
{

    // Create a binary file
    vector<int> vi{12, 34, 56, 78, 123456};
    for (int i : vi)
    {
        cout << i << "; ";
    }
    cout << endl;

    string oname{"fs_test_1.bin"};
    ofstream ofs{oname, ios_base::binary}; // note: stream mode
    // binary tells the stream not to try anything clever with the bytes
    if (!ofs)
        error("can't open output file ", oname);
    // write to binary file:
    for (int x : vi)
        ofs.write(as_bytes(x), sizeof(int)); // note: writing bytes
    ofs.close();

    // open an istream for binary input from a file:
    // cout << "Please enter input file name\n";
    // string iname;
    // cin >> iname;
    string iname{"fs_test_1.bin"};
    ifstream ifs{iname, ios_base::binary}; // note: stream mode
    // binary tells the stream not to try anything clever with the bytes
    if (!ifs)
        error("can't open input file ", iname);

    // open an ostream for binary output to a file:
    // cout << "Please enter output file name\n";
    // string oname;
    // cin >> oname;
    string oname2{"fs_test_2.bin"};
    ofstream ofs2{oname2, ios_base::binary}; // note: stream mode
    // binary tells the stream not to try anything clever with the bytes
    if (!ofs2)
        error("can't open output file ", oname2);

    vector<int> v;
    // read from binary file:
    for (int x; ifs.read(as_bytes(x), sizeof(int));) // note: reading bytes
        v.push_back(x);

    // . . . do something with v . . .
    for (int i = 0; i < v.size(); i++)
    {
        v[i] *= 2;
    }
    cout << "Before writing to a bin file" << endl;
    for (int i : v)
    {
        cout << i << "; ";
    }
    cout << endl;

    cout << "Using for_each..." << endl;
    for_each(v.begin(), v.end(), [](int x)
             { cout << x << " "; });
    cout << endl;

    // write to binary file:
    for (int x : v)
        ofs2.write(as_bytes(x), sizeof(int)); // note: writing bytes
    return 0;
}
catch (...)
{
    cout << "Error caught.";
}