#include <iostream>
#include "MyContainer.hpp"

using namespace Containers;
int main(){
    MyContainer<int> container;
    container.add(5);
    container.add(10);
    container.add(7);
    container.add(3);
    container.add(16);

    std::cout<<"original container : " << container << std::endl;
    std::cout<<"original container size : " << container.size() << std::endl;

    std::cout << "AScednding order\n";

    for(auto it = container.beginAscendingOrder(); it != container.endAscendingOrder(); ++it){
        std::cout<< *it << " ";
    }
    std::cout<<std::endl;

    std::cout << "Descending order\n";

    for(auto it = container.beginDescendingOrder(); it != container.endDescendingOrder(); ++it){
        std::cout<< *it << " ";
    }
    std::cout<<std::endl;

    std::cout << "SideCross order\n";

    for(auto it = container.beginSideCrossOrder(); it != container.endSideCrossOrder(); ++it){
        std::cout<< *it << " ";
    }
    std::cout<<std::endl;

    std::cout << "Reverse order\n";

    for(auto it = container.beginReverseOrder(); it != container.endReverseOrder(); ++it){
        std::cout<< *it << " ";
    }
    std::cout<<std::endl;

    std::cout << "regular order\n";

    for(auto it = container.beginOrderIterator(); it != container.endOrderIterator(); ++it){
        std::cout<< *it << " ";
    }
    std::cout<<std::endl;

    std::cout << "MiddleOut order\n";

    for(auto it = container.beginMiddleOutOrder(); it != container.endMiddleOutOrder(); ++it){
        std::cout<< *it << " ";
    }
    std::cout<<std::endl;

    std::cout << "\nremoving element 10" << std::endl;
    container.remove(10);
    std::cout<<"container after remove : "<<container<<std::endl;



}