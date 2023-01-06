// 函数声明

// 防止头文件被多次编译
#ifndef __ADD_H__ // if not define
#define __ADD_H__

int add(int x, int y);

#if 0
// 内联函数不能分成头文件和实现文件的形式（不能将声明和定义分开）
//如果一定要讲头文件与实现文件分开，可以在头文件中加入`#include 实现文件`
    inline
    int add(int x, int y);//在进行字符串替换的时候，只有声明没有实现，导致无法替换

#include "add.cc" //引入定义

#endif

#endif // end of ifndef __ADD_H__