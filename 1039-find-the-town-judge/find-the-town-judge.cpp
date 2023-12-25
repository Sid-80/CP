class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_set<int> a_person; 
        unordered_map<int,int> b_person; 
        if(n == 1)
            return 1;
        for(auto x:trust)
        {
            a_person.insert(x[0]);
            b_person[x[1]]++;
        }
        for(auto x:b_person)
        {
            if(x.second == n-1)
            {
                if(a_person.find(x.first) == a_person.end())
                {
                    return x.first;
                }
            }
        }
        return -1;
    }
};