class Data{
    public:
    int start;
    int end;
    int pos;
};
bool comp(Data &a, Data &b){
    return a.end<b.end;
}
int maximumMeetings(vector<int> &start, vector<int> &end)
{
    int n=start.size();
    vector<Data> arr(n);
    for(int i=0;i<n;i++){
        arr[i].start=start[i];
        arr[i].end=end[i];
        arr[i].pos=i+1;
    }
    sort(arr.begin(), arr.end(), comp);
    int cnt=1;
    int freetime=arr[0].end;
    vector<int> ds;
    ds.push_back(arr[0].pos);
    for(int i=1;i<n;i++){
        if(arr[i].start>freetime){
            cnt++;
            freetime=arr[i].end;
            ds.push_back(arr[i].pos);
        }
    }
    return cnt;
  //return ds if position is asked
}
