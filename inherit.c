/*
 * @FileName: 
 * @Author: YangSL
 * @Date: 2022-03-01 18:06:58
 * @LastEditTime: 2022-03-01 18:12:41
 * @Description: 
 */
#include <stdio.h>

struct Mammal {
    int eyeColor;
    void (*ShowEyeColor)(struct Mammal *this);
    int callNum;
    void (*Call)(struct Mammal *this);
};

void ShowEyeColor(struct Mammal *this)
{
    if (this->eyeColor == 1) {
        printf("眼睛是绿色\n");
    } else {    
        printf("眼睛是蓝色\n");
    }
    return;
}

void Call(struct Mammal *this)
{
    printf("叫%d声\n", this->callNum);
    return;
}

// struct Mammal 的构造函数
void Mammal(struct Mammal *this, int eyeColor, int callNum)
{
    this->eyeColor = eyeColor;    
    this->ShowEyeColor = ShowEyeColor;  
    this->callNum = callNum;
    this->Call = Call;
    return;  
}

struct Dog {
    struct Mammal mammal;
};

// struct Dog 的构造函数
void Dog(struct Dog *this, int eyeColor, int callNum)
{
    Mammal(this, eyeColor, callNum);
    // 狗类的其它属性，略
    return;
}

// struct Dog 的析构函数
void  _Dog(struct Dog *this)
{

}

struct Cat {
    struct Mammal mammal;
    // 猫类的其它属性，略
};

// struct Cat 的构造函数
void Cat(struct Cat *this, int eyeColor, int callNum)
{
    Mammal(this, eyeColor, callNum);
    return;
}

// struct Cat 的析构函数
void  _Cat(struct Cat *this)
{

}

main()
{
    struct Dog myDog;
    Dog(&myDog, 1, 3);
    myDog.mammal.ShowEyeColor(&myDog);
    myDog.mammal.Call(&myDog);
    _Dog(&myDog);
 
    struct Cat myCat;
    Cat(&myCat, 2, 5);
    myCat.mammal.ShowEyeColor(&myCat);
    myCat.mammal.Call(&myCat);
    _Cat(&myCat); 
    
    return;
}
