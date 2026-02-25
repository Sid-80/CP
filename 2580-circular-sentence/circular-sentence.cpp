class Solution {
public:
    bool isCircularSentence(string sentence) {
        int n = sentence.size();

        int i = 1;
        while(true){
            if(i == n) break;
            if(sentence[i-1] == ' '){
                if( sentence[i-2] != sentence[i]) {
                    // cout<<sentence[i-1]<< " "<< sentence[i]<<endl;
                    return false;
                }
            }

            i++;
        }

        if(sentence[0] != sentence[n-1]) return false;

        return true;

    }
};