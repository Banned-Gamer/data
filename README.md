# 数据与结构大作业

## 简介
&emsp;&emsp;这是两个菜鸡数据结构的大作业  
&emsp;&emsp;ps:重新写一遍解决所有问题

## 树tree  
1.用先序递归过程建立二叉树 (存储结构：二叉链表)  
&emsp;&emsp;输入数据按先序遍历所得序列输入，当某结点左子树或右子树为空时，输入‘*’号。

2.将任意一个指定的文件进行哈夫曼编码，并以真正的二进制位生成一个二进制文件（压缩文件）；反过来，可将一个压缩文件解码还原为原来的文件。  
&emsp;&emsp;提示：对选定的文件以二进制方式读入，一次读入一定的长度如1024 bytes，然后对每一字节（一字节8 bit，所以刚好对应256个ASCII字符）进行统计，如此循换统计。  

## 图论graph theory
已知某图是边带权(权值为正数)的有向无环图,采用邻接表存储,求出图中距离最远的两个结点。


1）安装gcc-3.4

wget http://old-releases.ubuntu.com/ubuntu/pool/universe/g/gcc-3.4/gcc-3.4-base_3.4.6-6ubuntu3_i386.deb

sudo dpkg -i gcc-3.4-base_3.4.6-6ubuntu3_i386.deb

wget http://old-releases.ubuntu.com/ubuntu/pool/universe/g/gcc-3.4/cpp-3.4_3.4.6-6ubuntu3_i386.deb

sudo dpkg -i cpp-3.4_3.4.6-6ubuntu3_i386.deb 

wget http://old-releases.ubuntu.com/ubuntu/pool/universe/g/gcc-3.4/gcc-3.4_3.4.6-6ubuntu3_i386.deb

sudo dpkg -i gcc-3.4_3.4.6-6ubuntu3_i386.deb

wget http://old-releases.ubuntu.com/ubuntu/pool/universe/g/gcc-3.4/libstdc++6-dev_3.4.6-6ubuntu3_i386.deb

sudo dpkg --force-depends -i libstdc++6-dev_3.4.6-6ubuntu3_i386.deb

wget http://old-releases.ubuntu.com/ubuntu/pool/universe/g/gcc-3.4/g++-3.4_3.4.6-6ubuntu3_i386.deb

sudo dpkg -i g++-3.4_3.4.6-6ubuntu3_i386.deb

2）安装as86

sudo apt install bin86

