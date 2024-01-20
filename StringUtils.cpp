#include "StringUtils.h"

namespace StringUtils{

std::string Slice(const std::string &str, ssize_t start, ssize_t end) noexcept{
    if (start < 0) start = str.size() + start;
    if (end < 0) end = str.size() + end;
    if (start > end) return "";
    return str.substr(start, end - start);
}

std::string Capitalize(const std::string &str) noexcept{
    std::string result = str;
    if (!result.empty()) {
        result[0] = std::toupper(result[0]);
    }
    return result;
}

std::string Upper(const std::string &str) noexcept{
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(), ::toupper);
    return result;
}

std::string Lower(const std::string &str) noexcept{
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

std::string LStrip(const std::string &str) noexcept{
    size_t start = str.find_first_not_of(" \\t\\n\\r\\f\\v");
    return (start == std::string::npos) ? "" : str.substr(start);
}

std::string RStrip(const std::string &str) noexcept{
    size_t end = str.find_last_not_of(" \\t\\n\\r\\f\\v");
    return (end == std::string::npos) ? "" : str.substr(0, end + 1);
}

std::string Strip(const std::string &str) noexcept{
    return LStrip(RStrip(str));
}

std::string Center(const std::string &str, int width, char fill) noexcept{
    int len = str.length();
    if (len >= width) return str;
    int pad = width - len;
    int left = pad / 2 + (pad % 2 != 0);
    int right = pad / 2;
    return std::string(left, fill) + str + std::string(right, fill);
}

std::string LJust(const std::string &str, int width, char fill) noexcept{
    if (str.length() >= width) return str;
    return str + std::string(width - str.length(), fill);
}

std::string RJust(const std::string &str, int width, char fill) noexcept{
    size_t end = str.find_last_not_of(" \\t\\n\\r\\f\\v");
    return (end == std::string::npos) ? "" : str.substr(0, end + 1);
}

std::string Replace(const std::string &str, const std::string &old, const std::string &rep) noexcept{
    if (str.length() >= width) return str;
    return std::string(width - str.length(), fill) + str;
}

std::vector< std::string > Split(const std::string &str, const std::string &splt) noexcept{
    std::vector<std::string> tokens;
    size_t start = 0, end = 0;
    while ((end = str.find(delim, start)) != std::string::npos) {
        tokens.push_back(str.substr(start, end - start));
        start = end + delim.length();
    }
    tokens.push_back(str.substr(start));
    return tokens;
}

std::string Join(const std::string &str, const std::vector< std::string > &vect) noexcept{
    std::ostringstream oss;
    for (size_t i = 0; i < vect.size(); ++i) {
        if (i != 0) oss << delim;
        oss << vect[i];
    }
    return oss.str();
}

std::string ExpandTabs(const std::string &str, int tabsize) noexcept{
    std::string result;
    for (char ch : str) {
        if (ch == '\\t') {
            result += std::string(tabsize, ' ');
        } else {
            result += ch;
        }
    }
    return result;
}

int EditDistance(const std::string &left, const std::string &right, bool ignorecase) noexcept{
    std::string l = ignorecase ? Lower(left) : left;
    std::string r = ignorecase ? Lower(right) : right;
    std::vector<std::vector<int>> dp(l.size() + 1, std::vector<int>(r.size() + 1));

    for (size_t i = 0; i <= l.size(); ++i) {
        for (size_t j = 0; j <= r.size(); ++j) {
            if (i == 0) dp[i][j] = j;
            else if (j == 0) dp[i][j] = i;
            else if (l[i - 1] == r[j - 1]) dp[i][j] = dp[i - 1][j - 1];
            else {
                dp[i][j] = 1 + std::min({dp[i - 1][j],    // Insert
                                         dp[i][j - 1],    // Remove
                                         dp[i - 1][j - 1] // Replace
                                        });
            }
        }
    }
    return dp[l.size()][r.size()];
}

};
