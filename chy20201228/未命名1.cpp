//
// Created by l50007414 on 2019/9/18.
//
#include<iostream>
#include <stdio.h>
#include <string.h>

void caculate1(char *data);

typedef struct stack {
    char data[10000];
    int top;
} stack;

int main() {
	int n;
	cin>>n; 
    for (int i = 0; i < n; ++i) {
        char data[10000];
        gets(data);
        caculate1(data);
    }

    return 0;
}

void caculate1(char *data) {
    stack temp = {{0}, -1};
    int size = strlen(data);
    for (int i = 0; i < size; ++i) {
        //�����������  ������ջ
        if (data[i] == '(' || data[i] == '{' || data[i] == '[' || data[i] == '<') {
            temp.data[++temp.top] = data[i];
        } else {
            //�������  �ͽ�����ջ��Ԫ�رȽ�  ���������  ��Ⱦͳ�ջ
            if ((data[i] == ')' && temp.data[temp.top] == '(') || (data[i] == '}' && temp.data[temp.top] == '{') ||
                (data[i] == ']' && temp.data[temp.top] == '[')
                || (data[i] == '>' && temp.data[temp.top] == '<')) {
                temp.top--;
            } else {
                printf("no\n");
                return;;
            }
        }
    }
    if (temp.top == -1) {
        printf("yes\n");
    } else {
        printf("no\n");
    }
}


