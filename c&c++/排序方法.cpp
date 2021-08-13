#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <algorithm> 
using namespace std;
#include<vector>

void selection_sort(vector<int> &nums, int n);//选择排序    
void bubble_sort(vector<int> &nums, int n) ;//冒泡排序
void merge_sort(vector<int> &nums, int l, int r, vector<int> &temp);//归并排序
void quick_sort(vector<int> &nums, int l, int r);//快速排序
void insertion_sort(vector<int> &nums, int n);//插入排序
void full_permutation(vector<int>&nums);//全排序
bool cmp(const vector<int>& a, const vector<int>& b)
{
 return a[1]<b[1];//按二维数组的第二列从小到大排
}

void sort() {
vector<int> nums = {1,3,5,7,2,6,4,8,9,2,8,7,6,0,3,5,9,4,1,0};
vector<int> temp(nums.size());
sort(nums.begin(), nums.end());
quick_sort(nums, 0, nums.size());
merge_sort(nums, 0, nums.size(), temp);
insertion_sort(nums, nums.size());
bubble_sort(nums, nums.size());
selection_sort(nums, nums.size());
full_permutation(nums);
vector<vector<int>>ans(5,vector<int>(2));
sort(ans.begin(),ans.end(),cmp);
}

void selection_sort(vector<int> &nums, int n) {
int mid;
    for (int i = 0; i < n - 1; ++i) {
     mid = i;
        for (int j = i + 1; j < n; ++j) {
            if (nums[j] < nums[mid]) {
            mid = j;
            } 
        }
    swap(nums[mid], nums[i]);
    } 
}


void bubble_sort(vector<int> &nums, int n) {
bool swapped;
    for (int i = 1; i < n; ++i) {
    swapped = false;
        for (int j = 1; j < n - i + 1; ++j) {
            if (nums[j] < nums[j-1]) {
            swap(nums[j], nums[j-1]);
            swapped = true; } 
            }
        if (!swapped) {break;}
    } 
}

void insertion_sort(vector<int> &nums, int n) {
for (int i = 0; i < n; ++i) {
    for (int j = i; j > 0 && nums[j] < nums[j-1]; --j) {
    swap(nums[j], nums[j-1]);
       } 
    }
}


void merge_sort(vector<int> &nums, int l, int r, vector<int> &temp) {
if (l + 1 >= r) {return;}
// divide
int m = l + (r - l) / 2;
merge_sort(nums, l, m, temp);
merge_sort(nums, m, r, temp);
// conquer
int p = l, q = m, i = l;
    while (p < m || q < r) {
        if (q >= r || (p < m && nums[p] <= nums[q])) {
        temp[i++] = nums[p++];
        } 
        else {
        temp[i++] = nums[q++];
        } 
    }
    for (i = l; i < r; ++i) {
    nums[i] = temp[i];
    } 
}

void quick_sort(vector<int> &nums, int l, int r) {
if (l + 1 >= r) {return;}
int first = l, last = r - 1, key = nums[first];
while (first < last){
    while(first < last && nums[last] >= key) {
    --last;
    }
    nums[first] = nums[last];
    while (first < last && nums[first] <= key) {
    ++first;
    }
    nums[last] = nums[first];
}
nums[first] = key;
quick_sort(nums, l, first);
quick_sort(nums, first + 1, r);
}

void full_permutation(vector<int>&nums){
   do{
   for (int i =0;i<nums.size();i++)printf("%d", nums[i]);

   }while(next_permutation(nums.begin(),nums.end()));
}