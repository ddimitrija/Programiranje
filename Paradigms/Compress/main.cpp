#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ifstream input("original.txt");
    ofstream output("encoded.txt");

    map<char, int> freq;
    char ch;
    string text = "";

    while (input.get(ch)) {
        text += ch;
        freq[ch]++;
    }
    input.close();

    vector<pair<char, int>> letters(freq.begin(), freq.end());

    sort(letters.begin(), letters.end(),
         [](pair<char, int> a, pair<char, int> b) {
             return a.second > b.second;
         });

    map<char, string> codes;
    string code = "10";

    for (int i = 0; i < letters.size(); i++) {
        codes[letters[i].first] = code;
        code = "1" + code;
    }

    for (char c : text) {
        output << codes[c];
    }
    output.close();

    cout << "Encoding complete. Check encoded.txt\n";

    return 0;
}