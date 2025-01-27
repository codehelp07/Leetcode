class Solution {
public:
    void func(int open,int close,int n,vector<string>&ans,string temp){
        if(temp.size()==2*n){
            ans.push_back(temp);
            return;
        }
        if(open<n){
            func(open+1,close,n,ans,temp+'(');
        }
        if(close<open){
            func(open,close+1,n,ans,temp+')');
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        func(0,0,n,ans,"");
        return ans;
    }
};
