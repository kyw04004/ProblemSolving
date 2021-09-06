#include <string>
#include <vector>
#include <iostream>

using namespace std;

string first_step(string id) {
    string new_id = "";
    for (int i = 0; i < id.size(); i++) {
        if (65 <= id[i] && id[i] <= 90) id[i] += 32;
        new_id += id[i];
    }
    cout << new_id << '\n';
    return new_id;
}

string second_step(string id) {
    string new_id = "";
    for (int i = 0; i < id.size(); i++) {
        if (97 <= id[i] && id[i] <= 122) new_id += id[i];
        else if (0 <= id[i] - '0' && id[i] - '0' <= 9) new_id += id[i];
        else if (id[i] == '-' || id[i] == '_' || id[i] == '.') new_id += id[i];
    }
    cout << new_id << '\n';
    return new_id;
}

string third_step(string id) {
    string new_id = "";
    for (int i = 0; i < id.size(); i++) {
        if (new_id[new_id.size() - 1] == '.' && id[i] == '.') continue;
        else new_id += id[i];
    }
    cout << new_id << '\n';
    return new_id;
}

string four_step(string id) {
    string new_id = "";
    for (int i = 0; i < id.size(); i++) {
        if (new_id.size() == 0 && id[i] == '.') continue;
        else new_id += id[i];
    }

    while (new_id[new_id.size() - 1] == '.') new_id.pop_back();
    cout << new_id << '\n';
    return new_id;
}

string five_step(string id) {
    if (id.size() == 0) return "a";
    else return id;
}

string six_step(string id) {
    string new_id = "";
    if (id.size() >= 16)
        for (int i = 0; i < 15; i++)
            new_id += id[i];
    else new_id = id;
    while (new_id[new_id.size() - 1] == '.') new_id.pop_back();
    cout << new_id << '\n';
    return new_id;
}

string seven_step(string id) {
    string new_id = id;
    while (new_id.size() <= 2) new_id += id[id.size() - 1];
    cout << new_id << '\n';
    return new_id;
}

string solution(string new_id) {
    new_id = first_step(new_id);
    new_id = second_step(new_id);
    new_id = third_step(new_id);
    new_id = four_step(new_id);
    new_id = five_step(new_id);
    new_id = six_step(new_id);
    new_id = seven_step(new_id);
    return new_id;
}