#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    
    cout << "Enter a string: ";
    string input;
    getline(cin,input);
 
    string reversedString{};
    vector<string> modified_input{};

    for (size_t i{input.size()-2}; i<-1 ; --i)
        reversedString.push_back(input.at(i));     
    
    modified_input.push_back(input += reversedString);

    while (input.size() > 1)
        modified_input.push_back(input.erase((input.size()/2),2));
    
    string space{};
    for (size_t i{1}; i < modified_input.size(); ++i) {
        space += " ";
        modified_input.at(i).insert(0, space);
    }

    for (size_t i{modified_input.size()-1}; i < -1; --i)
       cout << modified_input.at(i) << endl;

    return 0;
}


/*
Which C++ loop(s) did you use and why?

How did you handle displaying the leading spaces in each row of the pyramid?

Now that you completed the assignment, how might approach the problem differently if you had to solve it again?
*/