#ifndef MYCONTAINER_HPP
#define MYCONTAINER_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iterator>
#include <type_traits>

namespace Containers{

template<typename T = int>

class MyContainer
{
private:
    std::vector<T> elements;
public:
//forward declerations
class AscendingOrderIterator;
class DescendingOrderIterator;
class SideCrossOrderIterator;
class ReverseOrderIterator;
class OrderIterator;
class MiddleOutOrderIterator;



 void add(const T &element){
    elements.push_back(element);
 }

 void remove(const T &element){
    auto originalSize = elements.size();
    elements.erase(std::remove(elements.begin(),elements.end(),element),elements.end());
    if(elements.size() == originalSize){
        throw std::runtime_error("element dot found in container");
    }
 }

 size_t size()const{
    return elements.size();
 }

 friend std::ostream& operator<<(std::ostream &os,const MyContainer &container){
    os<<"[";
    for (size_t i = 0; i < container.elements.size(); i++)
    {
        os<<container.elements[i];
        if(i < container.elements.size()-1){
            os<<",";
        }
    }
    os<<"]";
    return os;
 }

AscendingOrderIterator beginAscendingOrder();
AscendingOrderIterator endAscendingOrder();

DescendingOrderIterator beginDescendingOrder();
DescendingOrderIterator endDescendingOrder();

SideCrossOrderIterator beginSideCrossOrder();
SideCrossOrderIterator endSideCrossOrder();

ReverseOrderIterator beginReverseOrder();
ReverseOrderIterator endReverseOrder();

OrderIterator beginOrderIterator();
OrderIterator endOrderIterator();

MiddleOutOrderIterator beginMiddleOutOrder();
MiddleOutOrderIterator endMiddleOutOrder();

class AscendingOrderIterator
{
private:
    std::vector<T> sorted_elements;
    int index;
public:
    AscendingOrderIterator(const std::vector<T> &elements, int index):index(index){
        sorted_elements = elements;
        std::sort(sorted_elements.begin(),sorted_elements.end());
    }
    
    T& operator*(){
        return sorted_elements[index];
    }
    AscendingOrderIterator& operator++(){
        index++;
        return *this;
    }

    bool operator!=(const AscendingOrderIterator &other)const{
        return index != other.index;
    }
        bool operator==(const AscendingOrderIterator &other)const{
        return index == other.index;
    }
};

class DescendingOrderIterator
{
private:
    std::vector<T> sorted_elements;
    int index;
public:
    DescendingOrderIterator(const std::vector<T> &elements, int index):index(index){
        sorted_elements = elements;
        std::sort(sorted_elements.begin(),sorted_elements.end());
        std::reverse(sorted_elements.begin(),sorted_elements.end());
    }
    
    T& operator*(){
        return sorted_elements[index];
    }
    DescendingOrderIterator& operator++(){
        index++;
        return *this;
    }

    bool operator!=(const DescendingOrderIterator &other)const{
        return index != other.index;
    }
        bool operator==(const DescendingOrderIterator &other)const{
        return index == other.index;
    }
};

class SideCrossOrderIterator
{
private:
    std::vector<T> ordered_elements;
    int index;
public:
    SideCrossOrderIterator(const std::vector<T> &elements, int index):index(index){
        std::vector<T> sorted_elements = elements;
         std::sort(sorted_elements.begin(),sorted_elements.end());

         int left = 0;
         int right = sorted_elements.size()-1;
         
         bool take_left =true;
         while (left<=right)
         {
            if(take_left){
                ordered_elements.push_back(sorted_elements[left]);
                left++;
            }
            else{
                ordered_elements.push_back(sorted_elements[right]);
                right--;
            }
            take_left = !take_left;
         }
         
    }

    T& operator*(){
        return ordered_elements[index];
    }
    SideCrossOrderIterator& operator++(){
        index++;
        return *this;
    }

    bool operator!=(const SideCrossOrderIterator &other)const{
        return index != other.index;
    }
        bool operator==(const SideCrossOrderIterator &other)const{
        return index == other.index;
    }

};

class ReverseOrderIterator
{
private:
    std::vector<T> elements;
    int index;
public:
    ReverseOrderIterator(const std::vector<T> elements, int index):elements(elements),index(index){}

