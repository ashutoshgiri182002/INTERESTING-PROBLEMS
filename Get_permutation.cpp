#include<bits/stdc++.h>
using namespace std;

class Solution{
private:
  void SwapPermute(int ind,vector<int>&arr,vector<vector<int>>&ans){
    if(ind==arr.size()){
      ans.push_back(arr);
      return;
    }
    for(int i=ind;i<arr.size();i++){
      swap(arr[ind],arr[i]);
      SwapPermute(ind+1,arr,ans);
      swap(arr[ind],arr[i]);
    }
  }
public:
  vector<vector<int>>permute(vector<int>&arr){
    vector<vector<int>>ans;
    SwapPermute(0,arr,ans);
    return ans;
  }
};


int main(){

Solution obj;
vector<int>arr{1,2,3};

vector<vector<int>>res = obj.permute(arr);

cout<<"All the Permutation are "<<endl;

for(int i=0;i<res.size();i++){
  for(int j=0;j<res[i].size();j++){
    cout<<res[i][j]<<" ";
  }
  cout<<endl;
}

  return 0;
}
