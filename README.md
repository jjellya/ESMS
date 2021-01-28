# 职工工资管理系统(ESMS)

Employee Salary Managing System.

2021-01-24

```
1.初始化项目
```





2021-01-27

1.实现了与MySQL的连接：
	①需要在QT安装目录下找到源码
		[“盘符:\Qt\Qt5.13.2\5.13.2\Src\qtbase\src\plugins\sqldrivers\mysql”]()
	②打开该项目mysql.pro修改文件为:

```properties
#mysql.pro
TARGET = qsqlmysql

HEADERS += $$PWD/qsql_mysql_p.h
SOURCES += $$PWD/qsql_mysql.cpp $$PWD/main.cpp

#QMAKE_USE += mysql

INCLUDEPATH += MySQL位置/mysql-5.7.29-winx64/include
DEPENDPATH += MySQL位置/mysql-5.7.29-winx64/include
LIBS += MySQL位置/mysql-5.7.29-winx64/lib/libmysql.lib

OTHER_FILES += mysql.json

PLUGIN_CLASS_NAME = QMYSQLDriverPlugin
include(../qsqldriverbase.pri)
```

​	③将qsqldriverbase.pri文件修改为：

```properties
QT  = core core-private sql-private

# For QMAKE_USE in the parent projects.
#include($$shadowed($$PWD)/qtsqldrivers-config.pri)
include(./configure.pri)
PLUGIN_TYPE = sqldrivers
load(qt_plugin)

DEFINES += QT_NO_CAST_TO_ASCII QT_NO_CAST_FROM_ASCII
```

​	④并把configure.pri复制到mysql的QT项目文件中

​	⑤编译运行,得到两个插件在qt的兄弟文件夹下的plugins中

> ​	有两个文件，分别为qsqlmysql.dll和qsqlmysqld.dll

​	⑥将这两个文件放置到编译环境下的plugins/sqldrivers下，例如[D:\Qt\Qt5.13.2\5.13.2\msvc2017_64\plugins\sqldrivers](D:\Qt\Qt5.13.2\5.13.2\msvc2017_64\plugins\sqldrivers)



2021-01-28

```
1.实现了UserDAO
2.编写了SalaryDAO、AttendanceDAO的头文件方法名，还未实现。
3.实现了EmployeeDAO
```

