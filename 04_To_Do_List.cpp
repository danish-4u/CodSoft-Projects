#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<string> tasks;
    int choice;
    string task;

    do {
        cout << "\n1. Add Task\n2. View Tasks\n3. Delete Task\n4. Exit\nEnter choice: ";
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1:
                cout << "Enter task: ";
                getline(cin, task);
                tasks.push_back(task);
                break;
            case 2:
                cout << "\nYour Tasks:\n";
                for (int i = 0; i < tasks.size(); i++)
                    cout << i + 1 << ". " << tasks[i] << endl;
                break;
            case 3:
                int del;
                cout << "Enter task number to delete: ";
                cin >> del;
                if (del > 0 && del <= tasks.size())
                    tasks.erase(tasks.begin() + del - 1);
                else
                    cout << "Invalid task number.";
                break;
        }
    } while (choice != 4);
    return 0;
}
