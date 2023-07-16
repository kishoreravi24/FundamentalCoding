bool sortBasedOn(const std::pair<int, int>& one, const std::pair<int, int>& two) {
    return one.second < two.second;
}

int maximumMeetings(std::vector<int>& start, std::vector<int>& end) {
    int whenMeetingEnd = 0, meeting = 0;
    int n = std::min(start.size(), end.size());
    std::vector<std::pair<int, int>> scheduler;
    for (int i = 0; i < n; i++) {
        scheduler.push_back({start[i], end[i]});
    }
    std::sort(scheduler.begin(), scheduler.end(), sortBasedOn);
    for (int i = 0; i < n; i++) {
        if (scheduler[i].first > whenMeetingEnd) {
            meeting++;
            whenMeetingEnd = scheduler[i].second;
        }
    }
    return meeting;
}
