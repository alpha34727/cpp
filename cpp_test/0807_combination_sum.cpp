#include <iostream>
#include <vector>

using namespace std;

int n, target, Sum, answer_count;
vector<int> candidates;
vector<int> trials;

void print_trials(){
    for (int i = 0; i < trials.size(); i++){
        cout << candidates[trials[i]];
        if (i != trials.size()){
            cout << " ";
        }
    }
    cout << endl;
}

void calc(int st = 0){       
    for (int i = st; i < n; i++){
        trials.push_back(i);
        Sum += candidates[trials.back()];

        // print_trials();

        if (Sum >= target){
            if (Sum == target){
                print_trials();
                answer_count++;
            }

            if (trials.size() >= 1){
                Sum -= candidates[trials.back()];
                trials.pop_back();
            }
            break;
        }
        else{
            calc(i);
        }
        
        if (trials.size() >= 1){
            Sum -= candidates[trials.back()];
            trials.pop_back();
        }
    }
}

int main(){
    while (cin >> n && n != 0){
        candidates.clear();
        trials.clear();
        candidates.resize(n);
        Sum = 0;
        answer_count = 0;

        for (int i = 0; i < n; i++){
            cin >> candidates[i];
        }
        cin >> target;

        calc();

        if (answer_count == 0){
            cout << "No Combination" << endl;
        }

        cout << endl;
    }

    return 0;
}