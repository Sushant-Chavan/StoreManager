#include "additemtoinventory.h"
#include "ui_additemtoinventory.h"

#include <QDebug>

AddItemToInventory::AddItemToInventory(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddItemToInventory)
{
    ui->setupUi(this);

    this->setLayout(ui->TopLayout);

    QObject::connect(ui->AddItem, SIGNAL(clicked()), this, SLOT(addItemToInventorySlot()));
    QObject::connect(ui->Cancel, SIGNAL(clicked()), this, SLOT(cancelSlot()));
}

void AddItemToInventory::addItemToInventorySlot()
{
    emit AddItemToInventorySignal(defines::addItemToInventory::addItemToInventory::ADD_TO_INVENTORY);

    std::string itemName = ui->ItemNameEntry->text().toStdString();
    unsigned int itemCode = ui->ItemCodeEntry->text().toUInt();
    float itemPrice = ui->ItemPriceEntry->text().toFloat();
    float itemQuantity = ui->ItemQuantityEntry->text().toFloat();


    qDebug() << "Add Item. Name: " << itemName.c_str() << "\t Code: " << itemCode << "\t Price: " << itemPrice << "\t Quantity :" << itemQuantity;

}

void AddItemToInventory::cancelSlot()
{
    emit AddItemToInventorySignal(defines::addItemToInventory::addItemToInventory::CANCEL);

    qDebug() << "CANCEL";
}

AddItemToInventory::~AddItemToInventory()
{
    delete ui;
}
