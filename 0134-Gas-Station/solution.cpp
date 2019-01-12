class Solution1 {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int num = gas.size();
        int minSum = 0;
        int allSum = 0;
        int startPoint = 0;

        if (num == 0) return -1;

        minSum = gas[0] - cost[0];
        startPoint = 1;
        for (int i = 0; i < num; ++i)
        {
            allSum += (gas[i]-cost[i]);
            if (allSum < minSum)
            {
                minSum = allSum;
                startPoint = i+1;
            }
        }

        return (allSum >= 0? (startPoint % num): -1);
    }
};

class Solution2 {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int num    = gas.size();
        int tanks  = 0;
        int allSum = 0;
        int startPoint = 0;
        for (int i = 0; i < num; ++i)
        {
            allSum += (gas[i]-cost[i]);
            tanks  += (gas[i]-cost[i]);
            if (tanks < 0)
            {
                startPoint = i + 1;
                tanks = 0;
            }
        }

        return (allSum >= 0? startPoint: -1);
    }
};
