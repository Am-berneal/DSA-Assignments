#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int countStudents(vector<int>& students, vector<int>& sandwiches) {
    queue<int> q;
    for (int s : students)
        q.push(s);

    int index = 0;           // index for sandwich stack
    int rotations = 0;       // how many students were rotated without success

    while (!q.empty()) {
        if (q.front() == sandwiches[index]) {
            q.pop();
            index++;
            rotations = 0;   // reset because a match was found
        } 
        else {
            q.push(q.front());
            q.pop();
            rotations++;
        }

        // If rotated all students and no one wants the sandwich at stack top, break
        if (rotations == q.size())
            break;
    }

    return q.size(); // students left who cannot eat
}

int main() {
    vector<int> students = {1, 1, 0, 0};
    vector<int> sandwiches = {0, 1, 0, 1};

    cout << countStudents(students, sandwiches);

    return 0;
}