    T& operator*(){
        return const_cast<T&>(elements[elements.size()-1-index]);
    }
    ReverseOrderIterator& operator++(){
        index++;
        return *this;
    }

    bool operator!=(const ReverseOrderIterator &other)const{
        return index != other.index;
    }
        bool operator==(const ReverseOrderIterator &other)const{
        return index == other.index;
    }

};

class OrderIterator
{
private:
    std::vector<T> elements;
    int index;
public:
    OrderIterator(const std::vector<T> elements, int index):elements(elements),index(index){}

    T& operator*(){
        return const_cast<T&>(elements[index]);
    }
    OrderIterator& operator++(){
        index++;
        return *this;
    }

    bool operator!=(const OrderIterator &other)const{
        return index != other.index;
    }
        bool operator==(const OrderIterator &other)const{
        return index == other.index;
    }
};

class MiddleOutOrderIterator
{
private:
    std::vector<T> ordered_elements;
    int index;
public:
    MiddleOutOrderIterator(const std::vector<T> elements, int index):index(index){
        if(elements.empty()){return;}

        int mid = elements.size()/2;
        ordered_elements.push_back(elements[mid]);

        int left = mid-1;
        int right = mid +1;
        bool take_left = true;

        while (left >= 0 || right<elements.size())
        {
            if(take_left && left >= 0){
            ordered_elements.push_back(elements[left]);
            left--;
            }
            else if(!take_left && right < elements.size()){
                 ordered_elements.push_back(elements[right]);
                 right++;
            }
            take_left = !take_left;
        }
    }

    T& operator*(){
        return ordered_elements[index];
    }
    MiddleOutOrderIterator& operator++(){
        index++;
        return *this;
    }

    bool operator!=(const MiddleOutOrderIterator &other)const{
        return index != other.index;
    }
        bool operator==(const MiddleOutOrderIterator &other)const{
        return index == other.index;
    }

    };
};

template <typename T>
typename MyContainer<T>::AscendingOrderIterator MyContainer<T>::beginAscendingOrder(){
    return AscendingOrderIterator(elements,0);
}

template <typename T>
typename MyContainer<T>::AscendingOrderIterator MyContainer<T>::endAscendingOrder(){
    return AscendingOrderIterator(elements,elements.size());
}

template <typename T>
typename MyContainer<T>::DescendingOrderIterator MyContainer<T>::beginDescendingOrder(){
    return DescendingOrderIterator(elements,0);
}

template <typename T>
typename MyContainer<T>::DescendingOrderIterator MyContainer<T>::endDescendingOrder(){
    return DescendingOrderIterator(elements,elements.size());
}

template <typename T>
typename MyContainer<T>::SideCrossOrderIterator MyContainer<T>::beginSideCrossOrder(){
    return SideCrossOrderIterator(elements,0);
}

template <typename T>
typename MyContainer<T>::SideCrossOrderIterator MyContainer<T>::endSideCrossOrder(){
    return SideCrossOrderIterator(elements,elements.size());
}

template <typename T>
typename MyContainer<T>::ReverseOrderIterator MyContainer<T>::beginReverseOrder(){
    return ReverseOrderIterator(elements,0);
}

template <typename T>
typename MyContainer<T>::ReverseOrderIterator MyContainer<T>::endReverseOrder(){
    return ReverseOrderIterator(elements,elements.size());
}

template <typename T>
typename MyContainer<T>::OrderIterator MyContainer<T>::beginOrderIterator(){
    return OrderIterator(elements,0);
}

template <typename T>
typename MyContainer<T>::OrderIterator MyContainer<T>::endOrderIterator(){
    return OrderIterator(elements,elements.size());
}

template <typename T>
typename MyContainer<T>::MiddleOutOrderIterator MyContainer<T>::beginMiddleOutOrder(){
    return MiddleOutOrderIterator(elements,0);
}

template <typename T>
typename MyContainer<T>::MiddleOutOrderIterator MyContainer<T>::endMiddleOutOrder(){
    return MiddleOutOrderIterator(elements,elements.size());
}

};

#endif