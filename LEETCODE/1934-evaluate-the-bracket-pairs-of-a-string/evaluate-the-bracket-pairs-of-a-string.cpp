class node{
    public:
    bool end;
    vector<node*>next;
    string str;
    node(){
        end = 0;
        next = vector<node*>(26, NULL);
        str = "";
    }
    bool contains(char ch){
        return next[ch-'a'] != NULL;
    }
};
class Trie{
    public:
    node *root;
    Trie(){
        root = new node();
    }
    void add(string &s, string &t){
        int n = s.size(), i = 0;
        node* temp = root;
        while(i<n){
            if(!temp->contains(s[i])) temp->next[s[i]-'a'] = new node();
            temp = temp->next[s[i]-'a'];
            i++;
        }
        temp->end = 1;
        temp->str = t;
    }
    void search(string &s, string &ans){
        int n = s.size(), i = 0;
        node* temp = root;
        while(i<n){
            if(!temp->contains(s[i])){
                ans += '?';
                return;
            }
            temp = temp->next[s[i]-'a'];
            i++;
        }
        if(temp->end){
            ans += temp->str;
            return;
        }
        ans += '?';
    }
};
class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        // string ans = "", t = "";
        // int n = s.size(), i = 0;
        // map<string, string>mp;
        // for(auto &p: knowledge) mp[p[0]] = p[1];
        // while(i<n){
        //     if(s[i] == '('){
        //         i++;
        //         t = ""; 
        //         while(i<n && s[i] != ')') t += s[i++];
        //         i++;
        //         if(mp.count(t)) ans += mp[t];
        //         else ans += '?';
        //     }else ans += s[i++];
        // }
        // return ans;
        
        //can be solved using Trie

        string ans = "", t = "";
        int n = s.size(), i = 0;
        Trie tr = Trie();
        for(auto &p: knowledge) tr.add(p[0], p[1]);
        while(i<n){
            if(s[i] == '('){
                i++;
                t = ""; 
                while(i<n && s[i] != ')') t += s[i++];
                i++;
                tr.search(t, ans);
            }else ans += s[i++];
        }
        return ans;
    }
};