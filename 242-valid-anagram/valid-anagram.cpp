class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>count(26,0);
        for(char &ch:s)
        {
            count[ch-'a']++;
        }
        for(char &ch:t)
        {
            count[ch-'a']--;
        }
        bool allZeros=all_of(count.begin(),count.end(),[](int element){
            return element==0;
        });
        return allZeros;
    }
};