int camelcase(string s) {
    int count = 1;  // Start with 1 word for the first lowercase word
    for (int i = 1; i < s.length(); i++) {
        int ascii = static_cast<int>(s[i]);
        if (ascii >= 65 && ascii <= 90) {  // Check if uppercase letter
            count++;
        }
    }
    return count;
}