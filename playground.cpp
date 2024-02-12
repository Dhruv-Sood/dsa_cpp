#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector <int> v;
    vector<int>* vp = new vector<int>;

    v.push_back(5);
    v.push_back(5);
    v.push_back(5);
    v.push_back(5);
    v.push_back(5);

    // v[20] = 80;
    cout<<v.capacity();
    cout<<endl<<endl;
    return 0;
}