#include "primaryhmi.h"
#include "ui_primaryhmi.h"
#include "createbill.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QDebug>

PrimaryHMI::PrimaryHMI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PrimaryHMI)
{
    ui->setupUi(this);
    this->setLayout(ui->topLayout);

    initializeBackEnd();

    QObject::connect(ui->CreateBillPushButton, SIGNAL(clicked()), this, SLOT(createBill()));
    QObject::connect(ui->SearchItemCodePushButton, SIGNAL(clicked()), this, SLOT(searchItemCode()));
    QObject::connect(ui->SearchItemPricePushButton, SIGNAL(clicked()), this, SLOT(searchItemPrice()));
    QObject::connect(ui->DisplayInventoryPushButton, SIGNAL(clicked()), this, SLOT(displayInventory()));
    QObject::connect(ui->AddNewItemPushButton, SIGNAL(clicked()), this, SLOT(addItemToInventory()));
    QObject::connect(ui->RemoveInventoryItemPushButton, SIGNAL(clicked()), this, SLOT(removeItemFromInventory()));
}

void PrimaryHMI::initializeBackEnd()
{
    _iManager = new itemManager;
    _configReader = new readConfig(_iManager);
    _configwriter = new writeConfig(_iManager);
    _configReader->readItemData();
}

void PrimaryHMI::createBill()
{
    qDebug() << "createBill" << endl;

    emit primaryHmiSignal(defines::primaryHmiButtons::primaryHmiButtons::CREATE_BILL);
}

void PrimaryHMI::searchItemCode()
{
    emit primaryHmiSignal(defines::primaryHmiButtons::primaryHmiButtons::SEARCH_ITEM_CODE);

    qDebug() << "searchItemCode" << endl;
}

void PrimaryHMI::searchItemPrice()
{
    emit primaryHmiSignal(defines::primaryHmiButtons::primaryHmiButtons::SEARCH_ITEM_PRICE);

    qDebug() << "searchItemPrice" << endl;
}

void PrimaryHMI::displayInventory()
{
    emit primaryHmiSignal(defines::primaryHmiButtons::primaryHmiButtons::DISPLAY_INVENTORY);

    qDebug() << "displayInventory" << endl;
}

void PrimaryHMI::addItemToInventory()
{
    emit primaryHmiSignal(defines::primaryHmiButtons::primaryHmiButtons::ADD_ITEM_TO_INVENTORY);

    qDebug() << "addItemToInventory" << endl;
}

void PrimaryHMI::removeItemFromInventory()
{
    emit primaryHmiSignal(defines::primaryHmiButtons::primaryHmiButtons::REMOVE_ITEM_FROM_INVENTORY);

    qDebug() << "removeItemFromInventory" << endl;
}

PrimaryHMI::~PrimaryHMI()
{
    delete ui;
}
