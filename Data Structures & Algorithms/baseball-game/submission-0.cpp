class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> record;
        for(string oper:operations){
            if(oper == "C")
                {record.pop_back();}
            else if(oper == "D"){
                record.push_back(2*record.back());
            }
            else if(oper == "+"){
                int size = record.size();
                record.push_back(record[size-1]+record[size-2]);
            }
            else{
                record.push_back(stoi(oper));
            }
        }
        return accumulate(record.begin(), record.end(), 0);
    }
};