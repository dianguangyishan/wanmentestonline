#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    int result = 0;
    int temp = 0;
    vector<int>::iterator iter;
    cin >> N;
    int *a = new int[N];
    int i = 0;
    while(i < N)
        cin >> a[i++];
    vector<int> hep(a, a + N);
    /*for(vector<int>::iterator iter=hep.begin();iter!=hep.end();++iter)
        cout<<*iter<<" "<<endl;*/
    make_heap(hep.begin(), hep.end(),greater<int>());//build heap;

    while(hep.size() != 1)
    {
        pop_heap(hep.begin(), hep.end());
        iter = hep.end() - 1;
        cout << *iter <<endl;
        temp = *iter;
        hep.pop_back();
        //for(iter=hep.begin();iter!=hep.end();++iter)
        //    cout<<*iter<<" 1"<<endl;
        pop_heap(hep.begin(), hep.end());
        iter = hep.end() - 1;
        cout << *iter <<endl;
        temp += *iter;
        hep.pop_back();
        //for(iter=hep.begin();iter!=hep.end();++iter)
        //    cout<<*iter<<" 2"<<endl;
        result += temp;
        cout << "temp ="<<temp<<endl;
        hep.push_back(temp);
        push_heap(hep.begin(), hep.end());
        //for(iter=hep.begin();iter!=hep.end();++iter)
        //    cout<<*iter<<" 3"<<endl;
    }
    cout << result << endl;

    /*for(i = 0;i < N;i++)
        cout << a[i] << endl;
    */
}
