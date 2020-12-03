## [Validate IP Address](https://leetcode.com/problems/validate-ip-address/)

### Problem Link - https://leetcode.com/problems/validate-ip-address/

---

### Solution

```cpp

    class Solution {
    public:
        string validIPAddress(string IP) {
            bool ipv4 = true;
            bool ipv6 = true;
            int del = 0;
            int len = 0;
            int count = 0;
            for(int i = 0; i < IP.length(); i++) {
                len = 0, count = 0;
                while(i < IP.length() && IP[i] == '0') {
                    i++;
                    len++;
                }
                if(len > 1)
                    ipv4 = false;
                if(len == 1 && IP[i] != '.')
                    ipv4 = false;
                while(i < IP.length() && IP[i] != '.' && IP[i] != ':') {
                    if(IP[i] < '0' || IP[i] > '9')
                        ipv4 = false;
                    else
                        count = count * 10 + (IP[i] - '0');
                    if(!((IP[i] >= '0' && IP[i] <= '9') || (IP[i] >= 'a' && IP[i] <= 'f') 
                        || (IP[i] >= 'A' && IP[i] <= 'F')))
                        ipv6 = false;
                    if(count > 255) {
                        count = 0;
                        ipv4 = false;
                    }
                    len++;
                    i++;
                }
                if(len == 0) {
                    ipv4 = false;
                }
                if(i == IP.length() - 1) {
                    ipv4 = false;
                    ipv6 = false;
                }
                if(IP[i] == '.')
                    ipv6 = false;
                if(IP[i] == ':')
                    ipv4 = false;
                if(len < 1 || len > 4)
                    ipv6 = false;
                if(count < 0 || count > 255)
                    ipv4 = false;
                del++;
            }
            if(ipv4 && del != 4)
                ipv4 = false;
            if(ipv6 && del != 8)
                ipv6 = false;
            if(ipv4)
                return "IPv4";
            if(ipv6)
                return "IPv6";
            return "Neither";
        }
    };

```