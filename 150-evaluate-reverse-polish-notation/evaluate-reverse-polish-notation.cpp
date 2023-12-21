class Solution {

public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> s;

        for(auto it : tokens){
            if(it != "+" && it != "/" && it != "*" && it != "-"){
                
                long long number = stol(it);
                cout<<number<<endl;
                s.push(number);
            }else{
                long long s1 = s.top();
                s.pop();
                long long s2 = s.top();
                s.pop();
                long long ans = 0;
                
                if(it == "+"){ 
                    s.push(s1+s2);
                }else if(it == "-"){
                    s.push(s2-s1);
                }else if(it == "*"){ 
                    s.push(s1*s2);
                }else if(it == "/"){
                    s.push(s2/s1);
                }

            }
        }

        return s.top();
    }
};