
#include <stdio.h>
//#include <assert.h>

int strlen1(const char s[] ){
    int lntS = 0;
    for( lntS = 0; s[lntS] != '\0'; lntS++)
        ;
    return lntS;
}

int strins(char *t, const unsigned int size, const char *s, const unsigned int idx){
    if( t == NULL || s == NULL)
        return -1;
    //assert("idx == 0");
    unsigned int lntS = strlen1(s);
    unsigned int lntT = strlen1(t);
    if(lntS + lntT + 1 > size)
        return -2;
    if(idx > lntT)
        return -3;

    unsigned int i = 0;
    for(i = lntT; i >= idx && i <= lntT; i--){
    	//assert("0 <= i+lntS && i+lntS < size");
    	//assert("0 <= i && i < size");
    	//assert("0 <= i && i < lntT");
        t[i + lntS] = t[i];
    }
    for(i = 0; i < lntS; i++){
    	//assert("0 <= i && i < lntS");
    	//assert("0 <= i+idx && i+idx <= size");
        t[i+idx] = s[i];
    }
    return 0;
}

/*
int main(void)
{
    char t[200]= "Quaka";
    char s[200] = "";
    unsigned int size = 10;
    unsigned int idx = 11;
    int res = strins(t, size, s, idx );
    //printf("FINISH");
    printf("%s %d", t, res);
    return 0;
}
*/
