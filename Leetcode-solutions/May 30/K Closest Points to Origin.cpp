class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
    vector<vector<int>> result;
    vector<vector<int>> sum;
    if (points.size() < K)
        return result;
    else if (points.size() == K)
        return points;
    int i = 0;
    for (auto& elem : points)
    {
        int j = pow(elem[0],2) + pow(elem[1], 2);
        sum.push_back({ j, i });
        i++;
    }

    sort(sum.begin(), sum.end());

    //cout << "sort: ";
   // for (auto elem : sum)
    //{
     //   cout << elem[0] << "," << elem[1] << "\t";
    //}
    cout << endl;
    i = 0;
    while(i<K)
    {
        result.push_back(points[sum[i++][1]]);
    }

    return result;
    }
};

//Thank you Tejas for helping!
