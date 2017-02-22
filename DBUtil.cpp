#include "DBUtil.h"
QMutex DBUtil::mutex;
DBUtil *DBUtil::s_Instance = NULL;
#include <QMessageBox>

int DBUtil::insert(const QString &sql, const QVariantMap &params)
{
    int id = -1;

    DBUtil::instance()->executeSql(sql, params, [&id](QSqlQuery *query) {
        id = query->lastInsertId().toInt(); // 插入行的主键
    });

    return id;
}

bool DBUtil::update(const QString &sql, const QVariantMap &params)
{
    bool result;

    DBUtil::instance()->executeSql(sql, params, [&result](QSqlQuery *query) {
        result = query->lastError().type() == QSqlError::NoError;
    });

    return result;
}


DBUtil *DBUtil::instance()
{
    if (0 == s_Instance)
        {
            mutex.lock();
            if (0 == s_Instance) {
                s_Instance = new DBUtil();
            }
            mutex.unlock();
        }
        return s_Instance;
}

void DBUtil::releaseInstance()
{
    if (NULL != s_Instance)
        {
            mutex.lock();
            delete s_Instance;
            s_Instance = NULL;
            mutex.unlock();
        }
}

void DBUtil::bindValues(QSqlQuery *query, const QVariantMap &params) {
    for (QVariantMap::const_iterator i=params.constBegin(); i!=params.constEnd(); ++i) {
        query->bindValue(":" + i.key(), i.value());
    }
}

void DBUtil::executeSql(const QString &sql, const QVariantMap &params, std::function<void (QSqlQuery *)> handleResult)
{
    QSqlQuery query(db);
    query.prepare(sql);
    bindValues(&query, params);

    if (query.exec()) {
        handleResult(&query);
    }

}

DBUtil::DBUtil()
{
    // 1. 加载 SQLite 数据库驱动
       db = QSqlDatabase::addDatabase("QSQLITE", "Connection_Name");

       // 2. sqlitedata.db 是 SQLite 的数据库文件名
       //    如果此文件不存在则自动创建，如果已经存在则使用已经存在的文件
	   QStringList paths = QStandardPaths::standardLocations(QStandardPaths::TempLocation);
	   QString strPath = paths.at(0) + "/lottery.db";
	   //QString path = QDir::currentPath() + "/lottery.db";
       db.setDatabaseName(strPath);
       // 3. 打开数据库连接，成功返回 true，不成功则程序退出
          if (!db.open()) {
			  QMessageBox::warning(nullptr, "error", QString("can't open db:%1, \n path:%2").arg(db.lastError().text()).arg(strPath));
              exit(128);
          }
}

DBUtil::~DBUtil()
{
    //关闭数据库
    db.close();
}
