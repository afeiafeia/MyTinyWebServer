## hash冲突的解决方案：

1. 探测：分为线性探测、平方探测、随机探测，当计算出来的哈希地址有冲突时，增大哈希值重新计算地址：
例如：地址序列为：H0、H1、H2、H3...
此时计算H0 = hash(key)MOD m(为哈希表长度)，说明key与已有地址冲突，此时将hsah(key)增大x，重新计算
H = (hash(key)+x)MOD m,如果仍然冲突，增大y
根据每次增长的方式，分为线性、平方、随机探测；
线性探测是指每次的探测值x为等差数列，例如x = 1、2、3、4、5、6；
平方探测是指增长值x，是探测值是前一次探测的2被；x = 1、2、-2、4、-4、8、-8
随机探测是指每次的探测值是一个随机值

2. 链地址法：
   将哈希地址相同的元素按照链表组织起来，哈希表中该哈希地址处存放链表的头指针（这在一定程度可以解决频繁插入导致的哈希扩容问题，但随着插入的不断增加，链表会不断增大，后续插入、查找到效率会降低）

3. 再哈希：
   构造多个不同的哈希函数，当时有hash1计算的地址有已有的冲突时，使用下一个哈希函数计算，直到计算出不冲突的地址；这种方法不易像链表法造成聚集，但增加了计算时间

4. 公共溢出区
   将哈希表分为基本表和溢出表两部分，当计算出的哈希地址没有冲突时，放入基本表，否则放入公共溢出区；这也缓解了哈希扩容的发生，但查找、删除效率将有所降低

<https://www.cnblogs.com/weigy/p/12571648.html>
<https://www.cnblogs.com/carreyBlog/p/13657099.html>
<https://blog.csdn.net/pange1991/article/details/82347284>
<https://blog.csdn.net/v_july_v/article/details/6879101>