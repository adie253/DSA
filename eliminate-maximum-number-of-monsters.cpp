#include<stdio.h>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {

        int n = dist.size();
        vector<int> time(n);
        
        for(int i=0; i<n; i++){
            time[i]=ceil((float)dist[i]/speed[i]);
        }

        sort(begin(time),end(time));

        int count =1;
        int tp = 1;

        for(int i=1; i<n; i++)
        {
            if(time[i]-tp<=0)
            {
                return count;
            }
            count++;
            tp+=1;
        }

        return count;
    }
   
};

int main() {
    Solution solution;
    vector<int> dist = {1, 3, 4};
    vector<int> speed = {1, 1, 1};
    int result = solution.eliminateMaximum(dist, speed);
    std::cout << "Maximum number of monsters eliminated: " << result << std::endl;
    return 0;
}