# `vector` 的常见用法详解



## 一、如何认识 `vector`

​		`vector` 译为向量，但实质上是一个“**变长数组**”。

​		在实际的应用中，使用普通数组通常会遇到溢出的情况，而使用 `vector` 会让问题得到简化。与此同时， `vector` 常常也用于**以邻接表的方式存储图**，这对于*结点数很多的图*而言是十分友好的（结点数太多不仅无法使用邻接矩阵存储，而且往往会导致指针的使用变得更加复杂）。本文将从四个方面来解析 `vector ` 的使用方法：

- [ ] 增：push_back、
- [ ] 删：pop_back、
- [ ] 查：按数组下标访问、使用**迭代器**访问、查找算法；
- [ ] 改：



## 二、`vector` 的定义和访问

### 1、`vector` 的定义：

#### （1）单独定义一个 `vector`：

单独定义一个 `vector`，实际上就**相当于定义一个一维数组**，与定义普通数组不同的是：`vector` 定义的数组，其**长度可变**。给出示例如下：

```C++
vector<typename> variable_name;
```

- 这里的 `typename` 可以是任何基本类型：`int`、`double`、`char`、`bool` 等；

- 特别的，`typename` 也同样可以是 `STL` 标准容器，例如：`vector`、`set`、`queue` 等，此时定义的时候要在 >> 符号之间加上空格；

```C++
vector<int> score;						// 使用任意的基本数据类型
vector<int> array(100);					// 创建一个长为100的数组
vector<vecotr<int> > name;				// 使用 STL 标准容器，此时定义了一个二维数组
```

#### （2）定义 vector 二维数组：

定义 vector 二维数组时，有两种定义方法

```C++
vector<vecotr<int> > name;				// 定义一个 一维长度不固定、二维长度也不固定的数组 name 		
vector<typename> array[size];			// 定义一个 一维长度固定（为size）、二维长度不固定的数组 array
```

### 2、`vector` 的访问：

#### （1）通过下标访问：

​		与访问普通数组的方式一样，通过下标的索引访问 `vector` 数组。如定义一个 `vector` 容器： `vector<int> vi` ，**直接访问 `vi[index]` 即可**访问对应的数据。注意：**`index` 的取值范围 `0 ~ vi.size()-1`**

#### ==（2）通过迭代器访问：==

​		迭代器（iterator）可以理解为类似指针的东西，其定义为： `vector<typename>::iterator it;`  这样就定义了一个对应类型的迭代器 `it` ，以下是一个应用示例：

```C++
#include <iostream>
#include <vector>
using namespace std;

int main(){
    // 定义并初始化一个 vector 容器
    vector<int> vi;
    for(int i=0;i<=5;i++){
        vi.push_back(i);                        // 在 vector 容器的末尾添加元素 i
    }

    // 使用迭代器访问并输出
    vector<int>::iterator it = vi.begin();      // vi.begin(): 用于取 vi 的首元素地址
    for(int i=0;i<5;i++){						// 第二种循环方法：for(;it != vi.end(); it++){ cout<<*it<<' ';}
        cout<<*(it + i)<<' ';
    }
    cout<<endl;
    return 0;
}
```

输出结果如下：

```C++
0 1 2 3 4
```

注意：

- `vector` 的迭代器不支持 `it < vi.end()` 的写法，因此循环条件只能用 `it != vi.end()` ;
- 在 `STL` 容器中，**只有 `vector` 和 `string`** 中，才允许使用 `vi.begin + 5` 这种**迭代器+整数**的写法；



## 三、`vector` 常用函数解析

### 1、`begin` 和 `end` 函数：

由 二.2.(2) 中的示例可知：

- `vi.begin()+i` 等价于 `vi[i]` ，即：`vi.begin()` 的作用是**取 vi 的首元素地址**；
- `vi.end()` 并不是取 vi 尾元素地址，而是**取尾元素地址的下一个地址**，是一种 **左闭右开** 的设计思想。

### 2、`push_back` 和 `pop_back` 函数：

- push_back：在数组的末尾插入元素；（元素入栈）
- pop_back：在数组的末尾删除元素；（元素出栈）

### 3、`insert` 函数：

```C++
vector<int>::iterator it = vec.begin()		// 获取首元素地址
vec.insert(it, 2)							// 在 it 所指向的位置插入一个元素 2, 后面的元素依次后移一位
```

注意：执行完插入操作之后，迭代器 it 指向未知地址，因此若需要继续使用此迭代器变量，需要**重新赋值**；

### 4、`clear` 函数：

```C++
vec1.clear();                    						// 清空所有元素bool
```

### 5、`erase` 函数：

```

```

### 6、`size` 函数：

```C++
vector<int> vec1; 										// 声明一个空的 vector，元素类型为 int
vector<vector<int>> merged;								// 定义一个二维数组
size_t size = vec1.size();       						// 返回元素个数
int rows = merged.size();								// 计算二维数组的行数
int cols = (merged.size() > 0) ? merged[0].size() : 0;	// 计算二维数组的列数
```

### 7、`empty` 函数：

```C++
bool isEmpty = vec1.empty();     						// 检查是否为空
```





## 四、`list` 的常见用法详解

用法完全同 vector。
