## [Encode and Decode TinyURL](https://leetcode.com/problems/encode-and-decode-tinyurl/)

### Problem Link - https://leetcode.com/problems/encode-and-decode-tinyurl/

---

### Solution

```cpp

    class Solution {
    public:
        
        unordered_map<string, string> shortToLong;
        unordered_map<string, string> longToShort;

        // Encodes a URL to a shortened URL.
        string encode(string longUrl) {
            srand(time(0));
            string tinyUrl = "";
            for(int i = 0; i < 6; i++) {
                int random = rand() % 62;
                if(random < 26)
                    tinyUrl += (char)('a' + random);
                else if(random < 52)
                    tinyUrl += (char)('A' + random - 26);
                else
                    tinyUrl += (char)('0' + random - 52);
            }
            shortToLong[tinyUrl] = longUrl;
            longToShort[longUrl] = tinyUrl;
            return tinyUrl;
        }

        // Decodes a shortened URL to its original URL.
        string decode(string shortUrl) {
            return shortToLong[shortUrl];
        }
    };

    // Your Solution object will be instantiated and called as such:
    // Solution solution;
    // solution.decode(solution.encode(url));

```