class Solution {
public:/*
    int solve( vector<int>& arr, unordered_map<int,int>& map, int i, int p){
        if(i>=arr.size()) return 0;

        int inc=0;
        if(p==-1 || arr[p]!=arr[i]-1){
            inc = arr[i]*map[arr[i]] + solve(arr, map, i+1, i);
        }
        int exc = solve(arr, map, i+1, p);
        return max(inc, exc);
    }
*/
/*
    int solveMem( vector<int>& arr, unordered_map<int,int>& map, int i, int p, vector<vector<int>>& dp){
        if(i>=arr.size()) return 0;

        if(dp[i][p+1]!=-1) return dp[i][p+1];

        int inc=0;
        if(p==-1 || arr[p]!=arr[i]-1){
            inc = arr[i]*map[arr[i]] + solve(arr, map, i+1, i, dp);
        }
        int exc = solve(arr, map, i+1, p, dp);
        dp[i][p+1] = max(inc, exc);
        return dp[i][p+1];
    }
*/
/*
        int solveMem( vector<int>& arr, unordered_map<int,int>& map, int i, int p, vector<vector<int>>& dp){
        if(i>=arr.size()) return 0;

        if(dp[i][p+1]!=-1) return dp[i][p+1];

        int inc=0;
        if(p==-1 || arr[p]!=arr[i]-1){
            inc = arr[i]*map[arr[i]] + solve(arr, map, i+1, i, dp);
        }
        int exc = solve(arr, map, i+1, p, dp);
        dp[i][p+1] = max(inc, exc);
        return dp[i][p+1];
    }
*/
/*
    int solve( vector<int>& arr, unordered_map<int,int>& map, vector<vector<int>>& dp){       
        
        int n=arr.size();

        for(int i=n-1; i>=0; i-- ){
            for(int p=i; p>=-1; p--){

            int inc=0;
            if(p==-1 || arr[p]!=arr[i]-1){
                inc = arr[i]*map[arr[i]] + dp[i+1][i+1];
            }
            int exc = dp[i+1][p+1];
            dp[i][p+1] = max(inc, exc);
            }
        }
        return dp[0][0];
    }
*/
    int solve( vector<int>& arr, unordered_map<int,int>& map, vector<vector<int>>& dp){       
        
        int n=arr.size();

        vector<int> curr(n+1,0);
        vector<int> prev(n+1,0);

        for(int i=n-1; i>=0; i-- ){
            for(int p=i; p>=-1; p--){

            int inc=0;
            if(p==-1 || arr[p]!=arr[i]-1){
                inc = arr[i]*map[arr[i]] + prev[i+1];
            }
            int exc = prev[p+1];
            curr[p+1] = max(inc, exc);
            }
            prev=curr;
        }
        return curr[0];
    }



    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        unordered_map<int,int> map;

        set<int> st;
        for(int num : nums){
            map[num]++;
            st.insert(num);
        }
        vector<int> arr(st.begin(), st.end());
        int n=arr.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        return solve(arr, map, dp);
    }
};