import math

def solution(area):
    # Your code here
    ans = []
    while area != 0:
        s = int(math.sqrt(area))
        area -= s * s
        print(s*s)
        ans.append(s * s)
    return ans

solution(15324)
