typedef long long int ll;
class Solution {
public:

    vector<bool> sieve(ll n)
    {
        vector<bool> prime(n + 1, true);
        prime[0] = false;
        prime[1] = false;
        long long int m = sqrt(n);
        for (ll p = 2; p <= m; p++)
        {
            // If prime[p] is not changed, then it
            // is a prime
            if (prime[p])
            {

                // Update all multiples of p
                for (ll i = p * 2; i <= n; i += p)
                    prime[i] = false;
            }
        }

        // push all the primes into the vector ans
        // vector<ll> ans;
        // for (ll i = 0; i < n; i++)
        //     if (prime[i])
        //         ans.push_back(i);
        return prime;
    }

    int largestPrime(int n) {
        vector<bool> x = sieve(n);

        int ans = 0;

        ll tmp = 0;

        for(int i = 0;i < x.size();i++){
                // cout<<i<<" "<<x[i]<<" \n";
            if(x[i]){
                tmp+=i;
                if(tmp <= n && x[tmp]){
                    ans = tmp;
                }
            }

        }

        return ans;
    }
};