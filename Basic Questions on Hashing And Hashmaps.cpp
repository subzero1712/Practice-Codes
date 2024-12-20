//Counting Frequency of Numbers Using Hashing
int n = arr.size();
vector<int>ans(n,0);
for(int i=0;i<arr.size();i++){
     ans[arr[i]-1]++;
}
return ans;

//Counting Frequency of Characters Uisng Hashing
void func(string s){
  int hash[26];  //for only capital or small letters
  //int hash[226]={0}; //for all characters
  for(int i=0;i<s.size();i++){
    hash[s[i]-'a']++;
    //hash[s[i]-'A']++;
    //hash[s[i]]++;
}

//Counting Frequency of Numbers Using Hash Maps
map<int,int> mpp;
//map<char,int> mpp; //for character frequency
//unordered_map<int,int> mpp; //if order does not matter it has constant best and average time complexity but have linear worst case time complexity 
for(int i=0;i<arr.size();i++){
  mpp[arr[i]]++;
}
for(auto it:mpp){
  cout<<it.first<<"->"<<it.second<<endl;
}
