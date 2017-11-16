#include <string>
#include <map>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;
vector<string> tot;

int main() {
	string s;
	map<string, int>dict;
	while (cin >> s && s != "#") {
		tot.push_back(s);
		int len = s.length();
		for (int i = 0; i < len; i++)s[i] = tolower(s[i]);
		sort(s.begin(), s.end());
		if (dict.find(s) == dict.end())dict.insert(map<string,int>::value_type(s,1));
		else dict.find(s)->second++;
	}
	int len = tot.size();
	sort(tot.begin(), tot.end());
	for (int i = 0; i < len; i++) {
		string tmp = tot[i];
		int tl = tmp.length();
		for (int i = 0; i < tl; i++)tmp[i] = tolower(tmp[i]);
		sort(tmp.begin(), tmp.end());
		if (dict.find(tmp)->second == 1)cout << tot[i] << endl;
	}
}

/*
map<string,int> cnt;
vector<string> words;

string repr(const string s){
    string ans = s;
    for(int i = 0; i<ans.length();i++){
        ans[i]=tolower[ans[i]];
    }
    sort(ans.begin(),ans.end());
    return ans;
}

int main(){
    int n=0;
    string s;
    while(cin>>s){
        if(s[0]=='#')break;
        words.push_back(s);
        string r=repr(s);
        if(!cnt.count(r))cnt[r]=0;
        cnt[r]++;
    }
    vector<string>ans;
    for(int i=0;i<words.size();i++)
        if(cnt[repr(words[i])]==1)ans.push.back(words[i]);
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<endl;
    return 0;
}
*/