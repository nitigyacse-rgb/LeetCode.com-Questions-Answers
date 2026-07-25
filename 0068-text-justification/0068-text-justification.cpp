class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int n = words.size();
        int i = 0;

        while (i < n) {
            int j = i;
            int lineLength = 0;

            // Greedy check: fit as many words as possible with single spaces
            while (j < n && lineLength + words[j].length() + (j - i) <= maxWidth) {
                lineLength += words[j].length();
                j++;
            }

            int numWords = j - i;
            string line = "";

            // Case 1: Last line OR line containing only 1 word -> Left-justified
            if (j == n || numWords == 1) {
                for (int k = i; k < j; ++k) {
                    line += words[k];
                    if (k < j - 1) line += " ";
                }
                // Right-pad remaining spaces
                while (line.length() < maxWidth) {
                    line += " ";
                }
            } 
            // Case 2: Fully justified line
            else {
                int totalSpaces = maxWidth - lineLength;
                int baseSpaces = totalSpaces / (numWords - 1);
                int extraSpaces = totalSpaces % (numWords - 1);

                for (int k = i; k < j; ++k) {
                    line += words[k];
                    if (k < j - 1) {
                        int spacesToApply = baseSpaces + (k - i < extraSpaces ? 1 : 0);
                        line.append(spacesToApply, ' ');
                    }
                }
            }

            result.push_back(line);
            i = j; // Move to next set of words
        }

        return result;
    }
};