class Solution {
public:
    int trap(vector<int>& height) {
        
        int ret = 0;
        int upmost = 0;
        int leftUpmost = 0;
        int rightUpmost = 0;

        if (height.size() <= 1) return ret;

        for (int i = 0; i < height.size(); ++i)
        {
            if (height[i] > upmost)
            {
                upmost = height[i];
                leftUpmost = i;
            }
            else if (height[i] == upmost)
                rightUpmost = i;
        }
        if (rightUpmost < leftUpmost) rightUpmost = leftUpmost;
        
        for (int i = 0; i < leftUpmost;)
        {
            if (height[i+1] < height[i])
            {
                int leftBorder = height[i++];
                while (height[i] < leftBorder)
                    ret += (leftBorder - height[i++]);
            }
            else
                ++i;
        }

        for (int i = height.size() - 1; i > rightUpmost; )
        {
            if (height[i-1] < height[i])
            {
                int rightBorder = height[i--];
                while (height[i] < rightBorder)
                    ret += (rightBorder - height[i--]);
            }
            else
                --i;
        }
        
        for (int i = leftUpmost + 1; i < rightUpmost; i++)
            ret += (height[leftUpmost] - height[i]);

        return ret;
    }
};