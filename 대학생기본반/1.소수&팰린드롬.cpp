#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool is_palindrom(int n) {
    string s = to_string(n);
    int length = s.length();
    for(int i = 0 ; i < length / 2; i++) {
        
        if(s[i] != s[length - i - 1]) {
            return false;
        }
    }
    
    return true;
}

vector<int> get_primes() {
    int mat[1003001];
    vector<int> primes;
    for(int i = 1; i <= 1003001; i++) {
        mat[i] = i;
    }

    for(int i = 2; i <= 1003001; i++) {
        if(mat[i] == 0) {
            continue;
        }

        primes.push_back(i);

        for(int j = i + i; j <= 1003001; j+= i) {
            mat[j] = 0;
        }
    }

    return primes;
}

int main(void) {
    
    int n;
    vector< int > primes = get_primes();

    cin >> n;

    for(int i = 0; i < primes.size(); i++) {
        if(primes[i] >= n && is_palindrom(primes[i])) {
                cout << primes[i] << endl;
                return 0;
        }
    }
}