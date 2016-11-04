/*
 * main.c
 *
 *  Created on: 06 дек. 2013 г.
 *      Author: ALTAIR
 */

#include <stdio.h>
#include <stdlib.h>
int check(int **a,int n){
    int i,j,g,v,d1,d2;
    for(i=0;i<n;i++){
        g=a[i][0];
        v=a[0][i];
        for(j=0;j<n;j++)
            if(a[i][j]!=g||g==' '){
                g=' ';
                break;
            }
        for(j=0;j<n;j++)
            if(a[j][i]!=v||v==' '){
                v=' ';
                break;
            }
        if(g!=' ')
            return g;
        if(v!=' ')
            return v;
    }
    d1=a[0][0];
    d2=a[n-1][n-1];
    for(i=0;i<n;i++)
        if(a[i][i]!=d1){
            d1=' ';
            break;
        }
    if(d1!=' ')
        return d1;
    for(i=0;i<n;i++)
        if(a[n-i-1][n-1-i]!=d2){
            d2=' ';
            break;
        }
    if(d2!=' ')
        return d2;
    return ' ';
}
void out(int **a,int n){
    int i,j;
    system("cls");
    for(j=0;j<n;j++)
        printf("--");
    printf("-\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
            printf("|%c",a[i][j]);
        printf("|\n");
        for(j=0;j<n;j++)
            printf("--");
        printf("-\n");
    }
}
int main(){
    int **a,i,j,pl,n;
    printf("size of ground: ");
    scanf("%d",&n);
    a=new int*[n];
    for(i=0;i<n;i++){
        a[i]=new int[n];
    for(j=0;j<=n;j++)
        a[i][j]=' ';
    }
    for(pl=0;;pl=!pl){
        do{
            out(a,n);
            printf("\n%s player:\n",pl?"second":"first");
            printf("X>0,X<=%d: ",n); scanf("%d",&i);
            printf("Y>0,Y<=%d: ",n); scanf("%d",&j);
        }while(i>n||j>n||i<0||j<0||a[i-1][j-1]!=' ');
        a[i-1][j-1]=pl?111:120;
        i=check(a,n);
        if(i!=' '){
            out(a,n);
            printf("\n%s player win:\n",i==111?"second":"first");
            system("pause");
            break;
        }
    }
    return 0;
}
