
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int main() {
    int k; // 第几次输入通道
    char c[10] = "c"; // 摆放的商品
    char g[6] = "g"; // 要买的商品
    int f[6][3] = { 0 }; // 第P个想买的商品的属性
    int a[10][3] = { 0 }; // a分别对应后面三个
    int p = 0;
    int check[10][3] = { 0 };
    int clear = 0;
    int k2=0;
    int junk = 0;
    int cishu = 0;
    printf("请依次输入货品种类，通道标号，货品单价，货品个数（输入END结束,输入back撤销上一步）：\n");
    
        for (k = 0; k < 5; k++) {
            char test[10] = "test"; // 用于检验END
            scanf_s("%s", test, (unsigned int)sizeof(test));
          
            if (strcmp(test, "END") == 0)  // 检查是否输入END
            {
                k2 = k;
                break;
            }
            if (strcmp(test, "back") == 0)
            {
                if (k >= 0)
                {
                    clear = 2;
                    if (clear == 2)//用于摆放的商品撤销后让商品无法再次被购买
                    {
                        for (int n = 0; n < 3; n++)
                        {
                            check[k][n] = 0;
                            a[k][n] = 0;
                            check[k - 1][n] = 0;
                            c[k - 1] = 0;
                            a[k - 1][n] = 0;
                        }
                    }
                    k = k - 2;
                    printf("上一步已撤销\n");//检验撤销有没有             
                    continue;
                }           
            }
            if (test[0] >= 'A' && test[0] <= 'Z' && strlen(test) < 2)
            {
                c[k] = test[0]; // 摆放货品种类
                clear = 0;
            }
            else
            {
               
                if (cishu == 0)
                {
                    printf("请输入正确的商品信息！\n");
                }
                    test[k] = '/0';
                    cishu++;
                clear = 1;
                k--;
                continue;
            }

            for (int n = 0; n < 3; n++)
            {

                scanf_s("%d", &check[k][n]); // 读取通道标号，单价和个数           
            }
            for (int n = 0; n < 3; n++)
            {
                if (check[k][0] < 6 && check[k][0]>0 && check[k][1] > 0 && check[k][1] < 10 && check[k][2]>0 && check[k][2] < 51)
                {
                    if (n == 0)
                    {
                        for (int P = 0;P < k;P++)//检查通道有没有重复
                        {
                            if (check[k][0] == check[P][0])
                            {
                                printf("此通道已摆放了商品，请换一个通道,若再次错误输入，将需重启\n");
                                printf("请输入新的通道编号\n");
                                scanf_s("%d", &check[k][0]);
                                if (check[k][0] != 1 && check[k][0] != 2 && check[k][0] != 3 && check[k][0] != 4 && check[k][0] != 5)
                                {
                                    printf("输入错误通道，请重启\n");
                                    return 0;
                                }
                                else
                                {
                                    for (int P = 0;P < k;P++)//检查通道有没有重复
                                    {
                                        if (check[k][0] == check[P][0])
                                        {
                                            printf("输入错误通道，请重启\n");
                                            return 0;
                                        }
                                    }
                                    a[k][n] = check[k][n];
                                }
                            }
                        }
                        a[k][n] = check[k][n];
                    }
                    a[k][n] = check[k][n];

                }
                else
                {
                    printf("输入信息有误请退出重试\n");
                    return 0;
                    break;
                }
            }
            if (clear == 1)//清除掉乱输入的
            {
                for (int n = 0; n < 3; n++)
                {
                    check[k][n] = 0;
                    a[k][n] = 0;
                }
                k--;
            }
        }
        
        printf("请依次输入想购买的商品，通道编号，购买个数（输入END结束，输入back撤销上一步）：\n");
       
        for (p = 0; p < 5; p++) {
        char exam[10] = "exam";
        scanf_s("%s", exam,(unsigned int)sizeof(exam));

        if (strcmp(exam, "END") == 0) { // 检查是否输入END
            break;
        }
        if (strcmp(exam, "back") == 0)
        {
            if (p == 0)
            {
                memset(exam, '\0', sizeof(exam));
               
                printf("请依次输入货品种类，通道标号，货品单价，货品个数（输入END结束,输入back撤销上一步）：\n");
                for (k = k2+1;k <= 4;k++)
                { 
                    
                    scanf_s("%s", &c[k-1],(unsigned int)sizeof(c));
                    if (c[k-1]=='E' && c[k]=='N' && c[k + 1]=='D')  // 检查是否输入END
                    {
                        k2 = k;
                        c[k-1] = '/0';
                        c[k] = '/0';
                        c[k+1] = '/0';
                        p = -1;
                        break;
                    }
                    if (c[k - 1] == 'b' && c[k] == 'a' && c[k + 1] == 'c' && c[k + 2] == 'k')
                    { 
                        int k3 = k-2;
                        for (;k3 <= k + 2;k3++)
                        {
                            c[k3] = '/0';
                            a[k][0] = 0;
                            a[k][1] = 0;
                            a[k][2] = 0;                           
                           
                        }
                        k--;
                        printf("已清除上一个摆放的商品\n");
                        continue;
                    }
                    for (int n = 0;n <= 2;n++)
                    {
                        scanf_s("%d", &a[k-1][n]);
                    }
                }
                continue;
                
              }
            if (p >= 1)
            {
                exam[p] = '/0';
                exam[p - 1] = '/0';                           
                exam[p+1] = '/0';
                f[p - 1][0] = 0;
                f[p - 1][1] = 0;
                exam[p + 2] = '/0';
                g[p - 1] = '/0';
                p =p-2;
                printf("上一步已撤销\n");//这里还需要仿照上面加能够真正撤销的
                continue;
            }
            else
            {
                continue;
            }
            continue;
            p --;
        }
        if (p >=0)
        {
            for (k = 0;k < 5;k++)
            {
                if (exam[0] == c[k])
                {
                    g[p] = exam[0]; // 摆放货品种类
                    break;
                }
               
                if (k >= 4)
                {
                    printf("未找到已摆放的商品，请重新选择\n");
                    exam[p] = '\0';
                    for (int x = 0;x <= 1;x++)
                    {
                        scanf_s("%d", &junk);
                    }
                    p--;
                    continue;
                }
            }
            scanf_s("%d", &f[p][0]); // 通道编号

            scanf_s("%d", &f[p][1]); // 购买个数
        }
        else
        {
            continue;
        }
    }

    // 记录能匹配的,加p的一律是第p个想买的,p从0开始
    int k1[6] = { -1 };
    for (k = 0; k < 5; k++) {
        for (p = 0; p < 5; p++) {
            if (c[k] == g[p] && a[k][0] == f[p][0]) {
                k1[p] = k; // 记录能匹配的
                break;
            }
        }
    }

    for (p = 0; p < 5; p++) {
        if (k1[p] != -1) {
            if (f[p][1] > a[k1[p]][2]) { // 检查购买数量是否大于剩余数量
                printf("购买数量大于剩余数量\n");
                p--;
                continue;
            }
            else {
                int money = 0;

                if (k1[p] >= 0)
                {
                    money = f[p][1] * a[k1[p]][1];
                }

                // 计算当前商品的总金额
                if (money > 1000)
                {
                    break;
                }
                if (money > 0)
                {
                    printf("当前购买%c所需总金额为：%d元，请进行投币购买，仅可投入1，2，5元硬币。\n", c[k1[p]], money);
                }
                int sum = 0; // 初始化投币金额
                int lastcoin = 0; // 存储上一次读取的数字

                while (sum < money) {
                    while (1) {
                        printf("请输入一个数字（输入 'back' 撤销上一次读取）：\n");
                        char coin[20] = "coin"; // 用于存储用户输入
                        scanf_s("%s", coin, (unsigned)sizeof(coin)); // 读取用户输入

                        // 检查是否输入 "back"
                        if (strcmp(coin, "back") == 0) {
                            printf("撤销上一次投币，当前投币金额为：%d\n", lastcoin);
                            sum -= lastcoin; // 撤销上一次投币金额
                            continue; // 继续循环，不读取新数字
                        }

                        // 尝试将输入转换为数字
                        int cointr = atoi(coin);
                        lastcoin = cointr; // 更新上一次读取的数字
                        printf("您投入的硬币金额为是：%d\n", cointr);

                        if (cointr != 1 && cointr != 2 && cointr != 5) {
                            printf("请输入正确的投币金额\n");
                        }
                        else {
                            sum += cointr; // 累加投币金额
                            // 计算找零
                            if (sum >= money) {
                                printf("购买成功，找零%d元\n", (sum - money));
                                // 更新剩余数量
                                a[k1[p]][2] -= f[p][1]; // 减少库存
                                printf("购买已完成，%c剩余数量为：%d\n", c[k1[p]], a[k1[p]][2]);
                                break;
                                // 退出投币循环
                            }
                        }
                    }
                }

            }
        }

        else
        {
            printf("请输入对应的商品\n");
        }
    }
    return 0;

}
