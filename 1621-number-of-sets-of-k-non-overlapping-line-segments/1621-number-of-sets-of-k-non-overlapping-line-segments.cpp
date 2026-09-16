class Solution {
public:
    int numberOfSets(int n, int k) {
        long long MOD = 1e9 + 7;
        int total = n + k - 1;
        int r = 2 * k;
        
        // nCr optimization: nCr = nC(n-r)
        if (r > total - r) r = total - r;
        
        long long num = 1, den = 1;
        for (int i = 1; i <= r; ++i) {
            num = (num * (total - i + 1)) % MOD;
            den = (den * i) % MOD;
        }
        
        // Fermat's Little Theorem for modular inverse: den^(MOD - 2) % MOD
        auto power = [&](long long base, long long exp) {
            long long res = 1;
            base %= MOD;
            while (exp > 0) {
                if (exp % 2 == 1) res = (res * base) % MOD;
                base = (base * base) % MOD;
                exp /= 2;
            }
            return res;
        };
        
        return (num * power(den, MOD - 2)) % MOD;
    }
};