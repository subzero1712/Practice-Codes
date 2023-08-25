#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int zero = 0, one = 0, two = 0, three = 0, four = 0, five = 0, six = 0, seven = 0, eight = 0, nine = 0;
    char str[10];
    scanf("%s", str);
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == '0') {
            zero++;
        }
        if (str[i] == '1') {
            one++;
        }
        if (str[i] == '2') {
            two++;
        }
        if (str[i] == '3') {
            three++;
        }
        if (str[i] == '4') {
            four++;
        }
        if (str[i] == '5') {
            five++;
        }
        if (str[i] == '6') {
            six++;
        }
        if (str[i] == '7') {
            seven++;
        }
        if (str[i] == '8') {
            eight++;
        }
        if (str[i] == '9') {
            nine++;
        }
    }
    printf("0: %d\n1: %d\n2: %d\n3: %d\n4: %d\n5: %d\n6: %d\n7: %d\n8: %d\n9: %d\n",
           zero, one, two, three, four, five, six, seven, eight, nine);

    return 0;
}
