#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> v = { 1, 2, 3, 4, 5 };

	v.clear();
	v.shrink_to_fit();

	cout << "The vector size is " << v.size() << " and its "
			  << "capacity is " << v.capacity();

    v.push_back(1);
    v.push_back(2);

    cout << v[0] << endl << v[1] << endl;

	return 0;
}