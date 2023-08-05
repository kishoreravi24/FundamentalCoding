class Solution {
public:
    int findMinArrowShots(std::vector<std::vector<int>>& points) {
        std::sort(points.begin(), points.end(), [](const std::vector<int> &v1,const std::vector<int> &v2){
            return v1[1]<v2[1];
        });
        int arrows = 1, end = points[0][1];
        for (int i = 1; i < points.size(); i++) {
            if (end >= points[i][0]) {
                continue;
            } else {
                arrows++;
                end = points[i][1];
            }
        }
        return arrows;
    }
};
