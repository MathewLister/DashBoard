#include "todolistmodel.h"


todolistmodel::todolistmodel(QObject *parent)
{

}

int todolistmodel::rowCount(const QModelIndex &parent) const
{
    return taskNames.size();
}

int todolistmodel::columnCount(const QModelIndex &parent) const
{
    return 2;
}

QVariant todolistmodel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole) {
        switch (index.column()) {
        case 0: //task name
            return taskNames.at(index.row());
        case 1: //task due date
            return taskDueDate.at(index.row());
        }
    }
    return QVariant();
}

void todolistmodel::openFile(QString filePath)
{
    QFile file(filePath);

    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "error", file.errorString());
        return;
    }

    QTextStream in(&file);

    taskNames.clear();
    taskDueDate.clear();

    for(int i = 0; !in.atEnd(); i++) {
        QString line = in.readLine();
        QStringList fields = line.split(",");

        if (i == 0) continue;

        for(int j = 0; j < fields.size(); j++) {
            std::cout << "[" << j << "]" << fields[j].toStdString();
        }
        std::cout << std::endl;

        taskNames.push_back(fields[0]);
        taskDueDate.push_back(fields[1]);
    }

    file.close();
    emit layoutChanged();
}














