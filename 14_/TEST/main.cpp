#include <QCoreApplication>


#include <QSqlDatabase>
#include <QDebug>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QStringList driversList = QSqlDatabase::drivers();
    foreach(QString str,driversList)
        qDebug() << str;
    return a.exec();
}
