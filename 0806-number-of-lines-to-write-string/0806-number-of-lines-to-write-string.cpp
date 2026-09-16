

class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        
        int lines = 1;
        int pixels = 0;
        
        for (char c : s) {
            
            int w = widths[c - 'a'];
            
            if (pixels + w <= 100) {
                pixels += w;
            }
            else {
                lines++;
                pixels = w;
            }
        }
        
        return {lines, pixels};
    }
};