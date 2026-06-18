//Brute Force Approach
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();

        vector<int> left(n,1);
        vector<int> right(n,1);

        for(int i=1;i<n;i++){
            if(ratings[i] > ratings[i-1])
                left[i] = left[i-1] + 1;
        }
        for(int i=n-2;i>=0;i--){
            if(ratings[i] > ratings[i+1])
                right[i] = right[i+1] + 1;
        }
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += max(left[i], right[i]);
        }
        return sum;
    }
};

//Better Approach
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();

        vector<int> left(n,1);

        for(int i=1;i<n;i++){
            if(ratings[i] > ratings[i-1]){
                left[i] = left[i-1] + 1;
            }
            else left[i]=1;
        }
        int sum=max(left[n-1], 1);
        int right=1;
        for(int i=n-2;i>=0;i--){
            if(ratings[i] > ratings[i+1]){
                right=right+1;
            }
            else right=1;
            sum+=max(left[i],right);
        }
        return sum;
    }
};

//Optimal Approach
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        int sum=1;
        int i=1;
        while(i<n){
            if(ratings[i]==ratings[i-1]){
                sum+=1;
                i++;
                continue;
            }
            int peak=0;
            while(i<n && ratings[i]>ratings[i-1]){
                peak++;
                sum+=peak+1;
                i++;
            }
            int down=0;
            while(i<n && ratings[i]<ratings[i-1]){
                down++;
                sum+=down;
                i++;
            }
            if(down>peak){
                sum+=(down-peak);
            }
        }
        return sum;
    }
};
