
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int main() {
    int k; // �ڼ�������ͨ��
    char c[10] = "c"; // �ڷŵ���Ʒ
    char g[6] = "g"; // Ҫ�����Ʒ
    int f[6][3] = { 0 }; // ��P���������Ʒ������
    int a[10][3] = { 0 }; // a�ֱ��Ӧ��������
    int p = 0;
    int check[10][3] = { 0 };
    int clear = 0;
    int k2=0;
    int junk = 0;
    int cishu = 0;
    printf("�����������Ʒ���࣬ͨ����ţ���Ʒ���ۣ���Ʒ����������END����,����back������һ������\n");
    
        for (k = 0; k < 5; k++) {
            char test[10] = "test"; // ���ڼ���END
            scanf_s("%s", test, (unsigned int)sizeof(test));
          
            if (strcmp(test, "END") == 0)  // ����Ƿ�����END
            {
                k2 = k;
                break;
            }
            if (strcmp(test, "back") == 0)
            {
                if (k >= 0)
                {
                    clear = 2;
                    if (clear == 2)//���ڰڷŵ���Ʒ����������Ʒ�޷��ٴα�����
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
                    printf("��һ���ѳ���\n");//���鳷����û��             
                    continue;
                }           
            }
            if (test[0] >= 'A' && test[0] <= 'Z' && strlen(test) < 2)
            {
                c[k] = test[0]; // �ڷŻ�Ʒ����
                clear = 0;
            }
            else
            {
               
                if (cishu == 0)
                {
                    printf("��������ȷ����Ʒ��Ϣ��\n");
                }
                    test[k] = '/0';
                    cishu++;
                clear = 1;
                k--;
                continue;
            }

            for (int n = 0; n < 3; n++)
            {

                scanf_s("%d", &check[k][n]); // ��ȡͨ����ţ����ۺ͸���           
            }
            for (int n = 0; n < 3; n++)
            {
                if (check[k][0] < 6 && check[k][0]>0 && check[k][1] > 0 && check[k][1] < 10 && check[k][2]>0 && check[k][2] < 51)
                {
                    if (n == 0)
                    {
                        for (int P = 0;P < k;P++)//���ͨ����û���ظ�
                        {
                            if (check[k][0] == check[P][0])
                            {
                                printf("��ͨ���Ѱڷ�����Ʒ���뻻һ��ͨ��,���ٴδ������룬��������\n");
                                printf("�������µ�ͨ�����\n");
                                scanf_s("%d", &check[k][0]);
                                if (check[k][0] != 1 && check[k][0] != 2 && check[k][0] != 3 && check[k][0] != 4 && check[k][0] != 5)
                                {
                                    printf("�������ͨ����������\n");
                                    return 0;
                                }
                                else
                                {
                                    for (int P = 0;P < k;P++)//���ͨ����û���ظ�
                                    {
                                        if (check[k][0] == check[P][0])
                                        {
                                            printf("�������ͨ����������\n");
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
                    printf("������Ϣ�������˳�����\n");
                    return 0;
                    break;
                }
            }
            if (clear == 1)//������������
            {
                for (int n = 0; n < 3; n++)
                {
                    check[k][n] = 0;
                    a[k][n] = 0;
                }
                k--;
            }
        }
        
        printf("�����������빺�����Ʒ��ͨ����ţ��������������END����������back������һ������\n");
       
        for (p = 0; p < 5; p++) {
        char exam[10] = "exam";
        scanf_s("%s", exam,(unsigned int)sizeof(exam));

        if (strcmp(exam, "END") == 0) { // ����Ƿ�����END
            break;
        }
        if (strcmp(exam, "back") == 0)
        {
            if (p == 0)
            {
                memset(exam, '\0', sizeof(exam));
               
                printf("�����������Ʒ���࣬ͨ����ţ���Ʒ���ۣ���Ʒ����������END����,����back������һ������\n");
                for (k = k2+1;k <= 4;k++)
                { 
                    
                    scanf_s("%s", &c[k-1],(unsigned int)sizeof(c));
                    if (c[k-1]=='E' && c[k]=='N' && c[k + 1]=='D')  // ����Ƿ�����END
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
                        printf("�������һ���ڷŵ���Ʒ\n");
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
                printf("��һ���ѳ���\n");//���ﻹ��Ҫ����������ܹ�����������
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
                    g[p] = exam[0]; // �ڷŻ�Ʒ����
                    break;
                }
               
                if (k >= 4)
                {
                    printf("δ�ҵ��Ѱڷŵ���Ʒ��������ѡ��\n");
                    exam[p] = '\0';
                    for (int x = 0;x <= 1;x++)
                    {
                        scanf_s("%d", &junk);
                    }
                    p--;
                    continue;
                }
            }
            scanf_s("%d", &f[p][0]); // ͨ�����

            scanf_s("%d", &f[p][1]); // �������
        }
        else
        {
            continue;
        }
    }

    // ��¼��ƥ���,��p��һ���ǵ�p�������,p��0��ʼ
    int k1[6] = { -1 };
    for (k = 0; k < 5; k++) {
        for (p = 0; p < 5; p++) {
            if (c[k] == g[p] && a[k][0] == f[p][0]) {
                k1[p] = k; // ��¼��ƥ���
                break;
            }
        }
    }

    for (p = 0; p < 5; p++) {
        if (k1[p] != -1) {
            if (f[p][1] > a[k1[p]][2]) { // ��鹺�������Ƿ����ʣ������
                printf("������������ʣ������\n");
                p--;
                continue;
            }
            else {
                int money = 0;

                if (k1[p] >= 0)
                {
                    money = f[p][1] * a[k1[p]][1];
                }

                // ���㵱ǰ��Ʒ���ܽ��
                if (money > 1000)
                {
                    break;
                }
                if (money > 0)
                {
                    printf("��ǰ����%c�����ܽ��Ϊ��%dԪ�������Ͷ�ҹ��򣬽���Ͷ��1��2��5ԪӲ�ҡ�\n", c[k1[p]], money);
                }
                int sum = 0; // ��ʼ��Ͷ�ҽ��
                int lastcoin = 0; // �洢��һ�ζ�ȡ������

                while (sum < money) {
                    while (1) {
                        printf("������һ�����֣����� 'back' ������һ�ζ�ȡ����\n");
                        char coin[20] = "coin"; // ���ڴ洢�û�����
                        scanf_s("%s", coin, (unsigned)sizeof(coin)); // ��ȡ�û�����

                        // ����Ƿ����� "back"
                        if (strcmp(coin, "back") == 0) {
                            printf("������һ��Ͷ�ң���ǰͶ�ҽ��Ϊ��%d\n", lastcoin);
                            sum -= lastcoin; // ������һ��Ͷ�ҽ��
                            continue; // ����ѭ��������ȡ������
                        }

                        // ���Խ�����ת��Ϊ����
                        int cointr = atoi(coin);
                        lastcoin = cointr; // ������һ�ζ�ȡ������
                        printf("��Ͷ���Ӳ�ҽ��Ϊ�ǣ�%d\n", cointr);

                        if (cointr != 1 && cointr != 2 && cointr != 5) {
                            printf("��������ȷ��Ͷ�ҽ��\n");
                        }
                        else {
                            sum += cointr; // �ۼ�Ͷ�ҽ��
                            // ��������
                            if (sum >= money) {
                                printf("����ɹ�������%dԪ\n", (sum - money));
                                // ����ʣ������
                                a[k1[p]][2] -= f[p][1]; // ���ٿ��
                                printf("��������ɣ�%cʣ������Ϊ��%d\n", c[k1[p]], a[k1[p]][2]);
                                break;
                                // �˳�Ͷ��ѭ��
                            }
                        }
                    }
                }

            }
        }

        else
        {
            printf("�������Ӧ����Ʒ\n");
        }
    }
    return 0;

}
