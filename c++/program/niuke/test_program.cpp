#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool Find(vector<vector<int> > array,int target) {
    	int i, j, index, y_limit;
        
        if (array.empty()) {
            return false;
        }
        
        y_limit = array.size();
        for (i = array[0].size() - 1, j = 0; i >= 0 && j < y_limit; j = 0) {
            if (array[i][j] > target) {
                i--;
            } else if (array[i][j] < target) {
            	for (index = j; index < y_limit; index++) {
                    if (array[index][i] > target) {
                        y_limit = index;
                        i--;
                    } else if (array[index][i] < target) {
                        continue;
                    } else {
                        return true;
                    }
                } 
            } else {
                return true;
            }    
        }
        return false;
    }
};

int main(void) {

  vector<vector <int> > array(4, vector<int>(4));
  
  array[0][0] = 1;
  array[0][1] = 2;
  array[0][2] = 8;
  array[0][3] = 9;
  array[1][0] = 2;
  array[1][1] = 4;
  array[1][2] = 9;
  array[1][3] = 12;
  array[2][0] = 4;
  array[2][1] = 7;
  array[2][2] = 10;
  array[2][3] = 13;
  array[3][0] = 6;
  array[3][1] = 8;
  array[3][2] = 11;
  array[3][3] = 15;

  cout << array.size() << endl;
  cout << array[0].size() << endl;
  cout << array.empty() << endl;

  Solution islo;
  cout << islo.Find(array, 15);
  return 0;
}
