#include "WidgetManager.h"
#include <QDebug>

widgetManager::widgetManager(QWidget *parent) :
    QWidget(parent)
  , primaryHmi(NULL)
  , createBill(NULL)
  , addItemToInventory(NULL)
  , removeItemFromInventory(NULL)
{
    initializeAndSetUpPrimryHmi();
}

void widgetManager::primaryHmiSlot(defines::primaryHmiButtons::primaryHmiButtons button)
{
    switch (button) {
    case defines::primaryHmiButtons::primaryHmiButtons::CREATE_BILL:
        initializeAndSetUpCreateBill();
        break;
    case defines::primaryHmiButtons::primaryHmiButtons::ADD_ITEM_TO_INVENTORY:
        initializeAndSetUpAddItemToInventory();
        break;
    case defines::primaryHmiButtons::primaryHmiButtons::REMOVE_ITEM_FROM_INVENTORY:
        initializeAndSetUpRemoveItemFromInventory();
        break;
    default:
        break;
    }

    primaryHmi->hide();
}

void widgetManager::createBillSlot(defines::createBillButtons::createBillButtons button)
{
    switch (button) {
    case defines::createBillButtons::createBillButtons::FINALIZE_BILL:
        createBill->hide();
        primaryHmi->show();
        break;
    default:
        break;
    }
}

void widgetManager::addItemToInventorySlot(defines::addItemToInventory::addItemToInventory /*button*/)
{
    addItemToInventory->hide();
    primaryHmi->show();
}

void widgetManager::removeItemFromInventorySlot(defines::removeItemFromInventory::removeItemFromInventory /*button*/)
{
    removeItemFromInventory->hide();
    primaryHmi->show();
}

void widgetManager::initializeAndSetUpPrimryHmi()
{
    if (!primaryHmi)
    {
        primaryHmi = new PrimaryHMI(this);
        QObject::connect(primaryHmi, SIGNAL(primaryHmiSignal(defines::primaryHmiButtons::primaryHmiButtons)), this, SLOT(primaryHmiSlot(defines::primaryHmiButtons::primaryHmiButtons)));
    }

    primaryHmi->show();
}

void widgetManager::initializeAndSetUpCreateBill()
{
    if (!createBill)
    {
       createBill = new CreateBill(this);
       QObject::connect(createBill, SIGNAL(createBillSignal(defines::createBillButtons::createBillButtons)), this, SLOT(createBillSlot(defines::createBillButtons::createBillButtons)));
    }

    createBill->show();
}

void widgetManager::initializeAndSetUpAddItemToInventory()
{
    if (!addItemToInventory)
    {
       addItemToInventory = new AddItemToInventory(this);
       QObject::connect(addItemToInventory, SIGNAL(AddItemToInventorySignal(defines::addItemToInventory::addItemToInventory)), this, SLOT(addItemToInventorySlot(defines::addItemToInventory::addItemToInventory)));
    }

    addItemToInventory->show();
}

void widgetManager::initializeAndSetUpRemoveItemFromInventory()
{
    if (!removeItemFromInventory)
    {
       removeItemFromInventory = new RemoveItemFromInventory(this);
       QObject::connect(removeItemFromInventory, SIGNAL(removeItemFromInventorySignal(defines::removeItemFromInventory::removeItemFromInventory)), this, SLOT(removeItemFromInventorySlot(defines::removeItemFromInventory::removeItemFromInventory)));
    }

    removeItemFromInventory->show();
}
