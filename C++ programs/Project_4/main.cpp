#include <iostream>
#include <vector>

using namespace std;

void welcome_prompt();
char take_answer();
void print(const vector<int> list);
void add_to_list(vector<int> &list);
void find_the_mean(const vector<int> list);
void find_the_smallest(const vector<int> list);
void find_the_largest(const vector<int> list);
void repeated_intances_in(const vector<int> list);
void clean(vector<int> &list);
void quit(bool &flag);

int main() {
    bool flag{false};
    vector<int> vec{};

    do {

        welcome_prompt();

        char answer {take_answer()};

        if (answer == 'P' || answer == 'p')
            print(vec);
        else if (answer == 'A' || answer == 'a')
            add_to_list(vec);
        else if (answer == 'M' || answer == 'm') 
            find_the_mean(vec);
        else if (answer == 'S' || answer == 's') 
            find_the_smallest(vec);
        else if (answer == 'L' || answer == 'l') 
            find_the_largest(vec);
        else if (answer == 'F' || answer == 'f')
            repeated_intances_in(vec);
        else if (answer == 'C' || answer == 'c') 
            clean(vec);
        else if (answer == 'Q' || answer == 'q')
            quit(flag);
        else 
            cout << "Unknown selection, please try again" << endl;
        
    
    } while(flag != true);
    return 0;
}

void welcome_prompt(){
    cout << "\nP - Print numbers" << endl;
    cout << "A - Add a number" << endl;
    cout << "M - Display mean of the numbers" << endl;
    cout << "S - Display the smallest number" << endl;
    cout << "L - Display the largest number" << endl;
    cout << "F - Find intances of a number" << endl;
    cout << "C - Clan list" << endl;
    cout << "Q - Quit\n" << endl;
}

char take_answer(){
    char answer{};
    cout << "Enter your choice: ";
    cin >> answer;
    return answer;
}

void print(const vector<int> list){
    cout << "[ ";
    for (auto num : list)
        cout << num << " ";
    cout << "]" << endl;
}

void add_to_list(vector<int> &list){
    int newValue{};
    cout << "Enter an integer to add to the list: ";
    cin >> newValue; 
    list.push_back(newValue);
    cout << newValue <<" Value added" << endl;
}

void find_the_mean(const vector<int> list){
    if (!list.empty()) {
        double mean{};
        for (auto num : list)
            mean+= num;
        cout << "The mean is: " << (mean/list.size()) << endl;
    }else{cout << "Unable to calculate the mean - no data" << endl;}
}

void find_the_smallest(const vector<int> list){
    if (!list.empty()) {
        int smallest{list.at(0)};
        for (auto num : list)
            if (num < smallest) smallest = num;
        cout << smallest << " is the smallest number in the list" << endl;
    } else {cout << "Unable to determine the smallest number - list is empty" << endl;}
}

void find_the_largest(const vector<int> list){
    if (!list.empty()) {
        int largest{list.at(0)};
        for (auto num : list)
            if (num > largest) largest = num;
        cout << largest << " is the largest number in the list" << endl;
    } else {cout << "Unable to determine the largest number - list is empty" << endl;}
}

void repeated_intances_in(const vector<int> list){
    if (!list.empty()){
        size_t ocurrences{};
        int search{};
        cout << "Which value you want to find: ";
        cin >> search;
        for (auto num : list)
            if (search == num) ++ocurrences;
        cout << "There is " << ocurrences << " instances of " << search << " in the list" << endl;
    } else {cout << "Unable to determine any instances - list is empty" << endl;}
}

void clean(vector<int> &list){
    list.clear();
    cout << "List Cleaned!" << endl;
}

void quit(bool &flag){
    flag = true;
    cout << "Goodbye!" << endl;
}