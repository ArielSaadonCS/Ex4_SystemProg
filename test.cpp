#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "MyContainer.hpp"

using namespace Containers;

TEST_CASE("basic operations"){
    MyContainer<int> container;

    SUBCASE("empty"){
        CHECK(container.size()==0);
    }

    SUBCASE("add and remove elements"){
    container.add(5);
    container.add(10);
    container.add(7);
    CHECK(container.size()==3);
    container.remove(5);
    CHECK(container.size()==2);
    }

    SUBCASE("remove unexisting element"){
        container.add(5);
        CHECK_THROWS_AS(container.remove(99),std::runtime_error);
    }

    SUBCASE("remove duplicate elements"){//should remove all duplicate
    container.add(5);
    container.add(10);    
    container.add(10);
    container.remove(10);
    CHECK(container.size()==1);
    }
}

TEST_CASE("output operator"){
    MyContainer<int> container;
    container.add(1);
    container.add(2);    
    container.add(3);

    std::ostringstream os;
    os<<container;
    CHECK(os.str() == "[1,2,3]");

}

TEST_CASE("test order iterators"){
    MyContainer<int> container;
    container.add(1);
    container.add(15);    
    container.add(2);
    container.add(7);
    container.add(6);

    SUBCASE("Order Iterator"){
    std::vector<int> expected = {1,15,2,7,6};
    std::vector<int> result;

    for(auto it = container.beginOrderIterator(); it != container.endOrderIterator(); ++it){
        result.push_back(*it);
    }
    CHECK(result == expected); 
    }    

    SUBCASE("Reverse order"){
    std::vector<int> expected = {6,7,2,15,1};
    std::vector<int> result;

    for(auto it = container.beginReverseOrder(); it != container.endReverseOrder(); ++it){
        result.push_back(*it);
    }
    CHECK(result == expected); 
    }
    
    SUBCASE("ascesndig order iterator"){
    std::vector<int> expected = {1,2,6,7,15};
    std::vector<int> result;

    for(auto it = container.beginAscendingOrder(); it != container.endAscendingOrder(); ++it){
        result.push_back(*it);
    }
    CHECK(result == expected);
}

    SUBCASE("Descending order"){
    std::vector<int> expected = {15,7,6,2,1};
    std::vector<int> result;

    for(auto it = container.beginDescendingOrder(); it != container.endDescendingOrder(); ++it){
        result.push_back(*it);
    }
    CHECK(result == expected);
    }

    SUBCASE("side cross order"){
    std::vector<int> expected = {1, 15, 2, 7, 6};
    std::vector<int> result;

    for(auto it = container.beginSideCrossOrder(); it != container.endSideCrossOrder(); ++it){
        result.push_back(*it);
    }
    CHECK(result == expected);
    }

    SUBCASE("middle out order"){
    std::vector<int> expected = {2, 15, 7, 1, 6};
    std::vector<int> result;

    for(auto it = container.beginMiddleOutOrder(); it != container.endMiddleOutOrder(); ++it){
        result.push_back(*it);
    }
    CHECK(result == expected);
    }

}

TEST_CASE("other types"){
    MyContainer<std::string> container;
    container.add("hello");
    container.add("bye");
    container.add("apple");

    std::vector<std::string> expected = {"apple","bye","hello"};
    std::vector<std::string> result;
    for(auto it = container.beginAscendingOrder(); it != container.endAscendingOrder(); ++it){
        result.push_back(*it);
    }
    CHECK(result == expected);
}

