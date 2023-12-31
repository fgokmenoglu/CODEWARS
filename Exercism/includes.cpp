/*
INTRODUCTION
In general, you don't want to reinvent the wheel when it comes to programming. 
For many standard algorithms, there will be someone who might have already done your work for you.

INCLUDE DIRECTIVE
To include the content of other files C++ uses the include directive. 
These includes should be stated at the top of the file. 
During compilation, the line with the directive is replaced by the content of the respective file. 
Namespaces are kept as they are in the original file after includes.

THE STANDARD LIBRARY
The standard library offers many common functions, algorithms, and data structures. The standard library uses the std namespace.
One example is the C numerics library cmath. It provides many common mathematical operations.

NOTES
Standard libraries are included with angled braces <> instead of double quotes ". 
The difference is the location, where the compiler searches for the respective files. 
The search in the current project is skipped for the angled braces version, and it directly starts in the system's include directories. 
If you want to include local files you would use double quotes
*/

/*
  Task 1: Implement the log_line::message method to return a log line's message.
  Task 2: Implement the log_line::log_level method to return a log line's log level, which should be returned in uppercase.
  Task 3: Implement the log_line::reformat method that reformats the log line, putting the message first and the log level after it in parentheses.
*/
#include <string>

namespace log_line {
    std::string message(std::string logLine) {
        // find the position of whitespace just before the message
        size_t pos = logLine.find(" ");
        // return the log message that is from 'pos + 1' to the end of a log line
        return logLine.substr(pos + 1);
    }
    std::string log_level(std::string logLine) {
        // find the position of ']' enclosing the log level information
        size_t pos = logLine.find("]");
        // return the log level that starts at index 1 and has length 'pos - 1' 
        return logLine.substr(1, pos - 1);
    }
    std::string reformat(std::string logLine) {
        // Get the log message and the log level from the corresponding methods
        std::string messagePart = message(logLine);
        std::string levelPart = log_level(logLine);
        // Return the reformatted log line 
        return messagePart + " (" + levelPart + ")";
    }
} // namespace log_line
