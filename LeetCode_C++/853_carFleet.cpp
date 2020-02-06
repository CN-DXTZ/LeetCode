#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;
struct Car
{
	int rest;
	double time;
	Car(int r, double t) { rest = r; time = t; }
};
bool cmp(Car x, Car y)
{
	return x.rest > y.rest;
}
class Solution
{
public:
	int carFleet(int target, vector<int>& position, vector<int>& speed)
	{
		int num = position.size();
		vector<Car> cars;
		int rest;
		double time;
		for (int i = 0; i < num; i++)
		{
			rest = target - position[i];
			time = (double)rest / (double)speed[i];
			cars.push_back(Car(rest, time));
		}
		sort(cars.begin(), cars.end(), cmp);

		list<double> tList;
		list<double>::iterator it;
		for (int i = 0; i < num; i++)
		{
			it = tList.begin();
			while (it != tList.end())
			{
				auto tmep = it++;
				if ((*tmep - cars[i].time) < 1e-6)
					tList.erase(tmep);
			}
			tList.push_back(cars[i].time);
		}
		return tList.size();
	}
} s;
int main()
{
	vector<int> a1 = { 10,8,0,5,3 };
	vector<int> b1 = { 2,4,1,1,3 };
	cout << s.carFleet(12, a1, b1) << endl;
	vector<int> a2 = { 0,4,2 };
	vector<int> b2 = { 2,1,3 };
	cout << s.carFleet(10, a2, b2) << endl;
	system("pause");
	return 0;
}