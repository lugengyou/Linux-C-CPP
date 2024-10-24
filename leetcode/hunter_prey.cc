#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <algorithm>

using namespace std;


bool canKill(string& skills, string& weaknesses) {
    // 需要确定技能是否全覆盖弱点
	unordered_set<char> skill_set(skills.begin(), skills.end());	
	unordered_set<char> weakness_set(weaknesses.begin(), weaknesses.end());

	// if (skill_set.size() < weakness_set.size()) {
	// 	return false;
	// }

	// 判断猎人有无 A-F 的技能
	bool hasAF = false;
	for (char c : skill_set) {
		if (c >= 'A' && c <= 'F') {
			hasAF = true;
			break;
		}
	}
	if (!hasAF) {
		return false;
	}

    // 技能要能覆盖所有弱点
    for (char c : weakness_set) {
        if (skill_set.find(c) == skill_set.end()) {
            return false;
        }
    }

    // 猎人最后一个技能需要至少命中猎物的任意一个弱点
    return weakness_set.find(skills.back()) != weakness_set.end();
}

int main() {

	int hunter_count = 0;
	int prey_count = 0;
	cin >> hunter_count >> prey_count;

	// 技能输入
	vector<string> hunters(hunter_count);
	for (int i = 0; i < hunter_count; ++i) {
		cin >> hunters[i];
	}	
	
	// 类物输入
	/*vector<string> preys(prey_count);
	for (int i = 0; i < prey_count; ++i) {
		cin >> preys[i];
	}*/
	// 每种类物的数量无限，应该要去重
	set<string> preys;
	for (int i = 0; i < prey_count; ++i) {
		string tmp;
		cin >> tmp;
		if (preys.count(tmp)) {
			continue;
		}
		preys.insert(tmp);
	}

	// 判断每个类人能射杀的猎物种类
	vector<int> result(hunter_count, 0);
	for (int i = 0; i < hunter_count; ++i) {
		for (auto prey : preys) {
			if (canKill(hunters[i], prey)) {
				result[i]++;
			}
		}
	}

	// 输出结果
	for (int i = 0; i < hunter_count - 1; ++i) {
		cout << result[i] << " ";
	}
	cout << result[hunter_count - 1] << endl;

	return 0;
}

/*
测试样例一：
3 5
028F415A 2340789E 043BCD12
0222F44A 44C 8848A 002B2 F4415CA
输出：2 0 1

测试样例二：
2 3
7519FCB0 01234567
25351727 A0 19C00
输出：1 0

测试样例三：
3 3
0278AB5C 12307ABC 043BCD1A
ABC0 0ABC 4ABC0
输出：2 2 3
*/

