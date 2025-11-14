long long connectRopes(int* arr, int n)
{
    if(n<=0) return 0;
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for(int i=0;i<n;i++){
        pq.push((long long)arr[i]);
    }
    long long ans=0;
    while(pq.size()>1){
        long long a=pq.top();
        pq.pop();
        long long b=pq.top();
        pq.pop();

        long long cost=a+b;
        ans+=cost;
        pq.push(cost);
    }
    return ans;
}
