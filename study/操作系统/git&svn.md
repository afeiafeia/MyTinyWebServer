Git：分布式版本控制系统

Git与SVN的区别：
1. Git是分布式的，SVN是集中式的
2. Git把内容按照元数据的方式存储，SVN是按文件存储


git分为工作区、暂存区以及版本库
1. 工作区：电脑上的本地文件
2. 暂存区：一般是存放在.git文件下的index文件
3. 版本库：含有一个.git隐藏目录的工作区（不能再称为工作区，而是git的版本库）

<https://www.runoob.com/git/git-basic-operations.html>
git add file1   //add命令就是将仓库中的文件file1传到暂存区（实际上不是传了文件，应该是记录了一条命令）
git commit -m "XXX"  //将文件从暂存区存入本地仓库
git push             //将文件从本地仓库推送到远程仓库

git clone是将文件从远程仓库（例如github）下载到本地仓库，然后通过checkout可以下载到本地工作区
git pull是将文件从远程仓库直接下载到工作区