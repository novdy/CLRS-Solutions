#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int inverse_factorial(vector<unsigned long long> v);
 
int main() {
    vector<unsigned long long> bigTime;

    for (unsigned long long i = 1; i < 1000; i++){
        bigTime.push_back(i);
        cout << i << " " << inverse_factorial(bigTime) << endl;
        bigTime.pop_back();
    }

    return 0;
}

int inverse_factorial(vector<unsigned long long> v){
    vector<int> remaining_divisors;
    int divisor = 1;
    bool been_divided;
    bool answer_is_exact;

    while (true){
        been_divided = false;
        answer_is_exact = true;

        //There's a lot of stuff that can be moved into this for loop
        unsigned int i;
        for(i = 0; i < v.size(); i++){
            if(v[i] % divisor == 0 && !been_divided){
                v[i] = v[i] / divisor;
                been_divided = true;
            }
            if(v[i] != 1){
                answer_is_exact = false;
                if(been_divided){
                    break;
                }
            }
        }

        if(answer_is_exact){
            return divisor;
        }

        if(!been_divided){
            remaining_divisors.push_back(divisor);
            unsigned long long reduced_product = 1;
            unsigned long long remaining_product = 1;

            for(unsigned long long x : v){
                reduced_product *= x;
            }
            for(int x : remaining_divisors){
                remaining_product *= x;
            }
            
            if (reduced_product <= remaining_product/remaining_divisors.back()){
                return remaining_divisors.back() - 1;
            }

            if (reduced_product <= remaining_product){
                return remaining_divisors.back();
            }
        }

        divisor++;
    }
}