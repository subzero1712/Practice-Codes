class Solution {
  public:
    long long sumBetweenTwoKth(long long A[], long long n, long long K1, long long K2) {
        priority_queue<long long> pq;
        for(int i=0;i<n;i++){
            pq.push(A[i]);
            if(pq.size()>K1){
                pq.pop();
            }
        }
        long long k1th=pq.top();
        while(!pq.empty()){
            pq.pop();
        }
        for(int i=0;i<n;i++){
            pq.push(A[i]);
            if(pq.size()>K2){
                pq.pop();
            }
        }
        long long k2th=pq.top();
        long long sum=0;
        for(int i=0;i<n;i++){
            if(A[i]>k1th && A[i]<k2th){
                sum+=A[i];
            }
        }
        return sum;
    }
};
