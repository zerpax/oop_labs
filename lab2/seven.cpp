#include <iostream>
#include <algorithm>
#include "seven.h"

using namespace std;


Seven::Seven(const size_t & n, const unsigned char t = 48){
    size = n;
    value = new unsigned char[n];
    fill(value, value + n, t);
}

Seven::Seven(const initializer_list< unsigned char>&t) {
    size = t.size();
    value = new unsigned char[size];
    int i = 0;
    for (unsigned char a : t) {
        *(value + size - i - 1) = a;
        i++;
    }
}

Seven::Seven(const string &t) {
    size = t.size();
    value = new unsigned char[size];
    for (int i = 0; i < size; i++) {
        value[size - i - 1] = t[i];
    }
}

Seven::Seven(const Seven& other) {
    size = other.size;
    value = new unsigned char[size];
    for (int i = 0; i < size; i++) {
        value[i] = other.value[i];
    }
}
    
Seven::Seven(Seven&& other) noexcept {
    size = other.size;
    value = other.value;

    other.size = 0;
    other.value = unullptr;
}

Seven::~Seven() {
    delete value;
    value = nullptr;
}


unsigned char* Seven::Value() {
    unsigned char* value = new unsigned char[this->size];
    for (int i = 0; i < size / 2; i++) {
        unsigned char temp = value[i];
        value[i] = value[size - i - 1];
        value[size - i - 1] = temp;
    }
    return value;
}

int Seven::Size() {
    return size;
}

void Seven::Print() {
    for (int i = size-1; i >= 0; i--) {
        cout << value[i];
    }
    cout << '\n';
}

     

Seven Seven::Plus(const Seven &b) {
    size = max(this->size, b.size);
    if (this->size == b.size && this->value[this->size - 1] - 48 + b.value[b.size - 1] - 48 >= 7) {
        size++;
    }
    Seven res(size);
    int carryover = 0;
    for (int i = 0; i < res.size; i++) {
             
        int sum = (this->value[i] - 48 + b.value[i] - 48) + carryover;
        res.value[i] = sum % 7 + 48;
        carryover = sum / 7;
    }
    if (res.size > this->size && res.size > b.size) {
        res.value[res.size - 1] = carryover;
    }
    return res;
}

Seven Seven::Minus(const Seven& b) {
    int size = this->size;
    Seven res(size);
    for (int i = 0; i < size; i++) {
        if (i < b.size) {
            res.value[i] += this->value[i] - b.value[i];
        }
        else {
            res.value[i] += this->value[i] - 48;
        }
        if (res.value[i] < 48) {
            res.value[i] += 7;
            try {
                if (i + 1 >= size) {
                    throw out_of_range("the result is a negative number");
                }
                else {
                    res.value[i + 1] -= 1;
                }
            }
            catch(const out_of_range& exp) {
                res.size = 1;
                res.value[0] = '0';
            }
        }
    }
    for (int i = res.size-1; i >= 0; i--) {
        //cout << int(res.value[i]) << int('0') << ' ';
        if (res.value[i] == 48) {
            res.size--;
        }
        else { 
            break;
        }
    }
    return res;
}

Seven Seven::Copy(const Seven& b) {
    size = b.size;
    value = new unsigned char[size];
    for (int i = 0; i < size; i++) {
        value[i] = b.value[i];
    }
    return *this;
}

bool Seven::Equals(const Seven& b) {
    if (this->size == b.size) {
        for (int i = this->size - 1; i >= 0; i--) {
            if (this->value[i] != b.value[i]) {
                return false;
            }
        }
    }
    else {
        return false;
    }
    return true;
}

bool Seven::Greater(const Seven& b) {
    if (this->size == b.size) {
        for (int i = this->size - 1; i >= 0; i--) {
            bool flag = true;
            if (this->value[i] > b.value[i]) {
                return true;
            }
            else if (this->value[i] < b.value[i]) {
                return false;
            }
        }
    }
    else if(this->size>b.size){
        return true;
    }
    else {
        return false;
    }
}

bool Seven::Less(const Seven& b) {
    return !(this->Greater(b));
}


