string Solution::solve(string A) {
    vector<string> ss;
    string s = "";

    for (int i = 0; i < A.size(); i++) {
        if (A[i] != ' ') {
            s += A[i];
        } else {
            if (!s.empty()) {
                ss.push_back(s);
                s = "";
            }
        }
    }

    if (!s.empty()) {
        ss.push_back(s);
    }

    reverse(ss.begin(), ss.end());

    string result;
    for (auto index : ss) {
        result += index;
        result += " ";
    }

    if (!result.empty()) {
        result.pop_back();
    }

    return result;
}
