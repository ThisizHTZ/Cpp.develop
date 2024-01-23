#include "StringUtils.h"
namespace StringUtils{

std::string Slice(const std::string &str, ssize_t start, ssize_t end) noexcept{
    if (start < 0) start = str.size() + start; //If start is negative, it means that the calculation starts from the end of the string.
    if (end < 0) end = str.size() + end;
    if (start > end) return ""; //Return an empty string

    return str.substr(start, end - start);
}

std::string Capitalize(const std::string &str) noexcept{
    std::string result = str; //Copy the input string.
    if (!result.empty()) {
        result[0] = std::toupper(result[0]); // Capitalize the first letter
    }
    return result;
}

std::string Upper(const std::string &str) noexcept{
    std::string result = str;
    for (char &ch : result) { // Using for loop, capitalize every letter in the str.
        ch = std::toupper(ch);
    }
    return result;
}

std::string Lower(const std::string &str) noexcept{
    std::string result = str; 
    for (char &ch : result) {
        ch = std::tolower(ch); //Same method as the above.
    }
    return result;
}

std::string LStrip(const std::string &str) noexcept{
    size_t start = str.find_first_not_of(" \t\n\r\f\v"); //Used to find and remove empty space in a string
    return (start == std::string::npos) ? "" : str.substr(start); //Represents the case where no match is found in the std::string class
} //If Nn non-whitespace characters are found in the string, then the function returns an empty string.

std::string RStrip(const std::string &str) noexcept{
    size_t end = str.find_last_not_of(" \t\n\r\f\v"); //find_last_not_of means find the last non-whitespace character.
    return (end == std::string::npos) ? "" : str.substr(0, end + 1);
}

std::string Strip(const std::string &str) noexcept{
    return LStrip(RStrip(str)); //Remove both front and tail whitespaces.
}

std::string Center(const std::string &str, int width, char fill) noexcept{
    int len = str.length();
    if (len >= width) return str; // Return the original string if it's already wider than the given width.
    int pad = width - len;
    int left = pad / 2 + (pad % 2 != 0); // Calculation 
    int right = pad / 2;
    return std::string(left, fill) + str + std::string(right, fill);
}

std::string LJust(const std::string &str, int width, char fill) noexcept{
    if (str.length() >= width) return str; // Return the original string if it's already wider than the given width.
    return str + std::string(width - str.length(), fill);
}

std::string RJust(const std::string &str, int width, char fill) noexcept{
    if (str.length() >= width) return str;
    return std::string(width - str.length(), fill) + str; // Return the string with padding added to the left.
}

std::string Replace(const std::string &str, const std::string &old, const std::string &rep) noexcept{
    if (old.empty()) return str; //If the old string is empty, return the original one.

    size_t start = 0;
    std::string result = str;

    while ((start = result.find(old, start)) != std::string::npos) { // while loop to find 
        result.replace(start, old.length(), rep); //Replace old with 'rep'.
        start += rep.length();
    }
    return result;
}

std::vector< std::string > Split(const std::string &str, const std::string &splt) noexcept{
    std::vector<std::string> tokens;
    size_t start = 0, end = 0;
    while ((end = str.find(splt, start)) != std::string::npos) { // Still using the loop to find all delimiters and split the string.
        tokens.push_back(str.substr(start, end));
        start = end + splt.length();
    }
    tokens.push_back(str.substr(start));
    return tokens;
}

std::string Join(const std::string &str, const std::vector< std::string > &vect) noexcept{ //Joins the elements of a vector of strings into a single string, separated by a specified delimiter
    std::string input;
    for (const std::string &str : vect) {
        input += str;
    }
    return input;
}

std::string ExpandTabs(const std::string &str, int tabsize) noexcept{
    std::string input;
    for (char ch : str) {
        if (ch == '\t') {
            input += std::string(tabsize, ' ');// if the ch is detected to be the tab, transform to one whitespace, the tabsize can be changed in Test.cpp
        } else {
            input += ch; //add the characters to the original input string.
        }
    }
    return input;
}

int EditDistance(const std::string &left, const std::string &right, bool ignorecase) noexcept{
    std::string l = ignorecase ? StringUtils::Lower(left) : left;
    std::string r = ignorecase ? StringUtils::Lower(right) : right;

    std::vector<std::vector<int>> dp(l.size() + 1, std::vector<int>(r.size() + 1)); //Make 2D matrix to store edit distances
    for (size_t i = 0; i <= l.size(); ++i) { //Initializing the matrix
        for (size_t j = 0; j <= r.size(); ++j) {
            if (i == 0) dp[i][j] = j; // row
            else if (j == 0) dp[i][j] = i; //column
            else if (l[i - 1] == r[j - 1]) dp[i][j] = dp[i - 1][j - 1];
            else {
                dp[i][j] = 1 + std::min(std::min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]); //Calculate edit distance
            }
        }
    }
    return dp[l.size()][r.size()];
};
};
