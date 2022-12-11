//
//  main.cpp
//  Median of Two Sorted Arrays
//
//  Created by Артём Lazemir on 10.12.2022.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double medianThree(int a, int b, int c) {
        if ((a > b) ^ (a > c))
            return a;
        else if ((b < a) ^ (b < c))
            return b;
        else
            return c;
    }

    double medianFour(int a, int b, int c, int d) {
        int Max = max(a, max(b, max(c, d)));
        int Min = min(a, min(b, min(c, d)));
        return (a + b + c + d - Max - Min) / 2.0;
    }

    double findMedian(vector<int>::iterator beg, vector<int>::iterator end) {
        size_t n = end - beg;
        if (n % 2 == 0) return (beg[n/2 - 1] + beg[n/2]) / 2.0;
        return *(beg + n/2);
    }

    double findMedianSortedArrays(vector<int>::iterator beg1, vector<int>::iterator end1, vector<int>::iterator beg2, vector<int>::iterator end2) {

        size_t size1 = end1 - beg1;
        size_t size2 = end2 - beg2;

        if (size1 > size2) {
            swap(size1, size2);
            swap(beg1, beg2);
            swap(end1, end2);
        }

        double m1 = findMedian(beg1, end1);
        double m2 = findMedian(beg2, end2);

        if (size1 == 1) {
            if (size2 == 1) {
                return (*beg1 + *beg2) / 2.0;
            }
            if (size2 % 2 == 0) {
                return medianThree(*beg1, beg2[size2 / 2], beg2[size2 / 2 - 1]);
            } else {
                return medianFour(*beg1, beg2[size2 / 2 + 1], beg2[size2 / 2], beg2[size2 / 2 - 1]);
            }
        }

        if (size1 == 2) {
            if (size2 == 2) {
                return medianFour(beg1[0], beg1[1], beg2[0], beg2[1]);
            }
            if (size2 % 2 == 0) {
                return medianFour(max(beg1[1], beg2[size2/2 - 2]), min(beg1[0], beg2[size2/2 + 1]), beg2[size2/2 - 1], beg2[size2/2]);
            } else {
                return medianThree(max(beg1[1], beg2[size2/2 - 1]), min(beg1[0], beg2[size2/2 + 1]), beg2[size2/2]);
            }
        }

        vector<int>::iterator new_beg1, new_end1, new_beg2, new_end2;
        size_t del_counter = (size1 - 1) / 2;
        if (m1 < m2 ) {
            new_beg1 = beg1 + del_counter;
            new_end1 = end1;
            new_beg2 = beg2;
            new_end2 = end2 - del_counter;
        } else {
            new_beg1 = beg1;
            new_end1 = end1 - del_counter;
            new_beg2 = beg2 + del_counter;
            new_end2 = end2;
        }

        return findMedianSortedArrays(new_beg1, new_end1, new_beg2, new_end2);
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() >= 1 && nums2.size() >= 1) {
            return findMedianSortedArrays(nums1.begin(), nums1.end(), nums2.begin(), nums2.end());
        }

        if (nums1.size() == 0) return findMedian(nums2.begin(), nums2.end());
        return findMedian(nums1.begin(), nums1.end());

    }
};

int main(int argc, const char * argv[]) {
    Solution sol;

    vector<int> vec1 = {0, 0, 0, 0, 0};
    vector<int> vec2 = {-1,0,0,0,0,0,1};
    std::cout << sol.findMedianSortedArrays(vec1, vec2) << std::endl;

    return 0;
}
