class Solution {
public:
    vector<string> split_sentence(string sen) {
  
    // Create a stringstream object
    stringstream ss(sen);
    
    // Variable to hold each word
    string word;
    
    // Vector to store the words
    vector<string> words;
    
    // Extract words from the sentence
    while (ss >> word) {
      
        // Add the word to the vector
        words.push_back(word);
    }
    
    return words;
    }   
    string decodeCiphertext(string et, int rows) {
        int n = et.length();

        //BASE CASE : 
        if(n<1) return et;
        if(rows < 2) return et;
        // int col =( ((n+3)/rows) + (n%rows) -1);
        // int act = (n+3)/rows;
        int i =0;int temp = 0;
        int col = n/rows;
        vector<string>words;
        for(i;i<n;i= i+col){
            words.push_back(et.substr(i+temp,col));
            temp++;
            cout<<i<<"   "<<temp<<endl;
            
        }
        // cout<<words[1]<<"jjkk"<<endl;
        string ans = "";
        for(int j = 0;j<words[0].size();j++){
            for(int i =0;i<rows;i++)
            if(j<words[i].size())
            ans += words[i][j];
        }
        while(ans.back() == ' ') ans.pop_back();
        return ans;
    }
};