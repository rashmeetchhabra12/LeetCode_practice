class Solution {
public:
    int bestClosingTime(string customers) {
        int n_bef=0; int n_aft=0;
        int y_bef=0; int y_aft=0;
        for(auto ch:customers){
            if(ch=='Y') y_aft++; else n_aft++;
        }
        vector<int>penalties;
        for(int i=0;i<=customers.size();i++){
            penalties.push_back(n_bef+y_aft);
            if(i==customers.size()) break;
            if(customers[i]=='Y'){
                y_bef++;
                y_aft--;
            }
            else{
                n_bef++;
                n_aft--;
            }
        }
        int index=0;
        int min_pen=INT_MAX;
        for(int i=0;i<penalties.size();i++){
            if(penalties[i]<min_pen){
                min_pen=penalties[i];
                index=i;
            }
        }
       // sort(penalties.begin(),penalties.end());
        return index;
    }
};