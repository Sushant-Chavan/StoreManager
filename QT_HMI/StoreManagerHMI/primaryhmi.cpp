#include "primaryhmi.h"
#include "ui_primaryhmi.h"
#include <QDebug>

PrimaryHMI::PrimaryHMI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PrimaryHMI)
{
    ui->setupUi(this);
    QObject::connect(ui->CreateBillPushButton, SIGNAL(clicked()), this, SLOT(createBill()));
    QObject::connect(ui->SearchItemCodePushButton, SIGNAL(clicked()), this, SLOT(searchItemCode()));
    QObject::connect(ui->SearchItemPricePushButton, SIGNAL(clicked()), this, SLOT(searchItemPrice()));
    QObject::connect(ui->DisplayInventoryPushButton, SIGNAL(clicked()), this, SLOT(displayInventory()));
    QObject::connect(ui->AddNewItemPushButton, SIGNAL(clicked()), this, SLOT(addItemToInventory()));
    QObject::connect(ui->RemoveInvemtoryItemPushButton, SIGNAL(clicked()), this, SLOT(removeItemFromInventory()));
}

void PrimaryHMI::createBill()
{
    qDebug() << "createBill" << endl;
}

void PrimaryHMI::searchItemCode()
{
    qDebug() << "searchItemCode" << endl;
}

void PrimaryHMI::searchItemPrice()
{
    qDebug() << "searchItemPrice" << endl;
}

void PrimaryHMI::displayInventory()
{
    qDebug() << "displayInventory" << endl;
}

void PrimaryHMI::addItemToInventory()
{
    qDebug() << "addItemToInventory" << endl;
}

void PrimaryHMI::removeItemFromInventory()
{
    qDebug() << "removeItemFromInventory" << endl;
}

PrimaryHMI::~PrimaryHMI()
{
    delete ui;
}
