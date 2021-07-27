class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        //method1 : O(N)
        // int n=arr.size();
        // int lmax[n];
        // int rmin[n+1];
        // lmax[0]=arr[0];
        // for(int i = 1;i<n;i++){
        //     lmax[i]=max(arr[i],lmax[i-1]);
        // }
        // rmin[n]=INT_MAX;
        // for(int i = n-1;i>=0;i--){
        //     rmin[i]=min(arr[i],rmin[i+1]);
        // }
        // int c=0;
        // for(int i=0;i<n;i++){
        //     if(lmax[i]<=rmin[i+1]){
        //         c++;
        //     }
        // }
        // return c;
        //method2 : O(N*N)
        multiset<int> idealarr;
        multiset<int> actualarr;
        vector<int> ideal(arr.begin(),arr.end());
        sort(ideal.begin(),ideal.end());
        int c=0;
        for(int i=0;i<arr.size();i++){ //n times
            actualarr.insert(arr[i]);
            idealarr.insert(ideal[i]);
            if(idealarr==actualarr){ //baar baar check : O(N)
                c++;
            }
            
        }
        return c;
    }
};
