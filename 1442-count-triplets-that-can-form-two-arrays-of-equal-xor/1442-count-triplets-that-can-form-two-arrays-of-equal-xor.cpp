class Solution {
public:
    int countTriplets(vector<int>& arr) {
        vector<int> left(arr.size() - 1);
        vector<int> right(arr.size() - 1);

        int k = arr.size()-1;
        int j = k;
        int i = 0;

        int x = 0;

        for(int l=i; l<j; l++){
            x ^= arr[l];
            left[l] = x;
        }

        x = 0;

        j = 1;
        for(int l=k; l>=j; l--){
            x ^= arr[l];
            right[l-1] = x;
        }

        int ans = 0;
        x = 0;

        while(k > 0){
            int y=0;
            i=0;
            while(i < k){

                for(int l=i; l<k; l++){
                    if((right[l]^x) == (left[l]^y)){
                        ans++;
                    }
                }


                y^=arr[i];
                i++;
            }

            x^=arr[k];
            k--;
        }












        // x = 0;

        // while(k >= 1){

        //     for(int l=i; l<=k-1; l++){
        //         if(left[l] == (right[l] ^ x)) {
        //             ans++;
        //             cout << left[l] << " " << (right[l] ^ x) << " " << k << endl;
        //         }
        //     }

        //     x ^= arr[k];
        //     k--;
        // }

        // k = arr.size() - 1;
        // x = arr[i];
        // i++;

        // while(i < k){

        //     for(int l=i; l<=k-1; l++){
        //         if(right[l] == (left[l] ^ x)) {
        //             ans++;
        //             cout << left[l] << " " << (right[l] ^ x) << " " << k << endl;
        //         }
        //     }

        //     x ^= arr[i];
        //     i++;
        // }

        // k--;
        // i = 1;

        // while(k >= 1){

        //     i=0;
        //     int y = 0;

        //     while(i < k){

        //         for(int l=i; l<=k-1; l++){
        //             if((right[l] ^ y) == (left[l] ^ x)) {
        //                 ans++;
        //                 // cout << (left[l]^x) << " " << (right[l] ^ y) << " " << l << " " << k << endl;
        //             }
        //         }

        //         y ^= arr[i];
        //         i++;
        //     }

        //     x ^= arr[k];
        //     k--;
        // }

        return ans;
    }
};