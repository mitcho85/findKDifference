#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

// input:  {1, 7, 5, 9, 2, 12, 3}
// output: {(1,3),(3,5),(5,7),(7,9)}

vector<int> a;

int absoluteValue(int x, int y){
    return (x-y)< 0 ? y-x : x-y;
}




// find pair difference of size k
void pairDiff(int k){
    for(int i = 0; i < a.size(); i++){
        for (int j = i+1; j < a.size(); j++){
            if (absoluteValue(a[i], a[j]) == k){
                cout << "(" << a[i] << "," << a[j] << ")";
            }
        }
    }
    cout << endl;
}


struct Biggger
{
    template<class T>
    bool operator()(T const &a, T const &b) const { return a < b; }
};

int main(){
    a = {1, 7, 5, 9, 2, 12, 3};
    Bigger st = new Bigger();
    std::sort(a.begin(), a.end(), st);
    pairDiff(2);
}