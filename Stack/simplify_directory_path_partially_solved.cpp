https://www.interviewbit.com/problems/simplify-directory-path/

Given an absolute path for a file (Unix-style), simplify it.

Examples:

path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"


APPROACH:More of a simulation problem.
Break the string along ‘/’ and process the substrings in order one by one. ‘..’ indicates popping an entry unless there is nothing to pop.

SOLUTION(Not correct): Works only for characters as path variables, doesn't work for string values in b/w the '/'s.
string Solution::simplifyPath(string A) {
    deque<char> out;
    string res;
    for(int i=0; i<A.size(); i++)
    {
        //cout << "i= " <<i << " and A[i] = " << A[i] <<endl;

        if(A[i] == '/' && A[i+1] == '.' && A[i+2] == '.')
        {
            i+=2;
            if (!out.empty())
            {
                out.pop_back();
                //cout << "popped\n";
            }
        }
        else if(A[i]=='/' && A[i+1]=='.')
        {
            i++;
        }
        else
        {
            if(A[i] != '/')
            {
                out.push_back(A[i]);
                //cout << "pushed\n";
            }
        }

    }

    while(!out.empty())
    {
        /*while(out.front() == '/')
        {
            out.pop_front();
        }*/
        //cout << "out.front() is: " << out.front() <<endl;
        //cout <<  "size of dque is: " << out.size() << endl;
        //if(!out.empty())
        //{   
            res += '/';
            res += out.front();

            out.pop_front();
        //}
    }
    return res;
}
