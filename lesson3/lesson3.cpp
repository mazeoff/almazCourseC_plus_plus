#include <iostream>
#include <string>
#include <math.h>

using namespace std;

struct Link {
    int data;
    Link* next;
};

class List {
private:
    Link* current;
    Link* last;
    int countItemsOfList;
public:
    List() {
        current = nullptr;
        last = nullptr;
    }
    void addItemToEnd(int value);
    void addItemToBegin(int value);
    int getCountOfList();
    void put(int value, int num);
    void clear();
    void deleteFirst();
    void deleteLast();
    void deleteItem(int num);
    void deleteItemsBetween(int firstItem, int secondItem);
    void show();
};

void List::addItemToEnd(int value) {
    Link* newLink = new Link;
    newLink->data = value;
    newLink->next = last;
    current = newLink;
    last = newLink;
}

void List::addItemToBegin(int value) {
    if (current == nullptr) {
        addItemToEnd(value);
        return;
    }
    Link* newLink = new Link;
    Link* prev = current;

    while (prev->next) {
        prev = prev->next;
    }

    newLink->data = value;
    newLink->next = nullptr;
    prev->next = newLink;
    current = newLink;
}

void List::show() {
    Link* temp = last;
    while (temp) {
        cout << temp->data << endl;
        temp = temp->next;
    }

}

int List::getCountOfList() {
    Link* temp = last;
    int count = 0;
    while (temp) {
        count++;
        temp = temp->next;
    }
    return count;
}

void List::put(int value, int num) {
    countItemsOfList = getCountOfList();
    int currCount = countItemsOfList;
    if (countItemsOfList + 1 < num) {
        cout << "Error! Not enough items in the list!";
        exit(0);
    }

    if (num > currCount) {
        addItemToEnd(value);
        return;
    }


    Link* prev;
    Link* post;

    current = last;

    while (currCount != num) {
        current = current->next;
        currCount--;
    }
    prev = current;
    post = prev->next;

    Link* newLink = new Link;
    newLink->data = value;
    newLink->next = post;
    prev->next = newLink;
}

void List::clear() {
    Link* temp = last;
    while (temp != nullptr) {
        last = temp;
        temp = temp->next;
        delete last;
    }
}

void List::deleteFirst() {
    Link* temp = last;
    Link* prev = last;

    while (temp->next) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = nullptr;
    delete temp;
}

void List::deleteLast() {
    Link* temp = last;
    last = last->next;
    delete temp;
}

void List::deleteItem(int num) {
    countItemsOfList = getCountOfList();
    int currCount = countItemsOfList;
    if (countItemsOfList < num) {
        cout << "Error! Not enough items in the list!";
        exit(0);
    }

    Link* prev;
    Link* post;

    prev = last;

    while (currCount - 1 != num) {
        prev = prev->next;
        currCount--;
    }

    post = prev->next->next;
    delete prev->next;
    prev->next = post;
}

void List::deleteItemsBetween(int firstItem, int secondItem) {
    countItemsOfList = getCountOfList();
    int currCount = countItemsOfList;
    if (countItemsOfList < firstItem && countItemsOfList < secondItem) {
        cout << "Error! Not enough items in the list!";
        exit(0);
    }

    Link* prev;
    Link* post;

    prev = last;
    post = last;

    while (currCount - 1 != firstItem) {
        prev = prev->next;
        currCount--;
    }
    currCount = countItemsOfList;
    while (currCount + 1 != secondItem) {

        post = post->next;
        currCount--;
    }
    current = post->next;
    Link* temp = post->next;
    while (current->next != post) {
        temp = current;
        delete temp;
        current = current->next;
    }

    prev->next = post;
}

class FracNum {
private:
    int numerator, denominator;
public:
    FracNum(int m_numerator = 0, int m_denominator = 0) {
        setNumerator(m_numerator);
        setDenominator(m_denominator);
    }
    void setDenominator(int m_denominator) {
        denominator = m_denominator;
    }
    void setNumerator(int m_numerator) {
        numerator = m_numerator;
    }
    int getDenominator() {
        return denominator;
    }
    int getNumerator() {
        return numerator;
    }
    string show() {
        return to_string(numerator) + "/" + to_string(denominator);
    }

    FracNum operator+(FracNum op) {
        return FracNum(numerator * op.denominator + op.numerator * denominator,
            denominator * op.denominator);
    }
    FracNum operator*(FracNum op) {
        return FracNum(numerator * op.numerator,
            denominator * op.denominator);
    }
    FracNum operator-(FracNum op) {
        return FracNum(numerator * op.denominator - op.numerator * denominator,
            denominator * op.denominator);
    }
    FracNum operator/(FracNum op) {
        return FracNum(numerator * op.denominator,
            denominator * op.numerator);
    }

    bool operator==(FracNum op) {
        return numerator == op.numerator && denominator == op.denominator;
    }
    bool operator!=(FracNum op) {
        return !(numerator == op.numerator && denominator == op.denominator);
    }

    bool operator>(FracNum op) {
        int commonDenominator;
        commonDenominator = denominator * op.denominator;
        numerator *= op.denominator;
        op.numerator *= denominator;

        return numerator > op.numerator;
    }
    bool operator<(FracNum op) {
        int commonDenominator;
        commonDenominator = denominator * op.denominator;
        numerator *= op.denominator;
        op.numerator *= denominator;

        return numerator < op.numerator;
    }

    bool operator>=(FracNum op) {
        int commonDenominator;
        commonDenominator = denominator * op.denominator;
        numerator *= op.denominator;
        op.numerator *= denominator;

        return numerator >= op.numerator;
    }
    bool operator<=(FracNum op) {
        int commonDenominator;
        commonDenominator = denominator * op.denominator;
        numerator *= op.denominator;
        op.numerator *= denominator;

        return numerator <= op.numerator;
    }

    void operator+=(FracNum op) {
        numerator = numerator * op.denominator + op.numerator * denominator;
        denominator = denominator * op.denominator;
    }
    void operator-=(FracNum op) {
        numerator = numerator * op.denominator - op.numerator * denominator;
        denominator = denominator * op.denominator;
    }
    void operator*=(FracNum op) {
        numerator = numerator * op.numerator;
        denominator = denominator * op.denominator;
    }
    void operator/=(FracNum op) {
        numerator = numerator * op.denominator;
        denominator = denominator * op.numerator;
    }

};

int main()
{
    FracNum a;
    FracNum b;
    FracNum c;

    a.setNumerator(3);
    a.setDenominator(4);

    b.setNumerator(5);
    b.setDenominator(6);
    a *= b;
   // cout << a.show();
   
//////////////////////////second task///////////////////////////////////////////

    List list;
    list.addItemToBegin(3);
    list.addItemToBegin(4);
    list.addItemToBegin(5);
    list.addItemToBegin(6);
    list.addItemToBegin(7);
    /*list.addItemToEnd(3);
    list.addItemToEnd(4);
    list.addItemToEnd(5);
    list.addItemToEnd(6);
    list.addItemToEnd(7);*/
    //list.put(88,6);
    //list.deleteItem(6);
    list.deleteItemsBetween(1, 5);
    list.show();
   // cout << "Count of list: " + to_string(list.getCountOfList());
}
