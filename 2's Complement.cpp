#include <bits/stdc++.h> 
string twosComplement(string bin)
{
    for(int i = 0; i < bin.length(); i++) {
        if(bin[i] == '1') bin[i] = '0';
        else bin[i] = '1';
    }
    int carry = 1;
    for(int i = bin.length() - 1; i >= 0; i--) {
        if(bin[i] == '1' && carry == 1) {
            bin[i] = '0';
        } else if(bin[i] == '0' && carry == 1) {
            bin[i] = '1';
            carry = 0;
        }
    }
    if(carry == 1) {
        bin = '1' + bin;
    }
    return bin;
}
