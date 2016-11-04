/*
 * main.c
 *
 *  Created on: 06 дек. 2013 г.
 *      Author: ALTAIR
 */
#include <stdio.h>
#include <io.h>

struct _finddata_t findData;

int tubs = 0;

int strins(char *t, const unsigned int size, const char *s, const unsigned int idx){
    if( t == NULL || s == NULL)
        return -1;
    //assert("idx == 0");
    unsigned int lntS = strlen(s);
    unsigned int lntT = strlen(t);
    if(lntS + lntT + 1 > size || idx > size)
        return -2;
    if( idx > lntT)
        return -3;

    unsigned int i = 0;
    /*
    for(i = lntT; i >= idx && i <= lntT; i--){
    	//assert("0 <= i+lntS && i+lntS < size");
    	//assert("0 <= i && i < size");
    	//assert("0 <= i && i < lntT");
        t[i + lntS] = t[i];
    }
    */
    for(i = 0; i < lntS; i++){
    	//assert("0 <= i && i < lntS");
    	//assert("0 <= i+idx && i+idx <= size");
        t[i+idx] = s[i];
    }
    t[lntS+idx] = '\0';
    return 0;
}

void printf_tubs() {
	int i;
	for(i = 0; i < tubs; i++)
		printf(" ");
}

int scandir(char *f_dir) {
	int len = strlen(f_dir);
	if(f_dir[len - 1] != '*') {
		strins(f_dir, 1024, "*.*", len);
		f_dir[len+3] = '\0';
	}
	//printf("dir : %s\n", f_dir);
	long find = _findfirst(f_dir, &findData);
	if(find != -1){
		do {
			if((findData.attrib & _A_SUBDIR) && strcmp(findData.name, "..") && strcmp(findData.name, ".") && strcmp(findData.name, "")) {
				printf_tubs();
				printf("d:%s\n", findData.name);
				strins(findData.name, 128, "\\", strlen(findData.name));
				strins(f_dir, 1024, findData.name, len);
				tubs++;
				scandir(f_dir);
				tubs--;
			}
		}while(_findnext(find, &findData) != -1);
		_findclose(find);
	}
	f_dir[len] = '\0';
	if(f_dir[len - 1] != '*') {
		strins(f_dir, 1024, "*.*", len);
		f_dir[len+3] = '\0';
	}
	//printf("dir2: %s\n", f_dir);
	find = _findfirst(f_dir, &findData);
	if(find != -1){
		do {
			if(!(findData.attrib & _A_SUBDIR)) {
				printf_tubs();
				printf("f:%s\n", findData.name);
			}
		}while(_findnext(find, &findData) != -1);
		_findclose(find);
	}
	return 0;
}

int main() {
	char f_dir[1024] = "E:\\workspace\\";
	scandir(f_dir);
	return 0;
}
