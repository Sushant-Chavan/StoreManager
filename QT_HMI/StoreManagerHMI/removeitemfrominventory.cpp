#include "removeitemfrominventory.h"
#include "ui_removeitemfrominventory.h"

#include <QDebug>

RemoveItemFromInventory::RemoveItemFromInventory(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RemoveItemFromInventory)
{
    ui->setupUi(this);

    this->setLayout(ui->TopLayout);

    QObject::connect(ui->RemoveItem, SIGNAL(clicked()), this, SLOT(removeItemFromInventorySlot()));
    QObject::connect(ui->Cancel, SIGNAL(clicked()), this, SLOT(cancelSlot()));
}

void RemoveItemFromInventory::removeItemFromInventorySlot()
{
    emit removeItemFromInventorySignal(defines::removeItemFromInventory::removeItemFromInventory::REMOVE_FROM_INVENTORY);

    unsigned int itemCode = ui->ItemCodeEntry->text().toUInt();

    qDebug() << "Remove from Inventory. Item Code: " << itemCode;
}

void RemoveItemFromInventory::cancelSlot()
{
    emit removeItemFromInventorySignal(defines::removeItemFromInventory::removeItemFromInventory::CANCEL);

    qDebug() << "CANCEL";
}

RemoveItemFromInventory::~RemoveItemFromInventory()
{
    delete ui;
}
