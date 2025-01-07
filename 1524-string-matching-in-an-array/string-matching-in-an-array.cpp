class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        int n = words.size();
        vector<string> result;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j || words[i].empty() || words[j].empty()) {
                    continue; // Skip same words and empty strings
                }
                if (words[j].find(words[i]) != string::npos) { // Check if words[i] is a substring of words[j]
                    result.push_back(words[i]);
                    break; // Break as we found a match for words[i]
                }
            }
        }

        // Return the result vector
        return result;
    }
};
