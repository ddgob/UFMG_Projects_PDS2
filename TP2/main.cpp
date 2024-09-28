#include <iostream>

int main() {

    int even[20];
    int odd[20];
    int x;
    int countOdd = 0;
    int countEven = 0;
    while (std::cin >> x) {
        if(x % 2 == 0) {
            int evenDuplicates = 0;
            for(int i = 0; i < countEven; i++) {
                if(x == even[i]) {
                    evenDuplicates++;
                }
            }
            if(evenDuplicates == 0) {
                even[countEven] = x;
                countEven++;
            }
        }else {
            int oddDuplicates = 0;
            for(int i = 0; i < countOdd; i++) {
                if(x == odd[i]) {
                    oddDuplicates++;
                }
            }
            if(oddDuplicates == 0) {
                odd[countOdd] = x;
                countOdd++;
            }
        }
    }
    for(int i = 0; i < countEven; i++) {
        std::cout << even[i] << " ";
    }
    std::cout << std::endl << std::endl;
    for(int i = 0; i < countOdd; i++) {
        std::cout << odd[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
