class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
	 int start=0,gasi=0,cos=0,sub=0;
    int n=gas.size();
    for(int i=0;i<n;i++){
        gasi=gasi+gas[i];
        cos=cos+cost[i];
    }
    if(cos>gasi){
        return -1;
    }
    for(int i=0;i<n;i++){ 
        sub+=gas[i]-cost[i];
        if(sub<0){
            sub=0;
            start=i+1;
        }
    } 
    return start;

    }
};