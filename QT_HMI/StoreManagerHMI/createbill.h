#ifndef CREATEBILL_H
#define CREATEBILL_H

#include <QWidget>
#include "backendSource/Billing.h"
#include "backendSource/ItemManager.h"
#include "Defines.h"

namespace Ui {
class CreateBill;
}

class CreateBill : public QWidget
{
    Q_OBJECT

public:
    explicit CreateBill(QWidget *parent = 0);
    explicit CreateBill(QWidget *parent = 0, itemManager* iManager = NULL);
    ~CreateBill();

private:
    Ui::CreateBill *ui;

signals:
    void createBillSignal(defines::createBillButtons::createBillButtons button);

public slots:
    void addItemSlot();
    void removeItemSlot();
    void showBillSlot();
    void finalizeBillSlot();

protected:
    itemManager* _iManager;
    bill* _customerBill;
};

#endif // CREATEBILL_H
