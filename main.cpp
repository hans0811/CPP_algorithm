#include <iostream>
#include <cstring>
#include <iomanip>
#include <vector>

using namespace std;

long long fac(int n){
    if(n==0 || n==1){
        return 1;
    }
    else
        return n*fac(n-1);
}

long long fib(int n){
    if(n < 1){
        return -1;
    }

    if(n==0 || n ==1){
        return 1;
    }

    return fib(n-1)+fib(n-2);

}

long double fib_forloop(int n){
    long double temp;
    if(n < 1){
        return -1;
    }

    long double *a = new long double[n+1];
    a[1]=1;
    a[2]=1;
    for(int i=3; i <= n; i++){
        a[i] = a[i-1] + a[i-2];
        cout << a[i] <<endl;
    }

    temp=a[n];
    delete a;

    return temp;
}

void swap(int &x, int &y){
    int temp;
    temp = x;
    x=y;
    y=temp;
    cout << "swap " << x << " and " <<  y << endl;
}

int sum(int n){
    if(n==1){
        return 1;
    }
    else
        return n + sum(n-1);

}



int main() {
//    int n;
//    long long s;
//    cin >> n;
//    s=fib(n);
//    cout<<s<<endl;

//    int x = 5, y= 10;
//    swap(x,y);
//    cout << "result-> swap " << x << " and " <<  y << endl;

    int n,x,y,total;
    n=4;

    int **a = new int*[n];
    for(int i=0; i < n; i++){
        a[i]=new int[n];
        memset(a[i],0,n*sizeof(int));
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<setw(5)<<a[i][j];
        }
        cout<<endl;
    }

    cout<<endl;

    x=0;
    y=0;
    total=1;
    a[0][0]=1;

    while(total < n*n){
        while( y+1 < n &&! a[x][y+1]){
            a[x][++y]=++total;
        }
        while( x+1 < n &&! a[x+1][y]){
            a[++x][y]=++total;
        }
        while( y-1 >= 0 &&! a[x][y-1]){
            a[x][--y]=++total;
        }
        while( x-1 >=0 &&! a[x-1][y]){
            a[--x][y]=++total;
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<setw(5)<<a[i][j];
        }
        cout<<endl;
    }

    for(int i=0; i < n; i++){
        delete[] a[i];
    }
    delete[] a;

    cout << fib_forloop(12) << endl;

    // check Palindrome
    string text = "TACOCAT";
    bool palindrome = true;

    for(int g=0; g < (text.length()-1)/2; g++){
        if(text[g] != text[(text.length()-1) - g]){
            palindrome = false;
            break;
        }
    }

    if(palindrome)
    {
        cout << "this string is a Palindrome" << endl;
    }
    else
    {
        cout << "this string is NOT a Palindrome" << endl;
    }

    int arr[] = {2, 3, 6, 8};
    int sum = 5;
    int arrSize = (sizeof(arr)/sizeof(arr[0]));
    int index = 0;
    int num1 = arr[index];

    while(index <= arrSize && num1 < sum){
        int i = index + 1;
        while(i < arrSize && ((sum-num1) >= arr[i])){
            if(num1 + arr[i] == sum){
                cout << num1 << " " << arr[i] << endl;
                i = arrSize;
            }else{
                i++;
            }
        }
        index++;
        num1 = arr[index];
    }

    int arr1[] = {9, 9, 9};
    int arrSize1 = (sizeof(arr1)/sizeof(arr1[0])) - 1;
    vector <int> result;
    int carry = 1;
    int sumHolder = 0;
    for(int i=arrSize1; i >= 0; i--){
        sumHolder = arr1[i] + carry;
        if (sumHolder >= 10){
            result.push_back(sumHolder % 10);
            carry = 1;
        }else{
            result.push_back(sumHolder);
            carry=0;
        }
    }

    if (carry == 1){
        result.push_back(carry);
        carry = 0;
    }

    for(int j = result.size() - 1; j >= 0; j--){
        cout << result.at(j);
    }
    return 0;
}
