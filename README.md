# StudentManagementSystem
使用Qt实现学生管理系统。使用SQLite存储数据服务；QTableView+QStandardModel负责数据上显；QDelegateItem委托表格中的组件。

## 1 学生系统管理界面
界面有两部分组成，一部分是功能按钮，**添加**和**删除**。另一部分是表格，进行学生信息展示。如下图所示
![image](https://github.com/dajinlou/StudentManagementSystem/assets/97718777/155ee9a3-5ce7-4425-aa74-7c656a20a357)


## 2 添加/修改界面
点击**添加**按钮，弹出添加修改界面，如下图所示。

![image](https://github.com/dajinlou/StudentManagementSystem/assets/97718777/2dac03c9-f715-41f9-8f32-72b81ff10394)

## 3 删除操作
可以勾选第一列的复选框，然后点击**删除**按钮，即可删除所选数据。当然，也可以点击左下角**全选**按钮，可以选中表格中的所有数据。

![image](https://github.com/dajinlou/StudentManagementSystem/assets/97718777/5688411f-81d0-4851-a849-ef1d6fbdc871)
