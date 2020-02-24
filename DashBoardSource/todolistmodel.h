#ifndef TODOLISTMODEL_H
#define TODOLISTMODEL_H


#include <QAbstractTableModel>
#include <vector>
#include <QFile>
#include <iostream>
#include <QMessageBox>
#include <QTextStream>


class todolistmodel: public QAbstractTableModel
{
public:
    todolistmodel(QObject *parent);
    std::vector<QString> taskNames;
    std::vector<QString> taskDueDate;

    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;

    void openFile(QString filePath);
};
#endif // TODOLISTMODEL_H
