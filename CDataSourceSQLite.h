#ifndef CDATASOURCESQLITE_H
#define CDATASOURCESQLITE_H

#include "IDataSource.h"

#include <QSqlDatabase>

class CDataSourceSQLite:public IDataSource
{
public:
    CDataSourceSQLite();
    ~CDataSourceSQLite();

    // IDataSource interface
    /**
     * @brief 查询所有学生的信息
     * @param stuInfoList[out]
     * @return true-成功，false-失败
     */
    virtual bool selectStuInfo(QList<CStuInfo> &stuInfoList) override;

    virtual bool addStuInfo(CStuInfo &stuInfo) override;
    virtual bool updateStuInfo(CStuInfo &stuInfo) override;
    virtual bool deleteStuInfo(int id) override;

private:
   QSqlDatabase m_db; //数据库
};

#endif // CDATASOURCESQLITE_H
