class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> numbers;
        int facto = 1;
        for(int i = 1; i < n; i++){
            facto *= i;
            numbers.push_back(i);
        }
        numbers.push_back(n);
        string ans = "";
        k--;
        while(true){
            ans += to_string(numbers[k/facto]);
            numbers.erase(numbers.begin() +  k/facto);
            if(numbers.size() == 0) break;
            k %= facto;
            facto /= numbers.size();
        }
        return ans;
    }
};