class Solution {
public:
    long long modulo = 1e9 + 7;

    long long power(long long a, long long b)
    {
        if(b == 0)
            return 1;
        
        long long temp = power(a, b/2);

        if(b%2 == 0)
            return (temp*temp)%modulo;
        else
            return (a*temp*temp)%modulo;
    }

    int countGoodNumbers(long long n) {
        long long even = power(5, (n+1)/2) % modulo;
        long long odd = power(4, n/2) % modulo;

        return (even*odd)%modulo;
    }
};
