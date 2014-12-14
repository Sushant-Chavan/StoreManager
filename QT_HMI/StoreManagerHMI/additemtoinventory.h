#ifndef ADDITEMTOINVENTORY_H
#define ADDITEMTOINVENTORY_H

#include <QWidget>
#include "Defines.h"

namespace Ui {
class AddItemToInventory;
}

class AddItemToInventory : public QWidget
{
    Q_OBJECT

public:
    explicit AddItemToInventory(QWidget *parent = 0);
    ~AddItemToInventory();


signals:
    void AddItemToInventorySignal(defines::addItemToInventory::addItemToInventory button);

public slots:
    void addItemToInventorySlot();
    void cancelSlot();

private:
    Ui::AddItemToInventory *ui;
};

#endif // ADDITEMTOINVENTORY_H
