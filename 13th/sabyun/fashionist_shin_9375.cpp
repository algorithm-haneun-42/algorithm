#include <iostream>
#include <map>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
int total;
using namespace std;
void printMap(const map<string, int>& myMap) {
	int i;
	int num = 0;
	i = 0;
    for (auto it = myMap.begin(); it != myMap.end(); ++it) {
        //cout << "Key: " << it->first << ", Value: " << it->second << '\n';
		if(it ==myMap.begin())
			num = it->second;
		else
			num*= it->second;
		i++;
    }
	//cout << "i =" <<i<<'\n';
	if (i == 1)
		num *=0;
	total +=num;
	cout << total << '\n';

}
int main() {
				map<string, int> dress;
				ios_base::sync_with_stdio(0);
				cin.tie(0);
				int get =0;
				int num = 0;
				string type;
				string name;
				cin >> get;
				for(int j = get ;j>0;j--)
				{
								cin >> num;
								for (int i = num; i>0 ;i--)
								{
												total = num;
												cin >>name >> type;
												auto key = dress.find(type);
												if(key ==dress.end())
													dress.insert({type,1});
												else
												{
													int cost = dress[type];
													dress.erase(type);
													dress.insert({type,++cost});
												}
								}
								printMap(dress);
								dress.clear();
								total = 0;
				}
				return 0;
}
