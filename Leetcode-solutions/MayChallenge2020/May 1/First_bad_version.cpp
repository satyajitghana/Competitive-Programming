// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int i,j;
        for(j =n;j>=1;j=j-10)
        {
            if(isBadVersion(j))
            {
                if(isBadVersion(j-10))
                    continue;
                else
                {
                    for(i=j;i>=j-10;i--)
                    {
                        if(!isBadVersion(i))
                            return i+1;
                    }
                }
            }
        }
        return 0;
    }
};
