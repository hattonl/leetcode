class Solution1 {
public:
    int candy(vector<int>& ratings) {
        int nums = ratings.size();
        int ret = 0;
        vector<int> candys (nums, 1);
        
        for (int i = 1; i < nums; ++i)
        {
            if (ratings[i] > ratings[i-1])
                candys[i] = candys[i-1] + 1;
        }
        for (int i = nums-2; i >= 0; --i)
        {
            if ((ratings[i] > ratings[i+1]) && (candys[i] <= candys[i+1]))
                candys[i] = candys[i+1] + 1;
        }
        
        for (int i = 0; i < nums; ++i)
        {
            ret += candys[i];
        }
        
        return ret;
        
    }
};

class Solution2 {
public:
    int candy(vector<int>& ratings) {
        int nums = ratings.size();
        int up = 0;
        int down = 0;
        int old_slop = 0;
        int new_slop = 0;
        int candies = 0;
        if (nums <= 1) return nums;

        for (int i = 1; i < nums; ++i)
        {
            new_slop = (ratings[i] > ratings[i-1]? 1: (ratings[i]<ratings[i-1]? -1: 0));
            if ((old_slop > 0 && new_slop == 0) || (old_slop < 0 && new_slop >= 0))
            {
                candies += count(up) + count(down) + MAX(up, down);
                up = 0;
                down = 0;
            }

            if (new_slop > 0)      up++;
            else if (new_slop < 0) down++;
            else                   candies++; // why ?? 算作上一个mount的增加 ??

            old_slop = new_slop;
        }

        candies += count(up) + count(down) + MAX(up, down) + 1;
    }

private:
    int count(int n)
    {
        return (n*(n+1))/2;
    }
};


class Solution2 {
public:
    int candy(vector<int>& ratings) {
        int nums = ratings.size();
        int up = 0;
        int down = 0;
        int old_slop = 0;
        int new_slop = 0;
        int candies = 0;
        if (nums <= 1) return nums;

        for (int i = 1; i < nums; ++i)
        {
            new_slop = (ratings[i] > ratings[i-1]? 1: (ratings[i]<ratings[i-1]? -1: 0));

            // if the ratings[i-1] is a valley point
            if ( 
                (old_slop == 0  && new_slop == 0) ||
                (old_slop == 0  && new_slop == 1) ||
                (old_slop == -1 && new_slop == 0) ||
                (old_slop == -1 && new_slop == 1) )
            { /* ratings[i-1] is a valley point */
                // candies += count(up) + count(down) + MAX(up, down);
                candies += countMount(up, down);
                up = 0;
                down = 0;
            }
            else 
            {  /* ratings[i-1] is not a valley point */
                if (new_slop == 1) up++;
                else /* new_slop <= -1 */ down++;
            }

            old_slop = new_slop;
        }

        /* check last point */
        // 最后一个有下降？
        candies += countMount(up, down);

        // 最有一个无下降？



        //
        return candies;
    }

private:
    int count(int n)
    {
        return (n*(n+1))/2;
    }

    int countMount(int up, int down)
    {
        int ret = 0;
        if (up == 0 && down == 0)
            ret = 1;
        else
            ret = count(up) + count(down) + MAX(up, down);
        
        return ret;
    }
};
