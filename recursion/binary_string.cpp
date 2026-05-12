



#include<bits/stdc++.h>
using namespace std;
// Method one 
void generate_binary(string s, string ds, vector<string>&ans, int n){
    if (n==0){
        ans.push_back(ds);
        return;
    }

    for (int i=0;i<2;i++){
        if (ds.size()!=0 && s[i]=='1'){
            if (s[i]==ds.back()) continue;
        }
        ds.push_back(s[i]);
        generate_binary(s, ds, ans, n-1);
        ds.pop_back();
    }
    
}

// alternative method

void generate(int n, string curr, vector<string>& result) {
    // Base case: if length is n, add to result
    if (curr.length() == n) {
        result.push_back(curr);
        return;
    }

    // Always try adding '0'
    generate(n, curr + "0", result);

    // Add '1' only if previous char is not '1'
    if (curr.empty() || curr.back() != '1') {
        generate(n, curr + "1", result);
    }
}

int main(){
    string s = "01";
    int n = 3;
    vector<string>ans;
    string ds = "";
    generate_binary(s,ds,ans,n);
    // generate(n, ds, res);
    for (int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}