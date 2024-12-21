#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>

class Solution
{
    public:
        bool wordBreak(std::string s, std::vector<std::string>& wordDict)
        {
            std::unordered_set<std::string> wordSet(wordDict.begin(), wordDict.end());
            std::vector<bool> wordEnd(s.length()+1, false);
            wordEnd[0] = true;
            for(int endIdx = 1; endIdx <= s.length(); endIdx++) 
            {
                for(int startIdx = 0; startIdx <= endIdx; startIdx++) 
                {
                    if(wordEnd[startIdx] && wordSet.find(s.substr(startIdx, endIdx-startIdx)) != wordSet.end())
                    {
                        wordEnd[endIdx] = true;
                        break;
                    }
                }
            }
            return wordEnd[s.length()]; 
        }
};