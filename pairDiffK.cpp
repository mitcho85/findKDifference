#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

// input:  {1, 7, 5, 9, 2, 12, 3}
// output: {(1,3),(3,5),(5,7),(7,9)}

vector<int> a;
unordered_map<int, int>map;
int absoluteValue(int x, int y){
    return (x-y)< 0 ? y-x : x-y;
}




// find pair difference of size k
// assuming the array is sorted
// brute force solution O(n^2)
void pairDiff(int k){
    for(int i = 0; i < a.size(); i++){
        for (int j = i+1; j < a.size(); j++){
            int difference = absoluteValue(a[i], a[j]);
            if (difference == k){
                cout << "(" << a[i] << "," << a[j] << ")";
            } else if (difference > k) break;
        }
    }
    cout << endl;
}


// hash map solution O(n)
int pairDiffMap(int k){
    int counter = 0;    
    for(int i = 0; i < a.size(); ++i){
        if (map[a[i] + k] > 0){
            cout << "(" << a[i] << "," << a[i]+k << ") ";
            map[a[i]+k] = -1; // to avoid duplicates
            ++counter;
        } else if (map[a[i] - k] > 0){
            cout << "(" << a[i] << "," << a[i]-k << ") ";
            map[a[i]-k] = -1;
            ++counter;
        }        

    }
    cout << endl << "Found " << counter << " pairs." << endl;
}

void insertIntoMap(vector<int> a){
    for(int i = 0; i < a.size(); ++i){        
        map[a[i]]++;
    }
}


struct Bigger
{
    template<class T>
    bool operator()(T const &a, T const &b) const { return a < b; }
};

int main(){
    a = {1, 7, 5, 9, 2, 12, 3};
    insertIntoMap(a);
    Bigger st;
    //std::sort(a.begin(), a.end(), st);
    // for(int i = 0; i < a.size(); i++) cout << " " << a[i] << " ";
    // cout << endl;    
    //pairDiff(2);
    pairDiffMap(2);
}