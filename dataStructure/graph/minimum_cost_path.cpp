class Solution {
public:
    int minimumCostPath(std::vector<std::vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        std::vector<std::vector<int>> distance(rows, std::vector<int>(cols, INT_MAX));
        distance[0][0] = grid[0][0];

        std::vector<std::pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        std::priority_queue<std::pair<int, std::pair<int, int>>, std::vector<std::pair<int, std::pair<int, int>>>, std::greater<std::pair<int, std::pair<int, int>>>> pq;

        pq.push(std::make_pair(grid[0][0], std::make_pair(0, 0)));

        while (!pq.empty()) {
            int cost = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;

            pq.pop();

            if (row == rows - 1 && col == cols - 1) {
                return cost;
            }

            for (auto dir : directions) {
                int dirx = row + dir.first;
                int diry = col + dir.second;

                if (dirx >= 0 && dirx < rows && diry >= 0 && diry < cols) {
                    int newcost = cost + grid[dirx][diry];
                    if (newcost < distance[dirx][diry]) {
                        distance[dirx][diry] = newcost;
                        pq.push(std::make_pair(newcost, std::make_pair(dirx, diry)));
                    }
                }
            }
        }

        return -1; // Return -1 if no valid path is found
    }
};