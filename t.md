# 命名空间 之一

本篇文章出于作者个人理解：

[TOC]

-------------------

## 1 命名空间的使用

> 使用命名空间是C++中比较重要的一个概念，根据需要导入不同的命名空间可以区别函数是哪个命名空间中的内容。由于人类的单词有限，现在大型的程序开发，尤其是各种库之间，不可能没有重名的，而且大型程序不可能一个人完成，难免会有名字重复的变量或函数，这时需要命名空间来区分

例如在C++中我们经常使用的 **std** 命名空间具体用法如下

```c++
#include <iostream>
int main() {
	int a;
	std::cin>>a;
	std::cout<<a<<std::endl;
	return 0;
}
```
每一个是cin 和 cout 他们分别是< istream > 和 < ostream >中的内容 他们都是 **std** 这个命名空间中内容所以在使用他们前得加上 **std::** 来进行使用

##2 命名空间的using声明
>如果对于每句我们都使用 **std::** 来引用非常麻烦,C++提供了简洁的方式类使用命名空间成员，使用 **using** 声明可以不需要加处处在使用**std::** 了


```c++
#include<iostream>
using std::cin;
using std::cout;
int main() {
	int a;
	cin >> a;
	cout << a;
	return 0;
}
```




