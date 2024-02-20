#include "std_lib_facilities.h"

// compute mean and median temperatures
int main()
{
    vector<string> words;
    cout << "Enter some words: \n";
    for (string temp; cin >> temp;) // read whitespace-separated words
        words.push_back(temp);      // put into vector
    cout << "Number of words: " << words.size() << '\n';

    sort(words.begin(), words.end()); // sort the words

    for (int i = 0; i < words.size(); ++i)
        if (i == 0 || words[i - 1] != words[i]) // is this a new word?
            cout << words[i] << "\n";
}