#pragma once

// 术语(terminology)

// a.声明式(declaration)	--名称和类型
// b.签名式(signature)		--参数和返回类型
// c.定义式(definition)		--拨发内存的地点
// d.初始化(initialization) --给予初值


// 关键字 explicit 阻止隐式类型转换，仍然可以被用来进行显示类型转换

// copy 构造函数被用来 "以同型对象初始化自我对象"
// copy assignment 操作符被用来 "从另一同型对象中拷贝其值到自我对象"
//  注意 "=" 语法也可用来调用 copy 构造函数，示例： widget w3 = w2;    可以关注是否有新对象被定义

// 命名习惯

// 
