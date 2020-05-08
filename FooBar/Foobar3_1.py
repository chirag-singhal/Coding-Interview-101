def solution(m, f):
    # Your code here
    ans = 0
    x, y = long(m), long(f)
    while not (x == 1 and y == 1):
        if x <= 0 or y <= 0:
            return "impossible"
        if y == 1:
            return str( ans + x - 1)
        else:
            ans += long(x / y)
            x, y = y, x % y
            
    return str(ans)