#include  "GraphM.h"
#include <vector>
int main(){
    vector< vector<char> > list{{'a', 'b'}, {'a', 'c'}, {'a', 'e'}, {'b', 'a'}, {'b', 'd'}, {'c', 'a'}, {'c', 'd'}, {'d', 'b'}, {'d', 'c'}, {'d', 'e'}, {'e', 'a'}, {'e', 'd'}};
    /* list.push_back({'a', 'b'});
    list.push_back({'a', 'c'});
    list.push_back({'a', 'e'});
    list.push_back({'b', 'a'});
    list.push_back({'b', 'd'});
    list.push_back({'c', 'a'});
    list.push_back({'c', 'd'});
    list.push_back({'d', 'b'});
    list.push_back({'d', 'c'});
    list.push_back({'d', 'e'});
    list.push_back({'e', 'a'});
    list.push_back({'e', 'd'}); */
    GraphM<char> graphM(list, 5, 12);
    graphM.print();

    /* vector< vector<char> > list1 = { {'a', 'b'},
                                   {'a', 'c'},
                                   {'b', 'c'},
                                   {'d', 'a'},
                                   {'d', 'b'},
                                   {'d', 'c'} }; */ 
    return 0;
}