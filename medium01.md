# 模块一：启动引导区 —— 语言的本源
## 【任务 1】
### 请写出十进制 211 对应的二进制表示。
- 11010011
### 请写出二进制 10110110 对应的十进制表示。
- 182
### 在 C/C++ 中，如何快速判断一个十进制整数是奇数还是偶数？
- 将其转化为2进制数，若末尾为1则为奇数，为0则为偶数。
````
if (n & 1)  // 奇数
else        // 偶数
````
# 模块二：能量阵列 —— 逻辑门的重构
## 【任务 2】
### 阅读并推导以下 C/C++ 代码的输出结果，并简要解释你的计算结果：
````
#include <stdio.h>

int main() {
    unsigned char a = 12;  // 二进制: 00001100
    unsigned char b = 25;  // 二进制: 00011001

    unsigned char res1 = a & b;
    unsigned char res2 = a | b;
    unsigned char res3 = a ^ b;
    unsigned char res4 = (a << 2) | (b >> 1);

    printf("%d %d %d %d\n", res1, res2, res3, res4);
    return 0;
}
````
- 8 29 21 60
- res1:按位与：二进制为00001000，转化为10进制为8；(同为1取1)
- res2:按位或：二进制为00011101，转化为10进制为29；(只要其中一个为1取1)
- res3:按位异或：二进制为00010101，转化为10进制为21；(二者不一样取1)
- res4:a左移2，b右移1后再按位或：二进制为00111100，转化为10进制为60；(每个移动后仍然为8位，空位补0)
### 给定一个整数x（十进制），同时指定一个位数n，确定这个整数x的二进制表示上第n位是0还是1。例如：251的二进制表示是11111011，n=3，结果返回0。
````
#include <stdio.h>

int main() {
    int a, b;
    printf("Enter a num: ");
    scanf("%d", &a);
    printf("Enter a \'n\': ");
    scanf("%d", &b);
    int c=(1<<(b-1));
    int d= a & c;
    int e= d>>(b - 1);
    printf("answer: %d", e);
}
````
- 截图已单独提交至github仓库[直接复制到md里面，在github上无法显示][这一段在完成过后已将代码修正为位运算，之前如截图所示，代数运算]
### 给定一个整数x（十进制），指定一个位数n，给定一个修正值t（0或者1），将整数x的二进制表示上的第n位改为修正值t。输出被修改后的整数。
````
#include <stdio.h>

int main() {
    int a, b, f;
    printf("Enter a num: ");
    scanf("%d", &a);
    printf("Enter a \'n\': ");
    scanf("%d", &b);
    printf("Enter a \'t\': ");
    scanf("%d", &f);
    int c= 1 << (b - 1);
    int e=(a & ~c) | (f ? c : 0);
    printf("fixed answer: %d", e);
}
````
- 截图已单独提交至github仓库（）
### 给定一个有符号32位整数x，找到其二进制表示上从右开始的第一个1，并输出该数，例如：x=10,二进制表示为1010,第一个1在第二位，所以输出二进制表示为10的数2。
````
#include <stdio.h>

int main() {
    int a;
    printf("Enter a num: ");
    scanf("%d", &a);
    int n=1;
    while(!(a & n)){
        n<<=1;
    }
    printf("answer: %d", n);
}
````
- 截图已单独提交至github仓库（）
### 现在有两串无符号数a和b的二进制编码，并且有a<b，每个数字的大小在100位以内，现在问区间[a,b]内&的结果。
````
#include <stdio.h>

int main() {
    long long a, b;
    printf("Enter two num(a/b)(also, a<b): ");
    scanf("%lld/%lld", &a, &b);
    long long n=a & b;
    a++;
    while(a<=b){
        n &= a;
        a++;
    }
    printf("answer: %lld", n);
}
````
- 此题的答案是：a与b从最高位开始看，直到遇到第一个不同的位。保留之前所有相同位，后续位全部换成0；
- - 截图已单独提交至github仓库（只截取了0或者a两种情况）

