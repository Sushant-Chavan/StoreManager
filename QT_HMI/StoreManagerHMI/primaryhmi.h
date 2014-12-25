#ifndef PRIMARYHMI_H
#define PRIMARYHMI_H

#include <QWidget>
#include "backendSource/ItemManager.h"
#include"backendSource/AccessConfig.h"
#include "createbill.h"
#include "Defines.h"

namespace Ui {
class PrimaryHMI;
}

class PrimaryHMI : public QWidget
{
    Q_OBJECT

public:
    explicit PrimaryHMI(QWidget *parent = 0);
    ~PrimaryHMI();

    itemManager* getItemManager() { return _iManager; }

private:
    Ui::PrimaryHMI *ui;

    CreateBill* createBillWidget;

signals:
    void primaryHmiSignal(defines::primaryHmiButtons::primaryHmiButtons button);

public slots:
    void createBill();
    void searchItemCode();
    void searchItemPrice();
    void displayInventory();
    void addItemToInventory();
    void removeItemFromInventory();

protected:
    itemManager* _iManager;
    readConfig* _configReader;
    writeConfig* _configwriter;

    void initializeBackEnd();
};

#endif // PRIMARYHMI_H
