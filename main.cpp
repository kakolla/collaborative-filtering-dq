#include <vector>
#include <iostream>

using namespace std;

int recurse(vector<int>& arr, int l, int r);


int main()
{
    // O(nlogn), T(n) = 2T(n/2) + O(n)
    // given a main user and secondary user's preferences, return the number of inversions (conflicts)
    // conflict - ai, ak, i < k in user1, but it is ak, ai in user2

    vector<int> u1 = {1, 2, 3, 4, 5, 6}; // first always sorted

    vector<int> u2 = {3, 2, 6, 1, 4, 5};
    // (ans) # of inversions: 2+1+3 = 6

    vector<int> u3 = {1, 4, 3, 6, 2, 5};  // should be 5 inversions


    int inversions = recurse(u2, 0, u2.size() - 1);
    int inversions2 = recurse(u3, 0, u3.size() -1);
    cout << "Number of user2's inversions: " << inversions << endl;
    cout << "Number of user3's inversions: " << inversions2 << endl;
    

    return 0;
}

int recurse(vector<int>& arr, int l, int r)
{
    if (l == r)
    {
        // [3] - 0 inversions
        return 0;
    }
    if (r - l == 1)
    {
        // i.e. [3, 5] - not an inversion
        // [5, 3] -- inversion
        if (arr[l] > arr[r])
        {
            int temp = arr[l];
            // sort
            arr[l] = arr[r];
            arr[r] = temp;
            return 1;
        }
        else
        {
            return 0;
        }
    }

    int m = (l + r) / 2;
    int left_inversions = recurse(arr, l, m);
    int right_inversions = recurse(arr, m + 1, r);

    // combining step -- inversions across the middle
    int i = l; // left arr
    int j = m+1; // right arr

    vector<int> combined;
    int middle_inversions = 0;
    
    while (i <= m && j <= r)    
    {
        if (arr[i] < arr[j])
        {
            combined.push_back(arr[i]);
            i++;
        }
        else
        {
            combined.push_back(arr[j]);
            j++;
            // inversion
            middle_inversions += m-i +1; // how many elems are in left half
            // if arr[i] > arr[j]
            // all items right of arr[i] will also be in inversion since sorted
        }
    }

    // stitch remaining
    if (i <= m) {
        for (int d = i; d < m+1; ++d) {
            combined.push_back(arr[d]);
        }
    }
    else if (j <= r) {
        for (int d = j; d < r+1; ++d) {
            combined.push_back(arr[d]);
        }
    }

    // make arr sorted using combined
    int t = 0;
    if (combined.size() != r-l +1) {
        cout << "combined arr size is not the length of r-l" << endl;
        return -1;
    }
    for (int z = l; z <= r; ++z) {
        arr[z] = combined[t];
        t++; 
    }



    int total_inversions = left_inversions + right_inversions + middle_inversions;

    return total_inversions;
}
