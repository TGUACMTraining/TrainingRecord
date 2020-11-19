//https://www.luogu.com.cn/problem/P1303

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
using namespace std;

class BigNum {
    vector<int> numArray;
    int pointPos = 0;

   public:
    BigNum(string numString) {
        try {
            changeToNumArray(numString);
        } catch (invalid_argument err) {
            cout << err.what() << endl;
        }
    }

    const BigNum operator*(const BigNum& rhs) {
        int lhsLength = this->size();
        int rhsLength = rhs.size();
        BigNum back("0");
        for (int i = 0; i < lhsLength; i++) {
            for (int j = 0; j < rhsLength; j++) {
                try {
                    back.setBit(i + j, this->getBit(i) * rhs.getBit(j) + back.getBit(i + j));
                } catch (invalid_argument err) {
                    cout << err.what() << endl;
                    cout << "pos = " << i + j << " value = "
                         << this->getBit(i) * rhs.getBit(j) + back.getBit(i + j) << endl;
                }
            }
        }
        back.removeZero();
        return back;
    }

   private:
    void changeToNumArray(string numString) {
        int length = numString.size();
        while (length--) {
            char c = numString.at(length);
            if (c >= '0' && c <= '9')
                numArray.push_back(c - '0');
            else if (c == '.')
                pointPos = numString.size() - 1 - length;
            else {
                throw invalid_argument("creat BigNum is failed, string is valid");
            }
        }
    }

    void setBit(int pos, int value) {
        if (value < 0) {
            throw invalid_argument("setBit is failed, value is negative!");
        }

        int tail = numArray.size() - 1;

        while (pos > tail) {
            numArray.push_back(0);
            tail++;
        }

        if (value > 9) {
            try {
                setBit(pos + 1, value / 10 + this->getBit(pos + 1));
            } catch (range_error err) {
                cout << err.what() << endl;
            }
            value = value % 10;
        }

        numArray[pos] = value;
    }

    int getBit(int pos) const {
        if (pos < 0)
            throw range_error("pos is invalid!");

        if (pos >= numArray.size())
            return 0;

        return numArray[pos];
    }

    int size() const {
        return numArray.size();
    }

    void removeZero() {
        while (numArray.size() && !numArray.at(numArray.size() - 1)) {
            numArray.erase(numArray.end() - 1);
        }

        if(!numArray.size())
            numArray.push_back(0);
    }

   public:
    string toString() const {
        string back;
        int length = numArray.size();

        if (length == 0)
            throw runtime_error("No num");

        while (length--) {
            back.push_back(numArray.at(length) + '0');
        }
        if (pointPos)
            back.insert(back.end() - pointPos, '.');

        return back;
    }
};

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include "Bignum.hpp"
using namespace std;

int main() {
    string numString;
    cin >> numString;
    BigNum num1(numString);
    cin >> numString;
    BigNum num2(numString);
    try {
        cout << (num1 * num2).toString() << '\n';
    } catch (runtime_error err) {
        cout << err.what() << endl;
    }
    return 0;
}
