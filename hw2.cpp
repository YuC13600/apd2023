#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main(void) {
    int l, w;
    scanf("%d %d%*c", &l, &w);
    const int img_size = l*w;
    int *arr = (int*)malloc(img_size * sizeof(int));
    for(int i=0; i<img_size; ++i) {
        cin >> arr[i];
    }
    int countarr[256]={0};
    for(int i=0; i<img_size; ++i)
        countarr[arr[i]]++;
    int peak_point(0), peak_point_index(0);
    for(int i=0; i<256; ++i)
        if(countarr[i]>peak_point) {
            peak_point=countarr[i];
            peak_point_index = i;
        }
    int lzero_index(-1), rzero_index(-1);
    for(int i=peak_point_index+1; i<256; ++i) {
        if(countarr[i]==0) {
            rzero_index = i;
            break;
        }
    }
    for(int i=peak_point_index-1; i>=0; --i) {
        if(countarr[i]==0) {
            lzero_index = i;
            break;
        }
    }
    int zp(-1);
    if(lzero_index != -1 && rzero_index != -1) {
        if(rzero_index-peak_point_index >= peak_point_index-lzero_index)
            zp=lzero_index;
        else
            zp=rzero_index;
    }
    else if(lzero_index != -1) {
        zp = lzero_index;
    }
    else if(rzero_index != -1) {
        zp = rzero_index;
    }
    cout << peak_point << endl << zp;
    return 0;

}