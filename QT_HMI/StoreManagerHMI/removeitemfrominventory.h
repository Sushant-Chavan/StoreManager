#ifndef REMOVEITEMFROMINVENTORY_H
#define REMOVEITEMFROMINVENTORY_H

#include <QWidget>
#include "Defines.h"

namespace Ui {
class RemoveItemFromInventory;
}

class RemoveItemFromInventory : public QWidget
{
    Q_OBJECT

public:
    explicit RemoveItemFromInventory(QWidget *parent = 0);
    ~RemoveItemFromInventory();

signals:
    void removeItemFromInventorySignal(defines::removeItemFromInventory::removeItemFromInventory button);

public slots:
    void removeItemFromInventorySlot();
    void cancelSlot();

private:
    Ui::RemoveItemFromInventory *ui;
};

#endif // REMOVEITEMFROMINVENTORY_H
