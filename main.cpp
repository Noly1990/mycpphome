#include <iostream>
#include <vector>

using namespace std;
int main()
{
    vector<int> v1;
    
    for (int i=0;i<10;i++) {
        v1.push_back(i);
    }
    for (auto i = v1.begin();i!=v1.end();i++) {
        cout << "element v1 ===>" << *i << endl;
    }

    auto it1 = v1.begin();
    it1 = it1 +2;

    auto it2 = v1.end();
    it2 -=2;

    std::cout << "distance : " << distance(it1, it2) << * --v1.end() << std::endl;

    system("pause");

    return 0;
}