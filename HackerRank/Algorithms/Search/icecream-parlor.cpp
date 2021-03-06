// Ice Cream Parlor
// Day #137
// Friday, October 13, 2017
// https://www.hackerrank.com/challenges/icecream-parlor

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class IceCream {
    
    public: 
        int flavor; 
        int index;

        IceCream(int flavor, int index) {
            this->flavor = flavor;
            this->index = index;
       }
};

struct compare {

    bool operator()(const IceCream & a, const IceCream & b) {

        return a.flavor < b.flavor;
    
    }

};

    
int binarySearch(int first, int last, vector<IceCream> arr, int search) {
   
	int left, right, mid;
    left = first;
    right = last;
	
    while (right >= left) {
		
        mid = (left + right) / 2;
        
		if (arr[mid].flavor == search) { 
            
            return arr[mid].index; 
        
        } else if (arr[mid].flavor > search) { 
            
            right = mid - 1; 
        
        } else {
		
            left = mid + 1;
	
        }
            
    } 

	return -1;

} // binarySearch()

int main() {
    int t;
    int n, m;
    cin >> t;
    for(int test = 0; test < t; test++) {       
        cin >> m >> n;
        vector<IceCream> arr;
        arr.reserve(n); 

        for (int i = 0; i < n; i++) {
            int cost;
            cin >> cost;
            arr.push_back(IceCream(cost, i + 1));
        }

        sort(arr.begin(), arr.end(), compare());
        int firstIndex = 100000, secondIndex = 100000;
        for(int i = 0; i < n - 1 ; i++) {
            int search = m - arr[i].flavor;
            if(search >= arr[i].flavor) {
                int index = binarySearch(i + 1, n - 1, arr, search);
                if( index != -1 ) {
                    cout << min(arr[i].index, index) << " " << max(arr[i].index, index) << endl;
                    break;

                }
            }
        }

    }

}