### 在接触了C语言这么长时间后，相信你已经对逻辑运算了如指掌了，那么你能说说看逻辑运算和位运算的区别和联系吗。思考并提交于markdown文档。
- 逻辑运算的对象是真与假（布尔值），位运算的对象是整数的二进制形式。逻辑运算的输出也是布尔值，而位运算的输出也依旧是整数。与此同时，逻辑运算和位运算的符号也有所不同，前者有（&& || !）后者有（& | << >> ^等等）
### 位运算的定义很简单，但是再简单的定义也可能产生一些有用的性质（比如运算律）。查阅资料了解位运算有哪些性质。
- 满足一些基本代数性质：如：& | ^满足交换律和结合率，然后&与|满足分配率；
- 与0和全1（-1）（~0）的性质，如：何任何数与0与，最后结果为0；
- 幂等性与自反性：如：a & a=a(幂等)， a ^ a=0(自反)
- 德摩根定律：非（P且Q）=非P或非Q；非（P或Q）=非P且非Q
- 通过位运算，实现原数的位移，转换，倒置，提取等
### 移位运算中，右移有两种，其中算数右移对应有符号数，逻辑右移对应无符号数，那么为什么会有这种区别呢。查阅资料理解整数的补码表示后回答于markdown文档。
- 逻辑右移左侧补0，算数右移左侧补0还是1根据数的符号来决定，负数则补1，正数则补0,。因为有符号数在计算机内用补码来显示，如果有符号数依旧用逻辑右移的方法，则会出现负数变为正数的情况。算数右移符合实践应用。同时，采用补码是为了方便计算机内对负数的加和，这样子考虑到负数的运算做的还是加法运算。
# 模块三：通信模块 —— 无碰撞协议
## 【任务 3】编程题：字符串交集检测
````
#include <stdio.h>
int hasCommonChar(const char *s1, const char *s2) {
    int mask1 = 0;
    int mask2 = 0;
   while(*s1!='\0'){
        for(int i=97; i<=122; i++){
            if(*s1==i){
                mask1|=(1 << (i - 97));
            }
        }
        s1++;
   }
   while(*s2!='\0'){
        for(int i=97; i<=122; i++){
            if(*s2==i){
                mask2|=(1 << (i - 97));
            }
        }
        s2++;
   }
   int n=mask1 & mask2;
   int m=0;
   for(int i=25; i>=0 ; i--){
        if(n/(1<<i)==1){
            m+=1;
            n-=(1<<i);
        }
   }
   printf("%d",m);
    return 0;
}
int main(){
    const char s1[100];
    const char s2[100];
    printf("s1 = ");
    scanf("%s", s1 );
    printf("s2 = ");
    scanf("%s", s2 );
    hasCommonChar(s1, s2);
    return 0;
}
````
# 模块四：反应堆核心 —— 绝对平衡的艺术
## 【任务 4】给定反应堆的规模 N (1≤N≤15)，请使用位运算实现求解控制棒摆放方案的总数
````
#include <stdio.h>
void solve(int row,int column, int diag1, int diag2, int N, int *count){
    if (row == N) {
        (*count)++;
    }
    int available = (~(column | diag1 | diag2)) & ((1 << N) - 1);
    while (available) {
        int pos = available & (-available);
        available -= pos;
        solve(row + 1, column | pos, (diag1 | pos) << 1, (diag2 | pos) >> 1,  N, count);
    }
    return;
}
int main(){
    int N,row, column, diag1, diag2, count;
    row=column=diag1=diag2=count=0;
    printf("YOUR \'N\'");
    scanf("%d",&N );
    solve(row,column,diag1,  diag2, N, &count);
    printf("%d", count);
    return 0;
}
````
# 模块五：管道穿梭 —— 自动化寻路
## 【任务 5】编程题：广度优先搜索 (BFS) 与位运算寻路
````
#include <stdio.h>
#include <stdbool.h>


typedef struct {
    int pos;   // 当前节点编号 (0~15)
    int dist;  // 到达当前节点的最短步数
} Node;

int minStepsToCheese(int walls) {
    int start = 0;
    int target = 15;
    // 如果起点或终点本身是墙，直接不可达
    if ((walls & (1 << start)) || (walls & (1 << target))) {
        return -1;
    }
    // BFS 队列与访问位图
    Node queue[16];
    int front = 0, rear = 0;
    int visited = 0;
    // 起点入队并标记已访问 (请使用位运算)
    queue[rear++] = (Node){start, 0};//当前位置，最短步数
    visited |= (1 << start);
    // 上、下、左、右四个方向的节点偏移量
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};
    //请在TO DO 和END OF TO DO 行之间补全代码：
    //TO DO
    while(front<rear){
        Node CUR;
        CUR.pos=queue[front].pos;
        CUR.dist=queue[front].dist;
        front++;
        if(CUR.pos==target){
            return CUR.dist;
        }
        int r = CUR.pos / 4;
        int c = CUR.pos % 4;
        int nr, nc, npos;
        for(int i=0; i<4; i++){
            nr=r+dr[i];
            nc=c+dc[i];
            if(nr<0 || nr>3 || nc>3 || nc<0){
                continue;
            }
            npos = nr * 4 + nc;
            if(walls & (1<<npos)){
                continue;
            }
            if(visited & (1<<npos)){
                continue;
            }
            visited |= (1 << npos);
            queue[rear] = (Node){npos, CUR.dist+1};
             rear++;
        }
       
    }
    //END OF TO DO
    return -1; // 无法到达
}
int main() {
    int walls = (1 << 5) | (1 << 10); // 5号和10号格子是墙
    int steps = minStepsToCheese(walls);
    printf("Minimum steps: %d\n", steps); // 应输出 6
    return 0;
}
````















