#include <iostream>
#include <string>
#include <vector>
#include <sstream>

class Solution {
public:
    std::string simplifyPath(std::string path) {
        std::vector<std::string> stack;
        std::stringstream ss(path);
        std::string token;
        
        // Split by '/'
        while (std::getline(ss, token, '/')) {
            if (token == "" || token == ".") {
                continue; // Skip empty tokens caused by consecutive slashes or current dir
            } else if (token == "..") {
                if (!stack.empty()) {
                    stack.pop_back(); // Go up one directory level
                }
            } else {
                stack.push_back(token); // Valid file/directory name
            }
        }
        
        // Build the simplified canonical path
        std::string result = "";
        for (const std::string& dir : stack) {
            result += "/" + dir;
        }
        
        return result.empty() ? "/" : result;
    }
};