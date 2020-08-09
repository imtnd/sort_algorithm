#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0; i<(n); i++)
#define REP2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long INF = numeric_limits<long long>::max();


template<std::size_t SIZE_L, std::size_t SIZE_R>
void merge(std::array<int, SIZE_L> *ar_l, std::array<int, SIZE_R> *ar_r, std::array<int, SIZE_L + SIZE_R> *ar){
    int i = 0;
    int j = 0;

    std::array<int, SIZE_L + SIZE_R> result = {};
    int k = 0;

    while(i < SIZE_L && j < SIZE_R){
        if(ar_l->at(i) < ar_r->at(j)){
            result.at(k) = ar_l->at(i);
            i++;
        } else {
            result.at(k) = ar_r->at(j);
            j++;
        }
        k++;
    }
    if(i < SIZE_L){
        result.at(k) = ar_l->at(i);
        k++;
    }
    if(j < SIZE_R){
        result.at(k) = ar_r->at(j);
        k++;
    }

    std::copy(result.begin(), result.begin() + SIZE_L + SIZE_R, ar->begin());
    return;
}

/**
 * Merge sort
 * Worst complexity: n^log(n)
 * Average complexity: n^log(n)
 * Best complexity: n^log(n)
 * Space complexity: n
 **/
template<std::size_t SIZE>
void merge_sort(std::array<int, SIZE> *ar){
    std::array<int, SIZE/2> left;
    std::array<int, SIZE- SIZE/2> right;
    
    if(SIZE <= 1){
        return;
    }

    std::copy(ar->begin(), ar->begin() + SIZE/2, left.begin());
    std::copy(ar->begin() + SIZE/2, ar->begin() + SIZE, right.begin());

    if(left.size() < right.size()){
        merge_sort(&left);
        merge_sort(&right);
    }
    merge(&left, &right, ar);

}

/**
 * Selection sort
 * Worst complexity: n^2
 * Average complexity: n^2
 * Best complexity: n^2
 * Space complexity: 1
 **/
template<std::size_t SIZE>
void selection_sort(std::array<int, SIZE> *ar){
    for(int i = 0; i < ar->size(); i++){
        int *min = &(ar->at(i));
        for(int j = i + 1; j < ar->size(); j++){
            if(*min > ar->at(j)){
               min = &(ar->at(j));
            }
        }
        std::swap(*min, ar->at(i));
    }
    return;
}

/**
 * Bubble sort
 * Worst complexity: n^2
 * Average complexity: n^2
 * Best complexity: n
 * Space complexity: 1
 **/
template<std::size_t SIZE>
void bubble_sort(std::array<int, SIZE> *ar){
    for(int i = 0; i < ar->size() ; i++) {
        for(std::size_t j = ar->size() - 1; j > i ; j--) {
            if (ar->at(j) < ar->at(j-1)){
                std::swap(ar->at(j), ar->at(j-1));
            }
        }
    }
    return;
}

int main()
{
    std::array<int, 5> ar = {5, 3, 2, 1, 4};

    //bubble_sort(&ar);
    //selection_sort(&ar);
    merge_sort(&ar);

    for (int i : ar){
        std::cout << i << ", ";
    }
    std::cout << std::endl;

    return 0;
}

