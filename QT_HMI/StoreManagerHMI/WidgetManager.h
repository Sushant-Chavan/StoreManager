#ifndef WIDGETMANAGER_H
#define WIDGETMANAGER_H

#include <QWidget>
#include "primaryhmi.h"
#include "createbill.h"
#include "additemtoinventory.h"
#include "removeitemfrominventory.h"

class widgetManager : public QWidget
{
    Q_OBJECT

public:
    explicit widgetManager(QWidget *parent = 0);
    ~widgetManager(){}

protected:
    PrimaryHMI* primaryHmi;
    CreateBill* createBill;
    AddItemToInventory* addItemToInventory;
    RemoveItemFromInventory* removeItemFromInventory;

    void initializeAndSetUpPrimryHmi();
    void initializeAndSetUpCreateBill();
    void initializeAndSetUpAddItemToInventory();
    void initializeAndSetUpRemoveItemFromInventory();


public slots:
    void primaryHmiSlot(defines::primaryHmiButtons::primaryHmiButtons button);
    void createBillSlot(defines::createBillButtons::createBillButtons button);
    void addItemToInventorySlot(defines::addItemToInventory::addItemToInventory button);
    void removeItemFromInventorySlot(defines::removeItemFromInventory::removeItemFromInventory button);
};

#endif // WIDGETMANAGER_H
