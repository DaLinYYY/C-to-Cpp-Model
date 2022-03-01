/*
 * @FileName: 
 * @Author: YangSL
 * @Date: 2022-03-01 18:06:14
 * @LastEditTime: 2022-03-01 18:10:04
 * @Description: 
 */
#include <stdio.h>

struct PowerCompany {
    int powerReserve;
    void (*PowerPlant)(struct PowerCompany *this, int power);
    void (*PowerUser)(struct PowerCompany *this, int power);
};


void PowerPlant(struct PowerCompany *this, int power)
{ 
    this->powerReserve += power;
    printf("默认发电厂，发电%d瓦\n", power); 
    return;  
}

void PowerUser(struct PowerCompany *this, int power)
{
    if (this->powerReserve >= power) {
        printf("用电%d瓦\n", power);
        this->powerReserve -= power;
    } else {
        printf("电力不足，用电失败\n");
    }
    return;
}

/* struct PowerCompany 的构造函数 */
void PowerCompany(struct PowerCompany *this)
{
    this->powerReserve = 0;
    this->PowerPlant = PowerPlant;
    this->PowerUser = PowerUser;
    return;
}

/* struct PowerCompany 的析构函数 */
void _PowerCompany(struct PowerCompany *this)
{

}

main()
{
    struct PowerCompany myPowerCompany;
    PowerCompany(&myPowerCompany);

    /* 发电 */
    myPowerCompany.PowerPlant(&myPowerCompany, 1000);

    /* 用电 */
    myPowerCompany.PowerUser(&myPowerCompany, 800);
    myPowerCompany.PowerUser(&myPowerCompany, 800);
    
    _PowerCompany(&myPowerCompany);
    return;
}
