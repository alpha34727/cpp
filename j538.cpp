#include <iostream>
#include <string>

using namespace std;

int main()
{
    string items, original;
    int item_counts[26] = {};
    int place_counts[26] = {};
    
    cin >> items >> original;

    for (int i = 0; i < items.length(); i++){
        if ('a' <= items[i] && items[i] <= 'z'){
            item_counts[(int)(items[i] - 'a')] += original[i] - '0';
            place_counts[(int)(items[i] - 'a')]++;
        }
        else if ('A' <= items[i] && items[i] <= 'Z'){
            item_counts[(int)(items[i] - 'A')] += original[i] - '0';
            place_counts[(int)(items[i] - 'A')]++;
        }
    }

    int item_index;
    for (int i = 0; i < items.length(); i++){
        if ('a' <= items[i] && items[i] <= 'z'){
            item_index = (int)(items[i] - 'a');
        }
        else if ('A' <= items[i] && items[i] <= 'Z'){
            item_index = (int)(items[i] - 'A');
        }

        cout << item_counts[item_index] / place_counts[item_index];
        item_counts[item_index] -= item_counts[item_index] / place_counts[item_index];
        place_counts[item_index]--;
    }
    cout << endl;

    return 0;
}
