#include <iostream>
#include <string>
#include <map>
#include<vector>
#include <fstream>
using namespace std;

class CBHT {
private:
    map<int , vector<string>> buckets;
    int hashType;

    static int hashByLength(const string& w) {
        int l=static_cast<int>(w.length());
        return l;
    }

    static int hashBySum(const string& w) {
        int sum = 0;
        for (int i = 0; i < w.length(); i++) {
            sum+=w[i]-'a'+1;
        }
        return sum;
    }

    static int hashByFirst(const string& w) {
        if (w.empty()) return 0;
        return w[0];
    }

    static int hashByFirstTwo(const string& w) {
        if (w.empty()) return 0;
        if (w.length()==1) return w[0];
        int a=w[0]-'a'+1;
        int b=w[1]-'a'+1;
        return a*26 + b;
    }

    [[nodiscard]] int hash(const string& w) const {
        switch (hashType) {
            case 0: return hashByLength(w);
            case 1: return hashBySum(w);
            case 2: return hashByFirst(w);
            case 3: return hashByFirstTwo(w);
        }
        return 0;
    }
public:
    CBHT(int typehash) : hashType(typehash) {}

    void insert(const string& w) {
        int idx = hash(w);
        buckets[idx].push_back(w);
    }

    void print() {
        for (auto &[key, vec] : buckets) {
            cout << "Bucket " << key << " : ";
            for (auto &s : vec) {
                cout << s << " ";
            }
            cout << endl;
        }
    }

};

int main() {
    CBHT byLength(0) , bySum(1) , byFirst(2) , byFirstTwo(3);
   /* ifstream f("common1000.txt");
    string w;
    while (f>>w) {
        byLength.insert(w);
        bySum.insert(w);
        byFirst.insert(w);
        byFirstTwo.insert(w);
    }*/
    byLength.insert("alpha");
    byLength.insert("beta");
    byLength.insert("gamma");
    byLength.insert("delta");
    bySum.insert("alpha");
    bySum.insert("beta");
    bySum.insert("gamma");
    bySum.insert("delta");
    byFirst.insert("alpha");
    byFirst.insert("beta");
    byFirst.insert("gamma");
    byFirst.insert("delta");
    byFirstTwo.insert("alpha");
    byFirstTwo.insert("beta");
    byFirstTwo.insert("gamma");
    byFirstTwo.insert("delta");
    cout << "By Length: " << endl;
    byLength.print();
    cout << endl;
    cout << "By Sum: " << endl;
    bySum.print();
    cout << endl;
    cout << "By First: " << endl;
    byFirst.print();
    cout << endl;
    cout << "By First Two: " << endl;
    byFirstTwo.print();
    return 0;
}