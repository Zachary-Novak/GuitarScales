#include <vector>
#include <stdlib.h>
using namespace std;

vector<int> smallestDifference(vector<int> arrayOne, vector<int> arrayTwo) {
  int temp = 0;
  for(int i = 0; i < arrayOne.size(); i++) {
    for(int j = i; j < arrayOne.size(); j++) {
      if (arrayOne[j] < arrayOne[i]) {
        temp = arrayOne[i];
        arrayOne[i] = arrayOne[j];
        arrayOne[j] = temp;
      }
    }
  }
  cout << "[";
  for(int i = 0; i < arrayOne.size(); i++) {
    cout << " " << arrayOne[i];
  }
  cout << "]" << endl;
  for(int i = 0; i < arrayTwo.size(); i++) {
    for(int j = i; j < arrayTwo.size(); j++) {
      if (arrayTwo[j] < arrayTwo[i]) {
        temp = arrayTwo[i];
        arrayTwo[i] = arrayTwo[j];
        arrayTwo[j] = temp;
      }
    }
  }
  cout << "[";
  for(int i = 0; i < arrayTwo.size(); i++) {
    cout << " " << arrayTwo[i];
  }
  cout << "]" << endl;
  vector<int> closest;
  int left = 0;
  int right = 0;
  closest.push_back(arrayOne[left]);
  closest.push_back(arrayTwo[right]);
  while ((left < arrayOne.size())&&(right<arrayTwo.size())&&(closest[0]-closest[1]!=0)) {
    if (arrayOne[left] > arrayTwo[right]) {
      if (right+1 == arrayTwo.size()) {
        break;
      }
      right++;
      cout << "right " << right << endl;
    } else if(arrayOne[left] < arrayTwo[right]){
      if (left+1 == arrayOne.size()) {
        break;
      }
      left++;
      cout << "left " << left << endl;
    }
    if (abs(arrayOne[left] - arrayTwo[right]) < abs(closest[0] - closest[1])) {
      closest.pop_back();
      closest.pop_back();
      closest.push_back(arrayOne[left]);
      closest.push_back(arrayTwo[right]);
      cout << closest[0] << " closest " << closest[1] << endl;
      cout << left << " :left right: " << right << endl;
    }
  }
  // Write your code here.
  return closest;
}
