class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ret = 0;
        unordered_set <int> numSet;
        for (auto i: nums)
            numSet.insert(i);

        for (auto i: nums)
        {
            if (numSet.find(i-1) != numSet.end())
                continue;

            int currentNum = i;
            int currentLong = 1;

            while (numSet.find(currentNum+1) != numSet.end())
            {
                currentNum++;
                currentLong++;
            }

            ret = max(ret, currentLong);
        }

        return ret;
    }
};


/*
    use a hash map to store boundary information of consecutive sequence 
    for each element; there are 4 cases when a new element i reached:

    neither i+1 nor i-1 has been seen: m[i]=1;  .. ok
    both i+1 and i-1 have been seen: extend m[i+m[i+1]] and m[i-m[i-1]] to each other; .. m[i + 1] + m[i - 1] + 1
    only i+1 has been seen: extend m[i+m[i+1]] and m[i] to each other; .. 这时m[i] 和 m[i+m[i+1]] 是两个边界
    only i-1 has been seen: extend m[i-m[i-1]] and m[i] to each other. .. 这时m[i] 和 m[i-m[i-1]] 是两个边界
*/

/*
    1. 查找num中的是否在map中
    2. 如果找到则跳过，继续循环
    3. 如果没有找到则插入（i, 0）到关联数组中，进行第4步
    4. 
*/
int longestConsecutive(vector<int> &num) {
    unordered_map<int, int> m;
    int r = 0;
    for (int i : num) {
        if (m[i]) continue; // 如果元素i被访问过就不在进行下面步骤的操作

        r = max(r, m[i] = m[i + m[i + 1]] = m[i - m[i - 1]] = m[i + 1] + m[i - 1] + 1);
        // 
    }
    /*
        m[i] = 
        m[i + m[i + 1]]
        m[i - m[i - 1]]    
        m[i + 1] + m[i - 1] + 1   neither i+1 nor i-1 has been seen: m[i]=1;
    */
    return r;
}



class Solution {
public:
    int longestConsecutive(vector<int> &num) {

        int ret = 0;
        unordered_map<int, int> m;
        for (int i: num)
            m[i] = 1;

        for (int i : num) {
            uint8_t mask = 0;
            if (m.find(m[i-1]) != m.end()) mask |= 0x01;
            if (m.find(m[i+1]) != m.end()) mask |= 0x02;

            switch (mask) {
                case 0x01:  // have i-1 no i + 1: extend m[i-m[i-1]] and m[i] to each other
                    m[i-m[i-1]]++;
                    m[i] = m[i-m[i-1]];
                    break;
                case 0x02:
                    m[i+m[i+1]]++;
                    m[i] = m[i+m[i+1]];
                    break;
                case 0x03:
                    m[i + m[i + 1]] = m[i - m[i - 1]] = m[i + 1] + m[i - 1] + 1;
                    break;
                default: // 0x00 no i-1 no i + 1
                    break;

            }
            // if (m[i]) continue; // 如果元素i被访问过就不在进行下面步骤的操作


            ret = max(ret, m[i]);
            // 
        }

        return ret;
    }
};
