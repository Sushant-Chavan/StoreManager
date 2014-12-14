#include "createbill.h"
#include "ui_createbill.h"
#include <QDebug>

CreateBill::CreateBill(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreateBill)
{
    ui->setupUi(this);

    this->setLayout(ui->createBillTopLayout);

    QObject::connect(ui->AddtoBillButton, SIGNAL(clicked()), this, SLOT(addItemSlot()));
    QObject::connect(ui->RemoveItemFromBill, SIGNAL(clicked()), this, SLOT(removeItemSlot()));
    QObject::connect(ui->ShowBill, SIGNAL(clicked()), this, SLOT(showBillSlot()));
    QObject::connect(ui->FinalizeBill, SIGNAL(clicked()), this, SLOT(finalizeBillSlot()));
}

void CreateBill::addItemSlot()
{
    emit createBillSignal(defines::createBillButtons::createBillButtons::ADD_TO_BILL);

    unsigned int itemCode = ui->ItemCodeEntry->text().toUInt();
    unsigned int itemQuantity = ui->ItemQuantityEntry->text().toUInt();

    qDebug() << "Add Item.  Item Code : " << itemCode << "\t Item Quantity : " << itemQuantity;
}

void CreateBill::removeItemSlot()
{
    emit createBillSignal(defines::createBillButtons::createBillButtons::REMOVE_FROM_BILL);

    unsigned int itemCode = ui->ItemCodeEntry->text().toUInt();

    qDebug() << "Remove Item.  Item Code : " << itemCode;
}

void CreateBill::showBillSlot()
{
    emit createBillSignal(defines::createBillButtons::createBillButtons::SHOW_BILL);

    qDebug() << "Show Bill";
}

void CreateBill::finalizeBillSlot()
{
    emit createBillSignal(defines::createBillButtons::createBillButtons::FINALIZE_BILL);

    qDebug() << "Finalaize Bill";
}

CreateBill::~CreateBill()
{
    delete ui;
}
