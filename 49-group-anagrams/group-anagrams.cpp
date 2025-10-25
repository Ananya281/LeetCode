class Solution {
public:
    string generate(string &str)
    {
        vector<int>hash(26,0);
        int n=str.size();
        for(int i=0;i<n;i++)
        {
            char ch=str[i];
            hash[ch-'a']++; //hash[digit]++ means uss index par jake value increament
        }
        //str="1123" string
        //str-'0' convert into integer 1123
        //str+'0  convert into string "1123" --->wrong

        //string to integer
        // string str = "1123";
        // int x = stoi(str);   // ✅ 1123

        // int digit = '5' - '0';   // ✅ 5 digit
        // char c = 7 + '0';   // ✅ '7' character
        // string s = string(1, '0') + "123";  // ✅ "0123"

        // 'b' - 'a' = 98 - 97 = 1  char -> index
        // 'z' - 'a' = 122 - 97 = 25

        // 'a' + index  when index -> char 'a'+2='c'
        string word;
        for(int i=0;i<26;i++)
        {
            int freq=hash[i];
            if(freq>0)
            {
                word=word+string(freq,i+'a');//freq,character as parameter
            }
        }
        return word;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        int n=strs.size();
        vector<vector<string>>result;
        map<string,vector<string>>mpp;
        for(int i=0;i<n;i++)
        {
            string str=strs[i];
            //using khud ka sort
            string temp=generate(str);//sorted string return
            mpp[temp].push_back(str);
            //using built-in sort
            // sort(str.begin(),str.end());
            // mpp[str].push_back(strs[i]);
        }
        for(auto it:mpp)
        {
            result.push_back(it.second);
        }
        return result;
    }
};