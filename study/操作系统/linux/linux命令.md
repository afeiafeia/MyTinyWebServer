## echo 
<https://www.runoob.com/linux/linux-shell-echo.html>
输出字符串



## >
<https://www.runoob.com/linux/linux-shell-io-redirections.html>
重定向

## wc
统计文件中的字节数、字符数、行数
*可通过man命令查看*


## apt
<https://www.runoob.com/linux/linux-comm-apt.html>
软件安装及更新


## sysctl 
在系统运行时查看、修改内核的配置参数,这些参数位于/proc/sys目录下
sysctl -a:显示左右的系统参数


<https://blog.csdn.net/sunfengye/article/details/78973831>

#  &符号：表示任务在后台执行
 ./test > log.txt &
运行test程序并置于后台执行（&的作用），执行的日志重定向到log.txt中（>的作用）

## &&符号：前一条命令执行成功时，再执行后一条命令
ls -l && cd ..

## |符号：表示管道，上一条命令的输出作为下一条命令的输入
ps -aux | grep aux

## ||符号：上一条命令执行失败时，执行下一条命令

## TCP的MSS大小
跟链路层协议有关，例如以太网1500字节，去掉ip头部20字节，TCP头部20字节，数据以供1460字节（MSS大小）


## 环境变量配置文件
1. /etc/profile文件，相当于系统环境变量配置，对所有用户有效
export CPLUS_INCLUDE_PATH=$CPLUS_INCLUDE_PATH:/usr/local/protobuf/include/
将/usr/local/protobuf/include/路径添加到C++的include搜索路径