# Project 1 README

Student 1: Tianzuo Hu (920473160)
Before the coding, I seached online to build the environment and the coding part.

## Project Status
This the current status of the project: I wrote some Test cases in the StringUtilsTest.cpp, and most of them can normally run right now.

## Known Issues
The project fails to function properly in the function of ExpandTabs and EditDistance. And there are some warning after run the makefile,but I am not sure how to fix them.

## Code References
* [Different methods to initialize variables](https://stackoverflow.com/questions/2218254/variable-initialization-in-c)(https://blog.csdn.net/qq_51372098/article/details/113361454)
* [Some other link](https://www.geeksforgeeks.org/substring-in-cpp/)(https://youtu.be/We3YDTzNXEk)(https://blog.csdn.net/XJX_ai_dai/article/details/121020096)(https://blog.csdn.net/weixin_39445116/article/details/116767026)(https://www.bilibili.com/video/BV1oD4y1h7S3/?spm_id_from=333.337.search-card.all.click&vd_source=a501ff7fe517fa76de783ccf31a9d30a)(https://code.visualstudio.com/docs/sourcecontrol/github)

## Generative AI Use
I used ChatGPT3.5 for Prompt 1 to Prompt 7, and ask for change my code from Change 1 to Change 4

### Prompt 1
What does a makefile usually start with? I need the first three lines.

### Response 1
At the beginning of the Makefile, you will usually see variable definitions for the compiler and compilation options, along with optional comments to describe the Makefile or provide instructions for usage. When you mention three missing lines, you may refer to the following:

Comment: Explain the purpose of the Makefile or provide author information and change logs.
Variable definition: specifies the compiler (such as CXX) and compiler flags (such as CXXFLAGS and LDFLAGS).
.phony: Indicates which targets are not file names.
Here is an example of the start of a Makefile with comments and a base definition:

makefile
Copy code
# Makefile for StringUtils project
# Author: Your Name
# Last Modified: Date of last modification

# Compiler settings
CXX = g++
CXXFLAGS = -std=c++17 -Wall -I$(INC_DIR)
LDFLAGS = -lgtest -lgtest_main -lpthread

# Rest of the Makefile
...
In this example, you start with a comment block that describes the general purpose of the Makefile and author information. Compiler Settings are then defined, which include the compiler for compiling C++ code (CXX), compilation options (CXXFLAGS), and linking options (LDFLAGS). Finally, the directory path variables used in the project are defined. These variables will be used later in the Makefile rules.

### Prompt 2
What should I type in the terminal to run it?

### Response 2
ChatGPT
To run the Makefile in the terminal to build and test your project, you need to perform the following steps:

Open terminal: First open a command line terminal.

Navigate to the project directory: Use the cd command to navigate to the directory containing the Makefile.

sh
cd path/to/your/project
Run make: In the project root directory, type the make command and press Enter to run the default target. Depending on the Makefile you provide, this will compile your code and run the test if it is defined.

sh
make
Perform cleanup: If you want to clean compile-generated objects and executables, you can run make clean.

sh
make clean
Create directories: If your Makefile contains a target to create the necessary directories, you can also run this target separately (although in your Makefile, running the default all target will automatically create these directories).

sh
make directories
Run tests: If you just want to compile and run a test, you can call the runtests target directly (if it is defined in the Makefile).

sh
make runtests
make sure that the Makefile is in the current directory and that it is configured correctly so that the make program can recognize and execute the defined rules. If there are errors or path problems in the Makefile, make may report an error and stop execution. If an error occurs, adjust it according to the error message.

### Prompt 3
No current configuration is defined in the workspace state. Assuming 'Default'.
No target defined in the workspace state. Assuming 'Default'. Why it's wrong?

### Response 3
//AI Generated
Workspace configuration Undefined: The extension does not find the current configuration in workspace state, so the "default" configuration is assumed.

Target Undefined: The target is not defined in the workspace state, so the "default" target is assumed.

Makefile path undefined: The path to the Makefile is not defined in the Settings file, and the extension does not find make.exe in the environment path.

Extension generation and caching configuration information: This is normal extension behavior and is used to cache configured and parsed information.

Call to 'make --dry-run' : This is a regular procedure that the extension uses to parse the Makefile and get useful information. But the process failed because make.exe was not found.

Build log alternative: If you don't want the extension to run make --dry-run, you can provide a full build log by setting makefile.buildLog instead.

make command failed: The make --dry-run command could not be run because make.exe could not be found in the environment.

Error: The extension gives some suggestions, such as making sure that the make command invoked in VSCode is the same as the one you use in your development environment, and defining or adjusting custom makefile configurations in the makefile.Configurations Settings, if necessary.

Configuration success: Although some substeps returned error codes, the overall configuration process was considered successful.

To sum up, your main problem is that the Makefile Tools extension in Visual Studio Code fails to find make.exe. To solve this problem, you need to ensure that:

If you are on Windows, you may want to install the make tool (for example through MinGW or Cygwin) and make sure it is in your system PATH environment variable.
Specify the path to make.exe in VSCode Settings if it is not installed in a standard location.
If you are using WSL (Windows Subsystem for Linux), make sure you install the MAKE tool in your WSL environment and configure WSL correctly in VSCode.
Once you've solved the path problem for make.exe, you should be able to successfully run the make command in VSCode.

### Prompt 4
what is the meaning of char &ch : result ? 

### Response 4
The expression char &ch : result is typically used in a C++ range-based for loop. Let's break down its meaning:

char: This part specifies the data type of the elements you are iterating over. In this case, it indicates that you are iterating over elements of type char.

&ch: This part declares a reference variable ch of type char. In a range-based for loop, & is used to create a reference to each element in the sequence, allowing you to modify the original elements if needed. The ch variable will represent each element of the sequence one by one as you iterate through it.

result: This is the sequence or container that you are iterating over. It can be an array, a std::vector<char>, a std::string, or any other iterable collection containing elements of type char.

### Prompt 5
What is the meaning of find_first_not_of ? Can we use it to find last non-whitespace character?
### Response 5

The find_first_not_of function in C++ is used to find the position of the first character in a string that is not part of a specified set of characters. It returns the index of the first character that does not match any of the characters in the provided set. If no such character is found, it returns std::string::npos.

To find the position of the last non-whitespace character in a string, you can use find_last_not_of instead of find_first_not_of. Here's how you can use find_last_not_of:

cpp
Copy code
#include <iostream>
#include <string>

int main() {
    std::string text = "   Hello, World!   ";

    // Find the position of the last non-whitespace character
    size_t found = text.find_last_not_of(" \t\n\r\f\v");

    if (found != std::string::npos) {
        // Found the last non-whitespace character
        std::cout << "Last non-whitespace character is at position " << found << ": " << text[found] << std::endl;
    } else {
        // No non-whitespace character found
        std::cout << "No non-whitespace character found." << std::endl;
    }

    return 0;
}
In this example, find_last_not_of is used to find the position of the last character that is not a whitespace character (space, tab, newline, carriage return, form feed, or vertical tab). The result is the index of the last non-whitespace character in the string.


### Prompt 6
What is the meaning of using std::string::npos to find the same problem? What is that mean in C++? Do not give me code.

### Response 6
//ChatGPT
std::string::npos is a special constant value used in C++ when working with strings. It represents the largest possible value of the size_t type, which is an unsigned integer type used to represent sizes and positions in memory. In the context of string manipulation, std::string::npos is typically used to indicate that a specific element or position was not found.
When you use functions like find_first_not_of or find_last_not_of to search for characters within a string, they return the position of the character if found, and if the character is not found, they return std::string::npos. It's essentially a sentinel value indicating "not found."

### Prompt 7
Explain const std::string &str : vect

### Response 7

The expression const std::string &str : vect in the context of your code is a range-based for loop declaration. It is used to iterate through the elements of the vect vector, one element at a time, and for each iteration, it assigns the current element to the str variable.

Let's break down the components:

const std::string &str: This part declares a constant reference variable named str of type const std::string. The const keyword indicates that the str variable is read-only within the loop, meaning you can't modify the elements of the vector vect through this reference. It's a good practice to use const when you don't intend to modify the elements.

: (colon): The colon is used to separate the variable declaration (const std::string &str) from the container or sequence that you want to iterate over (vect).

vect: This is the container or sequence (in this case, a vector of strings) that you want to loop through. The range-based for loop will iterate through each element of this container one by one, and for each iteration, the current element will be assigned to the str variable.


### Changes 1
There are some mistakes, can u help me find where to fix? Just tell me what are they.
./src/StringUtils.cpp:93:19: warning: multi-character character constant [-Wmultichar]
   93 |         if (ch == '\\t') {
      |                   ^~~~~
./src/StringUtils.cpp: In function ‘std::string StringUtils::Upper(const std::string&)’:
./src/StringUtils.cpp:22:10: error: ‘transform’ is not a member of ‘std’
   22 |     std::transform(result.begin(), result.end(), result.begin(), ::toupper);
      |          ^~~~~~~~~
./src/StringUtils.cpp: In function ‘std::string StringUtils::Lower(const std::string&)’:
./src/StringUtils.cpp:28:10: error: ‘transform’ is not a member of ‘std’
   28 |     std::transform(result.begin(), result.end(), result.begin(), ::tolower);
      |          ^~~~~~~~~
./src/StringUtils.cpp: In function ‘std::string StringUtils::LJust(const std::string&, int, char)’:
./src/StringUtils.cpp:56:22: warning: comparison of integer expressions of different signedness: ‘std::__cxx11::basic_string<char>::size_type’ {aka ‘long unsigned int’} and ‘int’ [-Wsign-compare]
   56 |     if (str.length() >= width) return str;
      |         ~~~~~~~~~~~~~^~~~~~~~
./src/StringUtils.cpp: In function ‘std::string StringUtils::Replace(const std::string&, const std::string&, const std::string&)’:
./src/StringUtils.cpp:66:25: error: ‘width’ was not declared in this scope; did you mean ‘wcwidth’?
   66 |     if (str.length() >= width) return str;
      |                         ^~~~~
      |                         wcwidth
...

//AIGC:
std::transform is not a member of the std namespace:

This usually means a lack of inclusion. algorithm&gt;  The header file. Make sure to include this header file at the top of the file.
Modified: Add #include &lt at the top of StringUtils.h or StringUtils.cpp; algorithm&gt; .
'\\t' is a multi-character character constant:

In C++, a character constant should contain only one character. If you want to check tabs, use '\t' instead of '\\t'.
Modified: Change if (ch == '\\t') to if (ch == '\t').
Undeclared width and fill in the Replace function:

This looks like a logical error. The Replace function does not implement as expected.
Modification: You may need to re-implement this function to properly replace substrings in a string.
delim is not declared in the Split and Join functions:

Make sure you use the correct parameter names in these functions.
Modified: Use the correct parameter names in the Split and Join functions.
std::ostringstream Incomplete type:

This indicates that the corresponding header file is missing.
Modified: Add #include &lt at the top of the file; sstream&gt; .
Syntax errors with std::min:

When initializing a list with braces, use std::initializer_list. Alternatively, you can simply call std::min three times to compare the three values.
Modified: Replace std::min({a, b, c}) with the appropriate call, such as std::min(std::min(a, b), c).

Here are some of the modified code snippets:

Here are some of the modified code snippets:

cpp
#include &lt; algorithm&gt;  // Ensure that this header file is included
#include &lt; sstream&gt;    // For std::ostringstream

//... Other codes...

// Modified ExpandTabs function
std::string ExpandTabs(const std::string &str, int tabsize) noexcept {
std::string result;
for (char ch : str) {
if (ch == '\t') {// Use '\t' instead of '\\t'
result += std::string(tabsize, ' ');
} else {
result += ch;
}
}
return result;
}

// min call in the modified EditDistance function
int EditDistance(const std::string &left, const std::string &right, bool ignorecase) noexcept {
//... Other codes...
dp[i][j] = 1 + std::min(std::min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]);
//... Other codes...
}


### Changes 2
How to copy the input string at the begining of the C++ code?

//AIGC:
To copy the input string at the beginning of a C++ code, you can use the C++ std::string class to store the input string and then include it in your code as needed. Here's a simple example of how to do this:
#include <iostream>
#include <string>

int main() {
    // Get the input string from the user
    std::string input_string;
    std::cout << "Enter an input string: ";
    std::getline(std::cin, input_string);

    // Output the input string at the beginning of the code
    std::cout << "Input String: " << input_string << std::endl;

    // The rest of your C++ code goes here

    return 0;
}

This way, the input string is captured and used at the beginning of your C++ code.

### Changes 3
int EditDistance(const std::string &left, const std::string &right, bool ignorecase) noexcept{
    std::string l = ignorecase ? StringUtils::Lower(left) : left;
    std::string r = ignorecase ? StringUtils::Lower(right) : right;
    std::vector<std::vector<int>> dp(l.size() + 1, std::vector<int>(r.size() + 1));
    for (size_t i = 0; i <= l.size(); ++i) {
        for (size_t j = 0; j <= r.size(); ++j) {
            if (i == 0) dp[i][j] = j;
            else if (l[i - 1] == r[j - 1]) dp[i][j] = dp[i - 1][j - 1];
            else {
                dp[i][j] = 1 + std::min(dp[i - 1][j])
            }
        }
    }
    return dp[l.size()][r.size()];
}; How to revise the code?

//AIGC:
It looks like there is a minor issue with the provided code where it cuts off while attempting to calculate the edit distance. To correct the code and complete the calculation of the edit distance, you should replace the incomplete line with the following code:
dp[i][j] = 1 + std::min(std::min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]);

Here's the corrected code:
int EditDistance(const std::string &left, const std::string &right, bool ignorecase) noexcept {
    std::string l = ignorecase ? StringUtils::Lower(left) : left;
    std::string r = ignorecase ? StringUtils::Lower(right) : right;
    std::vector<std::vector<int>> dp(l.size() + 1, std::vector<int>(r.size() + 1));

    for (size_t i = 0; i <= l.size(); ++i) {
        for (size_t j = 0; j <= r.size(); ++j) {
            if (i == 0) dp[i][j] = j;
            else if (j == 0) dp[i][j] = i;
            else if (l[i - 1] == r[j - 1]) dp[i][j] = dp[i - 1][j - 1];
            else {
                dp[i][j] = 1 + std::min(std::min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]);
            }
        }
    }
    return dp[l.size()][r.size()];

With this change, the code should correctly calculate the edit distance between the left and right strings, considering the ignorecase option if needed.
