// class Solution {
// public:
//     int reverse(int n){
//         int m = 0;

//         while(n != 0){
//             m = m *10 + n%10;
//             n = n/10;
//         }class Solution {
// public:
//     int reverse(int n){
//         int m = 0;

//         while(n != 0){
//             m = m *10 + n%10;
//             n = n/10;
//         }

//         return m;
//     }
//     int compareVersion(string v1, string v2) {

//         int i=v1.size();
//         int j=v2.size();

//         while(i>=0 && j>=0){
//             int n = 0;
//             int k = i;
//             int l = j;
//             while(i>=0 && v1[i] != '.'){
//                 cout << v1[1] - '0';
//                 n = n * 10 + (v1[i] - '0');
//                 i--;
//             }

//             int m = 0;
//             while(j>=0 &&v2[j] != '.'){
//                 m = m * 10 + (v2[j] - '0');
//                 j--;
//             }

//             if(m==0)

//             n = reverse(n);
//             m = reverse(m);
//             // cout << m << " " << n << endl;
//             i--;
//             j--;

//             if(n==0 && m!=0){
//                 j = l;
//                 continue;
//             }
//             if(m==0 && n!=0){
//                 i = k;
//                 continue;
//             }

//             if(n > m) return 1;
//             if(n < m) return -1;
            
//         }

//         if(i < j) return -1;
//         if(i > j) return 1;
//         return 0;

//     }
// };

//         return m;
//     }
//     int compareVersion(string v1, string v2) {

//         int i=v1.size();
//         int j=v2.size();

//         while(i>=0 && j>=0){
//             int n = 0;
//             int k = i;
//             int l = j;
//             while(i>=0 && v1[i] != '.'){
//                 cout << v1[1] - '0';
//                 n = n * 10 + (v1[i] - '0');
//                 i--;
//             }

//             int m = 0;
//             while(j>=0 &&v2[j] != '.'){
//                 m = m * 10 + (v2[j] - '0');
//                 j--;
//             }

//             if(m==0)

//             n = reverse(n);
//             m = reverse(m);
//             // cout << m << " " << n << endl;
//             i--;
//             j--;

//             if(n==0 && m!=0){
//                 j = l;
//                 continue;
//             }
//             if(m==0 && n!=0){
//                 i = k;
//                 continue;
//             }

//             if(n > m) return 1;
//             if(n < m) return -1;
            
//         }

//         if(i < j) return -1;
//         if(i > j) return 1;
//         return 0;

//     }
// };



class Solution {
public:
    static int compareVersion(string& v1, string& v2) {
        const int n1=v1.size(), n2=v2.size();
        int x1=0, x2=0;
        for(int i=0, j=0; i<n1 || j<n2; i++, j++){
            while(i<n1 && v1[i]!='.'){
                x1=10*x1+(v1[i++]-'0');
            }
            while(j<n2 && v2[j]!='.'){
                x2=10*x2+(v2[j++]-'0');
            }
            if (x1<x2) return -1;
            else if (x1>x2) return 1;
            x1=0;
            x2=0;
        }
        return 0;
    }
};

