# 201903
## 201903-1 小中大
思路：注意偶数时，小数点保留一位,可以在输出的时候判断两个数相加为奇数的时候，输出.5,
可以综合判断
## 201903-2 二十四点
思路，由于没有括号，可以直接处理，将+，-当作正负数，压栈，遇到*，/弹出一个数，读取后面一个数
运算压栈，最后对栈中的元素直接进行相加
## 201903-3 损坏的RAID5
思路：当l==n-1时，不要急着异或运算求出，这样运时长，根据编号确定块所在位置，
int row = inx/(n-1) * s , col = (n-row+inx/s-row*(n-1))%n;
int start = 8*(row*s+inx%s);
## 201903-4 消息传递接口
思路：将n个线程的信息用一个队列模拟，初始化的时候，将每一个进程的信息入队，出队的时候判断R(S)相
对应的信息是否出现过，此信息利用数组保留即可,出现过，消除信息，并将相对应的线程下一信息入队，每次入队的
时候判断消息的个数，当消息不为0，即死锁
## 201903-5 317号子任务

# 201812
## 201812-1 小明上学
思路：直接模拟即可，遇到道路直接相加，红灯->绿灯->黄灯->红灯,利用变化到绿灯的时间相加
## 201812-2 小明放学
思路：利用一个递归程序模拟上述信号灯变化，再模拟即可，如果直接利用变化的时候，注意红灯经过一个周期后
可能亦为红灯
## 201812-3 CIDR合并
思路：可以直接利用链表保存信息，这题主要经过一遍排序或，再经过符合要求往后扫描，和符合要求二往前扫描，
过程还要删除元素，利用链表方便操作
## 201812-4 数据中心
思路：先寻找一个最优的树结构，使得传输的时间最少（最小生成树），再根据题意的传输时间的定义可知
题意等价于求最小生成树的的最大边
## 201812-5 管道清洁

# 201809
## 201809-1 卖菜
思路：根据题意可知第二天的菜价时，旁边两家和自己的平均值，且向下取整（直接利用c++ 整数除法/即可），
注意边界是/2，即可
## 201809-2 买菜
思路：可以直接利用区间之间有多少重复，计算，区间的左端点的最大值，右端点的最小值，相减累加
或者（数据量不大）直接利用区间的判断，利用差分思想，由于是r-l,直接再r位置--即可，利用两个数组
## 201809-3 元素选择器
思路：题意利用缩进来表示的层次关系，利用数组存一个结构体，缩进大小，标签名称，id,注意的输入将
标签的名字换成一个同一大小写，输入的时候直接从最后一个判断即可
## 201809-4 再卖菜
思路：由于是c++ 整数/关系，即可以构造一个表达式，是三元表达式，且连续的，利用前缀和思想转换成二元
构造出一个差分约束方程，题意要求最小的字典序，即求最长路，利用SPFA求即可，同时前缀是递增，同样需要加入
方程组即可，同时求出的最长路之后，dist存的正是前缀和的解，利用a[i]=s[i]-s[i-1]求解即可
## 201809-5 线性递推式
# 201803
## 201803-1 跳一跳
思路：直接按照题意求解即可
## 201803-2 碰撞的小球
思路：先排序，再模拟即可
## 201803-3 URL映射
思路：先把N个规则存起来，每读取一个url的时候，依次根据每个规则匹配当遇到'<'，开始匹配，其他情况字符不同退出
每次匹配的时候先输出存到一个数组即可
## 201803-4 棋局评估
思路：直接暴搜即可,9!不会超时,利用dfs搜索，参数为k(1,2),表示不同的双方，在搜索前判断上次是否赢了
记得回溯即可
201803-5 二次求和
# 201712
## 201712-1 最小差值
思路：O（n^2),直接取任意两个数之间的数的绝对值的最小值即可
O(nlogn):先排序，在将相邻的两个数直接相减取最小值即可
O（n):桶排序的思想，即得在利用的数组的时候当个数>=2,结果为0,直接退出即可，安装上一条情况求即可
## 201712-2 游戏
典型的约瑟夫问题，可以利用vector,或者直接利用数组模拟即可
## 201712-3 Crontab
## 201712-4 行车路线
思路：利用Djakarta算法做，存两个数组（可以直接利用邻接矩阵），分在松弛操作的是否分两种情况更新
## 201712-5 商路
# 201709
## 201709-1 打酱油
思路：直接贪心即可，利用3个while循环，即可求解
## 201709-2 公共钥匙盒
思路：直接安装题意模拟
## 201709-3 JSON查询
思路：这题关键在于的层次方式，遇到“{”代表下一层，state代表状态，表示是读取关键字，还是value
存储结构采用map，处理的时候将value加入到字符串中,遇到“}”会退一层
## 201709-4 通信网络
思路：求树的最大直径，两遍搜索即可
## 201709-5 除法
思路：利用树状数组，差分思想
201703-1 分蛋糕
201703-2 学生排队
201703-3 Markdown
201703-4 地铁修建
201703-5 引水入城
201612-1 中间数
201612-2 工资计算
201612-3 权限查询
201612-4 压缩编码
201612-5 卡牌游戏
201609-1 最大波动
201609-2 火车购票
201609-3 炉石传说
201609-4 交通规划
201609-5 祭坛
201604-1 折点计数
201604-2 俄罗斯方块
201604-3 路径解析
201604-4 游戏
201604-5 网络连接
201512-1 数位之和
201512-2 消除类游戏
201512-3 画图
201512-4 送货
201512-5 矩阵
201509-1 数列分段
201509-2 日期计算
201509-3 模板生成系统
201509-4 高速公路
201509-5 最佳文章
201503-1 图像旋转
201503-2 数字排序
201503-3 节日
201503-4 网络延时
201503-5 最小花费
201412-1 门禁系统
201412-2 Z字形扫描
201412-3 集合竞价
201412-4 最优灌溉
201412-5 货物调度
201409-1 相邻数对
201409-2 画图
201409-3 字符串匹配
201409-4 最优配餐
201409-5 拼图
201403-1 相反数
201403-2 窗口
201403-3 命令行选项
201403-4 无线网络
201403-5 任务调度
201312-1 出现次数最多的数
201312-2 ISBN号码
201312-3 最大的矩形
201312-4 有趣的数
201312-5 I’m stuck!
