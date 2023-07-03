class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    static bool cmp(vector<int>&a , vector<int>&b){
        
        return a[1] < b[1];
    }
    int maxMeetings(int start[], int end[], int n)
    {
        vector<vector<int>> meetings;
        for(int i = 0; i < n; i++){
            meetings.push_back({start[i] , end[i] , i});
        }
        
        sort(meetings.begin() , meetings.end(), cmp);
        
        int cnt = 1;
        int prevFinishTime = meetings[0][1];
        for(int i = 1; i < n; i++){
            if(meetings[i][0] > prevFinishTime){
                cnt++;
                prevFinishTime = meetings[i][1];
            }
        }
        
        return cnt;
    }
};