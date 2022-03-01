/*
 * @FileName: 
 * @Author: YangSL
 * @Date: 2022-03-01 18:12:20
 * @LastEditTime: 2022-03-01 18:12:21
 * @Description: 
 */
#include <stdio.h>

struct Window {
    int length;
    int width;
    void (*ShowWindow)(struct Window *this);
};

void ShowWindow(struct Window *this)
{
    printf("这是长%d厘米、宽%d厘米的窗户\n", this->length, this->width);
    return;
}

void Window(struct Window *this, int length, int width)
{
    this->length = length;
    this->width = width;
    this->ShowWindow = ShowWindow;
    return;
}

void _Window(struct Window *this)
{

}

struct House {
    struct Window *window;
    int livingRoomNum;
    int bedRoomNum;
    int bathRoomNum;
    void (*ShowHouse)(struct House *this);
};

void ShowHouse(struct House *this)
{
    printf("这是%d室%d厅%d卫的房子\n", this->bedRoomNum, this->livingRoomNum, this->bathRoomNum);
    return;
}


void House(struct House *this, int livingRoomNum, int bedRoomNum, int bathRoomNum)
{
    this->livingRoomNum = livingRoomNum;
    this->bedRoomNum = bedRoomNum;
    this->bathRoomNum = bathRoomNum;
    this->ShowHouse = ShowHouse;
    return;
}

void _House(struct House *this)
{

}

void main()
{
    struct House myHouse;
    House(&myHouse, 2, 3, 2);
    
    /* 组合是一种低耦合，如果不初始化，子类只是存放了一个空指针来占位关联。
       此处是与继承关系的区别。继承是一种强耦合，在继承关系中，无论如何子类拥有父类全部的信息。*/
    struct Window myWindow1;
    myHouse.window = &myWindow1;
    Window(myHouse.window, 100, 50);

    /* 通过获得其它对象的引用而在“运行时”动态定义 */
    myHouse.ShowHouse(&myHouse);
    myHouse.window->ShowWindow(myHouse.window);

    _Window();
    _House();

    return;
}
