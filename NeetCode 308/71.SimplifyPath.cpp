class Solution {
public:
/*
    Problem:
        Given a string path, which is an absolute path (starting with a slash '/') to a file or directory in a Unix-style file system, convert it to the simplified canonical path.
        In a Unix-style file system, a period '.' refers to the current directory, a double period '..' refers to the directory up a level, and any multiple consecutive slashes (i.e.
        '//') are treated as a single slash '/'. For this problem, any other format of periods such as '...' are treated as file/directory names.
        The canonical path should have the following format:The path starts with a single slash '/'.Any two directories are separated by a single slash '/'.
        The path does not end with a trailing '/'.
        The path only contains the directories on the path from the root directory to the target file or directory (i.e., no period '.' or double period '..')
        Return the simplified canonical path.


-----------------------------------------------------------------------------------------------------------
    Approach:
        1. We will be using a stack for this problem in order to backtrack throughout the algorithmn,
            our stack will contain strings of the names of the file directories in between each of the 
            slashes
        2. We will iterate through the path, if we encounter a "/" just continue to the next iteration, 
            this is because we want to fill our stack with directory names in between slashes, but not the
            slashes themselves
        3. Create a temp string variable, and continue iterating and adding each char to temp
            until you reach a slash, now we have the current directory name
        4. if temp is = a ".", then just skip to the next iteration, if temp = "..", this means that 
            we have to go back a level in directory names, so we pop from the stack, if temp is neither of 
            these then we have a valid directory name and we can push it onto the stack
        5. After iterating, this is where we will add the slashes, while the stack if not empty keep adding 
            "/" + st.top() + result to the result string variable that we will be returning
-----------------------------------------------------------------------------------------------------------
*/
    string simplifyPath(string path) {
        
        //declare variables
        stack<string> st;
        string res = "";

        //implement stack algorithmn
        for(int i = 0; i < path.length(); i++) {

            //skip iterating if we find a slash
            if(path[i] == '/') {
                continue;
            }

            //store current directory name in a temp variable
            string temp = "";
            while(i < path.length() && path[i] != '/') {
                temp += path[i];
                i++;
            }

            //3 cases for what we do with temp

            //case 1: skip iteration
            if(temp == "."){
                continue;

            //case 2: pop from stack
            } else if ( temp == ".." ){

                if(!st.empty()) {
                    st.pop();
                }

            //case 3: push onto stack
            } else {
                st.push(temp);
            }
        }

        //create the full directory name string
        while(!st.empty()) {

            res = "/" + st.top() + res;
            st.pop();
        }

        //edge case
        if (res.size() == 0) {
            return "/";
        }

        return res;
        
    }
};
