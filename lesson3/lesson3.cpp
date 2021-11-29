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
public:
    List() {
        current = nullptr;
    }
    void addItemToEnd(int value);
    void addItemToBegin(int value);
    int getCountOfList();
    void putTo(int value, int num);
    void show();
};

void List::addItemToEnd(int value) {
    Link* newLink = new Link;
    newLink->data = value;
    newLink->next = current;
    current = newLink;
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
}

void List::show() {
    Link* temp = current;
    while (temp) {
        cout << temp->data << endl;
        temp = temp->next;
    }

}

int List::getCountOfList() {
    Link* temp = current;
    int count = 0;
    while (temp) {
        count++;
        temp = temp->next;
    }
    return count;
}

void List::putTo(int value, int num) {
    int currCount = 0;
    int count = getCountOfList();
    if (count < num) {
        cout << "Error! Not enough items in the list!";
        return;
    }

    Link* prev = current;
    Link* post = current;

    while (count - currCount != num) {
        prev = prev->next;
        currCount++;
    }
    post = prev->next;

    Link* newLink = new Link;
    newLink->data = value;
    newLink->next = post;
    prev->next = newLink;
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
    /*list.addItemToBegin(3);
    list.addItemToBegin(4);
    list.addItemToBegin(5);
    list.addItemToBegin(6);
    list.addItemToBegin(7);*/
    list.addItemToEnd(3);
    list.addItemToEnd(4);
    list.addItemToEnd(5);
    list.addItemToEnd(6);
    list.addItemToEnd(7);
    list.putTo(88,2);
    list.show();
   // cout << "Count of list: " + to_string(list.getCountOfList());
}
