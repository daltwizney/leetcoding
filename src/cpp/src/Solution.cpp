#include <unordered_set>

using namespace std;

class Solution {
public:
    bool checkIfPangram(string sentence) {

        unordered_set<char> seen;

        const char* characters = sentence.c_str();

        for (int i = 0; i < sentence.length(); ++i)
        {
            seen.emplace(characters[i]);

            if (seen.size() == 26)
            {
                return true;
            }
        }

        return false;
    }
};