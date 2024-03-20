根据 B站up主 程序员陈子青
up主的csdn主页：[程序员陈子青-CSDN博客](https://blog.csdn.net/weixin_40582034)
## Mysql的一些事项

默认端口号为 3306 ，默认账户名为 `root` ，密码自己定。

要把 server 的 bin 目录添加到 系统环境变量 path 里面。

基本命令如下

```
mysql -u root -p //登录

show database;
create database database_name;
show databases; //注意末尾有s
use database_name;
create table table_name(colume_name type not null auto_increment primary key)
insert into table_name values(...);

```
## DBeaver 的一些注意事项

暂无

## visual studio 2022开发环境配置
现有打开项目右击打开最下面的属性一栏
c/c++ 常规选项中 添加路径：server/include 文件夹  并且关闭 SDL检查（默认是开启的）
链接器常规的附加库目录中添加路径： server/lib 文件夹 
链接器的输入中添加附加依赖项 libmysql.lib（此文件出现在mysql server的lib文件夹里面）
如果编译后出现找不到 libmysql.dll 的问题，考虑把 mysql server 下 lib 里的libmysql.dll拷贝到 C 盘下面的 Windows/System32 里面，我自己的电脑亲测有效。


## 写代码中的注意事项
要包含头文件 <mysql.h>
设置字符编码